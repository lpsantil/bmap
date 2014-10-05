#ifndef __BMAP__
#define __BMAP__

#ifndef __bool_true_false_are_defined
   #ifdef _Bool
      #define bool _Bool
   #else
      #define bool char
   #endif
   #define true 1
   #define false 0
   #define __bool_true_false_are_defined 1
#endif

#define BMAP_DEFAULT_ALIGNMENT 64

typedef struct
{
   unsigned int sizeBits;
   unsigned int sizeBytes;
   unsigned char* bits;
} BMAP;

typedef struct
{
   BMAP* ( *New )( unsigned int bits );
   void ( *free )( BMAP* bm );
   void ( *set )( BMAP* bm, unsigned int idx );
   void ( *clear )( BMAP* bm, unsigned int idx );
   bool ( *check )( BMAP* bm, unsigned int idx );
} BMAP_Class;

extern unsigned int BMAP_CEIL_SIZE( unsigned int bits );

extern BMAP* BMap_New( unsigned int bits );
extern void BMap_free( BMAP* bm );
extern void BMap_set( BMAP* bm, unsigned int idx );
extern void BMap_clear( BMAP* bm, unsigned int idx );
extern bool BMap_check( BMAP* bm, unsigned int idx );

extern BMAP_Class BMap;

#endif
