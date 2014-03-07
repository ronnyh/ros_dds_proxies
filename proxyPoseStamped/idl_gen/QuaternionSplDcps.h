#ifndef QUATERNIONSPLTYPES_H
#define QUATERNIONSPLTYPES_H

#include "ccpp_Quaternion.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __Quaternion__load (c_base base);
extern const char * __Quaternion__keys (void);
extern const char * __Quaternion__name (void);
struct _Quaternion ;
extern  c_bool __Quaternion__copyIn(c_base base, struct Quaternion *from, struct _Quaternion *to);
extern  void __Quaternion__copyOut(void *_from, void *_to);
struct _Quaternion {
    c_double x;
    c_double y;
    c_double z;
    c_double w;
};

#endif
