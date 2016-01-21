/**************************************************************************/
/*                           Multi-word Anagram Utility                   */
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
#define BASEFILENAME "anagram_.bf"
#define TMPFILENAME "anagram_.000"
#define TMPFILENAME2 "anagram_.001"
#define MAXLEN 40
#define LINE_LEN 80
#define NOARGS 1
#define INCREMENT 1
#define WDS 2
#define BINGOLEN 8
#define SPACE ' '
#define XOUT '@'
#define WILDCARD '_'
#define FILLCHAR '_'
#define ASTERISK "*"
#define WD 12
#define CMDLINEERR 6

#define BUFFERSIZE 8192

   char ad[] =
"ANAGRAM utility by M Cooper, PO Box 237, St. David, AZ 85630-0237";

typedef enum { FALSE, TRUE } Boolean;

void getword( char *lset, char *filename );
void center( char *strng );
Boolean isanagram( char *letterset, char *word );
void mtest( char *filename, char *lettset, int Number_of_words );
void cleanup();

int main( int argc, char **argv )
{

   char letterset[ MAXLEN ],
        filename[ MAXLEN ],
        wordqty[ BINGOLEN ];
   int wordno;


	 if( argc == NOARGS )
	    {
	    puts("Enter a LETTERSET to test ... ");
	    fgets( letterset, MAXLEN, stdin );
            chop( letterset );
            printf( "\n\nHow many words in each anagram? ");
            fgets( wordqty, WDS, stdin );
	    }
	 else
	    strcpy( letterset, *( argv + 1 ) );

         if( argc == NOARGS + 1 )
            {
            printf( "\n\nHow many words in each anagram? ");
            fgets( wordqty, WDS, stdin );
            }


            if( argc > NOARGS + 1 )         
               strcpy( wordqty, *( argv + 2 ) );


         if( argc >= NOARGS + 2 )
            if( ( ( !islower( **( argv + 1 ) ) ) && **( argv + 1 ) != '_' )
              || ( !isdigit( **( argv + 2 ) ) ) )
                 {           
                 printf( "\nform: multi letterset number_of_words\n" );
                 exit( CMDLINEERR ); 
                 }


         if( argc == NOARGS + 3 )
            strcpy( filename, *( argv + 3 ) );
         else
            strcpy( filename, Wordfile );

         if( strlen( wordqty ) > 1 )
             {
             printf( "\nToo many words to anagram. It would take forever!\n" );
             exit( CMDLINEERR ); 
             }

          if( *( wordqty ) == '0' || *( wordqty ) == '1' )             
            {
            printf( "\nMust anagram more than 1 word.\n" );
            exit( CMDLINEERR ); 
            }




         wordno = atoi( wordqty );






	 getword( letterset, filename );

         mtest( TMPFILENAME, letterset, wordno );

         cleanup();

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

                        if( *word == SPACE )
                           word++;
 

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
		word [ MAXLEN ];

	FILE *fptr,
             *tfile,
	     *t2file;
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



	   if( !( tfile = fopen( BASEFILENAME, "wt" ) ) )
		 {
		 printf( "\7\7\7Cannot open intermediate file" );
		 exit( FILE_OPENING_ERROR );
		 }
      if( setvbuf( tfile, NULL, _IOFBF, BUFFERSIZE ) )
         exit ( FILE_OPENING_ERROR );  /*Extra buffering.*/

	   if( !( t2file = fopen( TMPFILENAME, "wt" ) ) )
		 {
		 printf( "\7\7\7Cannot open intermediate file" );
		 exit( FILE_OPENING_ERROR );
		 }
      if( setvbuf( t2file, NULL, _IOFBF, BUFFERSIZE ) )
         exit ( FILE_OPENING_ERROR );  /*Extra buffering.*/




		 /*********************Main Loop*************/	 
		  while( fgets( word, MAXLEN, fptr ) != NULL )

			if( isanagram( letter_set, word ) )
			   {
			   fprintf( tfile, "%s", word );
			   fprintf( t2file, "%s", word );
			   wcount++;
			   }
		  /*******************************************/





      fclose( fptr );
      fclose( tfile );
      fclose( t2file );

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


void mtest( char *fname, char *letterset, int wordcount )
{
   FILE *baselist,
        *alist,
        *blist;
   int tlen,
       combowlen,
       lsetlen,
       ndex,
       space_count = 0;
   char baseword [MAXLEN],
        nextword [MAXLEN],
        comboword [LINE_LEN];

      lsetlen = strlen( letterset );



    for( ndex = 1; ndex < wordcount; ndex++ )
      {
      baselist = fopen( BASEFILENAME, "r" );
      alist = fopen( TMPFILENAME, "r" );
      blist = fopen( TMPFILENAME2, "w" );

      ++space_count; 
      while( fgets( baseword, MAXLEN, baselist ) != NULL )
           {
           tlen = strlen( baseword );
           *( baseword + (tlen - 1) ) = SPACE; 

           while( fgets( nextword, MAXLEN, alist ) != NULL )
               {
               strcpy( comboword, baseword ); 
               strcat( comboword, nextword );
               combowlen = strlen( comboword );
               if( space_count + 1 == wordcount &&
                   combowlen - space_count - 1 == lsetlen &&
                   isanagram( letterset, comboword ) )
                   printf( "%s", comboword );
               else
                  if( combowlen - space_count - 1 < lsetlen &&
                      isanagram( letterset, comboword ) )
                          fprintf( blist, "%s", comboword );
               }
           rewind( alist );
           }
           rewind( baselist );

      fclose( baselist );
      fclose( alist );
      fclose( blist );

      unlink( TMPFILENAME );
      rename( TMPFILENAME2, TMPFILENAME );
      }

}

/*****************************************************************/

void cleanup()
{
      unlink( BASEFILENAME );
      unlink( TMPFILENAME );

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

