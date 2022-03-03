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
 */

#ifndef FFS_h
#define FFS_h

#include "Energia.h"
#include "Print.h"

extern "C" {
#include "utility/ff.h"
#include "utility/diskio.h"
#include "utility/integer.h"
#include "utility/ffconf.h"
}

#if (!_FS_READONLY)
class FFS : public Print
#else

class FFS
#endif
{
private:
    static FATFS fatfs_obj;
    static DIR dir_obj;
    static FIL fil_obj;
    static FILINFO fno;

    static unsigned char CS;

    static void CS_LOW(void);
    static void CS_HIGH(void);
    static int CS_READ(void);
    static void DLY10U(void);
    static void SPI_RECEIVE(uint8_t *pBuffer, uint16_t size);
    static void SPI_SEND(uint8_t *pBuffer, uint16_t size);
    static void SPI_SET_DIVIDER(const uint8_t);
    static void SPI_HIGH_SPEED(void);
    static void SPI_INIT(void);

public:
    FFS();

    /*--------------------------------------------------------------*/
    /* Functions for Local Disk Control                             */
    /*--------------------------------------------------------------*/
    FRESULT begin(unsigned char);
    FRESULT begin(unsigned char, uint8_t);
    DSTATUS disk_init(void);

    /*--------------------------------------------------------------*/
    /* Functions in the FatFs Module Application Interface          */
    /*--------------------------------------------------------------*/
    /* Overloaded methods use working copy of FATFS, DIR or FIL     */
    FRESULT mount(unsigned char, FATFS*);            // Mount/Unmount a logical drive
    FRESULT open(FIL*, const TCHAR*, unsigned char); // Open or create a file
    FRESULT open(const TCHAR*, unsigned char);
    FRESULT read(FIL*, void*, UINT, UINT*);          // Read data from a file
    FRESULT read(void*, UINT, UINT*);
    FRESULT write(FIL*, const void*, UINT, UINT*);   // Write data to a file
    FRESULT write(const void*, UINT, UINT*);
    FRESULT lseek(FIL*, DWORD); /* Move file pointer of a file object */
    FRESULT lseek(DWORD);
    FRESULT close(FIL*); /* Close an open file object */
    FRESULT close(void);
    FRESULT opendir(DIR*, const TCHAR*); /* Open an existing directory */
    FRESULT opendir(const TCHAR*);
    FRESULT opendir(void);
    FRESULT readdir(DIR*, FILINFO*); /* Read a directory item */
    FRESULT readdir(FILINFO*);
    FRESULT readdir(void);
    FRESULT stat(const TCHAR*, FILINFO*); /* Get file status */
    FRESULT getfree(const TCHAR*, DWORD*, FATFS**); /* Get number of free clusters on the drive */
    FRESULT truncate(FIL*); /* Truncate file */
    FRESULT truncate(void);
    FRESULT sync(FIL*); /* Flush cached data of a writing file */
    FRESULT sync(void);
    FRESULT unlink(const TCHAR*); /* Delete an existing file or directory */
    FRESULT mkdir(const TCHAR*); /* Create a new directory */
    FRESULT chmod(const TCHAR*, unsigned char, unsigned char); /* Change attriburte of the file/dir */
    FRESULT utime(const TCHAR*, const FILINFO*); /* Change timestamp of the file/dir */
    FRESULT rename(const TCHAR*, const TCHAR*); /* Rename/Move a file or directory */
    FRESULT forward(FIL*, UINT(*)(const unsigned char*, UINT), UINT, UINT*); /* Forward data to the stream */
    FRESULT mkfs(unsigned char, unsigned char, WORD); /* Create a file system on the drive */
    FRESULT chdir(const TCHAR*); /* Change current directory */
    FRESULT chdrive(unsigned char); /* Change current drive */

#if (!_FS_READONLY)
    virtual size_t write(uint8_t);
    virtual size_t write(FIL*, uint8_t);
    using Print::write;
#endif

#if _USE_STRFUNC
    int fputc(int, FIL*); /* Put a character to the file */
    int fputc(int);
    int puts(const char*, FIL*); /* Put a string to the file */
    int puts(const char*);
    int printf(FIL*, const char*, ...); /* Put a formatted string to the file */
    int printf(const char*, ...);
    char* gets(char*, int, FIL*); /* Get a string from the file */
    char* gets(char*, int);
//#define f_eof(fp) (((fp)->fptr == (fp)->fsize) ? 1 : 0)
//#define f_error(fp) (((fp)->flag & FA__ERROR) ? 1 : 0)
#ifndef EOF
#define EOF -1
#endif /* EOF */
#endif /* _USE_STRFUNC */
};

// The FatFs instance
extern FFS Jaffl;
#endif