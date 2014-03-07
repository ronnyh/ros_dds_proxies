#ifndef POSEWITHCOVARIANCESPLTYPES_H
#define POSEWITHCOVARIANCESPLTYPES_H

#include "ccpp_PoseWithCovariance.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "PoseSplDcps.h"

extern c_metaObject __PoseWithCovariance__load (c_base base);
extern const char * __PoseWithCovariance__keys (void);
extern const char * __PoseWithCovariance__name (void);
struct _PoseWithCovariance ;
extern  c_bool __PoseWithCovariance__copyIn(c_base base, struct PoseWithCovariance *from, struct _PoseWithCovariance *to);
extern  void __PoseWithCovariance__copyOut(void *_from, void *_to);
struct _PoseWithCovariance {
    struct _Pose pose;
    c_sequence covariance;
};

#endif
