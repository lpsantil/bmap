#include <stdlib.h>
#include <assert.h>
#include "bmap.h"

bool BMap_check( BMAP* bm, unsigned int idx )
{
   unsigned int byte = 0,
                bit = 0;
   unsigned char mask = 0;

   assert( bm != NULL );
   assert( bm->bits != NULL );
   assert( idx < bm->sizeBits );

   byte = idx / ( 8 * sizeof( char ) );
   assert( byte < bm->sizeBytes );

   bit = idx % ( 8 * sizeof( char ) );
   assert( bit <= 7 );

   mask = ( 1 << bit );

   if( ( bm->bits[ byte ] & mask ) == 0 )
   {
      return( false );
   }

   return( true );
}
