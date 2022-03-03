/* 
 * File:   FatFs2Jaffl.h
 * Author: chaos
 *
 * Created on March 15, 2015, 6:51 PM
 */

#ifndef FATFS2JAFFL_H
#define	FATFS2JAFFL_H

#include "utility/integer.h"

// Functions to attach Jaffl to FatFs
void attach_pins(void (*cs_low)(void), void (*cs_high)(void));
void attach_SPIdriver(void (*spi_receive)(BYTE*,UINT), void (*spi_send)(BYTE*,UINT) , void (*spi_init)(void), void (*spi_high_speed)(void));
// Extra functions not in diskio.h
BYTE validateCSD (void);
BYTE detectCard (void);
        
#endif	/* FATFS2JAFFL_H */

