#ifndef DDSJOYSPLTYPES_H
#define DDSJOYSPLTYPES_H

#include "ccpp_ddsJoy.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

#include "HeaderSplDcps.h"

extern c_metaObject __ddsJoy__load (c_base base);
extern char * __ddsJoy__keys (void);
extern char * __ddsJoy__name (void);
struct _ddsJoy ;
extern  c_bool __ddsJoy__copyIn(c_base base, struct ddsJoy *from, struct _ddsJoy *to);
extern  void __ddsJoy__copyOut(void *_from, void *_to);
struct _ddsJoy {
    struct _Header header;
    c_sequence axes;
    c_sequence buttons;
};

#endif
