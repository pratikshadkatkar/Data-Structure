#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

int main() {
    int n, choice, searchId;
    string searchText;
    bool found = false;

    cout << "Enter number of books: ";
    cin >> n;

    Book books[n];

    // Input book details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Book " << i + 1 << ":\n";

        cout << "Book ID: ";
        cin >> books[i].id;

        cin.ignore();

        cout << "Book Title: ";
        getline(cin, books[i].title);

        cout << "Author Name: ";
        getline(cin, books[i].author);
    }

    // Search menu
    cout << "\n===== SEARCH BOOK =====\n";
    cout << "1. Search by Book ID\n";
    cout << "2. Search by Title\n";
    cout << "3. Search by Author Name\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Search by ID
    if (choice == 1) {
        cout << "Enter Book ID: ";
        cin >> searchId;

        for (int i = 0; i < n; i++) {
            if (books[i].id == searchId) {
                cout << "\nBook Found!\n";
                cout << "ID: " << books[i].id << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                found = true;
                break;
            }
        }
    }

    // Search by Title
    else if (choice == 2) {
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, searchText);

        for (int i = 0; i < n; i++) {
            if (books[i].title == searchText) {
                cout << "\nBook Found!\n";
                cout << "ID: " << books[i].id << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                found = true;
                break;
            }
        }
    }

    // Search by Author
    else if (choice == 3) {
        cin.ignore();

        cout << "Enter Author Name: ";
        getline(cin, searchText);

        for (int i = 0; i < n; i++) {
            if (books[i].author == searchText) {
                cout << "\nBook Found!\n";
                cout << "ID: " << books[i].id << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                found = true;
                break;
            }
        }
    }

    else {
        cout << "Invalid choice!\n";
        return 0;
    }

    if (!found) {
        cout << "\nBook not found.\n";
    }

    return 0;
}

