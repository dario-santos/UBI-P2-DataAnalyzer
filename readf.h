// Name: Read File
// Reads from the file

#ifndef _READF_H_
#define _READF_H_

#include <stdio.h>

/*
 * Function: readf_int
 * -------------------
 *   Reads an integer from a file
 * 
 *   f: The file
 *
 *   returns: an integer
 */
int readf_int(FILE *f);

/*
 * Function: readf_char
 * --------------------
 *   Reads a char from a file
 * 
 *   f: The file
 *
 *   returns: a char
 */
char readf_char(FILE *f);

/*
 * Function: readf_string
 * ----------------------
 *   Reads a string from a file
 * 
 *   f: The file
 *   length: Length of the string   
 *
 *   returns: a string
 */
char *readf_string(FILE *f, int length);

#endif // _READF_H_