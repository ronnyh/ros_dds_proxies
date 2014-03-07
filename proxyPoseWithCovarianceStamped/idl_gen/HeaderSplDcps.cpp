#include "HeaderSplDcps.h"
#include "ccpp_Header.h"

const char *
__Header__name(void)
{
    return (const char*)"Header";
}

const char *
__Header__keys(void)
{
    return (const char*)"";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__Header__copyIn(
    c_base base,
    struct Header *from,
    struct _Header *to)
{
    c_bool result = TRUE;

    to->seq = (c_ulong)from->seq;
    if(result){
        extern c_bool __Time__copyIn(c_base, Time *, _Time *);
        result = __Time__copyIn(base, &from->stamp, &to->stamp);
    }
#ifdef OSPL_BOUNDS_CHECK
    if(from->frame_id){
        to->frame_id = c_stringNew(base, from->frame_id);
    } else {
        result = FALSE;
    }
#else
    to->frame_id = c_stringNew(base, from->frame_id);
#endif
    return result;
}

void
__Header__copyOut(
    void *_from,
    void *_to)
{
    struct _Header *from = (struct _Header *)_from;
    struct Header *to = (struct Header *)_to;
    to->seq = (::DDS::ULong)from->seq;
    {
        extern void __Time__copyOut(void *, void *);
        __Time__copyOut((void *)&from->stamp, (void *)&to->stamp);
    }
    to->frame_id = CORBA::string_dup(from->frame_id);
}

