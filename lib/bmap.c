#include <assert.h>
#include "bmap.h"

unsigned int BMAP_CEIL_SIZE( unsigned int bits )
{
   unsigned int tmp = bits + BMAP_DEFAULT_ALIGNMENT;

   assert( tmp != 0 );

   return( BMAP_DEFAULT_ALIGNMENT *
           ( tmp / BMAP_DEFAULT_ALIGNMENT ) );
}

/*
 * Contstructor for BMAP_Class Object
 */
BMAP_Class BMap =
{
   BMap_New,
   BMap_free,
   BMap_set,
   BMap_clear,
   BMap_check
};
