//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: TimeDcps.cpp
//  Source: TimeDcps.idl
//  Generated: Wed Oct  2 09:48:42 2013
//  OpenSplice V6.2.0
//  
//******************************************************************

#include "TimeDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUFLSeq < Time, struct TimeSeq_uniq_>;
#endif

const char * TimeTypeSupportInterface::_local_id = "IDL:TimeTypeSupportInterface:1.0";

TimeTypeSupportInterface_ptr TimeTypeSupportInterface::_duplicate (TimeTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TimeTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, TimeTypeSupportInterface::_local_id) == 0)
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

TimeTypeSupportInterface_ptr TimeTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   TimeTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (TimeTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < TimeTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TimeTypeSupportInterface_ptr TimeTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   TimeTypeSupportInterface_ptr result;
   result = dynamic_cast < TimeTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * TimeDataWriter::_local_id = "IDL:TimeDataWriter:1.0";

TimeDataWriter_ptr TimeDataWriter::_duplicate (TimeDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TimeDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, TimeDataWriter::_local_id) == 0)
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

TimeDataWriter_ptr TimeDataWriter::_narrow (DDS::Object_ptr p)
{
   TimeDataWriter_ptr result = NULL;
   if (p && p->_is_a (TimeDataWriter::_local_id))
   {
      result = dynamic_cast < TimeDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TimeDataWriter_ptr TimeDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   TimeDataWriter_ptr result;
   result = dynamic_cast < TimeDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * TimeDataReader::_local_id = "IDL:TimeDataReader:1.0";

TimeDataReader_ptr TimeDataReader::_duplicate (TimeDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TimeDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, TimeDataReader::_local_id) == 0)
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

TimeDataReader_ptr TimeDataReader::_narrow (DDS::Object_ptr p)
{
   TimeDataReader_ptr result = NULL;
   if (p && p->_is_a (TimeDataReader::_local_id))
   {
      result = dynamic_cast < TimeDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TimeDataReader_ptr TimeDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   TimeDataReader_ptr result;
   result = dynamic_cast < TimeDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * TimeDataReaderView::_local_id = "IDL:TimeDataReaderView:1.0";

TimeDataReaderView_ptr TimeDataReaderView::_duplicate (TimeDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TimeDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, TimeDataReaderView::_local_id) == 0)
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

TimeDataReaderView_ptr TimeDataReaderView::_narrow (DDS::Object_ptr p)
{
   TimeDataReaderView_ptr result = NULL;
   if (p && p->_is_a (TimeDataReaderView::_local_id))
   {
      result = dynamic_cast < TimeDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

TimeDataReaderView_ptr TimeDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   TimeDataReaderView_ptr result;
   result = dynamic_cast < TimeDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}



