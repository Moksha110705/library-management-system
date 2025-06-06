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
