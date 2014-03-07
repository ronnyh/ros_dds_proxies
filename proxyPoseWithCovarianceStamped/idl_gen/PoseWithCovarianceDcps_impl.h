#ifndef POSEWITHCOVARIANCEDCPS_IMPL_H_
#define POSEWITHCOVARIANCEDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_PoseWithCovariance.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


class  PoseWithCovarianceTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
{
public:
    PoseWithCovarianceTypeSupportFactory() {}
    virtual ~PoseWithCovarianceTypeSupportFactory() {}
private:
    ::DDS::DataWriter_ptr 
    create_datawriter (gapi_dataWriter handle);

    ::DDS::DataReader_ptr 
    create_datareader (gapi_dataReader handle);

    ::DDS::DataReaderView_ptr 
    create_view (gapi_dataReaderView handle);
};

class  PoseWithCovarianceTypeSupport : public virtual PoseWithCovarianceTypeSupportInterface,
                               public ::DDS::TypeSupport_impl
{
public:
    virtual ::DDS::ReturnCode_t register_type(
        ::DDS::DomainParticipant_ptr participant,
        const char * type_name) THROW_ORB_EXCEPTIONS;

    virtual char * get_type_name() THROW_ORB_EXCEPTIONS;    

    PoseWithCovarianceTypeSupport (void);
    virtual ~PoseWithCovarianceTypeSupport (void);

private:
    PoseWithCovarianceTypeSupport (const PoseWithCovarianceTypeSupport &);
    void operator= (const PoseWithCovarianceTypeSupport &);

    static const char *metaDescriptor;
};

typedef PoseWithCovarianceTypeSupportInterface_var PoseWithCovarianceTypeSupport_var;
typedef PoseWithCovarianceTypeSupportInterface_ptr PoseWithCovarianceTypeSupport_ptr;

class  PoseWithCovarianceDataWriter_impl : public virtual PoseWithCovarianceDataWriter,
                                    public ::DDS::DataWriter_impl
{
public:

    virtual ::DDS::InstanceHandle_t register_instance(
        const PoseWithCovariance & instance_data) THROW_ORB_EXCEPTIONS;
        
    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
        const PoseWithCovariance & instance_data,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
        
    virtual ::DDS::ReturnCode_t unregister_instance(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write_w_timestamp(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
        const PoseWithCovariance & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        PoseWithCovariance & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const PoseWithCovariance & instance_data) THROW_ORB_EXCEPTIONS;


    PoseWithCovarianceDataWriter_impl (
        gapi_dataWriter handle
    );

    virtual ~PoseWithCovarianceDataWriter_impl (void);

private:
    PoseWithCovarianceDataWriter_impl(const PoseWithCovarianceDataWriter_impl &);
    void operator= (const PoseWithCovarianceDataWriter &);
};

class  PoseWithCovarianceDataReader_impl : public virtual PoseWithCovarianceDataReader,
                                    public ::DDS::DataReader_impl
{
    friend class PoseWithCovarianceDataReaderView_impl;
public:
    virtual ::DDS::ReturnCode_t read(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        PoseWithCovariance & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        PoseWithCovariance & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_next_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t get_key_value(
        PoseWithCovariance & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::InstanceHandle_t lookup_instance(
        const PoseWithCovariance & instance) THROW_ORB_EXCEPTIONS;

    PoseWithCovarianceDataReader_impl (
        gapi_dataReader handle
    );

    virtual ~PoseWithCovarianceDataReader_impl(void);

private:
    PoseWithCovarianceDataReader_impl(const PoseWithCovarianceDataReader &);
    void operator= (const PoseWithCovarianceDataReader &);

    static ::DDS::ReturnCode_t check_preconditions(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples
    );
};

class  PoseWithCovarianceDataReaderView_impl : public virtual PoseWithCovarianceDataReaderView,
                                    public ::DDS::DataReaderView_impl
{
public:
    virtual ::DDS::ReturnCode_t read(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        PoseWithCovariance & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        PoseWithCovariance & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t take_next_instance(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        PoseWithCovarianceSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::ReturnCode_t get_key_value(
        PoseWithCovariance & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
    virtual ::DDS::InstanceHandle_t lookup_instance(
        const PoseWithCovariance & instance) THROW_ORB_EXCEPTIONS;

    PoseWithCovarianceDataReaderView_impl (
        gapi_dataReader handle
    );

    virtual ~PoseWithCovarianceDataReaderView_impl(void);

private:
    PoseWithCovarianceDataReaderView_impl(const PoseWithCovarianceDataReaderView &);
    void operator= (const PoseWithCovarianceDataReaderView &);
};

#endif
