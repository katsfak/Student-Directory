#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include "Lesson.h"
using namespace std;

class Student
{
private:
    char* AM;
    string name;
    unsigned int sem;

    /*Συμπληρώστε την κλάση “Φοιτητής” ώστε να συμπεριλαμβάνονται τα ακόλουθα χαρακτηριστικά:
    Τα δηλωμένα μαθήματα του τρέχοντος εξαμήνου και οι βαθμοί των επιτυχώς ολοκληρωμένων μαθημάτων προηγούμενων εξαμήνων. 
    Προσθέστε την λειτουργικότητα που θεωρείτε απαραίτητη.*/
    vector<Lesson*> d_subjects;
    vector<pair<Lesson*, float>> pass_subjects;

public:
    //constructors
    Student(const char* am, string surname);
    Student(const char* am, string surname, unsigned int s);
    Student(const char* am, string surname, unsigned int s,vector<Lesson*> dsubjects);
    Student(const char* am, string surname, unsigned int s,vector<Lesson*> dsubjects,vector<pair<Lesson*, float>> psubjects);
    Student(const Student& otherstudent);
    Student& operator=(const Student& other);
    
    //getter
    const char* getAM() const;
    string getName() const;
    unsigned int getSemester() const;
    vector<Lesson*> getDsubjects() const;
    vector<pair<Lesson*, float>> getPasssubjects() const;

    //setter
    void setAM(const char * AM);
    void setName(string name);
    void setsemester(unsigned int sem);
    void setDsubjects(vector<Lesson*> dsubjects);
    void setPasssubjects(vector<pair<Lesson*, float>> passsubjects);

    //print
    friend ostream& operator<<(ostream& C1, const Student& S1);
    void print(ostream& screen) const;


    //change
    Student& operator++(); //++sem
    Student& operator++(int); //sem++

    //overload
    Student& operator+=(unsigned int s);
    Student& operator-=(unsigned int s);
    Student& operator+=(const Lesson& Lesson);
    bool operator==(const Student& otherstudent1);
    bool operator!=(const Student& otherstudent1); 
    bool operator<(const Student& otherstudent1); 
    bool operator<=(const Student& otherstudent1); 
    bool operator>(const Student& otherstudent1); 
    bool operator>=(const Student& otherstudent1);

    //destructor
    ~Student();
};
#endif