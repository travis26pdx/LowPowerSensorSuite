/*
 * Just another FatFs Library
 * Ross Marchant, ross.marchant@my.jcu.edu.au
 * 
 * Based on:
 * Arduino Wrapper Function Library for FatFs
 * (c) 2010, David Sirkin sirkin@stanford.edu
 *
 * FatFS by ChaN:
 * http://elm-chan.org/fsw/ff/00index_e.html
 *
 * Modified by Travis Johnson, travis26@pdx.edu
 * 03/03/2022
 * Edits based on edits made by JCR, posted in 43oh.com forum
 * Line 42: Add SPIClass spi;
 * Line 121: Add 0 to begin(0)
 */

#include <msp430.h>
#include "SPI.h"
#include "Jaffl.h"
extern "C" {
#include "FatFs2Jaffl.h"
}

FATFS FFS::fatfs_obj; // Working copy of FATFS
DIR FFS::dir_obj; // Working copy of DIR
FIL FFS::fil_obj; // Working copy of FIL
FILINFO FFS::fno; // Working copy of FILINFO

unsigned char FFS::CS; // Pin to sd card's CS

uint8_t _clkdivider = 2; // Default spi clock 8Mhz / 2 = 4MHz


/*-----------------------------------------------------------------------*/
/* Constructor                                                           */
/*-----------------------------------------------------------------------*/

/* Don't instantiate from the sketch; it's done at the end of this file. */
FFS::FFS()
{
	SPIClass spi; // TGJ update
}


/*-----------------------------------------------------------------------*/
/* Chip Select/Deselect Functions for the Card's CS Pin                  */

/*-----------------------------------------------------------------------*/
void FFS::CS_LOW(void)
{
    digitalWrite(CS, LOW);
    //digitalWrite(RED_LED, HIGH);
    //SDCard_setCSLow();
}

void FFS::CS_HIGH(void)
{
    digitalWrite(CS, HIGH);
    //digitalWrite(RED_LED, LOW);
    //SDCard_setCSHigh();
}

int FFS::CS_READ(void)
{
    return !digitalRead(CS);
}

/*-----------------------------------------------------------------------*/
/* SPI Functions for diskio driver                  */

/*-----------------------------------------------------------------------*/

void FFS::SPI_RECEIVE(uint8_t *pBuffer, uint16_t size)
{
    uint16_t gie = __read_status_register() & GIE;               //Store current GIE state
    __disable_interrupt();                                  //Make this operation atomic
    UCB0IFG &= ~UCRXIFG;                                    //Ensure RXIFG is clear
    //Clock the actual data transfer and receive the bytes
    while (size--){
        while (!(UCB0IFG & UCTXIFG)) ;                      //Wait while not ready for TX
        UCB0TXBUF = 0xff;                                   //Write dummy byte
        while (!(UCB0IFG & UCRXIFG)) ;                      //Wait for RX buffer (full)
        *pBuffer++ = UCB0RXBUF;
    }
    __bis_SR_register(gie);                                 //Restore original GIE state
}

void FFS::SPI_SEND(uint8_t *pBuffer, uint16_t size)
{
    uint16_t gie = __read_status_register() & GIE;               //Store current GIE state
    __disable_interrupt();                                  //Make this operation atomic
    //Clock the actual data transfer and send the bytes. Note that we
    //intentionally not read out the receive buffer during frame transmission
    //in order to optimize transfer speed, however we need to take care of the
    //resulting overrun condition.
    while (size--){
        while (!(UCB0IFG & UCTXIFG)) ;                      //Wait while not ready for TX
        UCB0TXBUF = *pBuffer++;                             //Write byte
    }
    while (UCB0STAT & UCBUSY) ;                             //Wait for all TX/RX to finish
    UCB0RXBUF;                                              //Dummy read to empty RX buffer
                                                            //and clear any overrun conditions
    __bis_SR_register(gie);                                 //Restore original GIE state
}

void FFS::SPI_SET_DIVIDER(const uint8_t _clkdivider)
{
    SPI.setClockDivider(_clkdivider);
}

void FFS::SPI_HIGH_SPEED(void)
{
    SPI.setClockDivider(_clkdivider);
}

void FFS::SPI_INIT(void)
{
    pinMode(P1_7, INPUT_PULLUP);
    SPI.begin(0); // TGJ edit
    SPI.setClockDivider(128);
}

/*-----------------------------------------------------------------------*/
/* Delay function for diskio driver   */
/*-----------------------------------------------------------------------*/

void FFS::DLY10U(void)
{
    delayMicroseconds(10);
}

/*-----------------------------------------------------------------------*/
/* Setup FS Structures and Register CS Pin  */
/*-----------------------------------------------------------------------*/
FRESULT FFS::begin(
        unsigned char cs_pin /* Pin to connect to CS */
        )
{
    FRESULT res;
    res = begin(cs_pin, _clkdivider); // begin with def spi divider
    return res;
}

FRESULT FFS::begin(
        unsigned char cs_pin, /* Pin to connect to CS */
        uint8_t clkdivider // parameter for spi clock divider
        )
{
    _clkdivider = clkdivider;
    FRESULT res;

    CS = cs_pin;
    pinMode(CS, OUTPUT);
    
    
    
    attach_pins(CS_LOW, CS_HIGH);
    attach_SPIdriver(SPI_RECEIVE, SPI_SEND, SPI_INIT, SPI_HIGH_SPEED);
        
    disk_init();
        
    res = mount(0, &fatfs_obj);

#if _USE_DIR
    res = f_opendir(&dir_obj, (const CHAR *) "/");
#endif
    return res;
}


/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */

/*-----------------------------------------------------------------------*/

DSTATUS FFS::disk_init(
        void //unsigned char drv	/* Physical drive number (0) */
        )
{
    return disk_initialize(0);
}


/*-------------------------------------------------------------------------

   FatFs Module Public Functions (In ff.c and ff.h)

---------------------------------------------------------------------------
   Overloaded methods use working copy of FATFS, DIR or FIL
-------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
/* Mount/Unmount a Locical Drive                                         */

/*-----------------------------------------------------------------------*/

FRESULT FFS::mount(
        unsigned char vol, /* Logical drive number to be mounted/unmounted */
        FATFS *fs /* Pointer to new file system object (NULL for unmount) */
        )
{
    return f_mount(fs,"0:",1);
}


/*-----------------------------------------------------------------------*/
/* Open or Create a File                                                 */

/*-----------------------------------------------------------------------*/

FRESULT FFS::open(
        FIL *fp, /* Pointer to the blank file object */
        const TCHAR *path, /* Pointer to the file name */
        unsigned char mode /* Access mode and file open mode flags */
        )
{
    return f_open(fp, path, mode);
}

FRESULT FFS::open(
        const TCHAR *path, /* Pointer to the file name */
        unsigned char mode /* Access mode and file open mode flags */
        )
{
    return f_open(&fil_obj, path, mode);
}


/*-----------------------------------------------------------------------*/
/* Read File                                                             */
/*-----------------------------------------------------------------------*/
FRESULT FFS::read(
        FIL *fp, /* Pointer to the file object */
        void *buff, /* Pointer to data buffer */
        UINT btr, /* Number of bytes to read */
        UINT *br /* Pointer to number of bytes read */
        )
{
    return f_read(fp, buff, btr, br);
}

FRESULT FFS::read(
        void *buff, /* Pointer to data buffer */
        UINT btr, /* Number of bytes to read */
        UINT *br /* Pointer to number of bytes read */
        )
{
    return f_read(&fil_obj, buff, btr, br);
}


/*-----------------------------------------------------------------------*/
/* Write File                                                            */
/*-----------------------------------------------------------------------*/
#if !_FS_READONLY
FRESULT FFS::write(
        FIL *fp, /* Pointer to the file object */
        const void *buff, /* Pointer to the data to be written */
        UINT btw, /* Number of bytes to write */
        UINT *bw /* Pointer to number of bytes written */
        )
{
    return f_write(fp, buff, btw, bw);
}

FRESULT FFS::write(
        const void *buff, /* Pointer to the data to be written */
        UINT btw, /* Number of bytes to write */
        UINT *bw /* Pointer to number of bytes written */
        )
{
    return f_write(&fil_obj, buff, btw, bw);
}
size_t FFS::write(uint8_t character){
	UINT bw;
	f_write(&fil_obj, &character, 1, &bw);   //ok
	return (bw == 1) ? 1 : -1;
}
size_t FFS::write(FIL *fp, uint8_t character){
	UINT bw;
	f_write(fp, &character, 1, &bw);
	return (bw == 1) ? 1 : -1;
}
#endif /* !_FS_READONLY */


/*-----------------------------------------------------------------------*/
/* Close File                                                            */
/*-----------------------------------------------------------------------*/
FRESULT FFS::close(
        FIL *fp /* Pointer to the file object to be closed */
        )
{
    return f_close(fp);
}

FRESULT FFS::close(
        void /* Working copy file object will be closed */
        )
{
    return f_close(&fil_obj);
}


#if _FS_RPATH
/*-----------------------------------------------------------------------*/
/* Change Current Drive/Directory                                        */
/*-----------------------------------------------------------------------*/
FRESULT FFS::chdrive(
        unsigned char drv /* Drive number */
        )
{
    return f_chdrive(drv);
}

FRESULT FFS::chdir(
        const TCHAR *path /* Pointer to the directory path */
        )
{
    return f_chdir(path);
}
#endif /* _FS_RPATH */


#if _FS_MINIMIZE <= 2
/*-----------------------------------------------------------------------*/
/* Seek File R/W Pointer                                                 */
/*-----------------------------------------------------------------------*/
FRESULT FFS::lseek(
        FIL *fp, /* Pointer to the file object */
        DWORD ofs /* File pointer from top of file */
        )
{
    return f_lseek(fp, ofs);
}

FRESULT FFS::lseek(
        DWORD ofs /* File pointer from top of file */
        )
{
    return f_lseek(&fil_obj, ofs);
}

FRESULT FFS::endseek(
         void /* Moves file pointer to end of currently open file */
         )
{
     return f_lseek(&fil_obj, f_size(&fil_obj));
}
FRESULT FFS::endseek(
        FIL *fp /* Pointer to the file object */
        )
{
     return f_lseek(fp, f_size(fp));
}

#if _FS_MINIMIZE <= 1
/*-----------------------------------------------------------------------*/
/* Create a Directory Object                                             */
/*-----------------------------------------------------------------------*/
FRESULT FFS::opendir(
        DIR *dj, /* Pointer to directory object to create */
        const TCHAR *path /* Pointer to the directory path */
        )
{
    return f_opendir(dj, path);
}

FRESULT FFS::opendir(
        const TCHAR *path /* Pointer to the directory path */
        )
{
    return f_opendir(&dir_obj, path);
}

FRESULT FFS::opendir(
        void /* Working copies of directory object & path */
        )
{
    return f_opendir(&dir_obj, (const TCHAR *) "/");
}


/*-----------------------------------------------------------------------*/
/* Read Directory Entry in Sequence                                      */
/*-----------------------------------------------------------------------*/
FRESULT FFS::readdir(
        DIR *dj, /* Pointer to the open directory object */
        FILINFO *fno /* Pointer to file information to return */
        )
{
    return f_readdir(dj, fno);
}

FRESULT FFS::readdir(
        FILINFO *fno /* Pointer to file information to return */
        )
{
    return f_readdir(&dir_obj, fno);
}

FRESULT FFS::readdir(
        void /* Working copies of directory object & file */
        )
{
    return f_readdir(&dir_obj, NULL);
}


#if _FS_MINIMIZE == 0
/*-----------------------------------------------------------------------*/
/* Get File Status                                                       */
/*-----------------------------------------------------------------------*/
FRESULT FFS::stat(
        const TCHAR *path, /* Pointer to the file path */
        FILINFO *fno /* Pointer to file information to return */
        )
{
    return f_stat(path, fno);
}


#if !_FS_READONLY
/*-----------------------------------------------------------------------*/
/* Get Number of Free Clusters                                           */
/*-----------------------------------------------------------------------*/
FRESULT FFS::getfree(
        const TCHAR *path, /* Pointer to the logical drive number (root dir) */
        DWORD *nclst, /* Pointer to the variable to return number of free clusters */
        FATFS **fatfs /* Pointer to pointer to corresponding file system object to return */
        )
{
    return f_getfree(path, nclst, fatfs);
}


/*-----------------------------------------------------------------------*/
/* Truncate File                                                         */
/*-----------------------------------------------------------------------*/
FRESULT FFS::truncate(
        FIL *fp /* Pointer to the file object */
        )
{
    return f_truncate(fp);
}

FRESULT FFS::truncate(
        void /* Working copy file object */
        )
{
    return f_truncate(&fil_obj);
}


#if !_FS_READONLY
/*-----------------------------------------------------------------------*/
/* Synchronize the File Object                                           */
/*-----------------------------------------------------------------------*/
FRESULT FFS::sync(
        FIL *fp /* Pointer to the file object */
        )
{
    return f_sync(fp);
}

FRESULT FFS::sync(
        void /* Working copy file object */
        )
{
    return f_sync(&fil_obj);
}
#endif /* !_FS_READONLY */


/*-----------------------------------------------------------------------*/
/* Delete a File or Directory                                            */
/*-----------------------------------------------------------------------*/
FRESULT FFS::unlink(
        const TCHAR *path /* Pointer to the file or directory path */
        )
{
    return f_unlink(path);
}


/*-----------------------------------------------------------------------*/
/* Create a Directory                                                    */
/*-----------------------------------------------------------------------*/
FRESULT FFS::mkdir(
        const TCHAR *path /* Pointer to the directory path */
        )
{
    return f_mkdir(path);
}


/*-----------------------------------------------------------------------*/
/* Change File Attribute                                                 */
/*-----------------------------------------------------------------------*/
FRESULT FFS::chmod(
        const TCHAR *path, /* Pointer to the file path */
        unsigned char value, /* Attribute bits */
        unsigned char mask /* Attribute mask to change */
        )
{
    return f_chmod(path, value, mask);
}


/*-----------------------------------------------------------------------*/
/* Change Timestamp                                                      */
/*-----------------------------------------------------------------------*/
FRESULT FFS::utime(
        const TCHAR *path, /* Pointer to the file/directory name */
        const FILINFO *fno /* Pointer to the timestamp to be set */
        )
{
    return f_utime(path, fno);
}


/*-----------------------------------------------------------------------*/
/* Rename File/Directory                                                 */
/*-----------------------------------------------------------------------*/
FRESULT FFS::rename(
        const TCHAR *path_old, /* Pointer to the old name */
        const TCHAR *path_new /* Pointer to the new name */
        )
{
    return f_rename(path_old, path_new);
}
#endif /* !_FS_READONLY */
#endif /* _FS_MINIMIZE == 0 */
#endif /* _FS_MINIMIZE <= 1 */
#endif /* _FS_MINIMIZE <= 2 */


#if _USE_FORWARD && _FS_TINY
/*-----------------------------------------------------------------------*/
/* Forward data to the stream directly (Available on only _FS_TINY cfg)  */
/*-----------------------------------------------------------------------*/
FRESULT FFS::forward(
        FIL *fp, /* Pointer to the file object */
        UINT(*func)(const unsigned char*, UINT) out_stream, /* Pointer to the streaming function */
        UINT btr, /* Number of bytes to forward */
        UINT *bf /* Pointer to number of bytes forwarded */
        )
{
    return f_forward(fp, out_stream, btr, bf);
}
#endif /* _USE_FORWARD */


#if _USE_MKFS && !_FS_READONLY
/*-----------------------------------------------------------------------*/
/* Create File System on the Drive                                       */
/*-----------------------------------------------------------------------*/
FRESULT FFS::mkfs(
        unsigned char drv, /* Logical drive number */
        unsigned char partition, /* Partitioning rule 0:FDISK, 1:SFD */
        WORD allocsize /* Allocation unit size [bytes] */
        )
{
    return f_mkfs(drv, partition, allocsize);
}
#endif /* _USE_MKFS && !_FS_READONLY */


#if _USE_STRFUNC
/*-----------------------------------------------------------------------*/
/* Get a string from the file                                            */
/*-----------------------------------------------------------------------*/
char* FFS::gets(
        char* buff, /* Pointer to the string buffer to read */
        int len, /* Size of string buffer */
        FIL* fil /* Pointer to the file object */
        )
{
    return f_gets(buff, len, fil);
}

char* FFS::gets(
        char* buff, /* Pointer to the string buffer to read */
        int len /* Size of string buffer */
        )
{
    return f_gets(buff, len, &fil_obj);
}


#if !_FS_READONLY
#include <stdarg.h>
/*-----------------------------------------------------------------------*/
/* Put a character to the file                                           */
/*-----------------------------------------------------------------------*/
/* Since putc is also a macro, use fputc to avoid any parameter conflict */
int FFS::fputc(
        int chr, /* A character to be output */
        FIL* fil /* Ponter to the file object */
        )
{
    return f_putc(chr, fil);
}

int FFS::fputc(
        int chr /* A character to be output */
        )
{
    return f_putc(chr, &fil_obj);
}

/*-----------------------------------------------------------------------*/
/* Put a string to the file                                              */
/*-----------------------------------------------------------------------*/
int FFS::puts(
        const char* str, /* Pointer to the string to be output */
        FIL* fil /* Pointer to the file object */
        )
{
    return f_puts(str, fil);
}

int FFS::puts(
        const char* str /* Pointer to the string to be output */
        )
{
    return f_puts(str, &fil_obj);
}


/*-----------------------------------------------------------------------*/
/* Put a formatted string to the file                                    */
/*-----------------------------------------------------------------------*/
int FFS::printf(
        FIL* fil, /* Pointer to the file object */
        const char* str, /* Pointer to the format string */
        ... /* Optional arguments... */
        )
{
    int res;

    va_list arp;
    va_start(arp, str);
    res = f_vprintf(fil, str, arp);
    va_end(arp);

    return res;
}

int FFS::printf(
        const char* str, /* Pointer to the format string */
        ... /* Optional arguments... */
        )
{
    int res;

    va_list arp;
    va_start(arp, str);
    res = f_vprintf(&fil_obj, str, arp);
    va_end(arp);

    return res;
}
#endif /* !_FS_READONLY */
#endif /* _USE_STRFUNC */


/*-----------------------------------------------------------------------*/
/* Instantiate FFS for use by MSP430                                    */
/*-----------------------------------------------------------------------*/
FFS Jaffl = FFS(); /* Create usable instance */