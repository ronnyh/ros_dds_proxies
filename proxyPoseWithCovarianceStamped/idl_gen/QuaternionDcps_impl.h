#ifndef QUATERNIONDCPS_IMPL_H_
#define QUATERNIONDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_Quaternion.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


class  QuaternionTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
{
public:
    QuaternionTypeSupportFactory() {}
    virtual ~QuaternionTypeSupportFactory() {}
private:
    ::DDS::DataWriter_ptr 
    create_datawriter (gapi_dataWriter handle);

    ::DDS::DataReader_ptr 
    create_datareader (gapi_dataReader handle);

    ::DDS::DataReaderView_ptr 
    create_view (gapi_dataReaderView handle);
};

class  QuaternionTypeSupport : public virtual QuaternionTypeSupportInterface,
                               public ::DDS::TypeSupport_impl
{
public:
    virtual ::DDS::ReturnCode_t register_type(
        ::DDS::DomainParticipant_ptr participant,
        const char * type_name) THROW_ORB_EXCEPTIONS;

    virtual char * get_type_name() THROW_ORB_EXCEPTIONS;    

    QuaternionTypeSupport (void);
    virtual ~QuaternionTypeSupport (void);

private:
    QuaternionTypeSupport (const QuaternionTypeSupport &);
    void operator= (const QuaternionTypeSupport &);

    static const char *metaDescriptor;
};

typedef QuaternionTypeSupportInterface_var QuaternionTypeSupport_var;
typedef QuaternionTypeSupportInterface_ptr QuaternionTypeSupport_ptr;

class  QuaternionDataWriter_impl : public virtual QuaternionDataWriter,
                                    public ::DDS::DataWriter_impl
{
public:

    virtual ::DDS::InstanceHandle_t register_instance(
        const Quaternion & instance_data) THROW_ORB_EXCEPTIONS;
        
    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
        const Quaternion & instance_data,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
        
    virtual ::DDS::ReturnCode_t unregister_instance(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write_w_timestamp(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
        const Quaternion & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        Quaternion & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const Quaternion & instance_data) THROW_ORB_EXCEPTIONS;


    QuaternionDataWriter_impl (
        gapi_dataWriter handle
    );

    virtual ~QuaternionDataWriter_impl (void);

private:
    QuaternionDataWriter_impl(const QuaternionDataWriter_impl &);
    void operator= (const QuaternionDataWriter &);
};

class  QuaternionDataReader_impl : public virtual QuaternionDataReader,
                                    public ::DDS::DataReader_impl
{
    friend class QuaternionDataReaderView_impl;
public:
    virtual ::DDS::ReturnCode_t read(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        Quaternion & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        Quaternion & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_next_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t get_key_value(
        Quaternion & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::InstanceHandle_t lookup_instance(
        const Quaternion & instance) THROW_ORB_EXCEPTIONS;

    QuaternionDataReader_impl (
        gapi_dataReader handle
    );

    virtual ~QuaternionDataReader_impl(void);

private:
    QuaternionDataReader_impl(const QuaternionDataReader &);
    void operator= (const QuaternionDataReader &);

    static ::DDS::ReturnCode_t check_preconditions(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples
    );
};

class  QuaternionDataReaderView_impl : public virtual QuaternionDataReaderView,
                                    public ::DDS::DataReaderView_impl
{
public:
    virtual ::DDS::ReturnCode_t read(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        Quaternion & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        Quaternion & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_next_instance(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        QuaternionSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t get_key_value(
        Quaternion & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::InstanceHandle_t lookup_instance(
        const Quaternion & instance) THROW_ORB_EXCEPTIONS;

    QuaternionDataReaderView_impl (
        gapi_dataReader handle
    );

    virtual ~QuaternionDataReaderView_impl(void);

private:
    QuaternionDataReaderView_impl(const QuaternionDataReaderView &);
    void operator= (const QuaternionDataReaderView &);
};

#endif
