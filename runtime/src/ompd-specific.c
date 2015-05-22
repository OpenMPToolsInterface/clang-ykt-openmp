#include "ompd-specific.h"

/**
 * Declaration of symbols to hold struct size and member offset information
 */

#define ompd_declare_access(t,m) uint64_t ompd_access__##t##__##m; 
OMPD_FOREACH_ACCESS(ompd_declare_access)
#undef ompd_declare_access

#define ompd_declare_bitfield(t,m) uint64_t ompd_bitfield__##t##__##m; 
OMPD_FOREACH_BITFIELD(ompd_declare_bitfield)
#undef ompd_declare_bitfield

#define ompd_declare_sizeof(t) uint64_t ompd_sizeof__##t; 
OMPD_FOREACH_SIZEOF(ompd_declare_sizeof)
#undef ompd_declare_sizeof

void ompd_init()
{
  
/**
 * Calculate member offsets for structs and unions
 */

#define ompd_init_access(t,m) ompd_access__##t##__##m = (uint64_t)&(((t*)0)->m); 
OMPD_FOREACH_ACCESS(ompd_init_access)
#undef ompd_init_access

/**
 * Create bit mask for bitfield access
 */

#define ompd_init_bitfield(t,m) ompd_bitfield__##t##__##m=0; ((t*)(&ompd_bitfield__##t##__##m))->m = 1; 
OMPD_FOREACH_BITFIELD(ompd_init_bitfield)
#undef ompd_init_bitfield

/**
 * Calculate type size information
 */

#define ompd_init_sizeof(t) ompd_sizeof__##t = sizeof(t); 
OMPD_FOREACH_SIZEOF(ompd_init_sizeof)
#undef ompd_init_sizeof

}
