#ifndef POINTDCPS_IMPL_H_
#define POINTDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_Point.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


class  PointTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
{
public:
    PointTypeSupportFactory() {}
    virtual ~PointTypeSupportFactory() {}
private:
    ::DDS::DataWriter_ptr
    create_datawriter (gapi_dataWriter handle);

    ::DDS::DataReader_ptr
    create_datareader (gapi_dataReader handle);

    ::DDS::DataReaderView_ptr
    create_view (gapi_dataReaderView handle);
};

class  PointTypeSupport : public virtual PointTypeSupportInterface,
                               public ::DDS::TypeSupport_impl
{
public:
    virtual ::DDS::ReturnCode_t register_type(
        ::DDS::DomainParticipant_ptr participant,
        const char * type_name) THROW_ORB_EXCEPTIONS;

    virtual char * get_type_name() THROW_ORB_EXCEPTIONS;

    PointTypeSupport (void);
    virtual ~PointTypeSupport (void);

private:
    PointTypeSupport (const PointTypeSupport &);
    void operator= (const PointTypeSupport &);

    static const char *metaDescriptor;
};

typedef PointTypeSupportInterface_var PointTypeSupport_var;
typedef PointTypeSupportInterface_ptr PointTypeSupport_ptr;

class  PointDataWriter_impl : public virtual PointDataWriter,
                                    public ::DDS::DataWriter_impl
{
public:

    virtual ::DDS::InstanceHandle_t register_instance(
        const Point & instance_data) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
        const Point & instance_data,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write_w_timestamp(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
        const Point & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        Point & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const Point & instance_data) THROW_ORB_EXCEPTIONS;


    PointDataWriter_impl (
        gapi_dataWriter handle
    );

    virtual ~PointDataWriter_impl (void);

private:
    PointDataWriter_impl(const PointDataWriter_impl &);
    void operator= (const PointDataWriter &);
};

class  PointDataReader_impl : public virtual PointDataReader,
                                    public ::DDS::DataReader_impl
{
    friend class PointDataReaderView_impl;
public:
    virtual ::DDS::ReturnCode_t read(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        Point & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        Point & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        Point & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const Point & instance) THROW_ORB_EXCEPTIONS;

    PointDataReader_impl (
        gapi_dataReader handle
    );

    virtual ~PointDataReader_impl(void);

private:
    PointDataReader_impl(const PointDataReader &);
    void operator= (const PointDataReader &);

    static ::DDS::ReturnCode_t check_preconditions(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples
    );
};

class  PointDataReaderView_impl : public virtual PointDataReaderView,
                                    public ::DDS::DataReaderView_impl
{
public:
    virtual ::DDS::ReturnCode_t read(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample(
        Point & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample(
        Point & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        CORBA::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan(
        PointSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value(
        Point & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance(
        const Point & instance) THROW_ORB_EXCEPTIONS;

    PointDataReaderView_impl (
        gapi_dataReader handle
    );

    virtual ~PointDataReaderView_impl(void);

private:
    PointDataReaderView_impl(const PointDataReaderView &);
    void operator= (const PointDataReaderView &);
};

#endif
