#include "object.h"



Object::Object() {}
Object::Object(const std::string & strClassName):m_strClassName(strClassName)
{}


void Object::setClassName(const std::string & strClassName)
{
    this->m_strClassName = strClassName;
}

const std::string & Object::getClassName() const
{
    return this->m_strClassName;
}

