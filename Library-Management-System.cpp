#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Book class
class Book {
public:
    string title, author, ISBN;
    bool isAvailable;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isAvailable(true) {}

    void displayBook() {
        cout << left << setw(20) << title << setw(20) << author
             << setw(15) << ISBN << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

// Library class
class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, string ISBN) {
        books.push_back(Book(title, author, ISBN));
    }

    void displayBooks() {
        cout << "\nLibrary Books:\n";
        cout << left << setw(20) << "Title" << setw(20) << "Author"
             << setw(15) << "ISBN" << "Status" << endl;
        for (Book &b : books)
            b.displayBook();
    }

    bool borrowBook(string isbn) {
        for (Book &b : books) {
            if (b.ISBN == isbn && b.isAvailable) {
                b.isAvailable = false;
                cout << "Book borrowed successfully!\n";
                return true;
            }
        }
        cout << "Book not available!\n";
        return false;
    }

    bool returnBook(string isbn) {
        for (Book &b : books) {
            if (b.ISBN == isbn && !b.isAvailable) {
                b.isAvailable = true;
                cout << "Book returned successfully!\n";
                return true;
            }
        }
        cout << "Invalid return request!\n";
        return false;
    }
};

// Main function
int main() {
    Library lib;
    int choice;
    string title, author, isbn;

    // Sample books
    lib.addBook("C++ Programming", "Bjarne Stroustrup", "12345");
    lib.addBook("Data Structures", "Mark Weiss", "67890");

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Display Books\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.displayBooks();
            break;
        case 2:
            cout << "Enter ISBN to borrow: ";
            cin >> isbn;
            lib.borrowBook(isbn);
            break;
        case 3:
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            lib.returnBook(isbn);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
