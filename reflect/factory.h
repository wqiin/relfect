#ifndef FACTORY_H
#define FACTORY_H

#include "object.h"

#include <unordered_map>
#include <string>
#include <cstdint>


template<typename Key, typename Value>
using hash_map = std::unordered_map<Key, Value>;

using funCrtObj = Object* (*)();

class Factory
{
private:
    Factory();

public:
    static Factory & getInst(){
        static Factory inst;
        return inst;
    }

    void registerClass(const std::string & strClassName, funCrtObj func){
        if(!mpClassCreat.count(strClassName) || strClassName.empty()){
            return ;
        }

        mpClassCreat.emplace(strClassName, func);
    }

    void * crtObj(const std::string & strClassName);

private:
    using className = std::string;
    hash_map<className, funCrtObj> mpClassCreat;
};

#define FACTORY_INST Factory::getInst()

/*
#define REGISTER_CLASS(className)                                           \
inline void* createObject_##className_##__FILE__() {                                          \
        return (void*)(new className());                                    \
}                                                                           \
struct className##_Register{                                               \
    className##_Register() {                                                \
        FACTORY_INST.registerClass(#className, createObject_##className_##__FILE__);   \
    }                                                                       \
};                                                                          \
inline static className##_Register className##_reg;
*/

#define REGISTER_CLASS(className)                                           \
inline Object* createObject_##className() {                                          \
        return new className();                                    \
}                                                                           \
    struct className##_Register{                                               \
        className##_Register() {                                                \
            FACTORY_INST.registerClass(#className, createObject_##className);   \
    }                                                                       \
};                                                                          \
inline static className##_Register className##_reg;

#endif // FACTORY_H
