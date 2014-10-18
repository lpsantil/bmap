#include <stdlib.h>
#include <assert.h>
#include "bmap.h"

BMAP* BMap_New( unsigned int bits )
{
   BMAP* ret = NULL;
   unsigned int adjBits = BMAP_CEIL_SIZE( bits ),
                bytes = 0;

   assert( adjBits != 0 );
   assert( ( adjBits % BMAP_DEFAULT_ALIGNMENT ) == 0 );

   bytes = BMAP_DEFAULT_ALIGNMENT * adjBits;

   ret = ( BMAP* )( calloc( 1, sizeof( BMAP ) ) );

   assert( ret != NULL );

   ret->sizeBits = adjBits;
   ret->sizeBytes = bytes;
   ret->bits = ( unsigned char* )( calloc( bytes, sizeof( unsigned char ) ) );

   assert( ret->bits != NULL );

   return( ret );
}
