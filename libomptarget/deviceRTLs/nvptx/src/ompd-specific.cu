#include "ompd-specific.h"
#ifdef OMPD_SUPPORT

/**
 * Declaration of symbols to hold struct size and member offset information
 */

__device__ __shared__ static int ompd_initialized;

#define ompd_declare_access(t,m1,m2,m3) __device__ __shared__ uint64_t ompd_access__##t##__##m1##__##m2##__##m3; 
OMPD_FOREACH_ACCESS3(ompd_declare_access)
#undef ompd_declare_access

#define ompd_declare_access(t,m) __device__ __shared__ uint64_t ompd_access__##t##__##m; 
OMPD_FOREACH_ACCESS(ompd_declare_access)
#undef ompd_declare_access

#define ompd_declare_sizeof_member(t,m) __device__ __shared__ uint64_t ompd_sizeof__##t##__##m; 
OMPD_FOREACH_ACCESS(ompd_declare_sizeof_member)
#undef ompd_declare_sizeof_member

#define ompd_declare_sizeof_member(t,m1,m2,m3) __device__ __shared__ uint64_t ompd_sizeof__##t##__##m1##__##m2##__##m3; 
OMPD_FOREACH_ACCESS3(ompd_declare_sizeof_member)
#undef ompd_declare_sizeof_member

#define ompd_declare_sizeof(t) __device__ __shared__ uint64_t ompd_sizeof__##t; 
OMPD_FOREACH_SIZEOF(ompd_declare_sizeof)
#undef ompd_declare_sizeof

__device__ void ompd_init ( void )
{
if (ompd_initialized)
  return;
  
/**
 * Calculate member offsets for structs and unions
 */
#define ompd_init_access(t,m) ompd_access__##t##__##m = (uint64_t)&(((t*)0)->m); 
OMPD_FOREACH_ACCESS(ompd_init_access)
#undef ompd_init_access

#define ompd_init_access(t,m1,m2,m3) ompd_access__##t##__##m1##__##m2##__##m3 = (uint64_t)&(((t*)0)->m1.m2.m3); 
OMPD_FOREACH_ACCESS3(ompd_init_access)
#undef ompd_init_access

/**
 * Calculate type size information
 */
#define ompd_init_sizeof_member(t,m) ompd_sizeof__##t##__##m = sizeof(((t*)0)->m); 
OMPD_FOREACH_ACCESS(ompd_init_sizeof_member)
#undef ompd_init_sizeof

#define ompd_init_sizeof(t,m1,m2,m3) ompd_sizeof__##t##__##m1##__##m2##__##m3 = sizeof(((t*)0)->m1.m2.m3); 
OMPD_FOREACH_ACCESS3(ompd_init_sizeof)
#undef ompd_init_sizeof

#define ompd_init_sizeof(t) ompd_sizeof__##t = sizeof(t); 
OMPD_FOREACH_SIZEOF(ompd_init_sizeof)
#undef ompd_init_sizeof

  ompd_initialized = 1;
}

__device__ void ompd_bp_parallel_begin (){ asm (""); }
__device__ void ompd_bp_parallel_end (){ asm (""); }
__device__ void ompd_bp_task_begin (){ asm (""); }
__device__ void ompd_bp_task_end (){ asm (""); }
#endif /* OMPD_SUPPORT */
