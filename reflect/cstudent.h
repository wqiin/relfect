#ifndef CSTUDENT_H
#define CSTUDENT_H

#include "factory.h"
#include "object.h"

#include <iostream>

class CStudent : public Object
{
public:
    CStudent();

    void show();

    int nAge = 0;
    float fGrade = 0.0f;
};

REGISTER_CLASS(CStudent)
REFISTER_FIELD(CStudent, nAge, int)
REFISTER_FIELD(CStudent, fGrade, float)


class CTeacher : public Object
{
public:
    CTeacher(){}

    void show(){
        std::cout << "Hello World, this is the teacher\n";
    }
};
REGISTER_CLASS( CTeacher)


#endif // CSTUDENT_H
