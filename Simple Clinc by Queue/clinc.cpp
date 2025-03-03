#include "Queue.h"
#include <iostream>
using namespace std;
int main()
{
    LinkedQueue lq;
    string name;
    int age;
    string phonenumber;
    string date;
    cout<<  "=========================="<<endl;
    cout << "==== Welcome To Clinc ==== " << endl;
    cout<<  "=========================="<<endl;
    
    char choice = 'y';
    do
    {
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter your Age: ";
        cin >> age;
        cout << "Enter your Phonenumber: ";
        cin >> phonenumber;
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;
        lq.Appointment(name, age, phonenumber, date);
        cout << "Book New an appointment y/n" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "List of Appointments? (y/n): "<<endl;
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {

        lq.patiantDetails();
    }
    else
    {
        cout << "No Appointments" << endl;
    }
    cout << "Next Patient (y/n)?" << endl;
    cin >> choice;
    while (choice == 'y' || choice == 'Y')
    {
        if (lq.isEmpty())
        {
            cout << "No Patients" << endl;
        }
        else
        {
            lq.FristPatient();
            cout<<endl;
            lq.Nextpatenit();
        }
        cout << "Next Patient (y/n)?" << endl;
    cin >> choice;
    }
    cout<<"Last Patient (y/n)?"<<endl;
    cin>>choice;
    if (choice == 'y' || choice == 'Y')
    {
        lq.LastPatient();
    }
    else{
        cout<<"No Patients"<<endl;
    }
cout<<"Search Patient (y/n)?"<<endl;
    cin>>choice;
    if(choice == 'y' || choice == 'Y')
    {
        int id;
        cout<<"Enter Patient ID"<<endl;
        cin>>id;
        lq.SearchbyID(id);
    }
    else{
        cout<<"No Patients"<<endl;
    }
    cout<<"Delete Patient (y/n)?"<<endl;
    cin>>choice;
    if(choice == 'y' || choice == 'Y')
    {
        int id;
        cout<<"Enter patient ID"<<endl;
        cin>>id;
        lq.deleteAppointment(id);
    }
    cout<<"=====Project is Ended======"<<endl;
return 0;
}
