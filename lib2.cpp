void Library::addMember(Member m) {
    members.push_back(m);
    cout << "Member added successfully.\n";
}

void Library::removeMember(string id) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->id == id) {
            members.erase(it);
            cout << "Member removed.\n";
            return;
        }
    }
    cout << "Member not found.\n";
}

void Library::listMembers() {
    cout << "=== Member List ===\n";
    for (auto& m : members)
        m.display();
}

