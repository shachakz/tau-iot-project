/*
 * This file takes care of the wifi events. It exports the function that creates
 * the task, and keeps track of the connection and IP status.
 */

/*
 *  ======== app_wifi_evt.c ========
 */

#include "include/apps/app_wifi_evt.h"
#include "include/cc3100/cc3100_device.h"
#include "include/cc3100/simplelink.h"

#define MY_TASK_ID      APP_WIFI_EVTS_THREAD

uint8_t connectionStatus = 0;
uint8_t ipStatus = 0;

void SimpleLinkWlanEventHandler(SlWlanEvent_t *pWlanEvent)
{
    if(pWlanEvent == NULL)
    {
        return;
    }

    switch(pWlanEvent->Event)
    {
        case SL_WLAN_CONNECT_EVENT:
        {
            connectionStatus = 1;

            /*
             * Information about the connected AP (like name, MAC etc.) will be
             * available in 'slWlanConnectAsyncResponse_t' - Applications
             * can use it if required
             *
             * slWlanConnectAsyncResponse_t *pEventData = NULL;
             * pEventData = &pWlanEvent->EventData.STAandP2PModeWlanConnected;
             *
             */
        }
        break;

        case SL_WLAN_DISCONNECT_EVENT:
        {
            /* Clear connection & ip status */
            connectionStatus = ipStatus = 0;
            break;
        }

        default:
        {
            break;
        }
    }
}

/*!
    \brief This function handles events for IP address acquisition via DHCP
           indication

    \param[in]      pNetAppEvent is the event passed to the handler

    \return         None

    \note

    \warning
*/
void SimpleLinkNetAppEventHandler(SlNetAppEvent_t *pNetAppEvent)
{
    if(pNetAppEvent == NULL)
    {
        return;
    }

    switch(pNetAppEvent->Event)
    {
        case SL_NETAPP_IPV4_IPACQUIRED_EVENT:
        {
            ipStatus = 1;
            /*
             * Information about the connected AP's ip, gateway, DNS etc.
             * will be available in 'SlIpV4AcquiredAsync_t' - Applications
             * can use it if required
             *
             * SlIpV4AcquiredAsync_t *pEventData = NULL;
             * pEventData = &pNetAppEvent->EventData.ipAcquiredV4;
             * <gateway_ip> = pEventData->gateway;
             *
             */
            System_printf("Connected with ip: 0x%x\n\n", pNetAppEvent->EventData.ipAcquiredV4.ip);
            System_flush();
            break;
        }

        default:
        {
            break;
        }
    }
}
/*!
    \brief This function handles callback for the HTTP server events

    \param[in]      pHttpEvent - Contains the relevant event information
    \param[in]      pHttpResponse - Should be filled by the user with the
                    relevant response information

    \return         None

    \note

    \warning
*/
void SimpleLinkHttpServerCallback(SlHttpServerEvent_t *pHttpEvent,
                                  SlHttpServerResponse_t *pHttpResponse)
{
    /* Unused in this application */
    //CLI_Write(" [HTTP EVENT] Unexpected event \n\r");
}

/*!
    \brief This function handles general error events indication

    \param[in]      pDevEvent is the event passed to the handler

    \return         None
*/
void SimpleLinkGeneralEventHandler(SlDeviceEvent_t *pDevEvent)
{
    /*
     * Most of the general errors are not FATAL are are to be handled
     * appropriately by the application
     */
    //CLI_Write(" [GENERAL EVENT] \n\r");
}

/*!
    \brief This function handles socket events indication

    \param[in]      pSock is the event passed to the handler

    \return         None
*/
void SimpleLinkSockEventHandler(SlSockEvent_t *pSock)
{
    if(NULL == pSock)
    {
        return;
    }

    System_printf("Received socket event %d\n", pSock->Event);
    System_flush();    /*
     * This application doesn't work w/ socket - Hence not handling these events
     */
}

void* WifiEventsTask(void* arg0)
{
    sl_Task();
}
