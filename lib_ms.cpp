#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

// ----------- Part 1: Data Structures and Core Classes -----------

class Book {
public:
    string title, author, isbn;
    bool isAvailable;

    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = true;
    }

    void display() {
        cout << left << setw(15) << title
             << setw(15) << author
             << setw(15) << isbn
             << setw(10) << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

class Member {
public:
    string name, id;
    vector<string> borrowedBooks;

    Member(string n, string i) {
        name = n;
        id = i;
    }

    void display() {
        cout << left << setw(15) << name << setw(10) << id << "Books: ";
        for (auto& b : borrowedBooks) {
            cout << b << ", ";
        }
        cout << endl;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Book Operations
    void addBook(Book b);
    void removeBook(string isbn);
    void searchBook(string query);
    void listBooks();

    // Member Operations
    void addMember(Member m);
    void removeMember(string id);
    void listMembers();

    // Borrow/Return
    void borrowBook(string memberId, string isbn);
    void returnBook(string memberId, string isbn);

    // Save & Load
    void saveData();
    void loadData();
};

