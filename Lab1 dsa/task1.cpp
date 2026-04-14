#include <iostream>
using namespace std;

class libraryitem {
protected:
    int id;
    string title;

public:
    void setdata(int i, string t) {
        id = i;
        title = t;
    }

    int getid() {
        return id;
    }

    virtual void display() {
        cout << "id: " << id << ", title: " << title << endl;
    }
};

class book : public libraryitem {
private:
    string author;
    bool issued;

public:
    void setbook(int i, string t, string a) {
        setdata(i, t);
        author = a;
        issued = false;
    }

    void issuebook() {
        if (!issued) {
            issued = true;
            cout << "book issued successfully!" << endl;
        }
        else {
            cout << "book already issued!" << endl;
        }
    }

    void returnbook() {
        if (issued) {
            issued = false;
            cout << "book returned successfully!" << endl;
        }
        else {
            cout << "book was not issued!" << endl;
        }
    }

    void display() override {
        cout << "id: " << id
            << ", title: " << title
            << ", author: " << author
            << ", status: " << (issued ? "issued" : "available")
            << endl;
    }
};

class library {
private:
    book books[100];
    int count;

public:
    void init() {
        count = 0;
    }

    void addbook(int id, string title, string author) {
        if (count < 100) {
            books[count].setbook(id, title, author);
            count++;
            cout << "book added successfully!" << endl;
        }
        else {
            cout << "library is full!" << endl;
        }
    }

    void showbooks() {
        if (count == 0) {
            cout << "no books available." << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            books[i].display();
        }
    }

    void issuebook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].getid() == id) {
                books[i].issuebook();
                return;
            }
        }
        cout << "book not found!" << endl;
    }

    void returnbook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].getid() == id) {
                books[i].returnbook();
                return;
            }
        }
        cout << "book not found!" << endl;
    }
};

int main() {
    library lib;
    lib.init();

    int choice, id;
    string title, author;

    do {
        cout << endl << "--- library menu ---" << endl;
        cout << "1. add book" << endl;
        cout << "2. show books" << endl;
        cout << "3. issue book" << endl;
        cout << "4. return book" << endl;
        cout << "5. exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter id: ";
            cin >> id;
            cin.ignore();
            cout << "enter title: ";
            getline(cin, title);
            cout << "enter author: ";
            getline(cin, author);
            lib.addbook(id, title, author);
            break;

        case 2:
            lib.showbooks();
            break;

        case 3:
            cout << "enter book id to issue: ";
            cin >> id;
            lib.issuebook(id);
            break;

        case 4:
            cout << "enter book id to return: ";
            cin >> id;
            lib.returnbook(id);
            break;

        case 5:
            cout << "exiting..." << endl;
            break;

        default:
            cout << "invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}