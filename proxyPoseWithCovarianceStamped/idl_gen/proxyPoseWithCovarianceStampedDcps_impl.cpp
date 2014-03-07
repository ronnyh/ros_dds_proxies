#include "proxyPoseWithCovarianceStampedDcps_impl.h"
#include "gapi.h"
#include "gapi_loanRegistry.h"
#include "proxyPoseWithCovarianceStampedSplDcps.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


extern c_bool
__proxyPoseWithCovarianceStamped__copyIn(
    c_base base,
    struct proxyPoseWithCovarianceStamped *from,
    struct _proxyPoseWithCovarianceStamped *to);

extern void
__proxyPoseWithCovarianceStamped__copyOut(
    void *_from,
    void *_to);

// DDS proxyPoseWithCovarianceStamped TypeSupportFactory Object Body

 DDS::DataWriter_ptr 
proxyPoseWithCovarianceStampedTypeSupportFactory::create_datawriter (gapi_dataWriter handle)
{
    return new proxyPoseWithCovarianceStampedDataWriter_impl(handle);
}

 DDS::DataReader_ptr 
proxyPoseWithCovarianceStampedTypeSupportFactory::create_datareader (gapi_dataReader handle)
{
    return new proxyPoseWithCovarianceStampedDataReader_impl (handle);
}


 DDS::DataReaderView_ptr 
proxyPoseWithCovarianceStampedTypeSupportFactory::create_view (gapi_dataReaderView handle)
{
    return new proxyPoseWithCovarianceStampedDataReaderView_impl (handle);
}

// DDS proxyPoseWithCovarianceStamped TypeSupport Object Body

 proxyPoseWithCovarianceStampedTypeSupport::proxyPoseWithCovarianceStampedTypeSupport(void) :
    TypeSupport_impl(
        __proxyPoseWithCovarianceStamped__name(),
        __proxyPoseWithCovarianceStamped__keys(),
        proxyPoseWithCovarianceStampedTypeSupport::metaDescriptor,
        (gapi_copyIn) __proxyPoseWithCovarianceStamped__copyIn,
        (gapi_copyOut) __proxyPoseWithCovarianceStamped__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<proxyPoseWithCovarianceStampedSeq, proxyPoseWithCovarianceStamped>,
        new  proxyPoseWithCovarianceStampedTypeSupportFactory())
{
    // Parent constructor takes care of everything.
}

 proxyPoseWithCovarianceStampedTypeSupport::~proxyPoseWithCovarianceStampedTypeSupport(void)
{
    // Parent destructor takes care of everything.
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedTypeSupport::register_type(
    DDS::DomainParticipant_ptr domain,
    const char * type_name) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

 char *
proxyPoseWithCovarianceStampedTypeSupport::get_type_name() THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS proxyPoseWithCovarianceStamped DataWriter_impl Object Body

 proxyPoseWithCovarianceStampedDataWriter_impl::proxyPoseWithCovarianceStampedDataWriter_impl (
    gapi_dataWriter handle
) : DDS::DataWriter_impl(handle)
{
    // Parent constructor takes care of everything.
}

 proxyPoseWithCovarianceStampedDataWriter_impl::~proxyPoseWithCovarianceStampedDataWriter_impl(void)
{
    // Parent destructor takes care of everything.
}

 DDS::InstanceHandle_t
proxyPoseWithCovarianceStampedDataWriter_impl::register_instance(
    const proxyPoseWithCovarianceStamped & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
}

 DDS::InstanceHandle_t 
proxyPoseWithCovarianceStampedDataWriter_impl::register_instance_w_timestamp(
    const proxyPoseWithCovarianceStamped & instance_data,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataWriter_impl::unregister_instance(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);
}

 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataWriter_impl::unregister_instance_w_timestamp(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataWriter_impl::write(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataWriter_impl::write_w_timestamp(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataWriter_impl::dispose(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}

 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataWriter_impl::dispose_w_timestamp(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataWriter_impl::writedispose(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose(&instance_data, handle);
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataWriter_impl::writedispose_w_timestamp(
    const proxyPoseWithCovarianceStamped & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataWriter_impl::get_key_value(
    proxyPoseWithCovarianceStamped & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
proxyPoseWithCovarianceStampedDataWriter_impl::lookup_instance(
	const proxyPoseWithCovarianceStamped & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::lookup_instance(&instance_data);
}

// DDS proxyPoseWithCovarianceStamped DataReader_impl Object Body

 proxyPoseWithCovarianceStampedDataReader_impl::proxyPoseWithCovarianceStampedDataReader_impl (
    gapi_dataReader handle
) : DDS::DataReader_impl(handle)
{
    // Parent constructor takes care of everything.
}

 proxyPoseWithCovarianceStampedDataReader_impl::~proxyPoseWithCovarianceStampedDataReader_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::read(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::take(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::read_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::take_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReader_impl::read_next_sample(
    proxyPoseWithCovarianceStamped & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReader_impl::take_next_sample(
    proxyPoseWithCovarianceStamped & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::read_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::take_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::read_next_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::take_next_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReader_impl::read_next_instance_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReader_impl::take_next_instance_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReader_impl::return_loan(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 ) {
        if (received_data.length() == info_seq.length() && 
            received_data.release() == info_seq.release() ) {
            if (!received_data.release()) {
                status = DataReader_impl::return_loan( received_data.get_buffer(),
                                                       info_seq.get_buffer() );

                if ( status == DDS::RETCODE_OK ) {
                    if ( !received_data.release() ) {
                        proxyPoseWithCovarianceStampedSeq::freebuf( received_data.get_buffer(false) );
                        received_data.replace(0, 0, NULL, false);
                        DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                        info_seq.replace(0, 0, NULL, false);
                    }
                } else if ( status == DDS::RETCODE_NO_DATA ) {
                    if ( received_data.release() ) {
                        status = DDS::RETCODE_OK;
                    } else {
                        status = DDS::RETCODE_PRECONDITION_NOT_MET;
                    }
                }
            }
        } else {
            status = DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReader_impl::get_key_value(
    proxyPoseWithCovarianceStamped & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
proxyPoseWithCovarianceStampedDataReader_impl::lookup_instance(
    const proxyPoseWithCovarianceStamped & instance) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples)
{
    DDS::ReturnCode_t status = DDS::RETCODE_PRECONDITION_NOT_MET;
    
    if ( received_data.length() == info_seq.length() &&
         received_data.maximum() == info_seq.maximum() &&
         received_data.release() == info_seq.release() ) {
        if ( received_data.maximum() == 0 || received_data.release() ) {
            if (received_data.maximum() == 0 ||
				max_samples <= static_cast<CORBA::Long>(received_data.maximum()) ||
				max_samples == DDS::LENGTH_UNLIMITED ) {
                status = DDS::RETCODE_OK;
            }
        }
    }
    return status;
}


// DDS proxyPoseWithCovarianceStamped DataReaderView_impl Object Body

 proxyPoseWithCovarianceStampedDataReaderView_impl::proxyPoseWithCovarianceStampedDataReaderView_impl (
    gapi_dataReaderView handle
) : DDS::DataReaderView_impl(handle)
{
    // Parent constructor takes care of everything.
}

 proxyPoseWithCovarianceStampedDataReaderView_impl::~proxyPoseWithCovarianceStampedDataReaderView_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::read(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::take(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::read_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::take_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReaderView_impl::read_next_sample(
    proxyPoseWithCovarianceStamped & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReaderView_impl::take_next_sample(
    proxyPoseWithCovarianceStamped & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::read_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::take_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::read_next_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::take_next_instance(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReaderView_impl::read_next_instance_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReaderView_impl::take_next_instance_w_condition(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = proxyPoseWithCovarianceStampedDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
proxyPoseWithCovarianceStampedDataReaderView_impl::return_loan(
    proxyPoseWithCovarianceStampedSeq & received_data,
    DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 ) {
        if (received_data.length() == info_seq.length() && 
            received_data.release() == info_seq.release() ) {
            if (!received_data.release()) {
                status = DataReaderView_impl::return_loan( received_data.get_buffer(),
                                                       info_seq.get_buffer() );

                if ( status == DDS::RETCODE_OK ) {
                    if ( !received_data.release() ) {
                        proxyPoseWithCovarianceStampedSeq::freebuf( received_data.get_buffer(false) );
                        received_data.replace(0, 0, NULL, false);
                        DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                        info_seq.replace(0, 0, NULL, false);
                    }
                } else if ( status == DDS::RETCODE_NO_DATA ) {
                    if ( received_data.release() ) {
                        status = DDS::RETCODE_OK;
                    } else {
                        status = DDS::RETCODE_PRECONDITION_NOT_MET;
                    }
                }
            }
        } else {
            status = DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }
    return status;
}


 DDS::ReturnCode_t 
proxyPoseWithCovarianceStampedDataReaderView_impl::get_key_value(
    proxyPoseWithCovarianceStamped & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
proxyPoseWithCovarianceStampedDataReaderView_impl::lookup_instance(
    const proxyPoseWithCovarianceStamped & instance) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::lookup_instance(&instance);
}



const char * proxyPoseWithCovarianceStampedTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Struct name=\"Time\"><Member name=\"sec\"><Long/></Member><Member name=\"nsec\">"
"<Long/></Member></Struct><Struct name=\"Header\"><Member name=\"seq\"><ULong/></Member><Member name=\"stamp\">"
"<Type name=\"Time\"/></Member><Member name=\"frame_id\"><String/></Member></Struct><Struct name=\"Point\">"
"<Member name=\"x\"><Double/></Member><Member name=\"y\"><Double/></Member><Member name=\"z\"><Double/>"
"</Member></Struct><Struct name=\"Quaternion\"><Member name=\"x\"><Double/></Member><Member name=\"y\">"
"<Double/></Member><Member name=\"z\"><Double/></Member><Member name=\"w\"><Double/></Member></Struct>"
"<Struct name=\"Pose\"><Member name=\"position\"><Type name=\"Point\"/></Member><Member name=\"orientation\">"
"<Type name=\"Quaternion\"/></Member></Struct><Struct name=\"PoseWithCovariance\"><Member name=\"pose\">"
"<Type name=\"Pose\"/></Member><Member name=\"covariance\"><Sequence size=\"36\"><Double/></Sequence></Member>"
"</Struct><Struct name=\"proxyPoseWithCovarianceStamped\"><Member name=\"header\"><Type name=\"Header\"/>"
"</Member><Member name=\"pose\"><Type name=\"PoseWithCovariance\"/></Member></Struct></MetaData>";
