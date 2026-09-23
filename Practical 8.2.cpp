#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

int binarySearch(Book books[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (books[mid].id == key) {
            return mid;
        }
        else if (books[mid].id < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, searchId;

    cout << "Enter number of books: ";
    cin >> n;

    Book books[n];

    cout << "\nEnter book details in ascending order of Book ID:\n";

    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << ":\n";

        cout << "Book ID: ";
        cin >> books[i].id;

        cin.ignore();

        cout << "Book Title: ";
        getline(cin, books[i].title);

        cout << "Author Name: ";
        getline(cin, books[i].author);
    }

    cout << "\nEnter Book ID to search: ";
    cin >> searchId;

    int result = binarySearch(books, n, searchId);

    if (result != -1) {
        cout << "\nBook Found!\n";
        cout << "Book ID: " << books[result].id << endl;
        cout << "Title: " << books[result].title << endl;
        cout << "Author: " << books[result].author << endl;
    }
    else {
        cout << "\nBook not found.\n";
    }

    return 0;
}

