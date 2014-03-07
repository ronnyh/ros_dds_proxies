#ifndef POSESPLTYPES_H
#define POSESPLTYPES_H

#include "ccpp_Pose.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "PointSplDcps.h"
#include "QuaternionSplDcps.h"

extern c_metaObject __Pose__load (c_base base);
extern const char * __Pose__keys (void);
extern const char * __Pose__name (void);
struct _Pose ;
extern  c_bool __Pose__copyIn(c_base base, struct Pose *from, struct _Pose *to);
extern  void __Pose__copyOut(void *_from, void *_to);
struct _Pose {
    struct _Point position;
    struct _Quaternion orientation;
};

#endif
