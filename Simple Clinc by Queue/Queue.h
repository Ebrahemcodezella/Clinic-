#include<iostream>
using namespace std;
class Node
{
public:
    string date;
    string name;
    int age;
    int id=1;
    string phonenumber;
    Node *next;
    Node()
    {
        next = nullptr;
    }
};

class LinkedQueue
{
public:
    Node *front;
    Node *back;
    
    int nextId = 1;
    LinkedQueue()
    {
        front = back = nullptr;
    }
    bool isEmpty()
    {
        return (front == nullptr);
    }

    void Appointment(string name,int age,string phonenumber,string date)
{
    Node *node = new Node();
    node->id=nextId++;
    node->date = date;
    node->name=name;
    node->age=age;
    node->phonenumber=phonenumber;
    if (isEmpty())
    {
        front = node;
        back = node;
    }
    else
    {
        back->next = node; 
        back = node;
    }
}
void Nextpatenit()
{
    Node *del = front;
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else if (front == back)
    {
        delete front;
        front = back = nullptr;
    }
    else
    {
        front = front->next;
        delete del;
    }
}

void patiantDetails()
{
    Node *temp = front;
    while (temp != nullptr)
    {
        cout<<"Patient Id: "<<temp->id<<" "<<endl;
        cout <<"Patient Name: " <<temp->name << " "<<endl;
        cout << "Patient age: "<<temp->age << " "<<endl;
        cout <<"Date: " <<temp->date << " "<<endl;
        cout << "Phone Number:"<<temp->phonenumber << " "<<endl;
        cout<<"----------------------"<<endl;
        temp = temp->next;
    }
    cout << endl;
}
void FristPatient()
{
    if (isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return ;
    }
    
    cout<< "Patient Id: "<<front->id <<" Patniet Name:  "<<front->name;
}
void LastPatient()
{
    if (isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return ;
    }
    cout<<"Patient Id: "<< back->id <<" Patniet Name: "<<back->name<<endl;
}
void SearchbyID(int id)
{
    Node *sea = front;
    bool flage = true;
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        while (sea != nullptr)
        {
            if (sea->id == id)
            {
                cout << "Appointment is on " << sea->date << endl;
                flage = false;
            }
            sea = sea->next;
        }
        if (flage)
        {
            cout << "Appointment Doesnot Exist" << endl;
        }
    }
}
    void deleteAppointment(int id) {
        if (isEmpty()) {
            cout << "No appointments to delete." << endl;
            return;
        }

        Node* current = front;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->id == id) {
                if (previous == nullptr) {
                    front = current->next;
                } else {
                    previous->next = current->next;
                }
                if (current == back) {
                    back = previous;
                }
                delete current;
                cout << "Appointment deleted successfully." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Patient ID not found." << endl;
    }
};
