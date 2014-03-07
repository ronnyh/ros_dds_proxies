#include "PoseSplDcps.h"
#include "ccpp_Pose.h"

const char *
__Pose__name(void)
{
    return (const char*)"Pose";
}

const char *
__Pose__keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__Pose__copyIn(
    c_base base,
    struct Pose *from,
    struct _Pose *to)
{
    c_bool result = TRUE;

    if(result){
        extern c_bool __Point__copyIn(c_base, Point *, _Point *);
        result = __Point__copyIn(base, &from->position, &to->position);
    }
    if(result){
        extern c_bool __Quaternion__copyIn(c_base, Quaternion *, _Quaternion *);
        result = __Quaternion__copyIn(base, &from->orientation, &to->orientation);
    }
    return result;
}

void
__Pose__copyOut(
    void *_from,
    void *_to)
{
    struct _Pose *from = (struct _Pose *)_from;
    struct Pose *to = (struct Pose *)_to;
    {
        extern void __Point__copyOut(void *, void *);
        __Point__copyOut((void *)&from->position, (void *)&to->position);
    }
    {
        extern void __Quaternion__copyOut(void *, void *);
        __Quaternion__copyOut((void *)&from->orientation, (void *)&to->orientation);
    }
}

