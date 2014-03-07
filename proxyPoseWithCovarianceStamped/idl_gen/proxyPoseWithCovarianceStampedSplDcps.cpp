#include "proxyPoseWithCovarianceStampedSplDcps.h"
#include "ccpp_proxyPoseWithCovarianceStamped.h"

const char *
__proxyPoseWithCovarianceStamped__name(void)
{
    return (const char*)"proxyPoseWithCovarianceStamped";
}

const char *
__proxyPoseWithCovarianceStamped__keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__proxyPoseWithCovarianceStamped__copyIn(
    c_base base,
    struct proxyPoseWithCovarianceStamped *from,
    struct _proxyPoseWithCovarianceStamped *to)
{
    c_bool result = TRUE;

    if(result){
        extern c_bool __Header__copyIn(c_base, Header *, _Header *);
        result = __Header__copyIn(base, &from->header, &to->header);
    }
    if(result){
        extern c_bool __PoseWithCovariance__copyIn(c_base, PoseWithCovariance *, _PoseWithCovariance *);
        result = __PoseWithCovariance__copyIn(base, &from->pose, &to->pose);
    }
    return result;
}

void
__proxyPoseWithCovarianceStamped__copyOut(
    void *_from,
    void *_to)
{
    struct _proxyPoseWithCovarianceStamped *from = (struct _proxyPoseWithCovarianceStamped *)_from;
    struct proxyPoseWithCovarianceStamped *to = (struct proxyPoseWithCovarianceStamped *)_to;
    {
        extern void __Header__copyOut(void *, void *);
        __Header__copyOut((void *)&from->header, (void *)&to->header);
    }
    {
        extern void __PoseWithCovariance__copyOut(void *, void *);
        __PoseWithCovariance__copyOut((void *)&from->pose, (void *)&to->pose);
    }
}

