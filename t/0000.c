#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bmap.h"

#define REQ 35

void printBMAP( BMAP* bm );

int main( int argc, char** argv )
{
   int i = 0;
   BMAP* bm = BMap.New( REQ );

   srand( time( NULL ) );

   printBMAP( bm );

   for( i = 0; i < REQ; i++ )
   {
      BMap.set( bm, rand() % REQ );
   }

   printBMAP( bm );

   for( i = 0; i < REQ; i++ )
   {
      BMap.clear( bm, rand() % REQ );
   }

   printBMAP( bm );

   for( i = 0; i < REQ; i++ )
   {
      BMap.clear( bm, i );
   }
   printBMAP( bm );

   BMap.free( bm );

   return( 0 );
}

void printBMAP( BMAP* bm )
{
   int i = 0;
   char* s = NULL;

   printf( "sizeBits(%u):sizeBytes(%u)\n",
           bm->sizeBits, bm->sizeBytes );

   printf( "#" );

   for( i = 0; i < bm->sizeBits; i++ )
   {
      s = ( i % 10 ) == 9 ? "9" : ".";
      s = ( i % 10 ) == 0 ? "0" : s;
      printf( "%s", s );
   }

   printf( "\n"
           "B" );

   for( i = 0; i < bm->sizeBits; i++ )
   {
      printf( "%s",
              ( BMap.check( bm, i ) == true ? "@" : "-" ) );
   }

   printf( "\n" );
}
