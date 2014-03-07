#include "QuaternionSplDcps.h"
#include "ccpp_Quaternion.h"

const char *
__Quaternion__name(void)
{
    return (const char*)"Quaternion";
}

const char *
__Quaternion__keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__Quaternion__copyIn(
    c_base base,
    struct Quaternion *from,
    struct _Quaternion *to)
{
    c_bool result = TRUE;

    to->x = (c_double)from->x;
    to->y = (c_double)from->y;
    to->z = (c_double)from->z;
    to->w = (c_double)from->w;
    return result;
}

void
__Quaternion__copyOut(
    void *_from,
    void *_to)
{
    struct _Quaternion *from = (struct _Quaternion *)_from;
    struct Quaternion *to = (struct Quaternion *)_to;
    to->x = (::DDS::Double)from->x;
    to->y = (::DDS::Double)from->y;
    to->z = (::DDS::Double)from->z;
    to->w = (::DDS::Double)from->w;
}

