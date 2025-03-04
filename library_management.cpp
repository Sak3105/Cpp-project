#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool isAvailable;

public:
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool isBookAvailable() const {
        return isAvailable;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "You have borrowed \"" << title << "\" by " << author << "." << endl;
        } else {
            cout << "Sorry, \"" << title << "\" is currently not available." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "You have returned \"" << title << "\" by " << author << "." << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book \"" << book.getTitle() << "\" added to the library." << endl;
    }

    void viewBooks() const {
        cout << "\nAvailable Books:\n";
        for (const auto& book : books) {
            cout << "\"" << book.getTitle() << "\" by " << book.getAuthor();
            if (book.isBookAvailable()) {
                cout << " (Available)";
            } else {
                cout << " (Not Available)";
            }
            cout << endl;
        }
    }

    void borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.borrowBook();
                return;
            }
        }
        cout << "Book \"" << title << "\" not found in the library." << endl;
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook();
                return;
            }
        }
        cout << "Book \"" << title << "\" not found in the library." << endl;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;

    do {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(Book(title, author));
                break;
            case 2:
                library.viewBooks();
                break;
            case 3:
                cout << "Enter the title of the book to borrow: ";
                getline(cin, title);
                library.borrowBook(title);
                break;
            case 4:
                cout << "Enter the title of the book to return: ";
                getline(cin, title);
                library.returnBook(title);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
