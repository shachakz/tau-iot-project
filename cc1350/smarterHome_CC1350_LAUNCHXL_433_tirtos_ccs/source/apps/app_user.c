/*
 * This file has the user thread. it subscribes to its relevant queues.
 * In addition, it contains the conversion from json to the value in it,
 * and publishes the response.
 */

/*
 *  ======== app_user.c ========
 */


#include "include/apps/app_user.h"
#include "include/system/threads.h"
#include "include/system/mqueue.h"
#include "include/json/json.h"

#define MY_TASK_ID      APP_USER_THREAD

#define NUM_OF_PARAMETERS               ( 6)
#define NUM_OF_TOKENS                   ( 1 + (NUM_OF_PARAMETERS * 2) )

#define MAXIMUM_PARAM_LENGTH            ( 10 )
#define MAXIMUM_USER_RESPONSE_LENGTH    ( 50 )
#define MAXIMUM_FULL_RESPONSE_LENGTH    ( 50 + MAXIMUM_USER_RESPONSE_LENGTH )

json_parser jParser;
jsontok_t tokens[NUM_OF_TOKENS];

char valueBuffer[MAXIMUM_PARAM_LENGTH];
char responseBuffer[MAXIMUM_USER_RESPONSE_LENGTH];
char fullResponseBuffer[MAXIMUM_FULL_RESPONSE_LENGTH];

int json_get_parts(char* message, int len, char* field, char* buffer)
{
    int i;

    int r = json_parse(&jParser, message, len, tokens, NUM_OF_TOKENS);
    if (r < 0) {
        System_printf("Failed to parse JSON: %d\n", r);
        System_flush();
        return 1;
    }

    /* Assume the top-level element is an object */
    if (r < 1 || tokens[0].type != JSON_OBJECT) {
        printf("Object expected\n");
        return 1;
    }

    for (i = 1; i < r; i++) {
        if (jsoneq(message, &tokens[i], field) == 0) {
            memcpy(buffer, message + tokens[i+1].start, tokens[i+1].end-tokens[i+1].start);
            return 0;
        }
    }

    return 1;
}

void GatewayHandler(MessageData* messageData)
{
    if(NULL == messageData || NULL == messageData->topicName || NULL == messageData->message)
        return;

    int correlation = messageData->correlation;

    MQTTMessage* message = messageData->message;

    json_init(&jParser);

    char* valueParam = NULL;
    memset(valueBuffer, 0x00, sizeof(valueBuffer));

    if (!json_get_parts(message->payload, message->payloadlen, "value", valueBuffer))
    {
        valueParam = valueBuffer;
    }

    memset(responseBuffer, 0x00, sizeof(responseBuffer));
    subscriptions[correlation].handler(messageData, responseBuffer, valueParam);

    /* Reply response to the requesting app. */
    char replyBuffer[30];
    memset(replyBuffer, 0, sizeof(replyBuffer));

    if(!json_get_parts(message->payload, message->payloadlen, "replyTo", replyBuffer) && (0 != strlen(responseBuffer)))
    {
        memset(fullResponseBuffer, 0x00, sizeof(fullResponseBuffer));
        sprintf(fullResponseBuffer, "{\"value\":\"%s\"}", responseBuffer);
        PublishMqtt(replyBuffer, fullResponseBuffer);
    }
}

void OnAppStart(void)
{
    UserInit();

    int i;
    for (i=0; i < subscriptionsSize; i++)
    {
        SubscribeMqtt(subscriptions[i].topic, GatewayHandler, i);
    }
}

void* UserThread(void *arg0)
{
    task_message_t inputMessage;

    SysCreateQueue(MY_TASK_ID, "UserQueue");

    while(1)
    {
        SysWaitOnQueue(MY_TASK_ID, &inputMessage, sizeof(inputMessage));
        System_printf("User recv: %u\n", inputMessage.message_type);
        System_flush();

        switch(inputMessage.message_type)
        {
            case SYS_MSG_APP_START:
                OnAppStart();
                break;
        }

        SysReleaseMessage(&inputMessage);
    }
}
