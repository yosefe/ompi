/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 */

#ifndef OPAL_SYS_ARCH_TIMER_H
#define OPAL_SYS_ARCH_TIMER_H 1


typedef uint64_t opal_timer_t;


#if OPAL_GCC_INLINE_ASSEMBLY

#if 0
static inline opal_timer_t
opal_sys_timer_get_cycles(void)
{
    opal_timer_t ret;

    __asm__ __volatile__("rdtsc" : "=A"(ret));

    return ret;
}

#else

static inline opal_timer_t 
opal_sys_timer_get_cycles(void)
{
     unsigned a, d; 
     __asm__ __volatile__ ("rdtsc" : "=a" (a), "=d" (d));
     return ((opal_timer_t)a) | (((opal_timer_t)d) << 32);
}

#endif

#define OPAL_HAVE_SYS_TIMER_GET_CYCLES 1

#else

opal_timer_t opal_sys_timer_get_cycles(void);

#define OPAL_HAVE_SYS_TIMER_GET_CYCLES 1

#endif /* OPAL_GCC_INLINE_ASSEMBLY */

#endif /* ! OPAL_SYS_ARCH_TIMER_H */
