#include "Library.h"

int main() {
    Librarian librarian("Bob Sherlock", "Head librarian");
    Library library("Library named after Volodymyr Panchenko", "St. Andriy Matvienko, 1-b", librarian);

    Book* book1 = new Book("Charlie and the Chocolate Factory", "Roald Dahl", 1995);
    Novel* novel1 = new Novel("Anna Karenina", "Leo Tolstoy", 1877, "Classical Novel");

    library.addBook(book1);
    library.addBook(novel1);

    library.displayInfo();

    library.removeBook("Anna Karenina");

    std::cout << "After removing a book:" << std::endl;
    library.displayInfo();

    delete book1;
    delete novel1;

    return 0;
}
