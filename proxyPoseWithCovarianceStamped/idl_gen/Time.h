//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: Time.h
//  Source: Time.idl
//  Generated: Thu Jul 26 17:33:32 2012
//  OpenSplice V5.5.1OSS
//  
//******************************************************************
#ifndef _TIME_H_
#define _TIME_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
struct Time;


struct Time
{
   DDS::Long sec;
   DDS::Long nsec;
};

typedef DDS_DCPSStruct_var < Time> Time_var;
typedef Time&Time_out;




#endif 