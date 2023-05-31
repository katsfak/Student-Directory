#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include "Student.h"
#include "Lesson.h"
using namespace std;

/*
    ΟΝΟΜΑΤΕΠΩΝΥΜΟ: ΣΦΑΚΙΑΝΟΥ ΑΙΚΑΤΕΡΙΝΗ ΕΙΡΗΝΗ
    ΑΡΙΘΜΟΣ ΜΗΤΡΩΟΥ: ICE20390223
    ΤΜΗΜΑ: 07
*/


int main(int argc, char **argv)
{
    /*
        Τροποποιήστε το υπόλοιπο πρόγραμμα ώστε να επιδεικνύει και τη νέα λειτουργικότητα.
        Μεταξύ άλλων θα πρέπει να αποθηκεύεται το σύνολο των δεδομένων σε αρχεία κειμένου.
    */
    //ΕΡΓΑΣΙΑ 3
    //LESSON
    //CONSTRUCTOR & COPY CONSTRUCTOR & OPERATOR=
    Lesson b1("ICE-1004","Προγραμματισμός Υπολογιστών",6,Χειμερινό);
    Lesson b2(b1);
    Lesson b3("ICE-2004","Αντικειμενοστρεφής Προγραμματισμός",6,Εαρινό);
    Lesson b4=b3;
    Lesson b5("ICE-1001","Μαθηματική Ανάλυση",5,Χειμερινό);
    Lesson b6("ICE-2003","Μαθηματική Ανάλυση 2",4,Εαρινό);

    //PRINT
    b1.print(cout);
    b2.print(cout);
    b3.print(cout);
    b4.print(cout);

    //SETTER
    b2.setCode("ICE-3003");
    b2.setLektiko("Δομές Δεδομένων");
    b2.setHours(5);
    b4.setSem(Χειμερινό);
    b4.setCode("ICE-4004");
    b4.setLektiko("Μεθοδολογίες Ανάπτυξης Εφαρμογών");
    b4.setHours(5);
    b4.setSem(Εαρινό);
    cout<<endl;

    //GETTER
    cout<<"Με Αλλαγές"<<endl;
    cout<<"Κωδικός "<<b2.getCode()<<" Λεκτικό "<<b2.getLektiko()<<" Ώρες "<<b2.getHours()<<" Εξάμηνο "<<b2.getSem()<<endl;  //0=Χειμερινό
    cout<<"Κωδικός "<<b4.getCode()<<" Λεκτικό "<<b4.getLektiko()<<" Ώρες "<<b4.getHours()<<" Εξάμηνο "<<b4.getSem()<<endl;  //1=Εαρινό
    cout<<endl;

    //STUDENT
    //CONSTRUCTOR & COPY CONSTRUCTOR & OPERATOR=
    vector<pair<Lesson*,float>> subject;
    subject.push_back(make_pair(&b1,6));
    vector<Lesson*> subj;
    subj.push_back(&b2);
    subj.push_back(&b4);
    Student a1("ice20390223","Κατερίνα Σφακιανού",6,subj,subject);
    Student a2=a1;
    a2.print(cout);
    a2.setAM("ice20390001");
    a2.setName("Νίκος Παππάς");
    a2.setsemester(1);
    Student a3("ice20390002","Alan Walker",1,subj);
    cout<<endl;

    //PRINT
    cout<<"Student 1 "<<endl<<a1<<endl;

    //SETTER
    vector<pair<Lesson*,float>> subjects2;
    subjects2.push_back(make_pair(&b4,10));
    subjects2.push_back(make_pair(&b2,3));
    vector<Lesson*> subja2;
    subja2.push_back(&b5);
    a2.setDsubjects(subja2);
    a2.setPasssubjects(subjects2);

    //GETTER
    cout<<"\t Δεύτερος Φοιτητής"<<endl;
    cout<<"Δηλωμένα Μαθήματα: "<<a2.getDsubjects().size()<<endl;

    cout<<"Περασμένα Μαθήματα "<<a2.getPasssubjects().size()/2<<endl;
    cout<<endl;

    //OVERLOAD
    a3.operator+=(b6); //Προσθετουμε ενα μαθημα στην λιστα των δηλωμένων μαθημάτων

    //BOOL
    cout<<"\tΣύγκριση Εξαμήνων Φοιτητή"<<endl;
    cout<<"Τελεστής == "<<a1.operator==(a2)<<endl;
    cout<<"Τελεστής != "<<a1.operator!=(a2)<<endl;
    cout<<"Τελεστής < "<<a1.operator<(a2)<<endl;
    cout<<"Τελεστής <= "<<a1.operator<=(a2)<<endl;
    cout<<"Τελεστής > "<<a1.operator>(a2)<<endl;
    cout<<"Τελεστής >= "<<a1.operator>=(a2)<<endl;


    //WRITE TO FILE
    ofstream oufile("Students.txt");
    if (oufile.is_open())
    {
        oufile << a1;
        oufile<<endl;
        oufile << a2;
        oufile<<endl;
        oufile << a3;
        cout<<"Η εγγραφή ολοκληρώθηκε με επιτυχία "<<endl;
    }
    else
    {
        cout<<" εγγραφή δεν ολοκληρώθηκε με επιτυχία "<<endl;
    }

    return 0;

    //ΕΡΓΑΣΙΑ 2
    //Student a1("ice20390223","Κατερίνα Σφακιανού",6);
    //cout<<"Πρώτος Φοιτητής"<<endl;
    //a1.print(cout);
    //cout<<"Δεύτερος Φοιτητής (Copy Constructor)"<<endl;
    //a1.print(cout);
    //cout<<"Αλλάζω τον αριθμό μητρώου, το ονοματεπώνυμο και το εξάμηνο του δεύτερου φοιτητή"<<endl;
    //a2.print(cout);
    //cout<<"Aύξηση εξάμηνου δεύτερου φοιτητή"<<endl;
    //a2.operator++();
    //cout<<"Aύξηση εξάμηνου δεύτερου φοιτητή"<<endl;
    //a2.operator++(1);
    //a2.print(cout);
    //cout<<"Αριθμός μητρώου με χρήση getter τρίτου φοιτητή"<<endl;
    //cout<<a3.getAM()<<" ΑΜ"<<endl;
    //cout<<"Αυξηση εξαμήνου τρίτου φοιτητή"<<endl;
    //a3.operator+=(3);
    //a3.print(cout);
    //cout<<"Μείωση εξαμήνου πρώτου φοιτητή"<<endl;
    //a1.operator-=(3);
    //a1.print(cout);
}
