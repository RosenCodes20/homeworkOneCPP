#include <iostream>
#include <vector>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#pragma once

class Library {
    private:
        std::vector<Book> books;
        std::vector<Member> members;
        std::vector<Loan> loans; 
    public:
        void addBook(const Book& b) {
            books.push_back(b);
        }

        void addMember(const Member& m) {
            members.push_back(m);
        }

        bool hasBook(const std::string& isbn) const {
            for (Book b : this->books) {
                if (b.getIsbn() == isbn) {
                    return true;
                }
            }

            return false;
        }

        bool isBookAvailable(const std::string& isbn) const {
            for (Loan l: this->loans) {
                if (l.getIsbn() == isbn && l.getReturned()) {
                    return true;
                } else if (l.getIsbn() == isbn && !l.getReturned()) {
                    return false;
                }
            }

            return "Not find book by this ibn";
        }


};