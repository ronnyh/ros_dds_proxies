#ifndef PROXYPOSESTAMPEDSPLTYPES_H
#define PROXYPOSESTAMPEDSPLTYPES_H

#include "ccpp_proxyPoseStamped.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "HeaderSplDcps.h"
#include "PoseSplDcps.h"

extern c_metaObject __proxyPoseStamped__load (c_base base);
extern const char * __proxyPoseStamped__keys (void);
extern const char * __proxyPoseStamped__name (void);
struct _proxyPoseStamped ;
extern  c_bool __proxyPoseStamped__copyIn(c_base base, struct proxyPoseStamped *from, struct _proxyPoseStamped *to);
extern  void __proxyPoseStamped__copyOut(void *_from, void *_to);
struct _proxyPoseStamped {
    struct _Header header;
    struct _Pose pose;
};

#endif
