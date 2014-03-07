#ifndef PROXYPOSEWITHCOVARIANCESTAMPEDSPLTYPES_H
#define PROXYPOSEWITHCOVARIANCESTAMPEDSPLTYPES_H

#include "ccpp_proxyPoseWithCovarianceStamped.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "HeaderSplDcps.h"
#include "PoseWithCovarianceSplDcps.h"

extern c_metaObject __proxyPoseWithCovarianceStamped__load (c_base base);
extern const char * __proxyPoseWithCovarianceStamped__keys (void);
extern const char * __proxyPoseWithCovarianceStamped__name (void);
struct _proxyPoseWithCovarianceStamped ;
extern  c_bool __proxyPoseWithCovarianceStamped__copyIn(c_base base, struct proxyPoseWithCovarianceStamped *from, struct _proxyPoseWithCovarianceStamped *to);
extern  void __proxyPoseWithCovarianceStamped__copyOut(void *_from, void *_to);
struct _proxyPoseWithCovarianceStamped {
    struct _Header header;
    struct _PoseWithCovariance pose;
};

#endif
