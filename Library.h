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
            for (const Book& b : this->books) {
                if (b.getIsbn() == isbn) {
                    return true;
                }
            }

            return false;
        }

        bool isBookAvailable(const std::string& isbn) const {
            for (const Loan& l : loans) {
                if (l.getIsbn() == isbn && !l.getReturned()) {
                    return false;
                }
            }
            return true;  
        }

        bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
            if (!hasBook(isbn)) return false;

            bool memberExists = false;
            for (const Member& m : members) {
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

        std::vector<Book> findByAuthor(const std::string& authorName) const {
            std::vector<Book> result;
            for (const Book& b : this->books) {
                if (b.getAuthor().getName() == authorName) {
                    result.push_back(b);
                }
            }

            return result;
        }

        std::string to_string() const {
        int activeLoans = 0;
        for (const Loan& loan : loans) {
            if (!loan.getReturned()) activeLoans++;
        }

        return "Library info:\n" +
               std::string("Total books: ") + std::to_string(books.size()) + "\n" +
               "Total members: " + std::to_string(members.size()) + "\n" +
               "Active loans: " + std::to_string(activeLoans) + "\n";
    }
};