#include <iostream>
#pragma once
#include "Author.h"

class Book{
    private:
        std::string title;
        Author author;
        int year;
        double price;
        std::string isbn;
        static int totalBooks;

    public:
        Book() : title("Pod Igoto"), 
        author(Author{"Ivan Vazov", 1924}), 
        year(1956), price(20), isbn("0-306-40615-2") {++totalBooks;}

        Book(std::string title, 
        Author author, int year, double price, std::string isbn) 
        : title(title), author(author), year(year), price(price), isbn(isbn) {++totalBooks;}

        Book(const Book& other) : title(other.title), 
        author(other.author), 
        year(other.year), price(other.price), isbn(other.isbn)  {
            ++totalBooks;
            if (isbn.length() != 13) {
                throw std::invalid_argument("Not right entered isbn");
            }
            }

        Book(Book&& other) noexcept
            : title(std::move(other.title)),
            author(std::move(other.author)),
            year(other.year),price(other.price),
            isbn(std::move(other.isbn)) {
                ++totalBooks;
                other.year=0;
                other.price = 0;
            }

        Book& operator=(const Book& other) {
            if (this != &other) {
                title  = other.title;
                author = other.author;
                year   = other.year;
                price  = other.price;
                isbn   = other.isbn;
            }
            return *this;
        }

        Book& operator=(Book&& other) noexcept {
            if (this != &other) {
                title  = std::move(other.title);
                author = std::move(other.author);
                year   = other.year;
                price  = other.price;
                isbn   = std::move(other.isbn);

                other.year = 0;
                other.price = 0;
            }
            return *this;
        }

        ~Book() = default;

        std::string getTitle() const {
            return this->title;
        }

        Author getAuthor() const {
            return this->author;
        }

        int getYear() const {
            return this->year;
        }

        double getPrice() const {
            return this->price;
        }

        std::string getIsbn() const {
            return this->isbn;
        }

        static int getTotalBooks() {
            return totalBooks;
        }

        void setTitle(std::string title) {
            this->title = title;
        }

        void setAuthor(Author author) {
            this->author = author;
        }

        void setYear(int year) {
            if (year >= 1850 && year <= 2025) {
                this->year = year;
            } else {
                throw std::invalid_argument("Not right entered year!");
            }
        }

        void setPrice(double price) {
            if (price >= 0) {
                this->price = price;
            } else {
                throw std::invalid_argument("Not right entered price!");
            }
        }

        void setIsbn(std::string isbn) {
            if (isbn.length() == 13) {
                this->isbn = isbn;
            } else {
                throw std::invalid_argument("Not right entered isbn");
            }
        }

        std::string to_string() const {
            return "Title: " + this->title + "\n" +
                   "Author name: " + this->author.getName() + "\n" +
                   "Author birth year: " + std::to_string(this->author.getBirthYear()) + "\n" +
                   "Book year: " + std::to_string(this->year) + "\n" +
                   "Book price: " + std::to_string(this->price) + "\n" +
                   "Book isbn: " + this->isbn + "\n" + 
                   "Total Book counts " + std::to_string(this->totalBooks) + "\n";
        }

};

inline int Book::totalBooks = 0;