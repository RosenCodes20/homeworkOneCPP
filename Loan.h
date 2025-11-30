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

        void setMemberId(std::string memberId) {
            if (memberId.empty() || memberId.length() != 10) {
                throw std::invalid_argument("Not entered id, or id length is not 10!");
            } else {
                this->memberId = memberId;
            }
        }

        void setStartDate(std::string startDate) {
            this->startDate = startDate;
        }

        void setDueDate(std::string dueDate) {
            this->dueDate = dueDate;
        }

        void markReturned() {
            this->returned = true;
        }

        bool isOverdue(const std::string& today) const {
            return !returned && today > dueDate;
        }
};