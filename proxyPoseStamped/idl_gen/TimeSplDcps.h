#ifndef TIMESPLTYPES_H
#define TIMESPLTYPES_H

#include "ccpp_Time.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Time__load (c_base base);
extern const char * __Time__keys (void);
extern const char * __Time__name (void);
struct _Time ;
extern  c_bool __Time__copyIn(c_base base, struct Time *from, struct _Time *to);
extern  void __Time__copyOut(void *_from, void *_to);
struct _Time {
    c_long sec;
    c_long nsec;
};

#endif
