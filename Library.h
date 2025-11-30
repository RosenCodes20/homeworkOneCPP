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
            for (Book& b : this->books) {
                if (b.getIsbn() == isbn) {
                    return true;
                }
            }

            return false;
        }

        bool isBookAvailable(const std::string& isbn) const {
            for (Loan& l: this->loans) {
                if (l.getIsbn() == isbn && l.getReturned()) {
                    return true;
                } else if (l.getIsbn() == isbn && !l.getReturned()) {
                    return false;
                }
            }

            return "Not find book by this ibn";
        }

        bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
            if (!hasBook(isbn)) return false;

            bool memberExists = false;
            for (Member& m : members) {
                if (m.getMemberId() == memberId) {
                    memberExists = true;
                    break;
                }
            }
            if (!memberExists) return false;

            if (!isBookAvailable(isbn)) return false;

            loans.emplace_back(isbn, memberId, start, due, false);
            return true;
        }

        bool returnBook(const std::string& isbn, const std::string& memberId) {
            for (Loan& l : this->loans) {
                if (l.getIsbn() == isbn && l.getMemberId() == memberId && !l.getReturned()) {
                    l.markReturned();
                    return true;
                }
            }

            return false;
        }

        vector<Book> findByAuthor(const string& authorName) const {
            for (Book& b : this->books) {
                if (b.getAuthor().getName() == authorName) {
                    return b;
                }
            }
        }

        std::string to_string() const {
        int activeLoans = 0;
        for (Loan& loan : loans) {
            if (!loan.isReturned()) activeLoans++;
        }

        return "Library info:\n" +
               std::string("Total books: ") + std::to_string(books.size()) + "\n" +
               "Total members: " + std::to_string(members.size()) + "\n" +
               "Active loans: " + std::to_string(activeLoans) + "\n";
    }
};