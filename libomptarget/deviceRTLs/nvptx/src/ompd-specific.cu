#include "ompd-specific.h"
#ifdef OMPD_SUPPORT

/**
 * Declaration of symbols to hold struct size and member offset information
 */

__device__ __shared__ static int ompd_target_initialized;
__device__ __shared__ uint64_t ompd_target_access__omptarget_nvptx_TaskDesc__data_items_threadId;
__device__ __shared__ uint64_t ompd_target_sizeof__omptarget_nvptx_TaskDesc__data_items_threadId;

#define ompd_target_declare_access(t,m) __device__ __shared__ uint64_t ompd_target_access__##t##__##m; 
OMPD_FOREACH_ACCESS(ompd_target_declare_access)
#undef ompd_target_declare_access

#define ompd_target_declare_sizeof_member(t,m) __device__ __shared__ uint64_t ompd_target_sizeof__##t##__##m; 
OMPD_FOREACH_ACCESS(ompd_target_declare_sizeof_member)
#undef ompd_target_declare_sizeof_member

#define ompd_target_declare_sizeof(t) __device__ __shared__ uint64_t ompd_target_sizeof__##t; 
OMPD_FOREACH_SIZEOF(ompd_target_declare_sizeof)
#undef ompd_target_declare_sizeof

__device__ void ompd_init ( void )
{
if (ompd_target_initialized)
  return;
  
/**
 * Calculate member offsets for structs and unions
 */
ompd_target_access__omptarget_nvptx_TaskDesc__data_items_threadId = 
          (uint64_t)&(((omptarget_nvptx_TaskDescr*)0)->data.items.threadId);

#define ompd_target_init_access(t,m) ompd_target_access__##t##__##m = (uint64_t)&(((t*)0)->m); 
OMPD_FOREACH_ACCESS(ompd_target_init_access)
#undef ompd_target_init_access

/**
 * Calculate type size information
 */
ompd_target_sizeof__omptarget_nvptx_TaskDesc__data_items_threadId = 
          (uint64_t)sizeof(((omptarget_nvptx_TaskDescr*)0)->data.items.threadId);

#define ompd_target_init_sizeof_member(t,m) ompd_target_sizeof__##t##__##m = sizeof(((t*)0)->m); 
OMPD_FOREACH_ACCESS(ompd_target_init_sizeof_member)
#undef ompd_target_init_sizeof_member

#define ompd_target_init_sizeof(t) ompd_target_sizeof__##t = sizeof(t); 
OMPD_FOREACH_SIZEOF(ompd_target_init_sizeof)
#undef ompd_target_init_sizeof

  ompd_target_initialized = 1;
}

__device__ void ompd_bp_parallel_begin (){ asm (""); }
__device__ void ompd_bp_parallel_end (){ asm (""); }
__device__ void ompd_bp_task_begin (){ asm (""); }
__device__ void ompd_bp_task_end (){ asm (""); }
#endif /* OMPD_SUPPORT */
