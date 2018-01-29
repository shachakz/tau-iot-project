/*
 * This file takes care of the WiFi. It scans for networks, and connects
 * to a predefined network. In addition, it contains the disconnect method.
 */

/*
 *  ======== app_wifi.c ========
 */

#include "include/apps/app_wifi.h"
#include "include/apps/app_wifi_evt.h"

#include "include/system/threads.h"
#include "include/system/mqueue.h"

/* Driver Header files */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>


/* Example/Board Header files */
#include "include/cc3100/cc3100_device.h"
#include "include/cc3100/simplelink.h"

#include "include/credentials.h"

#define MY_TASK_ID      APP_WIFI_THREAD

task_message_t connection_message;

#define NUM_OF_NET_SEARCH                   ( 10 )
#define NETWORK_CONNECTION_TIME_LIMIT_SEC   ( 5 )

uint8_t queryForNetwork(char* ssid, Sl_WlanNetworkEntry_t* entry)
{
    uint8_t intervalInSeconds = 300;
    sl_WlanPolicySet(SL_POLICY_SCAN, SL_SCAN_POLICY(TRUE), (_u8 *)&intervalInSeconds, sizeof(intervalInSeconds));
    usleep(300 * 1000); //Sleep for ~300ms - active scan time

    int i;
    Sl_WlanNetworkEntry_t netEntries[NUM_OF_NET_SEARCH];
    _i16 resultsCount = sl_WlanGetNetworkList(0, NUM_OF_NET_SEARCH, netEntries);

    /* Disable Scanning. */
    sl_WlanPolicySet(SL_POLICY_SCAN, SL_SCAN_POLICY(FALSE), 0, 0);

    for (i=0; i< resultsCount; i++)
    {
        if (!strcmp(ssid, netEntries[i].ssid))
        {
            memcpy(entry, &netEntries[i], sizeof(Sl_WlanNetworkEntry_t));
            return 1;
        }
    }
    return 0;
}

uint8_t connectToAp(Sl_WlanNetworkEntry_t* entry)
{
    int connectionLimit = NETWORK_CONNECTION_TIME_LIMIT_SEC;

    SlSecParams_t secParams = {0};
    secParams.Key = NETWORK_PSWD;
    secParams.KeyLen = strlen(secParams.Key);
    secParams.Type = SL_SEC_TYPE_WPA_WPA2;

    if (0 != sl_WlanConnect(entry->ssid, entry->ssid_len, 0, &secParams, 0))
    {
        return 0;
    }


    do
    {
        sleep(1);
    }
    while((--connectionLimit > 0) && (!connectionStatus || !ipStatus));

    if (!connectionStatus || !ipStatus)
    {
        //If we would like to support recovery, this is a good time to disconnect from wlan
       return 0;
    }

    return 1;
}

uint8_t disconnectFromEverthing()
{
    sl_WlanDisconnect();
}

uint8_t ensureWifiConnectedToAP()
{
    if (connectionStatus && ipStatus) {
        return 1;
    }

    /* Not sure if i'm connected, ip or whatever - let's disconnect. */
    disconnectFromEverthing();

    Sl_WlanNetworkEntry_t entry;
    uint8_t apFound = queryForNetwork(NETWORK_NAME, &entry);
    if(apFound)
    {
        uint8_t retVal = connectToAp(&entry);
        if(retVal)
        {
            connection_message.message_type = SYS_MSG_WIFI_CONNECTED;
            SysPublishToQueue(APP_MAIN_THREAD, &connection_message, sizeof(connection_message));
        }
        return retVal;
    }

    return 0;
}
/*
 *  ======== wifiThread ========
 */

void* WifiThread(void *arg0)
{
    /* Shut down external flash on LaunchPads. It is powered on by default
     * but can be shut down through SPI
     */
    int retVal;

    SysCreateQueue(MY_TASK_ID, "WifiQueue");

    /* Init GPIOs and shit. */
    cc3100_init();
    SysCreateThread(WifiEventsTask, WIFI_EVT_TASK_THREAD_SIZE_BYTES, WIFI_EVT_TASK_PRIORITY, NULL);

    retVal = sl_Start(0, 0, 0);

    System_printf("OH YEAH\n");
    System_flush();

    while(1)
    {
        uint8_t connected = ensureWifiConnectedToAP();

        System_printf("Connected state: %d\n", connected);
        System_flush();
        sleep(10);
    }
}
