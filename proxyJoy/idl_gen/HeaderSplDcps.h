#ifndef HEADERSPLTYPES_H
#define HEADERSPLTYPES_H

#include "ccpp_Header.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "TimeSplDcps.h"

extern c_metaObject __Header__load (c_base base);
extern char * __Header__keys (void);
extern char * __Header__name (void);
struct _Header ;
extern  c_bool __Header__copyIn(c_base base, struct Header *from, struct _Header *to);
extern  void __Header__copyOut(void *_from, void *_to);
struct _Header {
    c_ulong seq;
    struct _Time stamp;
    c_string frame_id;
};

#endif
