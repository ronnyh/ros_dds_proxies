//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: Header.h
//  Source: Header.idl
//  Generated: Mon Jun 11 14:26:46 2012
//  OpenSplice V5.4.1OSS
//  
//******************************************************************
#ifndef _HEADER_H_
#define _HEADER_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "Time.h"
struct Time;
struct Header;


struct Header
{
   DDS::ULong seq;
   Time stamp;
   DDS::String_mgr frame_id;
};

typedef DDS_DCPSStruct_var < Header> Header_var;
typedef DDS_DCPSStruct_out < Header> Header_out;




#endif 
