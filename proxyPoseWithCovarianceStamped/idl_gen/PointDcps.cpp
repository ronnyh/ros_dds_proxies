//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: PointDcps.cpp
//  Source: PointDcps.idl
//  Generated: Fri Jul 27 15:39:23 2012
//  OpenSplice V5.5.1OSS
//  
//******************************************************************

#include "PointDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUFLSeq < Point, struct PointSeq_uniq_>;
#endif

const char * PointTypeSupportInterface::_local_id = "IDL:PointTypeSupportInterface:1.0";

PointTypeSupportInterface_ptr PointTypeSupportInterface::_duplicate (PointTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PointTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, PointTypeSupportInterface::_local_id) == 0)
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

PointTypeSupportInterface_ptr PointTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   PointTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (PointTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < PointTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

PointTypeSupportInterface_ptr PointTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   PointTypeSupportInterface_ptr result;
   result = dynamic_cast < PointTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

const char * PointDataWriter::_local_id = "IDL:PointDataWriter:1.0";

PointDataWriter_ptr PointDataWriter::_duplicate (PointDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PointDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, PointDataWriter::_local_id) == 0)
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

PointDataWriter_ptr PointDataWriter::_narrow (DDS::Object_ptr p)
{
   PointDataWriter_ptr result = NULL;
   if (p && p->_is_a (PointDataWriter::_local_id))
   {
      result = dynamic_cast < PointDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

PointDataWriter_ptr PointDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   PointDataWriter_ptr result;
   result = dynamic_cast < PointDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

const char * PointDataReader::_local_id = "IDL:PointDataReader:1.0";

PointDataReader_ptr PointDataReader::_duplicate (PointDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PointDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, PointDataReader::_local_id) == 0)
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

PointDataReader_ptr PointDataReader::_narrow (DDS::Object_ptr p)
{
   PointDataReader_ptr result = NULL;
   if (p && p->_is_a (PointDataReader::_local_id))
   {
      result = dynamic_cast < PointDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

PointDataReader_ptr PointDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   PointDataReader_ptr result;
   result = dynamic_cast < PointDataReader_ptr> (p);
   result->m_count++;
   return result;
}

const char * PointDataReaderView::_local_id = "IDL:PointDataReaderView:1.0";

PointDataReaderView_ptr PointDataReaderView::_duplicate (PointDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean PointDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, PointDataReaderView::_local_id) == 0)
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

PointDataReaderView_ptr PointDataReaderView::_narrow (DDS::Object_ptr p)
{
   PointDataReaderView_ptr result = NULL;
   if (p && p->_is_a (PointDataReaderView::_local_id))
   {
      result = dynamic_cast < PointDataReaderView_ptr> (p);
      result->m_count++;
   }
   return result;
}

PointDataReaderView_ptr PointDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   PointDataReaderView_ptr result;
   result = dynamic_cast < PointDataReaderView_ptr> (p);
   result->m_count++;
   return result;
}



