#ifndef LESSON_H
#define LESSON_H
#include <iostream>
using namespace std;

/*
Δημιουργήστε την κλάση “Μάθημα” με τα εξής χαρακτηριστικά: 
Κωδικός (String), Λεκτικό (String), Ώρες ανά εβδομάδα (unsigned int), Εξάμηνο Διδασκαλίας (Χειμερινό, Εαρινό)
*/

enum Semesterd { Χειμερινό, Εαρινό};

class Lesson
{
private:
    string code,lektiko;
    unsigned int hours;
    Semesterd sem;
public:
    //Constructor
    Lesson(const string code, const string lektiko, unsigned int h,Semesterd sem);
    Lesson(const Lesson& other);

    //Print
    friend ostream& operator<<(ostream& os, const Lesson& l);
    void print(ostream& screen) const;

    
    //Setter
    void setCode(const string code);
    void setLektiko(const string lektiko);
    void setHours(unsigned int hours);
    void setSem(Semesterd sem);

    //Getter
    string getCode() const;
    string getLektiko() const;
    unsigned int getHours() const;
    Semesterd getSem() const;

    //Operator =
    Lesson& operator=(const Lesson& other);

    //destructor
    ~Lesson();
};

#endif