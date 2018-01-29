/*
 * cc3100_device.c
 *
 */

#include <stdint.h>
#include <ti/drivers/PIN.h>

#include "../../include/Board.h"
#include "../../include/cc3100/simplelink.h"

#include "../../include/cc3100/cc3100_device.h"


static PIN_State            wifiPinState;
static PIN_Handle           wifiPinHandle;

static P_EVENT_HANDLER      irqHandler;
static uint8_t              irqMasked;
static void*                irqHandlerArg;

void IrqCallback(PIN_Handle handle, PIN_Id pinId);

/*
 * Initial WIFI pin configuration table
 */
PIN_Config wifiPinTable[] = {
                             Board_PIN_CC3100_NHIB | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW  | PIN_PUSHPULL | PIN_DRVSTR_MAX,
                             Board_PIN_CC3100_IRQ  | PIN_INPUT_EN       | PIN_PULLDOWN  | PIN_IRQ_DIS,
                             PIN_TERMINATE
                            };


void cc3100_init()
{
    irqMasked = FALSE;
    wifiPinHandle = PIN_open(&wifiPinState, wifiPinTable);
    if(!wifiPinHandle) {
        /* Error initializing board LED pins */
        while(1);
    }

    /* Setup callback for button pins */
    if (PIN_registerIntCb(wifiPinHandle, &IrqCallback) != 0) {
        /* Error registering button callback function */
        while(1);
    }
}

/*!
    \brief register an interrupt handler for the host IRQ

    \param[in]      InterruptHdl    -    pointer to interrupt handler function

    \param[in]      pValue          -    pointer to a memory strcuture that is
                    passed to the interrupt handler.

    \return         upon successful registration, the function shall return 0.
                    Otherwise, -1 shall be returned

    \sa
    \note           If there is already registered interrupt handler, the
                    function should overwrite the old handler with the new one
    \warning
*/
int registerInterruptHandler(P_EVENT_HANDLER InterruptHdl , void* pValue)
{
    irqHandler      = InterruptHdl;
    irqHandlerArg   = pValue;
    return 0;
}

/*!
    \brief          Enables the CC3100

    \param[in]      none

    \return         none

    \note

    \warning
*/
void CC3100_enable()
{
    PIN_setOutputValue(wifiPinHandle, Board_PIN_CC3100_NHIB, 1);
}

/*!
    \brief          Disables the CC3100

    \param[in]      none

    \return         none

    \note

    \warning
*/
void CC3100_disable()
{
    PIN_setOutputValue(wifiPinHandle, Board_PIN_CC3100_NHIB, 0);
}

/*!
    \brief          Enables the interrupt from the CC3100

    \param[in]      none

    \return         none

    \note

    \warning
*/
void CC3100_InterruptEnable(void)
{
    PIN_Config curVal = PIN_getConfig(Board_PIN_CC3100_IRQ);
    curVal = ( curVal & ~PIN_BM_IRQ ) | PIN_IRQ_POSEDGE;
    PIN_setInterrupt(wifiPinHandle, curVal );
}

/*!
    \brief          Disables the interrupt from the CC3100

    \param[in]      none

    \return         none

    \note

    \warning
*/
void CC3100_InterruptDisable()
{
    PIN_Config curVal = PIN_getConfig(Board_PIN_CC3100_IRQ);
    curVal = ( curVal & ~PIN_BM_IRQ ) | PIN_IRQ_DIS;
    PIN_setInterrupt(wifiPinHandle, curVal );
}

/*!
    \brief      Masks the Host IRQ

    \param[in]      none

    \return         none

    \warning
*/
void MaskIntHdlr()
{
    irqMasked = TRUE;
}

/*!
    \brief     Unmasks the Host IRQ

    \param[in]      none

    \return         none

    \warning
*/
void UnMaskIntHdlr()
{
    irqMasked = FALSE;
}

void IrqCallback(PIN_Handle handle, PIN_Id pinId)
{
    if(!irqMasked)
    {
        irqHandler(irqHandlerArg);
    }
}

