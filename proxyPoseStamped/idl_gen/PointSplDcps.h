#ifndef POINTSPLTYPES_H
#define POINTSPLTYPES_H

#include "ccpp_Point.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Point__load (c_base base);
extern const char * __Point__keys (void);
extern const char * __Point__name (void);
struct _Point ;
extern  c_bool __Point__copyIn(c_base base, struct Point *from, struct _Point *to);
extern  void __Point__copyOut(void *_from, void *_to);
struct _Point {
    c_double x;
    c_double y;
    c_double z;
};

#endif
