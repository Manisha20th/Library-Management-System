#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool available;

    Book(string t, string a) : title(t), author(a), available(true) {}
};

class Library {
private:
    vector<Book> books;

public:
    Library() {
        // Adding some engineering books initially to the library
        books.push_back(Book("Introduction to Algorithms", "Thomas H. Cormen"));
        books.push_back(Book("The C++ Programming Language", "Bjarne Stroustrup"));
        books.push_back(Book("Data Structures and Algorithms Made Easy", "Narasimha Karumanchi"));
        books.push_back(Book("Artificial Intelligence: A Modern Approach", "Stuart Russell and Peter Norvig"));
        books.push_back(Book("Computer Networks", "Andrew S. Tanenbaum"));
        books.push_back(Book("Digital Design", "M. Morris Mano"));
        books.push_back(Book("Operating System Concepts", "Abraham Silberschatz, Greg Gagne, and Peter B. Galvin"));
        books.push_back(Book("Engineering Mathematics", "B.S. Grewal"));
        books.push_back(Book("An Introduction to Electrical Engineering Materials", "C. R. Paul"));
        books.push_back(Book("Mechanics of Materials", "Ferdinand P. Beer and E. Russell Johnston Jr."));
    }

    void addBook(string title, string author) {
        books.push_back(Book(title, author));
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        cout << "---- List of Books ----" << endl;
        for (const Book& book : books) {
            cout << "Title: " << book.title << "\tAuthor: " << book.author;
            cout << "\tStatus: " << (book.available ? "Available" : "Not Available") << endl;
        }
        cout << "-----------------------" << endl;
    }

    Book* findBookByTitle(string title) {
        for (Book& book : books) {
            if (book.title == title) {
                return &book;
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;

    do {
        cout << "\n--- Library Management System ---" << endl;
        cout << "1. Display Books\n2. Search Book\n3. Add New Book\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2:
                cout << "Enter the title of the book: ";
                cin.ignore();
                getline(cin, title);
                {
                    Book* book = library.findBookByTitle(title);
                    if (book != nullptr) {
                        cout << "Book found!" << endl;
                        cout << "Title: " << book->title << "\tAuthor: " << book->author;
                        cout << "\tStatus: " << (book->available ? "Available" : "Not Available") << endl;
                    } else {
                        cout << "Book not found!" << endl;
                    }
                }
                break;
            case 3:
                cout << "Enter title of the book: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author of the book: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            case 4:
                cout << "Thank you for using the Library Management System!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
