#include <iostream>
#include "Author.h"
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "Library.h"

int main() {
    Author a1;
    Author a2("J.K. Rowling", 1965);
    Author a3 = a2;
    a3.setName("Changed Author");
    a3.setBirthYear(1970);

    Book b1;
    Book b2("Harry Potter", a2, 1997, 29.99, "9780545010221");
    Book b3 = b2;
    Book b4 = std::move(b3);

    b4.setTitle("Harry Potter Updated");
    b4.setYear(1998);
    b4.setPrice(35.50);

    Member m1;

    std::cout << m1.to_string() << "\n\n";

    Member m2("John Doe", "1234567890", 2020);
    m2.setName("John D.");
    m2.setMemberId("0987654321");

    Loan l1("9780545010221", "0987654321", "2024-05-01", "2024-05-20", false);
    Loan l2("0-306-40615-2", "1251121252", "2024-04-01", "2024-04-10", false);


    Library lib;
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b4);

    lib.addMember(m1);
    lib.addMember(m2);

    std::cout  << "Has book?: " << lib.hasBook("9780545010221") << "\n";
    
    std::cout << "\n" << "Is book available: " << lib.isBookAvailable("9780545010221") << "\n";
    std::cout << "\n" << "Is book loaned: " << lib.loanBook("9780545010221", "0987654321", "2024-05-01", "2024-05-20") << "\n";
    std::cout << "\n" << "Is book loaned: " << lib.loanBook("0-306-40615-2", "1251121252", "2024-05-02", "2024-05-25") << "\n";

    std::cout << "\nIs book returned: " << lib.returnBook("9780545010221", "0987654321") << "\n";

    std::vector<Book> found = lib.findByAuthor("Rowling");

    std::cout << "Found books: " << found.size() << "\n";
    for (const Book& b : found) {
        std::cout << b.to_string() << "\n";
    }

    std::cout << lib.to_string();

    return 0;
}
