#include <iostream>
#include <utility>
#include <vector>
#include "Student.h"
using namespace std;

//Constructors
/*
    Ορίζοντας ΑΜ και Ονοματεπώνυμο. Σε αυτή την περίπτωση το τρέχον
    εξάμηνο του φοιτητή θα είναι 1.
*/
Student::Student(const char* am, string surname)
{
    AM=new char[strlen(am)+1];
    if(AM==NULL)
    {
        cout<<"Δεν έγινε η δυναμική παραχώρηση μνήμης"<<endl;
        exit;
    }
    strcpy(AM,am);
    name=surname;
    sem=1;
}

/*
    Ορίζοντας τιμές σε όλα τα χαρακτηριστικά.
*/
Student::Student(const char* am, string surname, unsigned int s)
{
    AM=new char[strlen(am)+1];
    if(AM==NULL)
    {
        cout<<"Δεν έγινε η δυναμική παραχώρηση μνήμης"<<endl;
        exit;
    }
    strcpy(AM,am);
    name=surname;
    sem=s;
}

Student::Student(const char* am, string name, unsigned int s,vector<Lesson*> dsubjects)
{
    AM=new char[strlen(am)+1];
    if(AM==NULL)
    {
        cout<<"Δεν έγινε η δυναμική παραχώρηση μνήμης"<<endl;
        exit;
    }
    strcpy(AM,am);
    this->name=name;
    sem=s;
    d_subjects=dsubjects;
}

Student::Student(const char* am, string name, unsigned int s,vector<Lesson*> dsubjects,vector<pair<Lesson*, float>> psubjects)
{
    AM=new char[strlen(am)+1];
    if(AM==NULL)
    {
        cout<<"Δεν έγινε η δυναμική παραχώρηση μνήμης"<<endl;
        exit;
    }
    strcpy(AM,am);
    this->name=name;
    sem=s;
    d_subjects=dsubjects;
    pass_subjects=psubjects;
}


/*
    Ορίζοντας σε όλα τα χαρακτηριστικά ως τιμές τις τιμές των χαρακτηριστικών
    ενός άλλου “Φοιτητή”.

*/
Student::Student(const Student& otherstudent)
{
    AM=new char[strlen(otherstudent.AM)+1];
    if(AM==NULL)
    {
        cout<<"Δεν έγινε η δυναμική παραχώρηση μνήμης"<<endl;
        exit;
    }
    strcpy(AM,otherstudent.AM);
    name=otherstudent.name;
    sem=otherstudent.sem;
}

/*
    Υπερφορτώστε τον τελεστή εκχώρησης για την κλάση “Φοιτητής”.
*/

Student& Student::operator=(const Student& other)
{
    if(this==&other)
    {
        AM=new char[strlen(other.AM)+1];
        strcpy(AM,other.AM);
        name=other.name;
        sem=other.sem;
        d_subjects=other.d_subjects;
        pass_subjects=other.pass_subjects;
    }
    return *this;
}

/*
    Η κλάση θα παρέχει getters και setters για όλα τα χαρακτηριστικά της. Επιπλέον θα
    μπορεί να εκτελέσει τις ακόλουθες λειτουργίες:

*/
//      GETTER
const char* Student::getAM() const 
{
    return AM;
}

string Student::getName() const
{
    return name;
}

unsigned int Student::getSemester() const 
{
    return sem;
}

vector<Lesson*> Student::getDsubjects() const
{
    return d_subjects;
}

vector<pair<Lesson*, float>> Student::getPasssubjects() const
{
    return pass_subjects;
}

//     SETTER
void Student::setAM(const char * AM)
{
    this->AM=new char[strlen(AM)+1];
    if(this->AM==NULL)
    {
        cout<<"Δεν έγινε η δυναμική παραχώρηση μνήμης"<<endl;
        exit;
    }
    strcpy(this->AM,AM);
    
}

void Student::setDsubjects(vector<Lesson*> dsubjects)
{
    this->d_subjects=dsubjects;
}

void Student::setPasssubjects(vector<pair<Lesson*, float>> passsubjects)
{
    pass_subjects=passsubjects;
}

void Student::setName(string name)
{
    this->name=name;
}

void Student::setsemester(unsigned int sem)
{
    this->sem=sem;
}

//Print
/*
    Υπερφορτώστε ό,τι χρειάζεται, ώστε η εντολή: C1 << S1;
    (όπου C1 στιγμιότυπο της κλάσης “ostream” και S1 στιγμιότυπο της κλάσης Φοιτητής)
    να τυπώνει την αναλυτική βαθμολογία του φοιτητή στο κανάλι.
    Στην αναλυτική θα αναγράφεται και ο μέσος όρος του φοιτητή. 
*/
ostream& operator<<(ostream& C1, const Student& S1)
{
    float mesos = 0.0;
    C1 << "Αριθμός Μητρώου "<< S1.getAM() << endl << "Ονοματεπώνυμο " << S1.getName() << endl <<"Εξάμηνο " << S1.getSemester() <<endl;
    C1<<endl;
    C1<<"Δηλωμένα Μαθήματα "<<S1.d_subjects.size()<<endl;
    for (int i = 0; i < S1.getDsubjects().size(); i++)
    {
        C1<<*S1.getDsubjects()[i]<<endl;
    }
    C1 << "Βαθμοί: " <<endl;
    try
    {
        for(int i=0; i<S1.getPasssubjects().size(); i++)
        {
            C1<< *S1.getPasssubjects()[i].first<<endl;
            if (S1.getPasssubjects()[i].second<5)
            {
                mesos=mesos+0;
                throw -1;
            }
            else
            {
                C1<< S1.getPasssubjects()[i].second<<endl;
                mesos+=S1.getPasssubjects()[i].second;
            }
            
        }
    }
    catch(int)
    {
        cerr << "Λάθος Περασμένη Βαθμολογία" << endl;
        C1 << "Λάθος Περασμένη Βαθμολογία" << endl;

    }
    
    
    
    if (S1.getPasssubjects().empty())
    {
        C1 <<"Ο Μέσος Όρος είναι: "<< mesos <<endl;
        mesos=0.0;
    }
    else
    {
        C1 <<"Ο Μέσος Όρος είναι: "<< mesos <<endl;
        mesos/=S1.getPasssubjects().size();
    }
    

    return C1;
}

void Student::print(ostream& screen) const
{
    screen<<"Ονοματεπώνυμο "<<name<<" Αριθμός Μητρώου "<<AM<<" Τρέχων Εξάμηνο "<<sem<<endl;
    
    
}

/*
    Αύξηση του τρέχοντος εξαμήνου κατά 1 με χρήση του τελεστή προαύξησης
    ή του τελεστή μετααύξησης.
*/
Student& Student::operator++()
{
    ++sem;
    return *this;
}

Student& Student::operator++(int)
{
    sem++;
    return *this;
}

/*
    Αλλαγή του εξαμήνου με την χρήση των τελεστών “+=” και “-=”.
*/
Student& Student::operator+=(unsigned int s)
{
    sem+=s;
    return *this;
}

Student& Student::operator-=(unsigned int s)
{
    sem-=s;
    return *this;
}

/*
    Υπερφορτώστε τον τελεστή ‘+=’ ώστε να προσθέτει ένα μάθημα στο σύνολο των δηλωμένων μαθημάτων.
*/
Student& Student::operator+=(const Lesson& lesson)
{
    d_subjects.push_back(new Lesson(lesson));
    return *this;
}

/*
    Υπεροφρτώστε τους τελεστές “==”, “!=”, “<”, “<=”, “>”, “>=”.  
    Η σύγκριση θα αφορά το εξάμηνο του φοιτητή.
*/

bool Student::operator==(const Student& otherstudent1)
{
    return sem==otherstudent1.sem;
}

bool Student::operator!=(const Student& otherstudent1)
{
    return sem!=otherstudent1.sem;
}

bool Student::operator<(const Student& otherstudent1)
{
    return sem<otherstudent1.sem;
}

bool Student::operator<=(const Student& otherstudent1)
{
    return sem<=otherstudent1.sem;
}

bool Student::operator>(const Student& otherstudent1)
{
    return sem>otherstudent1.sem;
}

bool Student::operator>=(const Student& otherstudent1)
{
    return sem>=otherstudent1.sem;
}


//Καταστροφέας
Student::~Student()
{   
    if(AM)
    {
        delete[] AM;
    }

    while(!d_subjects.empty())
    {
        d_subjects.clear();
    }
    
}