void Library::returnBook(string memberId, string isbn) {
    for (auto& m : members) {
        if (m.id == memberId) {
            for (auto& b : books) {
                if (b.isbn == isbn && !b.isAvailable) {
                    b.isAvailable = true;
                    auto it = find(m.borrowedBooks.begin(), m.borrowedBooks.end(), isbn);
                    if (it != m.borrowedBooks.end())
                        m.borrowedBooks.erase(it);
                    cout << "Book returned successfully.\n";
                    return;
                }
            }
