#include <iostream>
#include <string>

using namespace std;

struct student
{
    int rollno;
    string name;
    float marks;
    student* next;
};

student* head = nullptr;

void insertatbeginning(int roll, string n, float m) 
{
    student* newnode = new student;
    newnode->rollno = roll;
    newnode->name = n;
    newnode->marks = m;
    newnode->next = head;
    head = newnode;
    cout << "record inserted at beginning." << endl;
}

void insertatend(int roll, string n, float m)
{
    student* newnode = new student;
    newnode->rollno = roll;
    newnode->name = n;
    newnode->marks = m;
    newnode->next = nullptr;
    if (head == nullptr) {
        head = newnode;
    }
    else {
        student* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    cout << "record inserted at end." << endl;
}

void insertafter(int targetroll, int roll, string n, float m) 
{
    student* temp = head;
    while (temp != nullptr && temp->rollno != targetroll) 
    {
        temp = temp->next;
    }
    if (temp != nullptr) {
        student* newnode = new student;
        newnode->rollno = roll;
        newnode->name = n;
        newnode->marks = m;
        newnode->next = temp->next;
        temp->next = newnode;
        cout << "record inserted after roll no " << targetroll << "." << endl;
    }
    else {
        cout << "roll number " << targetroll << " not found." << endl;
    }
}

void deleterecord(int roll) 
{
    if (head == nullptr) {
        cout << "list is empty." << endl;
        return;
    }
    if (head->rollno == roll) {
        student* temp = head;
        head = head->next;
        delete temp;
        cout << "record deleted." << endl;
        return;
    }
    student* curr = head;
    student* prev = nullptr;
    while (curr != nullptr && curr->rollno != roll) 
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) 
    {
        cout << "record not found." << endl;
    }
    else {
        prev->next = curr->next;
        delete curr;
        cout << "record deleted." << endl;
    }
}

void searchrecord(int roll)
{
    student* temp = head;
    while (temp != nullptr) 
    {
        if (temp->rollno == roll) 
        {
            cout << "found: roll: " << temp->rollno << ", name: " << temp->name << ", marks: " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "record not found." << endl;
}

void updaterecord(int roll) 
{
    student* temp = head;
    while (temp != nullptr) 
    {
        if (temp->rollno == roll) 
        {
            cout << "enter new name: ";
            cin >> temp->name;
            cout << "enter new marks: ";
            cin >> temp->marks;
            cout << "record updated." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "record not found." << endl;
}

void displayrecords() 
{
    if (head == nullptr) 
    {
        cout << "no records to display." << endl;
        return;
    }
    student* temp = head;
    cout << "rollnamemarks" << endl;
    while (temp != nullptr) {
        cout << temp->rollno << "" << temp->name << "" << temp->marks << endl;
        temp = temp->next;
    }
}

void calculatestats() {
    if (head == nullptr) {
        cout << "no records for statistics." << endl;
        return;
    }
    float high = head->marks, low = head->marks, sum = 0;
    int count = 0;
    student* temp = head;
    while (temp != nullptr) {
        if (temp->marks > high) {
            high = temp->marks;
        }
        if (temp->marks < low) {
            low = temp->marks;
        }
        sum += temp->marks;
        count++;
        temp = temp->next;
    }
    cout << "highest: " << high << endl;
    cout << "lowest: " << low << endl;
    cout << "average: " << (sum / count) << endl;
}

int main() {
    int choice, roll, target;
    string name;
    float marks;

    while (true) {
        cout << "\n1. insert beginning\n2. insert end\n3. insert after\n4. delete\n5. display\n6. search\n7. update\n8. stats\n9. exit" << endl;
        cout << "choice: ";
        cin >> choice;

        if (choice == 9) {
            break;
        }

        switch (choice) {
        case 1:
            cout << "roll, name, marks: ";
            cin >> roll >> name >> marks;
            insertatbeginning(roll, name, marks);
            break;
        case 2:
            cout << "roll, name, marks: ";
            cin >> roll >> name >> marks;
            insertatend(roll, name, marks);
            break;
        case 3:
            cout << "target roll, new roll, name, marks: ";
            cin >> target >> roll >> name >> marks;
            insertafter(target, roll, name, marks);
            break;
        case 4:
            cout << "roll to delete: ";
            cin >> roll;
            deleterecord(roll);
            break;
        case 5:
            displayrecords();
            break;
        case 6:
            cout << "roll to search: ";
            cin >> roll;
            searchrecord(roll);
            break;
        case 7:
            cout << "roll to update: ";
            cin >> roll;
            updaterecord(roll);
            break;
        case 8:
            calculatestats();
            break;
        default:
            cout << "invalid choice." << endl;
        }
    }
    return 0;
}