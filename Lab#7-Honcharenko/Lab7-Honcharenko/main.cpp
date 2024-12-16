#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year;
    string isbn;

    Book(const string& title, const string& author, int year, const string& isbn)
        : title(title), author(author), year(year), isbn(isbn) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBookByISBN(const string& isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].isbn == isbn) {
                books.erase(books.begin() + i);
                i--;
            }
        }
    }

    void searchByAuthor(const string& author) {
        cout << "Books by " << author << ":\n";
        for (int i = 0; i < books.size(); i++) {
            if (books[i].author == author) {
                cout << "Title: " << books[i].title << ", Year: " << books[i].year << ", ISBN: " << books[i].isbn << '\n';
            }
        }
    }

    void searchByYear(int year) {
        cout << "Books published in " << year << ":\n";
        for (int i = 0; i < books.size(); i++) {
            if (books[i].year == year) {
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", ISBN: " << books[i].isbn << '\n';
            }
        }
    }

    void printLibrary() {
        cout << "Library books:\n";
        for (int i = 0; i < books.size(); i++) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << ", ISBN: " << books[i].isbn << '\n';
        }
    }
};

int main() {
    Library library;

    library.addBook(Book("Charlie and the Chocolate Factory", "Roald Dahl", 1964, "9780142410318"));
    library.addBook(Book("After", "Rina Kunce", 2017, "9785487018433"));
    library.addBook(Book("Think and Grow Rich", "Napoleon Hill", 1937, "9780974192581"));
    library.addBook(Book("Never Eat Alone", "Keith Ferrazzi", 2005, "9780385516022"));

    library.printLibrary();

    cout << "\nRemoving book with ISBN 9785487018433...\n";
    library.removeBookByISBN("9785487018433");

    library.printLibrary();

    library.searchByAuthor("Napoleon Hill");

    library.searchByYear(1937);

    return 0;
}
