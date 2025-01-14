#ifndef CSTUDENT_H
#define CSTUDENT_H

#include "factory.h"
#include "object.h"

class CStudent : public Object
{
public:
    CStudent();

    void show();
};

REGISTER_CLASS(CStudent)

#endif // CSTUDENT_H
