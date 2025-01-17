
#include <iostream>

#include "factory.h"
#include "cstudent.h"
#include "object.h"


int main(int argc, char *argv[])
{
    CStudent * pStu = (CStudent *)FACTORY_INST.crtObj("CStudent");
    pStu->show();
    std::cout << "classname:" << pStu->getClassName();

    // CTeacher * pTeacher = (CTeacher *)FACTORY_INST.crtObj("CTeacher");
    // pTeacher->show();

    int nAge;
    pStu->getValue("nAge", nAge);
    std::cout << "nAge:" << nAge << std::endl;

    pStu->setValue("nAge", 53);
    pStu->getValue("nAge", nAge);
    std::cout << "nAge after setting:" << nAge << std::endl;

    return 0;
}
