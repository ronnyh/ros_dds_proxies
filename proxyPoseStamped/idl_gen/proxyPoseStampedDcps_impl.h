#ifndef PROXYPOSESTAMPEDDCPS_IMPL_H_
#define PROXYPOSESTAMPEDDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_proxyPoseStamped.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


class  proxyPoseStampedTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
{
public:
    proxyPoseStampedTypeSupportFactory() {}
    virtual ~proxyPoseStampedTypeSupportFactory() {}
private:
    ::DDS::DataWriter_ptr
    create_datawriter (gapi_dataWriter handle);

    ::DDS::DataReader_ptr
    create_datareader (gapi_dataReader handle);

    ::DDS::DataReaderView_ptr
    create_view (gapi_dataReaderView handle);
};

class  proxyPoseStampedTypeSupport : public virtual proxyPoseStampedTypeSupportInterface,
                               public ::DDS::TypeSupport_impl
{
public:
    virtual ::DDS::ReturnCode_t register_type(
        ::DDS::DomainParticipant_ptr participant,
        const char * type_name) THROW_ORB_EXCEPTIONS;

    virtual char * get_type_name() THROW_ORB_EXCEPTIONS;

    proxyPoseStampedTypeSupport (void);
    virtual ~proxyPoseStampedTypeSupport (void);

private:
    proxyPoseStampedTypeSupport (const proxyPoseStampedTypeSupport &);
    void operator= (const proxyPoseStampedTypeSupport &);

    static const char *metaDescriptor;
};

typedef proxyPoseStampedTypeSupportInterface_var proxyPoseStampedTypeSupport_var;
typedef proxyPoseStampedTypeSupportInterface_ptr proxyPoseStampedTypeSupport_ptr;

class  proxyPoseStampedDataWriter_impl : public virtual proxyPoseStampedDataWriter,
                                    public ::DDS::DataWriter_impl
{
public:

    virtual ::DDS::InstanceHandle_t register_instance(
        const proxyPoseStamped & instance_data) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
        const proxyPoseStamped & instance_data,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write_w_timestamp(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
        const proxyPoseStamped & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        proxyPoseStamped & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const proxyPoseStamped & instance_data) THROW_ORB_EXCEPTIONS;


    proxyPoseStampedDataWriter_impl (
        gapi_dataWriter handle
    );

    virtual ~proxyPoseStampedDataWriter_impl (void);

private:
    proxyPoseStampedDataWriter_impl(const proxyPoseStampedDataWriter_impl &);
    void operator= (const proxyPoseStampedDataWriter &);
};

class  proxyPoseStampedDataReader_impl : public virtual proxyPoseStampedDataReader,
                                    public ::DDS::DataReader_impl
{
    friend class proxyPoseStampedDataReaderView_impl;
public:
    virtual ::DDS::ReturnCode_t read(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        proxyPoseStamped & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        proxyPoseStamped & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        proxyPoseStamped & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const proxyPoseStamped & instance) THROW_ORB_EXCEPTIONS;

    proxyPoseStampedDataReader_impl (
        gapi_dataReader handle
    );

    virtual ~proxyPoseStampedDataReader_impl(void);

private:
    proxyPoseStampedDataReader_impl(const proxyPoseStampedDataReader &);
    void operator= (const proxyPoseStampedDataReader &);

    static ::DDS::ReturnCode_t check_preconditions(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples
    );
};

class  proxyPoseStampedDataReaderView_impl : public virtual proxyPoseStampedDataReaderView,
                                    public ::DDS::DataReaderView_impl
{
public:
    virtual ::DDS::ReturnCode_t read(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        proxyPoseStamped & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        proxyPoseStamped & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        proxyPoseStampedSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        proxyPoseStamped & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const proxyPoseStamped & instance) THROW_ORB_EXCEPTIONS;

    proxyPoseStampedDataReaderView_impl (
        gapi_dataReader handle
    );

    virtual ~proxyPoseStampedDataReaderView_impl(void);

private:
    proxyPoseStampedDataReaderView_impl(const proxyPoseStampedDataReaderView &);
    void operator= (const proxyPoseStampedDataReaderView &);
};

#endif
