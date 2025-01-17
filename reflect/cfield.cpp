#include "cfield.h"

CField::CField():m_strFieldName(""),m_strFieldType(""),m_nFieldOffset(0)
{}


CField::CField(const std::string strFieldName, const std::string & strFieldType, size_t nFieldOffset):m_strFieldName(strFieldName),m_strFieldType(strFieldType),m_nFieldOffset(nFieldOffset)
{}

CField::~CField()
{}


const std::string & CField::getFieldName() const
{
    return this->m_strFieldName;
}

const std::string & CField::getFieldType() const
{
    return this->m_strFieldType;
}

size_t CField::getFieldOffset() const
{
    return this->m_nFieldOffset;
}
