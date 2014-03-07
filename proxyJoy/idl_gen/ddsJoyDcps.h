//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: ddsJoyDcps.h
//  Source: ddsJoyDcps.idl
//  Generated: Mon Jun 11 14:26:39 2012
//  OpenSplice V5.4.1OSS
//  
//******************************************************************
#ifndef _DDSJOYDCPS_H_
#define _DDSJOYDCPS_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "dds_dcps_builtintopics.h"
#include "dds_builtinTopics.h"
#include "ddsJoy.h"
#include "Time.h"
#include "dds_dcps_interfaces.h"
#include "Header.h"
struct Time;
struct Header;
struct ddsJoy;

class ddsJoyTypeSupportInterface;

typedef ddsJoyTypeSupportInterface * ddsJoyTypeSupportInterface_ptr;
typedef DDS_DCPSInterface_var < ddsJoyTypeSupportInterface> ddsJoyTypeSupportInterface_var;
typedef DDS_DCPSInterface_out < ddsJoyTypeSupportInterface> ddsJoyTypeSupportInterface_out;


class ddsJoyDataWriter;

typedef ddsJoyDataWriter * ddsJoyDataWriter_ptr;
typedef DDS_DCPSInterface_var < ddsJoyDataWriter> ddsJoyDataWriter_var;
typedef DDS_DCPSInterface_out < ddsJoyDataWriter> ddsJoyDataWriter_out;


class ddsJoyDataReader;

typedef ddsJoyDataReader * ddsJoyDataReader_ptr;
typedef DDS_DCPSInterface_var < ddsJoyDataReader> ddsJoyDataReader_var;
typedef DDS_DCPSInterface_out < ddsJoyDataReader> ddsJoyDataReader_out;


class ddsJoyDataReaderView;

typedef ddsJoyDataReaderView * ddsJoyDataReaderView_ptr;
typedef DDS_DCPSInterface_var < ddsJoyDataReaderView> ddsJoyDataReaderView_var;
typedef DDS_DCPSInterface_out < ddsJoyDataReaderView> ddsJoyDataReaderView_out;


struct ddsJoySeq_uniq_ {};
typedef DDS_DCPSUVLSeq < ddsJoy, struct ddsJoySeq_uniq_> ddsJoySeq;
typedef DDS_DCPSSequence_var < ddsJoySeq> ddsJoySeq_var;
typedef DDS_DCPSSequence_out < ddsJoySeq> ddsJoySeq_out;
class ddsJoyTypeSupportInterface
:
   virtual public DDS::TypeSupport
{ 
public:
   typedef ddsJoyTypeSupportInterface_ptr _ptr_type;
   typedef ddsJoyTypeSupportInterface_var _var_type;

   static ddsJoyTypeSupportInterface_ptr _duplicate (ddsJoyTypeSupportInterface_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static ddsJoyTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
   static ddsJoyTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static ddsJoyTypeSupportInterface_ptr _nil () { return 0; }
   static const char * _local_id;
   ddsJoyTypeSupportInterface_ptr _this () { return this; }


protected:
   ddsJoyTypeSupportInterface () {};
   ~ddsJoyTypeSupportInterface () {};
private:
   ddsJoyTypeSupportInterface (const ddsJoyTypeSupportInterface &);
   ddsJoyTypeSupportInterface & operator = (const ddsJoyTypeSupportInterface &);
};

class ddsJoyDataWriter
:
   virtual public DDS::DataWriter
{ 
public:
   typedef ddsJoyDataWriter_ptr _ptr_type;
   typedef ddsJoyDataWriter_var _var_type;

   static ddsJoyDataWriter_ptr _duplicate (ddsJoyDataWriter_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static ddsJoyDataWriter_ptr _narrow (DDS::Object_ptr obj);
   static ddsJoyDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static ddsJoyDataWriter_ptr _nil () { return 0; }
   static const char * _local_id;
   ddsJoyDataWriter_ptr _this () { return this; }

   virtual DDS::InstanceHandle_t register_instance (const ddsJoy& instance_data) = 0;
   virtual DDS::InstanceHandle_t register_instance_w_timestamp (const ddsJoy& instance_data, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t unregister_instance (const ddsJoy& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t unregister_instance_w_timestamp (const ddsJoy& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t write (const ddsJoy& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t write_w_timestamp (const ddsJoy& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t dispose (const ddsJoy& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t dispose_w_timestamp (const ddsJoy& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t writedispose (const ddsJoy& instance_data, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::ReturnCode_t writedispose_w_timestamp (const ddsJoy& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
   virtual DDS::ReturnCode_t get_key_value (ddsJoy& key_holder, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::InstanceHandle_t lookup_instance (const ddsJoy& instance_data) = 0;

protected:
   ddsJoyDataWriter () {};
   ~ddsJoyDataWriter () {};
private:
   ddsJoyDataWriter (const ddsJoyDataWriter &);
   ddsJoyDataWriter & operator = (const ddsJoyDataWriter &);
};

class ddsJoyDataReader
:
   virtual public DDS::DataReader
{ 
public:
   typedef ddsJoyDataReader_ptr _ptr_type;
   typedef ddsJoyDataReader_var _var_type;

   static ddsJoyDataReader_ptr _duplicate (ddsJoyDataReader_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static ddsJoyDataReader_ptr _narrow (DDS::Object_ptr obj);
   static ddsJoyDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static ddsJoyDataReader_ptr _nil () { return 0; }
   static const char * _local_id;
   ddsJoyDataReader_ptr _this () { return this; }

   virtual DDS::ReturnCode_t read (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t read_next_sample (ddsJoy& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t take_next_sample (ddsJoy& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t read_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_next_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_next_instance_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t return_loan (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
   virtual DDS::ReturnCode_t get_key_value (ddsJoy& key_holder, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::InstanceHandle_t lookup_instance (const ddsJoy& instance) = 0;

protected:
   ddsJoyDataReader () {};
   ~ddsJoyDataReader () {};
private:
   ddsJoyDataReader (const ddsJoyDataReader &);
   ddsJoyDataReader & operator = (const ddsJoyDataReader &);
};

class ddsJoyDataReaderView
:
   virtual public DDS::DataReaderView
{ 
public:
   typedef ddsJoyDataReaderView_ptr _ptr_type;
   typedef ddsJoyDataReaderView_var _var_type;

   static ddsJoyDataReaderView_ptr _duplicate (ddsJoyDataReaderView_ptr obj);
   DDS::Boolean _local_is_a (const char * id);

   static ddsJoyDataReaderView_ptr _narrow (DDS::Object_ptr obj);
   static ddsJoyDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
   static ddsJoyDataReaderView_ptr _nil () { return 0; }
   static const char * _local_id;
   ddsJoyDataReaderView_ptr _this () { return this; }

   virtual DDS::ReturnCode_t read (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t read_next_sample (ddsJoy& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t take_next_sample (ddsJoy& received_data, DDS::SampleInfo& sample_info) = 0;
   virtual DDS::ReturnCode_t read_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t take_next_instance (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
   virtual DDS::ReturnCode_t read_next_instance_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t take_next_instance_w_condition (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
   virtual DDS::ReturnCode_t return_loan (ddsJoySeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
   virtual DDS::ReturnCode_t get_key_value (ddsJoy& key_holder, DDS::InstanceHandle_t handle) = 0;
   virtual DDS::InstanceHandle_t lookup_instance (const ddsJoy& instance) = 0;

protected:
   ddsJoyDataReaderView () {};
   ~ddsJoyDataReaderView () {};
private:
   ddsJoyDataReaderView (const ddsJoyDataReaderView &);
   ddsJoyDataReaderView & operator = (const ddsJoyDataReaderView &);
};

template <>
DDS::BuiltinTopicKey_t_slice* DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::copy (DDS::BuiltinTopicKey_t_slice *to, const DDS::BuiltinTopicKey_t_slice* from);
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::free (DDS::BuiltinTopicKey_t_slice *ptr);




#endif 