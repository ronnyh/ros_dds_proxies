#include "proxyPoseStampedSplDcps.h"
#include "ccpp_proxyPoseStamped.h"

const char *
__proxyPoseStamped__name(void)
{
    return (const char*)"proxyPoseStamped";
}

const char *
__proxyPoseStamped__keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__proxyPoseStamped__copyIn(
    c_base base,
    struct proxyPoseStamped *from,
    struct _proxyPoseStamped *to)
{
    c_bool result = TRUE;

    if(result){
        extern c_bool __Header__copyIn(c_base, Header *, _Header *);
        result = __Header__copyIn(base, &from->header, &to->header);
    }
    if(result){
        extern c_bool __Pose__copyIn(c_base, Pose *, _Pose *);
        result = __Pose__copyIn(base, &from->pose, &to->pose);
    }
    return result;
}

void
__proxyPoseStamped__copyOut(
    void *_from,
    void *_to)
{
    struct _proxyPoseStamped *from = (struct _proxyPoseStamped *)_from;
    struct proxyPoseStamped *to = (struct proxyPoseStamped *)_to;
    {
        extern void __Header__copyOut(void *, void *);
        __Header__copyOut((void *)&from->header, (void *)&to->header);
    }
    {
        extern void __Pose__copyOut(void *, void *);
        __Pose__copyOut((void *)&from->pose, (void *)&to->pose);
    }
}

