#include <iostream>
#include "Lesson.h"
using namespace std;

//Constructor
Lesson::Lesson(const string code, const string lektiko, unsigned int h,Semesterd sem)
{
    this->code=code;
    this->lektiko=lektiko;
    this->hours=h;
    this->sem=sem;
}

//Copy Constructor
Lesson::Lesson(const Lesson& other)
{
    this->code=other.code;
    this->lektiko=other.lektiko;
    this->hours=other.hours;
    this->sem=other.sem;
}

//Print
ostream& operator<<(ostream& os, const Lesson& l)
{
    if(l.sem==0)
    os << "Κωδικός " <<l.code<<" Λεκτικό "<<l.lektiko<<" Ώρες "<<l.hours<<" Εξάμηνο "<<"Χειμερινό "<<endl;
    else
    os << "Κωδικός " <<l.code<<" Λεκτικό "<<l.lektiko<<" Ώρες "<<l.hours<<" Εξάμηνο "<<"Εαρινό "<<endl;

    return os;
}


void Lesson::print(ostream& screen) const
{
    if(sem==0)
    screen<<"Κωδικός "<<code<<" Λεκτικό "<<lektiko<<" Ώρες "<<hours<<" Εξάμηνο "<<"Χειμερινό"<<endl;
    else
    screen<<"Κωδικός "<<code<<" Λεκτικό "<<lektiko<<" Ώρες "<<hours<<" Εξάμηνο "<<"Εαρινό"<<endl;
}

//Setter
void Lesson::setCode(const string code)
{
    this->code=code;
}

void Lesson::setLektiko(const string lektiko)
{
    this->lektiko=lektiko;
}

void Lesson::setHours(unsigned int hours)
{
    this->hours=hours;
}

void Lesson::setSem(Semesterd sem)
{
    this->sem=sem;
}

//Getter
string Lesson::getCode() const
{
    return this->code;
}

string Lesson::getLektiko() const
{
    return this->lektiko;
}

unsigned int Lesson::getHours() const
{
    return this->hours;
}

Semesterd Lesson::getSem() const
{
    return this->sem;
}

// Operator =
Lesson& Lesson::operator=(const Lesson& other)
{
    if (this!=&other)
    {
        code=other.code;
        lektiko=other.lektiko;
        hours=other.hours;
        sem=other.sem;
    }
    return *this;
}

//Destructor
Lesson::~Lesson()
{
    
}