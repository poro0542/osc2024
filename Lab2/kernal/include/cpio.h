#ifndef CPIO_H
#define CPIO_H


extern char* cpio_addr;

// New ASCII format:
// The  pathname  is  followed  by NUL bytes so that the total size	of the
// fixed header plus pathname is a multiple	of four.  Likewise,  the  file
// data is padded to a multiple of four bytes.

// Each file has a 110 byte header, a variable length, NUL terminated file name, and variable length file data.

// A header for a file name "TRAILER!!!" indicates the end of the archive. All the fields in the header are ISO 646 (approximately ASCII) strings of hexadecimal numbers, left padded, not NUL terminated.
struct cpio_newc_header {
    char    c_magic[6];         // The string "070701". This value can be used to determine whether this archive is written with little-endian or big-endian integers.
    char    c_ino[8];           // The  device inode numbers from the disk. These are used by programs	that read cpio archives	to determine when two  entries refer to	the same file.
    char    c_mode[8];          // The mode	specifies both the regular permissions and the filetype
    char    c_uid[8];
    char    c_gid[8];
    char    c_nlink[8];         // The number of links to this file. Directories always have a value of	at least two here. 
    char    c_mtime[8];         // Modification time of the	file, indicated	as the number of  seconds  since  the	 start	of  the	epoch, 00:00:00	UTC January 1,1970.
    char    c_filesize[8];      // The size	of the file.  Note that	this archive format is limited to  16 megabyte file sizes. Must be 0 for FIFOs and directories
    char    c_devmajor[8];      // The  device and inode numbers from the disk.  These are used by programs	that read cpio archives	to determine when two  entries refer to	the same file.
    char    c_devminor[8];      // Represents the major device number of the file being archived. Applies to all files, not just device files.
    char    c_rdevmajor[8];     // Used specifically for device files (character or block special files).
    char    c_rdevminor[8];     // Only valid for chr and blk special files
    char    c_namesize[8];      // The number of bytes in the pathname that	follows the  header.
    char    c_check[8];         // This field is always set	to zero	 by  writers  and  ignored  by readers.
};

void cpio_ls();
void cpio_cat(char* filename);
#endif