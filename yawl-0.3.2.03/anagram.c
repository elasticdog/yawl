/**************************************************************************/
/*                                 Anagram Utility                        */
/*                                                                        */
/*                                     M Cooper                           */
/*                                    PO Box 237                          */
/*                            St. David, AZ 85630-0237                    */
/*                        -------------------------------                 */
/*                        Email:  thegrendel@theriver.com                 */
/*                Web: http://personal.riverusers.com/~thegrendel         */ 
/*                                                                        */
/*                             License: Public Domain                     */
/*                                                                        */
/*                                                                        */
/**************************************************************************/


#include "srch.h"


#define FILE_OPENING_ERROR 3
#define FILENAME_MAXLEN 8
#define CR "\n"
#define FILE_SUFFIX ".ana"
#define MAXLEN 40
#define LINE_LEN 80
#define NOARGS 1
#define INCREMENT 1
#define BINGOLEN 8
#define SPACE ' '
#define XOUT '@'
#define WILDCARD '_'
#define FILLCHAR '_'
#define WD 12
/* #define ASTERISK "*"  */

#define BUFFERSIZE 8192

   char ad[] =
"ANAGRAM utility by M Cooper, PO Box 237, St. David, AZ 85630-0237";

typedef enum { FALSE, TRUE } Boolean;

void getword( char *lset, char *filename );
void center( char *strng );
Boolean isanagram( char *letterset, char *word );


int main( int argc, char **argv )
{

   char letterset[ MAXLEN ],
        filename[ MAXLEN ];


	 if( argc == NOARGS )
	    {
	    puts("Enter a LETTERSET to test ... ");
	    fgets( letterset, MAXLEN, stdin );
	    chop( letterset );
	    }
	 else
	    strcpy( letterset, *( argv + 1 ) );


         if( argc == NOARGS + 2 )
            strcpy( filename, *( argv + 2 ) );
         else
            strcpy( filename, Wordfile );

	 getword( letterset, filename );

	 return (0);
}


/**********************************ISANAGRAM*******************************/
/*       Function tests if word is constructible from Letterset           */
/*                 Args in: char *letterset, char *word                   */
/*   Returns: error_flag == TRUE (1) if constructible, FALSE (0) if not   */
/**************************************************************************/

Boolean isanagram( char *letterset, char *word )
{
	Boolean error_flag = TRUE;
	static char dup_lset[ MAXLEN ];
	register char *letpos;

	 strcpy( dup_lset, letterset );
         strcat( dup_lset, "\n" );

		while( *word )
			{
			if( ( letpos  = strchr( dup_lset, *word++ ) ) != NULL )
				*letpos = XOUT;
      else
         if( ( letpos = strchr( dup_lset, WILDCARD ) ) != NULL ) 
            *letpos = XOUT;

			else
				{ error_flag = FALSE; break; }
			}

		return( error_flag );
}

/*************************************************************/
void getword( char *letter_set, char *fname )
{

	char	l_set [ MAXLEN ],
/*              asterisk [ MAXLEN ],   */
		word [ MAXLEN ];

	FILE *fptr;
	long wcount = 0L;



	   strcpy ( l_set, letter_set );

	   /*********************************************************/

	   if( !( fptr = fopen( fname, "rt" ) ) )
		 {
		 printf( "\7\7\7Cannot open Wordfile!" );
		 exit( FILE_OPENING_ERROR );
		 }
      if( setvbuf( fptr, NULL, _IOFBF, BUFFERSIZE * 2 ) )
         exit ( FILE_OPENING_ERROR );  /*Extra buffering.*/





		 /****************Main Loop*********************/	 
		  while( fgets( word, MAXLEN, fptr ) != NULL )

			if( isanagram( letter_set, word ) )
			   {
/*
                           if( strlen( word ) >= BINGOLEN )
                               {
                               strcpy( asterisk, ASTERISK );
                               strcat( asterisk, word );
                               strcpy( word, asterisk );
                               } 
*/
			   printf( "%s", word );
			   wcount++;
			   }
		 /****************End Main Loop*********************/	 





/***************************for MSDOG**********************

      if( wcount == INCREMENT )
          strcpy( msg, "word" );
      else
          strcpy( msg, "words" );

		  printf( "%ld %s can be anagrammed from %s.\n",
				 wcount, msg, l_set );
*************************************************************/


}



void center( char *str )
{
   int padding;
   char st [ LINE_LEN + INCREMENT ];

	 padding = LINE_LEN / 2 - strlen( str ) / 2;
	 memset( st, SPACE, padding );
	 *( st + padding ) = 0;
	 strcat( st, str );
	 strcpy( str, st );

	 return;
}

/*  Removes trailing CR from passed string. */
void chop( char *string )
{
   register int length;

      length = strlen( string );
      length--; /* Adjust for zero-base indexing. */
      
      *( string + length ) = NUL;

      return;
}      

