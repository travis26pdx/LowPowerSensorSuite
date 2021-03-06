/**
 * File: usci_spi.c - msp430 USCI SPI implementation
 *
 * Copyright (c) 2012 by Rick Kimball <rick@kimballsoftware.com>
 * spi abstraction api for msp430
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 */

#include <msp430.h>
#include <stdint.h>
#include "spi_430.h"
#include <Energia.h>

#if defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_USCI__)

/**
 * USCI flags for various the SPI MODEs
 *
 * Note: The msp430 UCCKPL tracks the CPOL value. However,
 * the UCCKPH flag is inverted when compared to the CPHA
 * value described in Motorola documentation.
 */

#define SPI_MODE_0 (UCCKPH)			    /* CPOL=0 CPHA=0 */
#define SPI_MODE_1 (0)                 	/* CPOL=0 CPHA=1 */
#define SPI_MODE_2 (UCCKPL | UCCKPH)    /* CPOL=1 CPHA=0 */
#define SPI_MODE_3 (UCCKPL)			    /* CPOL=1 CPHA=1 */

#define SPI_MODE_MASK (UCCKPL | UCCKPH)

/**
 * spi_initialize() - Configure USCI UCB0 for SPI mode
 *
 * P2.0 - CS (active low)
 * P1.5 - SCLK
 * P1.6 - MISO aka SOMI
 * P1.7 - MOSI aka SIMO
 *
 */

/* Calculate divisor to keep SPI clock close to 4MHz but never over */
#ifndef SPI_CLOCK_SPEED
#define SPI_CLOCK_SPEED 4000000L
#endif

#if F_CPU < 4000000L
#define SPI_CLOCK_DIV() 1 
#else
#define SPI_CLOCK_DIV() ((F_CPU / SPI_CLOCK_SPEED) + (F_CPU % SPI_CLOCK_SPEED == 0 ? 0:1))
#endif

#if defined(DEFAULT_SPI)
    uint8_t spiModule = DEFAULT_SPI;
#else
    uint8_t spiModule = 0;
#endif

void spi_initialize(void)
{
	UCB0CTL1 = UCSWRST | UCSSEL_2;      // Put USCI in reset mode, source USCI clock from SMCLK
	UCB0CTL0 = SPI_MODE_0 | UCMSB | UCSYNC | UCMST;  // Use SPI MODE 0 - CPOL=0 CPHA=0

 	/* Set pins to SPI mode. */
	pinMode_int(SCK, SPISCK_SET_MODE);
	pinMode_int(MOSI, SPIMOSI_SET_MODE);
	pinMode_int(MISO, SPIMISO_SET_MODE);

	UCB0BR0 = SPI_CLOCK_DIV() & 0xFF;   // set initial speed to 4MHz
	UCB0BR1 = (SPI_CLOCK_DIV() >> 8 ) & 0xFF;

	UCB0CTL1 &= ~UCSWRST;			    // release USCI for operation
}

/**
 * spi_disable() - put USCI into reset mode
 */
void spi_disable(void)
{
    UCB0CTL1 |= UCSWRST;                // Put USCI in reset mode
}

#ifdef UC0IFG
/* redefine for older 2xx devices where the flags are in SFR */
#define UCB0IFG  UC0IFG   
#define UCRXIFG  UCB0RXIFG
#define UCTXIFG  UCB0TXIFG
#endif

/**
 * spi_send() - send a byte and recv response
 */
uint8_t spi_send(const uint8_t data)
{
	/* Wait for previous tx to complete. */
	while (!(UCB0IFG & UCTXIFG));
	/* Clear RX Flag */
	UCB0IFG &= ~UCRXIFG;

	/* Send byte */
	UCB0TXBUF = data;

	/* Wait for a rx character? */
	while (!(UCB0IFG & UCRXIFG));

	/* Reading clears RXIFG flag. */
	return UCB0RXBUF;
}



/**
 * spi_send() - send a word and recv response.
 */
uint16_t spi_send16(const uint16_t data)
{
	uint16_t datain;
	/* Wait for previous tx to complete. */
	while (!(UCB0IFG & UCTXIFG));
	/* Clear RX Flag */
	UCB0IFG &= ~UCRXIFG;
	
	if (UCB0CTL0 & UCMSB) // MSB first?
	{
		UCB0TXBUF = data >> 8;          /* Send first byte. */
		while (!(UCB0IFG & UCRXIFG));   /* Wait for a rx character? */
		datain = UCB0RXBUF;             /* receive MSB */
		
		UCB0TXBUF = data | 0xFF;        /* send second byte */
		while (!(UCB0IFG & UCRXIFG));   /* Wait for a rx character? */
		/* Reading clears RXIFG flag. */
		return ((datain << 8) | UCB0RXBUF);
	} else {
		UCB0TXBUF = data & 0xFF;        /* Send first byte. */
		while (!(UCB0IFG & UCRXIFG));   /* Wait for a rx character? */
		datain = UCB0RXBUF;
		/* send second byte */
		UCB0TXBUF = data >> 8;
		while (!(UCB0IFG & UCRXIFG));   /* Wait for a rx character? */
		/* Reading clears RXIFG flag. */
		uint16_t tmp = UCB0RXBUF;        /* receive MSB */
		return (datain | (tmp << 8));
	}
	
}

/**
 * spi_send() - send buffer of byte and recv response.
 */
void spi_send(void *buf, uint16_t count) 
{
    uint8_t *ptx = (uint8_t *)buf;
    uint8_t *prx = (uint8_t *)buf;
    if (count == 0) return;
    /* Wait for previous tx to complete. */
    while (!(UCB0IFG & UCTXIFG));
    /* Clear RX Flag */
    UCB0IFG &= ~UCRXIFG;
    while(count){
        while (!(UCB0IFG & UCTXIFG)); 
        /* Setting TXBUF clears the TXIFG flag. */
        UCB0TXBUF = *ptx++;
        count--;
        while (!(UCB0IFG & UCRXIFG)); 
        /* Reading RXBUF clears the RXIFG flag. */
        *prx++ = UCB0RXBUF;
    } 
}

/**
 * spi_transmit() - send a byte
 */
void spi_transmit(const uint8_t _data)
{
	UCB0TXBUF = _data; // setting TXBUF clears the TXIFG flag

	while (UCB0STAT & UCBUSY); // wait for SPI TX/RX to finish
	// clear RXIFG flag
	UCB0IFG &= ~UCRXIFG;
}

void spi_transmit16(const uint16_t data)
{
	/* Wait for previous tx to complete. */
	while (!(UCB0IFG & UCTXIFG));
	if (UCB0CTL0 & UCMSB) // MSB first?
	{
		/* Setting TXBUF clears the TXIFG flag. */
		UCB0TXBUF = data >> 8;
		/* Wait for previous tx to complete. */
		while (!(UCB0IFG & UCTXIFG));
		/* Setting TXBUF clears the TXIFG flag. */
		UCB0TXBUF = data & 0xFF;
	}else{
		/* Setting TXBUF clears the TXIFG flag. */
		UCB0TXBUF = data & 0xFF;
		/* Wait for previous tx to complete. */
		while (!(UCB0IFG & UCTXIFG));
		/* Setting TXBUF clears the TXIFG flag. */
		UCB0TXBUF = data >> 8;
	}
	while (UCB0STAT & UCBUSY); // wait for SPI TX/RX to finish
	// clear RXIFG flag
	UCB0IFG &= ~UCRXIFG;
}

void spi_transmit(void *buf, uint16_t count)
{
    uint8_t *ptx = (uint8_t *)buf;
	if (count == 0) return;
	while(count){
		if (UCB0IFG & UCTXIFG){
			/* Setting TXBUF clears the TXIFG flag. */
			UCB0TXBUF = *ptx++;
			count--;
		}
	}
	while (UCB0STAT & UCBUSY); // wait for SPI TX/RX to finish
	// clear RXIFG flag
	UCB0IFG &= ~UCRXIFG;
}

/***SPI_MODE_0
 * spi_set_divisor() - set new clock divider for USCI
 *
 * USCI speed is based on the SMCLK divided by BR0 and BR1
 *
 */
void spi_set_divisor(const uint16_t clkdiv)
{
	UCB0CTL1 |= UCSWRST;		// go into reset state
	UCB0BR0 = clkdiv & 0xFF;
	UCB0BR1 = (clkdiv >> 8 ) & 0xFF;
	UCB0CTL1 &= ~UCSWRST;		// release for operation
}

/**
 * spi_set_bitorder(LSBFIRST=0 | MSBFIRST=1)
 */
void spi_set_bitorder(const uint8_t order)
{
    UCB0CTL1 |= UCSWRST;        // go into reset state
    UCB0CTL0 = (UCB0CTL0 & ~UCMSB) | ((order == 1 /*MSBFIRST*/) ? UCMSB : 0); /* MSBFIRST = 1 */
    UCB0CTL1 &= ~UCSWRST;       // release for operation
}

/**
 * spi_set_datamode() - mode 0 - 3
 */
void spi_set_datamode(const uint8_t mode)
{
    UCB0CTL1 |= UCSWRST;        // go into reset state
    switch(mode) {
    case 0: /* SPI_MODE0 */
        UCB0CTL0 = (UCB0CTL0 & ~SPI_MODE_MASK) | SPI_MODE_0;
        break;
    case 1: /* SPI_MODE1 */
        UCB0CTL0 = (UCB0CTL0 & ~SPI_MODE_MASK) | SPI_MODE_1;
        break;
    case 2: /* SPI_MODE2 */
        UCB0CTL0 = (UCB0CTL0 & ~SPI_MODE_MASK) | SPI_MODE_2;
        break;
    case 4: /* SPI_MODE3 */
        UCB0CTL0 = (UCB0CTL0 & ~SPI_MODE_MASK) | SPI_MODE_3;
        break;
    default:
        break;
    }
    UCB0CTL1 &= ~UCSWRST;       // release for operation
}
#else
    //#error "Error! This device doesn't have a USCI peripheral"
#endif
