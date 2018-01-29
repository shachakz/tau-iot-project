/*
 * This file allows others to subscribe and publish (implements the needed functions).
 * In addition, it creates the connection to the MQTT and announce the main when it's connected.
 */

/*
 *  ======== app_mqtt.c ========
 */

#include "include/apps/app_mqtt.h"
#include "include/system/threads.h"
#include "include/system/mqueue.h"

#include "include/credentials.h"

#define MY_TASK_ID      APP_MQTT_THREAD

#define WRITE_BUF_SIZE                  ( 300 )
#define READ_BUF_SIZE                   ( 300 )

static Network network;
static MQTTClient* pClient;


void ConnectToMQTTServer(uint8_t* writeBuf, uint8_t* readBuf);

void* MqttThread(void *arg0)
{
    task_message_t inputMessage;
    task_message_t outputMessage;
    MQTTClient client;

    pClient = &client;

    memset(&outputMessage, 0x00, sizeof(task_message_t));

    SysCreateQueue(MY_TASK_ID, "MqttQueue");

    uint8_t writebuf[WRITE_BUF_SIZE];
    uint8_t readbuf[READ_BUF_SIZE];

    while(1)
    {
        SysWaitOnQueue(MY_TASK_ID, &inputMessage, sizeof(inputMessage));
        System_printf("Mqtt recv: %u\n", inputMessage.message_type);
        System_flush();

        switch(inputMessage.message_type)
        {
            case SYS_MSG_MQTT_DO_CONNECT:
                ConnectToMQTTServer(writebuf, readbuf);
                outputMessage.message_type = SYS_MSG_MQTT_READY;
                SysPublishToQueue(APP_MAIN_THREAD, &outputMessage, sizeof(outputMessage));
                break;
        }

        SysReleaseMessage(&inputMessage);
    }
}

void ConnectToMQTTServer(uint8_t* writeBuf, uint8_t* readBuf)
{
    int rc = 0;
    NewNetwork(&network);
    int a = ConnectNetwork(&network, MQTT_HOST_URL, MQTT_HOST_PORT);
    System_printf("MQTT Connect Network: %d\n", a);
    System_flush();

    MQTTClientInit(pClient, &network, 1000, writeBuf, WRITE_BUF_SIZE, readBuf, READ_BUF_SIZE);
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.clientID.cstring   = MQTT_CLIENT_ID;
    data.username.cstring   = MQTT_USER;
    data.password.cstring   = MQTT_PASS;
    data.MQTTVersion        = 3;
    data.keepAliveInterval  = 0; /* This will tell MQTT client to spare keep alives. */
    data.cleansession       = 1;
    data.willFlag           = 0;

    rc = MQTTConnect(pClient, &data);
    System_printf("Connected client: %d\n", rc);
    System_flush();

    MQTTStartTask(pClient);
}


void PublishMqtt(char* topic, char* msg)
{
    MQTTMessage msgToPub;
    msgToPub.payload = msg;
    msgToPub.payloadlen = strlen(msg);
    msgToPub.qos = QOS0;

    int rc = MQTTPublish(pClient, topic, &msgToPub);
    if (0 == rc)
    {
        System_printf("Publish to: %s\n", topic);
        System_flush();
    }
}

void SubscribeMqtt(char* topic, messageHandler handler, int correlation)
{
    int rc = MQTTSubscribeWithCorrelation(pClient, topic, QOS2, handler, correlation);
    if (0 == rc)
    {
        System_printf("Subscribed to: %s\n", topic);
        System_flush();
    }
}
