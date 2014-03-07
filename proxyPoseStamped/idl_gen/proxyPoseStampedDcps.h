//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: proxyPoseStampedDcps.h
//  Source: proxyPoseStampedDcps.idl
//  Generated: Wed Oct  2 09:48:32 2013
//  OpenSplice V6.2.0
//  
//******************************************************************
#ifndef _PROXYPOSESTAMPEDDCPS_H_
#define _PROXYPOSESTAMPEDDCPS_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "Quaternion.h"
#include "dds_dcps_builtintopics.h"
#include "Pose.h"
#include "dds_builtinTopics.h"
#include "proxyPoseStamped.h"
#include "Point.h"
#include "Time.h"
#include "dds_dcps_interfaces.h"
#include "Header.h"
struct Time;
struct Header;
struct Point;
struct Quaternion;
struct Pose;
struct proxyPoseStamped;

class proxyPoseStampedTypeSupportInterface;

typedef proxyPoseStampedTypeSupportInterface * proxyPoseStampedTypeSupportInterface_ptr;
typedef DDS_DCPSInterface_var < proxyPoseStampedTypeSupportInterface> proxyPoseStampedTypeSupportInterface_var;
typedef DDS_DCPSInterface_out < proxyPoseStampedTypeSupportInterface> proxyPoseStampedTypeSupportInterface_out;


class proxyPoseStampedDataWriter;

typedef proxyPoseStampedDataWriter * proxyPoseStampedDataWriter_ptr;
typedef DDS_DCPSInterface_var < proxyPoseStampedDataWriter> proxyPoseStampedDataWriter_var;
typedef DDS_DCPSInterface_out < proxyPoseStampedDataWriter> proxyPoseStampedDataWriter_out;


class proxyPoseStampedDataReader;

typedef proxyPoseStampedDataReader * proxyPoseStampedDataReader_ptr;
typedef DDS_DCPSInterface_var < proxyPoseStampedDataReader> proxyPoseStampedDataReader_var;
typedef DDS_DCPSInterface_out < proxyPoseStampedDataReader> proxyPoseStampedDataReader_out;


class proxyPoseStampedDataReaderView;

typedef proxyPoseStampedDataReaderView * proxyPoseStampedDataReaderView_ptr;
typedef DDS_DCPSInterface_var < proxyPoseStampedDataReaderView> proxyPoseStampedDataReaderView_var;
typedef DDS_DCPSInterface_out < proxyPoseStampedDataReaderView> proxyPoseStampedDataReaderView_out;


struct proxyPoseStampedSeq_uniq_ {};
typedef DDS_DCPSUVLSeq < proxyPoseStamped, struct proxyPoseStampedSeq_uniq_> proxyPoseStampedSeq;
typedef DDS_DCPSSequence_var < proxyPoseStampedSeq> proxyPoseStampedSeq_var;
typedef DDS_DCPSSequence_out < proxyPoseStampedSeq> proxyPoseStampedSeq_out;
class proxyPoseStampedTypeSupportInterface
:
   virtual public DDS::TypeSupport
{ 
public:
   typedef proxyPoseStampedTypeSupportInterface_ptr _ptr_type;
   typedef proxyPoseStampedTypeSupportInterface_var _var_type;

   static proxyPoseStampedTypeSupportInterface_ptr _duplicate (proxyPoseStampedTypeSupportInterface_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static proxyPoseStampedTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
   static proxyPoseStampedTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static proxyPoseStampedTypeSupportInterface_ptr _nil () { return 0; }
   static const char * _local_id;
   proxyPoseStampedTypeSupportInterface_ptr _this () { return this; }


protected:
   proxyPoseStampedTypeSupportInterface () {};
   ~proxyPoseStampedTypeSupportInterface () {};
private:
   proxyPoseStampedTypeSupportInterface (const proxyPoseStampedTypeSupportInterface &);
   proxyPoseStampedTypeSupportInterface & operator = (const proxyPoseStampedTypeSupportInterface &);
};

class proxyPoseStampedDataWriter
:
   virtual public DDS::DataWriter
{ 
public:
   typedef proxyPoseStampedDataWriter_ptr _ptr_type;
   typedef proxyPoseStampedDataWriter_var _var_type;

   static proxyPoseStampedDataWriter_ptr _duplicate (proxyPoseStampedDataWriter_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static proxyPoseStampedDataWriter_ptr _narrow (DDS::Object_ptr obj);
   static proxyPoseStampedDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static proxyPoseStampedDataWriter_ptr _nil () { return 0; }
   static const char * _local_id;
   proxyPoseStampedDataWriter_ptr _this () { return this; }

   virtual DDS::InstanceHandle_t register_instance (const proxyPoseStamped& instance_data) = 0;
   virtual DDS::InstanceHandle_t register_instance_w_timestamp (const proxyPoseStamped& instance_data, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t unregister_instance (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t unregister_instance_w_timestamp (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t write (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t write_w_timestamp (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t dispose (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t dispose_w_timestamp (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t writedispose (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t writedispose_w_timestamp (const proxyPoseStamped& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t get_key_value (proxyPoseStamped& key_holder, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::InstanceHandle_t lookup_instance (const proxyPoseStamped& instance_data) = 0;

protected:
   proxyPoseStampedDataWriter () {};
   ~proxyPoseStampedDataWriter () {};
private:
   proxyPoseStampedDataWriter (const proxyPoseStampedDataWriter &);
   proxyPoseStampedDataWriter & operator = (const proxyPoseStampedDataWriter &);
};

class proxyPoseStampedDataReader
:
   virtual public DDS::DataReader
{ 
public:
   typedef proxyPoseStampedDataReader_ptr _ptr_type;
   typedef proxyPoseStampedDataReader_var _var_type;

   static proxyPoseStampedDataReader_ptr _duplicate (proxyPoseStampedDataReader_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static proxyPoseStampedDataReader_ptr _narrow (DDS::Object_ptr obj);
   static proxyPoseStampedDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static proxyPoseStampedDataReader_ptr _nil () { return 0; }
   static const char * _local_id;
   proxyPoseStampedDataReader_ptr _this () { return this; }

   virtual DDS::ReturnCode_t read (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t read_next_sample (proxyPoseStamped& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t take_next_sample (proxyPoseStamped& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t read_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_next_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_next_instance_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t return_loan (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
   virtual DDS::ReturnCode_t get_key_value (proxyPoseStamped& key_holder, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::InstanceHandle_t lookup_instance (const proxyPoseStamped& instance) = 0;

protected:
   proxyPoseStampedDataReader () {};
   ~proxyPoseStampedDataReader () {};
private:
   proxyPoseStampedDataReader (const proxyPoseStampedDataReader &);
   proxyPoseStampedDataReader & operator = (const proxyPoseStampedDataReader &);
};

class proxyPoseStampedDataReaderView
:
   virtual public DDS::DataReaderView
{ 
public:
   typedef proxyPoseStampedDataReaderView_ptr _ptr_type;
   typedef proxyPoseStampedDataReaderView_var _var_type;

   static proxyPoseStampedDataReaderView_ptr _duplicate (proxyPoseStampedDataReaderView_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static proxyPoseStampedDataReaderView_ptr _narrow (DDS::Object_ptr obj);
   static proxyPoseStampedDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static proxyPoseStampedDataReaderView_ptr _nil () { return 0; }
   static const char * _local_id;
   proxyPoseStampedDataReaderView_ptr _this () { return this; }

   virtual DDS::ReturnCode_t read (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t read_next_sample (proxyPoseStamped& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t take_next_sample (proxyPoseStamped& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t read_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_next_instance (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_next_instance_w_condition (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t return_loan (proxyPoseStampedSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
   virtual DDS::ReturnCode_t get_key_value (proxyPoseStamped& key_holder, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::InstanceHandle_t lookup_instance (const proxyPoseStamped& instance) = 0;

protected:
   proxyPoseStampedDataReaderView () {};
   ~proxyPoseStampedDataReaderView () {};
private:
   proxyPoseStampedDataReaderView (const proxyPoseStampedDataReaderView &);
   proxyPoseStampedDataReaderView & operator = (const proxyPoseStampedDataReaderView &);
};

template <>
DDS::BuiltinTopicKey_t_slice* DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::copy (DDS::BuiltinTopicKey_t_slice *to, const DDS::BuiltinTopicKey_t_slice* from);
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::free (DDS::BuiltinTopicKey_t_slice *ptr);




#endif 