#include "kmp.h"
#include <stdint.h>

#ifndef __OMPD_SPECIFIC_H__
#define __OMPD_SPECIFIC_H__

#ifdef OMPD_SUPPORT

void ompd_init();
extern const char * * ompd_dll_locations;

#ifdef  __cplusplus
extern "C" {
#endif
void ompd_dll_locations_valid ( void );
void ompd_bp_parallel_begin ( void );
void ompd_bp_parallel_end ( void );
void ompd_bp_task_begin ( void );
void ompd_bp_task_end ( void );
#ifdef  __cplusplus
} /* extern "C" */
#endif

extern int ompd_state;
#define OMPD_ENABLE_BP 0x1

#define OMPD_FOREACH_ACCESS(OMPD_ACCESS) \
OMPD_ACCESS(kmp_base_info_t,      th_current_task) \
OMPD_ACCESS(kmp_base_info_t,      th_team) \
OMPD_ACCESS(kmp_base_info_t,      th_info) \
OMPD_ACCESS(kmp_base_info_t,      ompt_thread_info) \
\
OMPD_ACCESS(kmp_base_root_t,      r_in_parallel) \
\
OMPD_ACCESS(kmp_base_team_t,      ompt_team_info) \
OMPD_ACCESS(kmp_base_team_t,      t_active_level) \
OMPD_ACCESS(kmp_base_team_t,      t_implicit_task_taskdata) \
OMPD_ACCESS(kmp_base_team_t,      t_nproc) \
OMPD_ACCESS(kmp_base_team_t,      t_level) \
OMPD_ACCESS(kmp_base_team_t,      t_parent) \
OMPD_ACCESS(kmp_base_team_t,      t_pkfn) \
OMPD_ACCESS(kmp_base_team_t,      t_threads) \
\
OMPD_ACCESS(kmp_desc_t,           ds) \
\
OMPD_ACCESS(kmp_desc_base_t,      ds_thread) \
\
OMPD_ACCESS(kmp_info_t,           th) \
\
OMPD_ACCESS(kmp_r_sched_t,        r_sched_type) \
OMPD_ACCESS(kmp_r_sched_t,        chunk) \
\
OMPD_ACCESS(kmp_root_t,           r) \
\
OMPD_ACCESS(kmp_internal_control_t, dynamic) \
OMPD_ACCESS(kmp_internal_control_t, max_active_levels) \
OMPD_ACCESS(kmp_internal_control_t, proc_bind) \
OMPD_ACCESS(kmp_internal_control_t, sched) \
\
OMPD_ACCESS(kmp_taskdata_t,       ompt_task_info) \
OMPD_ACCESS(kmp_taskdata_t,       td_flags) \
OMPD_ACCESS(kmp_taskdata_t,       td_icvs) \
OMPD_ACCESS(kmp_taskdata_t,       td_parent) \
\
OMPD_ACCESS(kmp_team_p,           t) \
\
OMPD_ACCESS(ompt_task_info_t,     frame) \
OMPD_ACCESS(ompt_task_info_t,     task_id) \
\
OMPD_ACCESS(ompt_team_info_t,     parallel_id) \
\
OMPD_ACCESS(ompt_thread_info_t,   state) \
OMPD_ACCESS(ompt_thread_info_t,   wait_id) \
\
OMPD_ACCESS(ompt_frame_t,         reenter_runtime_frame) \
OMPD_ACCESS(ompt_frame_t,         exit_runtime_frame) \


#define OMPD_FOREACH_BITFIELD(OMPD_BITFIELD) \
OMPD_BITFIELD(kmp_tasking_flags_t,  final) \


#define OMPD_FOREACH_SIZEOF(OMPD_SIZEOF) \
OMPD_SIZEOF(kmp_info_t) \
OMPD_SIZEOF(kmp_taskdata_t) \
OMPD_SIZEOF(kmp_tasking_flags_t) \


#endif /* OMPD_SUPPORT */
#endif

