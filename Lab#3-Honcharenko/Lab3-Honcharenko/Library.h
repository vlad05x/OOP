#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Librarian {
private:
    string name;
    string position;

public:
    Librarian(string name, string position)
        : name(name), position(position) {}

    string getName() const {
        return name;
    }

    string getPosition() const {
        return position;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setPosition(const string& newPosition) {
        position = newPosition;
    }

    void displayInfo() const {
        cout << "Librarian: " << name << ", Position: " << position << endl;
    }
};

class Book {
protected:
    string title;
    string author;
    int publicationYear;

public:
    Book(string title, string author, int publicationYear)
        : title(title), author(author), publicationYear(publicationYear) {}

    virtual ~Book() {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getPublicationYear() const {
        return publicationYear;
    }

    void setTitle(const string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const string& newAuthor) {
        author = newAuthor;
    }

    void setPublicationYear(int newYear) {
        publicationYear = newYear;
    }

    virtual void displayInfo() const {
        cout << "Title: " << title << ", Author: " << author
             << ", Year: " << publicationYear << endl;
    }
};

class Novel : public Book {
private:
    string genre;

public:
    Novel(string title, string author, int publicationYear, string genre)
        : Book(title, author, publicationYear), genre(genre) {}

    ~Novel() override {}

    string getGenre() const {
        return genre;
    }

    void setGenre(const string& newGenre) {
        genre = newGenre;
    }

    void displayInfo() const override {
        cout << "Novel - Title: " << title << ", Author: " << author
             << ", Year: " << publicationYear << ", Genre: " << genre << endl;
    }
};

class Library {
private:
    string name;
    string address;
    vector<Book*> books;
    Librarian librarian;

public:
    Library(string name, string address, Librarian librarian)
        : name(name), address(address), librarian(librarian) {}

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    Librarian getLibrarian() const {
        return librarian;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setAddress(const string& newAddress) {
        address = newAddress;
    }

    void setLibrarian(const Librarian& newLibrarian) {
        librarian = newLibrarian;
    }

    void addBook(Book* book) {
        books.push_back(book);
    }

    void removeBook(const string& bookTitle) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i]->getTitle() == bookTitle) {
                books.erase(books.begin() + i);
                break;
            }
        }
    }

    void displayInfo() const {
        cout << "Library: " << name << ", Address: " << address << endl;
        librarian.displayInfo();
        cout << "Books available in the library:" << endl;
        for (const Book* book : books) {
            book->displayInfo();
        }
    }
};

#endif
