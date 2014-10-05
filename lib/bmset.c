#include <stdlib.h>
#include <assert.h>
#include "bmap.h"

void BMap_set( BMAP* bm, unsigned int idx )
{
   unsigned int byte = 0,
                bit = 0;
   unsigned char mask = 0;

   assert( bm != NULL );
   assert( bm->bits != NULL );

   byte = idx / ( 8 * sizeof( char ) );
   assert( byte < bm->sizeBytes );

   bit = idx % ( 8 * sizeof( char ) );
   assert( bit <= 7 );
   mask = ( 1 << bit );

   bm->bits[ byte ] |= mask;
}
