#include "TimeSplDcps.h"
#include "ccpp_Time.h"

const char *
__Time__name(void)
{
    return (const char*)"Time";
}

const char *
__Time__keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__Time__copyIn(
    c_base base,
    struct Time *from,
    struct _Time *to)
{
    c_bool result = TRUE;

    to->sec = (c_long)from->sec;
    to->nsec = (c_long)from->nsec;
    return result;
}

void
__Time__copyOut(
    void *_from,
    void *_to)
{
    struct _Time *from = (struct _Time *)_from;
    struct Time *to = (struct Time *)_to;
    to->sec = (::DDS::Long)from->sec;
    to->nsec = (::DDS::Long)from->nsec;
}

