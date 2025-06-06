#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    bool isBorrowed = false;

    Book(int id, string title, string author) : id(id), title(title), author(author) {}
};

class User {
public:
    int id;
    string name;
    vector<int> borrowedBooks;

    User(int id, string name) : id(id), name(name) {}
};

class Library {
    vector<Book> books;
    vector<User> users;

public:
    void addBook() {
        int id;
        string title, author;
        cout << "Please Enter the book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Please enter the title of the book: ";
        getline(cin, title);
        cout << "Please enter the author of the book: ";
        getline(cin, author);
        books.push_back(Book(id, title, author));
        cout << "Book added.\n";
    }

    void removeBook() {
        int id;
        cout << "Please Enter the book ID to remove: ";
        cin >> id;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                books.erase(books.begin() + i);
                cout << "The Book has been Succesfully removed.\n";
                return;
            }
        }
        cout << "The Book doesn't exist in our records.\n";
    }

    void searchTitle() {
        string title;
        cin.ignore();
        cout << "Please Enter the title of the book: ";
        getline(cin, title);
        for (Book b : books) {
            if (b.title == title) {
                cout << "Found: " << b.title << " by " << b.author << endl;
            }
        }
    }

    void searchAuthor() {
        string author;
        cin.ignore();
        cout << "Please Enter the author of the book: ";
        getline(cin, author);
        for (Book b : books) {
            if (b.author == author) {
                cout << "Book Found: " << b.title << " by " << b.author << endl;
            }
        }
    }

    void addUser() {
        int id;
        string name;
        cout << "Please Enter the user ID: ";
        cin >> id;
        cin.ignore();
        cout << "Please enter the name of the user: ";
        getline(cin, name);
        users.push_back(User(id, name));
        cout << "User added successfully.\n";
    }

    void borrowBook() {
        int uid, bid;
        cout << "Please Enter the User ID to proceed: ";
        cin >> uid;
        cout << "Please Enter the book ID to borrow: ";
        cin >> bid;
        for (Book &b : books) {
            if (b.id == bid && !b.isBorrowed) {
                for (User &u : users) {
                    if (u.id == uid) {
                        b.isBorrowed = true;
                        u.borrowedBooks.push_back(bid);
                        cout << u.name << " borrowed " << b.title << endl;
                        return;
                    }
                }
            }
        }
        cout << "Book borrowing failed.\n";
    }

    void returnBook() {
        int uid, bid;
        cout << "Please Enter the User ID to proceed: ";
        cin >> uid;
        cout << "Please Enter the book ID to return: ";
        cin >> bid;
        for (Book &b : books) {
            if (b.id == bid && b.isBorrowed) {
                for (User &u : users) {
                    if (u.id == uid) {
                        for (int i = 0; i < u.borrowedBooks.size(); i++) {
                            if (u.borrowedBooks[i] == bid) {
                                u.borrowedBooks.erase(u.borrowedBooks.begin() + i);
                                b.isBorrowed = false;
                                cout << u.name << " returned " << b.title << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
        cout << "Book returning failed.\n";
    }

    void showBooks() {
        for (Book b : books) {
            cout << "[" << b.id << "] " << b.title << " by " << b.author;
            if (b.isBorrowed) cout << " (Borrowed)";
            cout << endl;
        }
    }
};

int main() {
    Library lib;
    int choice;
    while (true) {
        cout << "\nZETECH ONLINE LIBRARY\n";
        cout << "1. Add a Book\n";
        cout << "2. Remove a Book\n";
        cout << "3. Search book by Title\n";
        cout << "4. Search book by Author\n";
        cout << "5. Add New User\n";
        cout << "6. Borrow a book\n";
        cout << "7. Return a book\n";
        cout << "8. Show all books available\n";
        cout << "9. Exit\n";
        cout << "\nPlease make a choice in the menu: ";
        cin >> choice;
        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.removeBook(); break;
            case 3: lib.searchTitle(); break;
            case 4: lib.searchAuthor(); break;
            case 5: lib.addUser(); break;
            case 6: lib.borrowBook(); break;
            case 7: lib.returnBook(); break;
            case 8: lib.showBooks(); break;
            case 9: return 0;
            default: cout << "Invalid Choice, please try again.\n";
        }
    }
}
