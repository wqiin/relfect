#include "factory.h"

#include <iostream>

Factory::Factory() {}


Object * Factory::crtObj(const std::string & strClassName)
{
    if(strClassName.empty() || !mpClassCreat.count(strClassName))
        return nullptr;

    //create a object according to classname by calling the register function
    return mpClassCreat.at(strClassName)();
}

CField Factory::getField(const className & strClassName, const std::string & strFieldName) const
{
    if(!mpClassFields.count(strClassName))
        return {};

    for(const auto & field : mpClassFields.at(strClassName)){
        if(field.getFieldName() == strFieldName)
            return field;
    }

    return {};
}
