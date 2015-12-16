#include "ompd-specific.h"

#ifdef OMPD_SUPPORT

/**
 * Declaration of symbols to hold struct size and member offset information
 */

#define ompd_declare_access(t,m) const uint64_t ompd_access__##t##__##m = (uint64_t)&(((t*)0)->m); 
OMPD_FOREACH_ACCESS(ompd_declare_access)
#undef ompd_declare_access

#define ompd_declare_bitfield(t,m) uint64_t ompd_bitfield__##t##__##m; 
OMPD_FOREACH_BITFIELD(ompd_declare_bitfield)
#undef ompd_declare_bitfield

#define ompd_declare_sizeof(t) const uint64_t ompd_sizeof__##t = sizeof(t); 
OMPD_FOREACH_SIZEOF(ompd_declare_sizeof)
#undef ompd_declare_sizeof

const char * * ompd_dll_locations=NULL;
const char * ompd_my_dll_locations[2] = {"libompd_intel.so",NULL};
uint64_t ompd_state=0;

extern void __ompt_init_internal(void);

int ompd_rtl_version = 4;

void ompd_init()
{
  
static int ompd_initialized = 0;

if (ompd_initialized)
  return;
  
/**
 * Create bit mask for bitfield access
 */

#define ompd_init_bitfield(t,m) ompd_bitfield__##t##__##m=0; ((t*)(&ompd_bitfield__##t##__##m))->m = 1; 
OMPD_FOREACH_BITFIELD(ompd_init_bitfield)
#undef ompd_init_bitfield

  ompd_dll_locations=ompd_my_dll_locations;
  ompd_dll_locations_valid ();

  const char *ompd_env_var = getenv("OMP_OMPD");
  if (ompd_env_var && !strcmp(ompd_env_var, "on"))
  {
    fprintf(stderr,
                "OMP_OMPD active\n");
    ompt_status = ompt_status_track_callback;
    ompd_state |= OMPD_ENABLE_BP;
    __ompt_init_internal();
  }
    
  ompd_initialized = 1;
}

void omp_ompd_enable ( void )
{
    fprintf(stderr,
                "OMP_OMPD active\n");
    ompt_status = ompt_status_track_callback;
    ompd_state |= OMPD_ENABLE_BP;
    __ompt_init_internal();
}

void ompd_dll_locations_valid ( void ){
  /* naive way of implementing hard to opt-out empty function 
     we might want to use a separate object file? */
  asm ("");
}

void ompd_bp_parallel_begin ( void ){
  /* naive way of implementing hard to opt-out empty function 
     we might want to use a separate object file? */
  asm ("");
}
void ompd_bp_parallel_end ( void ){
  /* naive way of implementing hard to opt-out empty function 
     we might want to use a separate object file? */
  asm ("");
}
void ompd_bp_task_begin ( void ){
  /* naive way of implementing hard to opt-out empty function 
     we might want to use a separate object file? */
  asm ("");
}
void ompd_bp_task_end ( void ){
  /* naive way of implementing hard to opt-out empty function 
     we might want to use a separate object file? */
  asm ("");
}


#endif /* OMPD_SUPPORT */
