#include "factory.h"

Factory::Factory() {}


void * Factory::crtObj(const std::string & strClassName)
{
    if(strClassName.empty() || !mpClassCreat.count(strClassName))
        return nullptr;

    //create a object according to classname by calling the register function
    return mpClassCreat.at(strClassName)();
}
