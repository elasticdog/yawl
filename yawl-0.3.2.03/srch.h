/* Include file for anagram.c, multi.c */
/* (parts of the 'yawl' package) */
/* author: Mendel Cooper <thegrendel@theriver.com> */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#define COMPARISON_ERROR 1
#define MAXTESTS 50
#define MAX_WLEN 24
#define MAX_SPAN 25
#define NUL '\0'

const char Wordfile[] = "/usr/share/dict/word.list";
/* Where the word file is. */
/* Used to be /usr/dict.   */
/* Change to suit.         */
/* Note: If location changed, then must likewise change Makefile. */


typedef enum { FAIL, SUCCESS } Rflag;

/*********************PROTOTYPES************************************/
Rflag l_search( char *search_word, FILE *fp );
Rflag b_search( char *search_word, FILE *fp, long left, long right );
Rflag lookup( char *test_word );
void chop ( char *string );
/*******************************************************************/
