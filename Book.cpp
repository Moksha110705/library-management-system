void Library::addBook(Book b) {
    books.push_back(b);
    cout << "Book added successfully.\n";
}
  
void Library::removeBook(string isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == isbn) {
            books.erase(it);
            cout << "Book removed.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::searchBook(string query) {
    cout << "=== Search Results ===\n";
    for (auto& b : books) {
        if (b.title.find(query) != string::npos || b.author.find(query) != string::npos)
            b.display();
    }
}

void Library::listBooks() {
    cout << "=== Book List ===\n";
    for (auto& b : books)
        b.display();
}

void Library::borrowBook(string memberId, string isbn) {
    for (auto& m : members) {
        if (m.id == memberId) {
            for (auto& b : books) {
                if (b.isbn == isbn && b.isAvailable) {
                    b.isAvailable = false;
                    m.borrowedBooks.push_back(isbn);
                    cout << "Book borrowed successfully.\n";
                    return;
                }
            }
        }
    }
    cout << "Borrow failed. Check Member ID or ISBN.\n";
}

