
#include <iostream>

#include "factory.h"
#include "cstudent.h"
#include "object.h"

int main(int argc, char *argv[])
{
    CStudent * pStu = (CStudent *)FACTORY_INST.crtObj("CStudent");
    pStu->show();
}
