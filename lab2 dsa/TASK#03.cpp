#include <iostream>
#include <string>
using namespace std;

class libraryitem
{
public:

    virtual void display() = 0;

    virtual ~libraryitem() {}
};

class book : public libraryitem
{

private:
    string title;
    string author;
    int pages;

public:
    book(){
    }
    book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }

    string gettitle() 
    { 
        return title; 
    }
    int getpages() 
    { 
        return pages; 
    }
    void display() override
    {
        cout << "Book is this:" << title << ", Author is this:  " << author << ", Pages is this: " << pages << endl;
    }
};

class newspaper : public libraryitem
{
private:
    string name;
    string date;
    string edition;

public:
    newspaper(){
    }

    newspaper(string n, string d, string e)
    {
        name = n;
        date = d;
        edition = e;
    }
    string getname() 
    {
        return name;
    }
    string getedition() 
    { 
        return edition; 
    }
    void display() override
    {
        cout << "Newspaper is this: " << name << ", Date is this: " << date << ", Edition is this: " << edition << endl;
    }
};
template <class t>

t* linearsearch(t arr[], int size, string key, string(*getkey)(t&))
{
    for (int i = 0; i < size; i++)
    {

        if (getkey(arr[i]) == key)
        {
            return &arr[i];
        }
    }
        return nullptr;
}

template <class t>

t* binarysearch(t arr[], int size, string key, string(*getkey)(t&))
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        string midkey = getkey(arr[mid]);
        if (midkey == key)
        {
            return &arr[mid];
        }
        else if (midkey < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return nullptr;
}

string getbooktitle(book& b) 
{ 
    return b.gettitle();
}
string getnewspapername(newspaper& n)
{ 
    return n.getname(); 
}

class library
{
private:
    book books[10];
    newspaper newspapers[10];
    int bookcount = 0;
    int newspapercount = 0;
    bool bookssortedbytitle = false;
    bool newspaperssortedbyname = false;

public:

    void addbook(book b)
    {
        books[bookcount++] = b;
        bookssortedbytitle = false;
    }

    void addnewspaper(newspaper n)
    {
        newspapers[newspapercount++] = n;
        newspaperssortedbyname = false;
    }

    void displaycollection()
    {
        cout << "The books is this:" << endl;

        for (int i = 0; i < bookcount; i++)
        {
            books[i].display();
        }
        cout << "The newspapers is :" << endl;

        for (int i = 0; i < newspapercount; i++)
        {
            newspapers[i].display();
        }
    }
    void sortbooksbypages()
    {
        for (int i = 0; i < bookcount - 1; i++)
        {
            for (int j = i + 1; j < bookcount; j++)
            {
                if (books[i].getpages() > books[j].getpages())
                {
                    swap(books[i], books[j]);
                }
            }
        }
    }
    void sortbooksbytitle()
    {
        for (int i = 0; i < bookcount - 1; i++)
        {
            for (int j = i + 1; j < bookcount; j++)
            {
                if (books[i].gettitle() > books[j].gettitle())
                {
                    swap(books[i], books[j]);
                }
            }
        }
        bookssortedbytitle = true;
    }
    void sortnewspapersbyedition()
    {
        for (int i = 0; i < newspapercount - 1; i++)
        {
            for (int j = i + 1; j < newspapercount; j++)
            {
                if (newspapers[i].getedition() > newspapers[j].getedition())
                {
                    swap(newspapers[i], newspapers[j]);
                }
            }
        }

    }
    void sortnewspapersbyname()
    {
        for (int i = 0; i < newspapercount - 1; i++)
        {
            for (int j = i + 1; j < newspapercount; j++)
            {
                if (newspapers[i].getname() > newspapers[j].getname())
                {
                    swap(newspapers[i], newspapers[j]);
                    
                }
            }
        }
        newspaperssortedbyname = true;
    }

    book* searchbookbytitlelinear(string title)
    {
        return linearsearch(books, bookcount, title, getbooktitle);
    }

    book* searchbookbytitlebinary(string title)
    {
        if (!bookssortedbytitle)
        {
            sortbooksbytitle();
        }
            return binarysearch(books, bookcount, title, getbooktitle);
    }

    newspaper* searchnewspaperbynamelinear(string name)
    {
        return linearsearch(newspapers, newspapercount, name, getnewspapername);
    }

    newspaper* searchnewspaperbynamebinary(string name)
    {
        if (!newspaperssortedbyname)
        {
            sortnewspapersbyname();
        }
        return binarysearch(newspapers, newspapercount, name, getnewspapername);
    }
};

int main()
{
    book book1(" the catcher in the rye", "j.d. salinger", 277);
    book book2(" to kill a mockingbird", "harper lee", 324);
    book book3(" 1984", "george orwell", 328);
    book book4(" pride and prejudice", "jane austen", 279);

    newspaper newspaper1(" washington post", "2024-10-13", "morning edition");
    newspaper newspaper2(" the times", "2024-10-12", "weekend edition");
    newspaper newspaper3(" the guardian", "2024-10-11", "evening edition");

    library library;

    library.addbook(book1);
    library.addbook(book2);
    library.addbook(book3);
    library.addbook(book4);

    library.addnewspaper(newspaper1);
    library.addnewspaper(newspaper2);
    library.addnewspaper(newspaper3);

    cout << "initial collection:" << endl;
    library.displaycollection();

    library.sortbooksbypages();
    library.sortnewspapersbyedition();

    cout << "collection after sorting by pages edition:" << endl;
    library.displaycollection();

    string booktitlesearch = "1984";
    book* linearbook = library.searchbookbytitlelinear(booktitlesearch);
    if (linearbook)
    {
        cout << "linear search found book: " << booktitlesearch << endl;
        linearbook->display();
    }
    else
        cout << "linear search book not found: " << booktitlesearch << endl;

    string newspapernamesearch = "the guardian";
    newspaper* linearnewspaper = library.searchnewspaperbynamelinear(newspapernamesearch);
    if (linearnewspaper)
    {
        cout << "linear search found newspaper: " << newspapernamesearch << endl;
        linearnewspaper->display();
    }
    else
        cout << "linear search newspaper not found: " << newspapernamesearch << endl;

    string binarybooksearch = "pride and prejudice";
    book* binarybook = library.searchbookbytitlebinary(binarybooksearch);
    if (binarybook)
    {
        cout << "binary search found book: " << binarybooksearch << endl;
        binarybook->display();
    }
    else
        cout << "binary search book not found: " << binarybooksearch << endl;

    string binarynewspapersearch = "the times";
    newspaper* binarynewspaper = library.searchnewspaperbynamebinary(binarynewspapersearch);
    if (binarynewspaper)
    {
        cout << "binary search found newspaper: " << binarynewspapersearch << endl;
        binarynewspaper->display();
    }
    else
        cout << "binary search newspaper not found: " << binarynewspapersearch << endl;

    return 0;
}