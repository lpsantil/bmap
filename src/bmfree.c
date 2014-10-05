#include <stdlib.h>
#include <assert.h>
#include "bmap.h"

void BMap_free( BMAP* bm )
{
   assert( bm != NULL );

   assert( bm->bits != NULL );

   free( bm->bits );

   bm->bits = NULL;

   free( bm );
}
