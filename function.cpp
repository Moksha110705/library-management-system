        }
    }
    cout << "Return failed. Check Member ID or ISBN.\n";
}

// ----------- Part 4: Main Menu + File Handling + Bonus Features -----------

void Library::saveData() {
    ofstream fout("library_data.txt");
    for (auto& b : books)
        fout << "B," << b.title << "," << b.author << "," << b.isbn << "," << b.isAvailable << "\n";
    for (auto& m : members) {
        fout << "M," << m.name << "," << m.id;
        for (auto& isbn : m.borrowedBooks)
            fout << "," << isbn;
        fout << "\n";
    }
    fout.close();
    cout << "Data saved.\n";
}

void Library::loadData() {
    ifstream fin("library_data.txt");
    string line;
    while (getline(fin, line)) {
        if (line[0] == 'B') {
            string t, a, i;
            bool avail;
            sscanf(line.c_str(), "B,%[^,],%[^,],%[^,],%d", &t[0], &a[0], &i[0], &avail);
            Book b(t, a, i);
            b.isAvailable = avail;
            books.push_back(b);
        } else if (line[0] == 'M') {
            vector<string> tokens;
            size_t pos = 0;
            while ((pos = line.find(',')) != string::npos) {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            Member m(tokens[1], tokens[2]);
            for (size_t i = 3; i < tokens.size(); ++i)

int main() {
    Library lib;
    lib.loadData();
    int choice;
    string title, author, isbn, id, name, query;

    while (true) {
        cout << "\n--- Library Menu ---\n"
             << "1. Add Book\n2. Remove Book\n3. List Books\n4. Search Book\n"
             << "5. Add Member\n6. Remove Member\n7. List Members\n"
             << "8. Borrow Book\n9. Return Book\n10. Save & Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Title: "; cin >> title;
            cout << "Author: "; cin >> author;
            cout << "ISBN: "; cin >> isbn;
            lib.addBook(Book(title, author, isbn));
            break;
        case 2:
            cout << "ISBN to remove: "; cin >> isbn;
            lib.removeBook(isbn);
            break;
        case 3:
            lib.listBooks();
            break;
        case 4:
            cout << "Search Query: "; cin >> query;
            lib.searchBook(query);
            break;
        case 5:
            cout << "Name: "; cin >> name;
            cout << "ID: "; cin >> id;
            lib.addMember(Member(name, id));
            break;
        case 6:
            cout << "ID to remove: "; cin >> id;
            lib.removeMember(id);
            break;
        case 7:
            lib.listMembers();
            break;
        case 8:
            cout << "Member ID: "; cin >> id;
            cout << "ISBN: "; cin >> isbn;
            lib.borrowBook(id, isbn);
            break;
        case 9:
            cout << "Member ID: "; cin >> id;
            cout << "ISBN: "; cin >> isbn;
            lib.returnBook(id, isbn);
            break;
        case 10:
            lib.saveData();
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}

