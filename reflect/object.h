#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "factory.h"

class Object
{
public:
    Object();
    Object(const std::string & strClassName);
    ~Object(){}


    template<typename T>
    void setValue(const std::string & strFieldName, const T & value)
    {
        auto && field = FACTORY_INST.getField(this->m_strClassName, strFieldName);
        size_t pAddr = (size_t)this + field.getFieldOffset();
        *((T*)pAddr) = value;
    }

    template<typename T>
    void getValue(const std::string & strFieldName, T & value)
    {
        auto && field = FACTORY_INST.getField(this->m_strClassName, strFieldName);
        size_t pAddr = (size_t)this + field.getFieldOffset();
        value = *((T*)pAddr) = value;
        //value = *(this + field.getFieldOffset());
    }

    void setClassName(const std::string & strClassName);
    const std::string & getClassName() const;

protected:
    std::string m_strClassName;
};


#endif // OBJECT_H
