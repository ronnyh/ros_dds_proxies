#include "PointSplDcps.h"
#include "ccpp_Point.h"

const char *
__Point__name(void)
{
    return (const char*)"Point";
}

const char *
__Point__keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__Point__copyIn(
    c_base base,
    struct Point *from,
    struct _Point *to)
{
    c_bool result = TRUE;

    to->x = (c_double)from->x;
    to->y = (c_double)from->y;
    to->z = (c_double)from->z;
    return result;
}

void
__Point__copyOut(
    void *_from,
    void *_to)
{
    struct _Point *from = (struct _Point *)_from;
    struct Point *to = (struct Point *)_to;
    to->x = (::DDS::Double)from->x;
    to->y = (::DDS::Double)from->y;
    to->z = (::DDS::Double)from->z;
}

