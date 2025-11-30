#include <iostream>
#pragma once

class Loan {
    private:
        std::string isbn;
        std::string memberId;
        std::string startDate;
        std::string dueDate;
        bool returned;
    public:
        Loan(
            std::string isbn,
            std::string memberId,
            std::string startDate,
            std::string dueDate,
            bool returned
        ) : isbn(isbn), memberId(memberId), 
        startDate(startDate), dueDate(dueDate), returned(returned) {
            if (this->startDate > this->dueDate) {
                throw std::invalid_argument("Start date cannot be after due date");
            }
        }

        std::string getIsbn() const {
            return this->isbn;
        }

        std::string getMemberId() const {
            return this->memberId;
        }

        std::string getStartDate() const {
            return this->startDate;
        }

        std::string getDueDate() const {
            return this->dueDate;
        }

        void setIsbn(std::string isbn) {
            if (isbn.length() == 13) {
                this->isbn = isbn;
            } else {
                throw std::invalid_argument("Not right entered isbn!");
            }
        }

};