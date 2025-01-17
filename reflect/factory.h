#ifndef FACTORY_H
#define FACTORY_H


#include <unordered_map>
#include <string>
#include <cstddef>

#include "cfield.h"

extern class Object;

template<typename Key, typename Value>
using hash_map = std::unordered_map<Key, Value>;

using funCrtObj = Object* (*)();

class Factory
{
using className = std::string;

private:
    Factory();

public:
    static Factory & getInst(){
        static Factory inst;
        return inst;
    }

    void registerClass(const className & strClassName, funCrtObj func){
        if(mpClassCreat.count(strClassName) || strClassName.empty()){
            return ;
        }

        mpClassCreat.emplace(strClassName, func);
    }


    //register field for the given class
    void registerField(const className & strClassName, CField cField){
        if(mpClassFields.count(strClassName)){
            return ;
        }

        mpClassFields[strClassName].emplace_back(cField);
    }


    CField getField(const className & strClassName, const std::string & strFieldName) const;

    Object * crtObj(const std::string & strClassName);




private:

    hash_map<className, funCrtObj> mpClassCreat;
    hash_map<className, std::vector<CField>> mpClassFields;
};

#define FACTORY_INST Factory::getInst()

#define REGISTER_CLASS(className)                                               \
inline Object* createObject_##className() {                                     \
    Object * pObj = new className();                                            \
    pObj->setClassName(#className);                                             \
    return pObj;                                                                \
}                                                                               \
    struct className##_Register{                                                \
        className##_Register() {                                                \
            FACTORY_INST.registerClass(#className, createObject_##className);   \
    }                                                                           \
};                                                                              \
inline static className##_Register className##_reg;



#define REFISTER_FIELD(className, fieldName, fieldType)                                 \
struct className##fieldName##_Register{                                                 \
    className##fieldName##_Register(){                                                  \
        CField field(#fieldName, #fieldType, offsetof(className, fieldName));           \
        FACTORY_INST.registerField(#className, field);                                  \
    }                                                                                   \
};                                                                                      \
inline static className##fieldName##_Register className##fieldName##_register_obj;


#endif // FACTORY_H
