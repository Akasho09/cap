#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string isbn;

public:
    Book(string t, string a, string i)
        : title(t), author(a), isbn(i) {}

    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
};

enum class BookStatus { AVAILABLE, ISSUED };

class BookCopy {
    Book* book;
    int copyId;
    BookStatus status;

public:
    BookCopy(Book* b, int id)
        : book(b), copyId(id), status(BookStatus::AVAILABLE) {}

    bool isAvailable() const {
        return status == BookStatus::AVAILABLE;
    }

    void issue() { status = BookStatus::ISSUED; }
    void returned() { status = BookStatus::AVAILABLE; }

    string getISBN() const {
        return book->getISBN();
    }
};

class Member {
protected:
    int memberId;
    string name;

public:
    Member(int id, string n) : memberId(id), name(n) {}
    virtual int getMaxBooksAllowed() const = 0;
};


class Student : public Member {
public:
    Student(int id, string n) : Member(id, n) {}
    int getMaxBooksAllowed() const override { return 3; }
};

class Faculty : public Member {
public:
    Faculty(int id, string n) : Member(id, n) {}
    int getMaxBooksAllowed() const override { return 5; }
};

class Library {
    vector<Book*> books;
    vector<BookCopy*> copies;
    vector<Member*> members;

public:
    void addBook(Book* book, int numberOfCopies) {
        books.push_back(book);
        for (int i = 0; i < numberOfCopies; i++) {
            copies.push_back(new BookCopy(book, copies.size() + 1));
        }
    }

    BookCopy* searchAvailableCopy(string isbn) {
        for (auto copy : copies) {
            if (copy->getISBN() == isbn && copy->isAvailable()) {
                return copy;
            }
        }
        return nullptr;
    }

    bool issueBook(Member* member, string isbn) {
        BookCopy* copy = searchAvailableCopy(isbn);
        if (!copy) return false;

        copy->issue();
        return true;
    }

    void returnBook(BookCopy* copy) {
        copy->returned();
    }
};

int main() {
    // Create Library
    Library library;

    // Create Books
    Book* cppBook = new Book("C++ Programming", "Bjarne Stroustrup", "ISBN001");
    Book* dsaBook = new Book("Data Structures", "CLRS", "ISBN002");

    // Add books to library (with copies)
    library.addBook(cppBook, 3);
    library.addBook(dsaBook, 2);

    // Create Members
    Member* student1 = new Student(1, "Akash");
    Member* faculty1 = new Faculty(2, "Dr. Sharma");

    // Issue Books
    cout << "Issuing C++ book to student...\n";
    if (library.issueBook(student1, "ISBN001"))
        cout << "Book issued successfully\n";
    else
        cout << "Book issue failed\n";

    cout << "Issuing DSA book to faculty...\n";
    if (library.issueBook(faculty1, "ISBN002"))
        cout << "Book issued successfully\n";
    else
        cout << "Book issue failed\n";

    // Try issuing unavailable book
    cout << "Issuing DSA book again...\n";
    if (library.issueBook(student1, "ISBN002"))
        cout << "Book issued successfully\n";
    else
        cout << "No available copies\n";

    return 0;
}