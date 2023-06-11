#include <iostream>
#include <string.h>
using namespace std;

/*
    ΟΝΟΜΑΤΕΠΩΝΥΜΟ: ΣΦΑΚΙΑΝΟΥ ΑΙΚΑΤΕΡΙΝΗ ΕΙΡΗΝΗ
    ΑΡΙΘΜΟΣ ΜΗΤΡΩΟΥ: ICE20390223
    ΤΜΗΜΑ: 07
*/

class Student
{
private:
    char* AM;
    string name;
    unsigned int sem;
public:
    //constructors
    Student(const char* am, string surname);
    Student(const char* am, string surname, unsigned int s);
    Student(const Student& otherstudent);

    //getter
    const char* getAM() const;
    string getName() const;
    unsigned int getSemester() const;

    //setter
    void setAM(const char * AM);
    void setName(string name);
    void setsemester(unsigned int sem);

    //print
    void print(ostream& screen) const;

    //change
    Student& operator++(); //++sem
    Student& operator++(int); //sem++

    //overload
    Student& operator+=(unsigned int s);
    Student& operator-=(unsigned int s);

    //destructor
    ~Student();
};

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

void Student::setName(string name)
{
    this->name=name;
}

void Student::setsemester(unsigned int sem)
{
    this->sem=sem;
}

/*
    Εκτύπωση όλων των χαρακτηριστικών, σε μία γραμμή, σε οποιοδήποτε
    κανάλι (οstream)
*/
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

//Καταστροφέας
Student::~Student()
{
    delete[] AM;
    //cout<<"Έγινε η καταστροφη του αντικειμένου"<<endl;
}



int main(int argc, char **argv)
{
    Student a1("ice20390223","Κατερίνα Σφακιανού",6);
    Student a2(a1);
    Student a3("ice20390002","Alan Walker");
    cout<<"Πρώτος Φοιτητής"<<endl;
    a1.print(cout);
    cout<<"Δεύτερος Φοιτητής (Copy Constructor)"<<endl;
    a2.print(cout);
    cout<<"Αλλάζω τον αριθμό μητρώου, το ονοματεπώνυμο και το εξάμηνο του δεύτερου φοιτητή"<<endl;
    a2.setAM("ice20390001");
    a2.setName("Νίκος Παππάς");
    a2.setsemester(1);
    a2.print(cout);
    cout<<"Aύξηση εξάμηνου δεύτερου φοιτητή"<<endl;
    a2.operator++();
    cout<<"Aύξηση εξάμηνου δεύτερου φοιτητή"<<endl;
    a2.operator++(1);
    a2.print(cout);
    cout<<"Αριθμός μητρώου με χρήση getter τρίτου φοιτητή"<<endl;
    cout<<a3.getAM()<<" ΑΜ"<<endl;
    cout<<"Αυξηση εξαμήνου τρίτου φοιτητή"<<endl;
    a3.operator+=(3);
    a3.print(cout);
    cout<<"Μείωση εξαμήνου πρώτου φοιτητή"<<endl;
    a1.operator-=(3);
    a1.print(cout);
    return 0;
}
