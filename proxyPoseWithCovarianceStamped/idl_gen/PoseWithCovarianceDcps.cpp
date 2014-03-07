//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: PoseWithCovarianceDcps.cpp
//  Source: PoseWithCovarianceDcps.idl
//  Generated: Fri Jul 27 15:39:16 2012
//  OpenSplice V5.5.1OSS
//  
//******************************************************************

#include "PoseWithCovarianceDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < PoseWithCovariance, struct PoseWithCovarianceSeq_uniq_>;
#endif

const char * PoseWithCovarianceTypeSupportInterface::_local_id = "IDL:PoseWithCovarianceTypeSupportInterface:1.0";

PoseWithCovarianceTypeSupportInterface_ptr PoseWithCovarianceTypeSupportInterface::_duplicate (PoseWithCovarianceTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PoseWithCovarianceTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, PoseWithCovarianceTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

PoseWithCovarianceTypeSupportInterface_ptr PoseWithCovarianceTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (PoseWithCovarianceTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < PoseWithCovarianceTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

PoseWithCovarianceTypeSupportInterface_ptr PoseWithCovarianceTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceTypeSupportInterface_ptr result;
   result = dynamic_cast < PoseWithCovarianceTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

const char * PoseWithCovarianceDataWriter::_local_id = "IDL:PoseWithCovarianceDataWriter:1.0";

PoseWithCovarianceDataWriter_ptr PoseWithCovarianceDataWriter::_duplicate (PoseWithCovarianceDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PoseWithCovarianceDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, PoseWithCovarianceDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

PoseWithCovarianceDataWriter_ptr PoseWithCovarianceDataWriter::_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceDataWriter_ptr result = NULL;
   if (p && p->_is_a (PoseWithCovarianceDataWriter::_local_id))
   {
      result = dynamic_cast < PoseWithCovarianceDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

PoseWithCovarianceDataWriter_ptr PoseWithCovarianceDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceDataWriter_ptr result;
   result = dynamic_cast < PoseWithCovarianceDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

const char * PoseWithCovarianceDataReader::_local_id = "IDL:PoseWithCovarianceDataReader:1.0";

PoseWithCovarianceDataReader_ptr PoseWithCovarianceDataReader::_duplicate (PoseWithCovarianceDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PoseWithCovarianceDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, PoseWithCovarianceDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

PoseWithCovarianceDataReader_ptr PoseWithCovarianceDataReader::_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceDataReader_ptr result = NULL;
   if (p && p->_is_a (PoseWithCovarianceDataReader::_local_id))
   {
      result = dynamic_cast < PoseWithCovarianceDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

PoseWithCovarianceDataReader_ptr PoseWithCovarianceDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceDataReader_ptr result;
   result = dynamic_cast < PoseWithCovarianceDataReader_ptr> (p);
   result->m_count++;
   return result;
}

const char * PoseWithCovarianceDataReaderView::_local_id = "IDL:PoseWithCovarianceDataReaderView:1.0";

PoseWithCovarianceDataReaderView_ptr PoseWithCovarianceDataReaderView::_duplicate (PoseWithCovarianceDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PoseWithCovarianceDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, PoseWithCovarianceDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

PoseWithCovarianceDataReaderView_ptr PoseWithCovarianceDataReaderView::_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceDataReaderView_ptr result = NULL;
   if (p && p->_is_a (PoseWithCovarianceDataReaderView::_local_id))
   {
      result = dynamic_cast < PoseWithCovarianceDataReaderView_ptr> (p);
      result->m_count++;
   }
   return result;
}

PoseWithCovarianceDataReaderView_ptr PoseWithCovarianceDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   PoseWithCovarianceDataReaderView_ptr result;
   result = dynamic_cast < PoseWithCovarianceDataReaderView_ptr> (p);
   result->m_count++;
   return result;
}



