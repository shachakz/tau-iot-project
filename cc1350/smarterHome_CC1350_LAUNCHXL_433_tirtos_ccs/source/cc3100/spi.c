/*
 * spi.c - msp430fr5969 launchpad spi interface implementation
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
#include <ti/drivers/SPI.h>
#include <ti/drivers/PIN.h>
//#include <ti/drivers/SPI/SPICC26XXDMA.h>

#include "../../include/cc3100/simplelink.h"
#include "../../include/cc3100/spi.h"
#include "../../include/Board.h"

static PIN_Handle hSpiNotSSPin = NULL;
static PIN_State pinState;

static PIN_Config WifiSpiPinTable[] =
{
    Board_SPI_CC3100_NCS | PIN_GPIO_OUTPUT_EN | PIN_GPIO_HIGH | PIN_PUSHPULL | PIN_DRVSTR_MIN,

    PIN_TERMINATE
};

SPI_Handle      spi;

int spi_Close(Fd_t fd)
{
    //Shouldn't we 'SPI_close(spi);' ?

    /* Disable WLAN Interrupt ... */
    CC3100_InterruptDisable();
    return SL_OS_RET_CODE_OK;
}

Fd_t spi_Open(char *ifName, unsigned long flags)
{
    SPI_Params      spiParams;

    SPI_init();
    hSpiNotSSPin = PIN_open(&pinState, WifiSpiPinTable);
    if (NULL == hSpiNotSSPin)
    {
        return NULL;
    }

    SPI_Params_init(&spiParams);  // Initialize SPI parameters
    spiParams.mode = SPI_MASTER;
    spiParams.bitRate = 1000000;
    spiParams.dataSize = 8;
    spiParams.transferMode = SPI_MODE_BLOCKING;
    spi = SPI_open(Board_SPI0, &spiParams);

    if (spi == NULL) {
        while (1);  // SPI_open() failed
    }

    CC3100_InterruptEnable();
    return SL_OS_RET_CODE_OK;
}


int spi_Write(Fd_t fd, unsigned char *pBuff, int len)
{
    SPI_Transaction spiTransaction;
    bool            transferOK;

    spiTransaction.count = len;
    spiTransaction.txBuf = pBuff;
    spiTransaction.rxBuf = NULL;

    PIN_setOutputValue(hSpiNotSSPin, Board_SPI_CC3100_NCS, 0);

    transferOK = SPI_transfer(spi, &spiTransaction);
    if (!transferOK) {
        // Error in SPI or transfer already in progress.
    }

    PIN_setOutputValue(hSpiNotSSPin, Board_SPI_CC3100_NCS, 1);

    return len;
}


int spi_Read(Fd_t fd, unsigned char *pBuff, int len)
{
    SPI_Transaction spiTransaction;
    bool            transferOK;

    spiTransaction.count = len;
    spiTransaction.txBuf = NULL;
    spiTransaction.rxBuf = pBuff;

    PIN_setOutputValue(hSpiNotSSPin, Board_SPI_CC3100_NCS, 0);

    transferOK = SPI_transfer(spi, &spiTransaction);
    if (!transferOK) {
        // Error in SPI or transfer already in progress.
    }

    PIN_setOutputValue(hSpiNotSSPin, Board_SPI_CC3100_NCS, 1);
    return len;
}

