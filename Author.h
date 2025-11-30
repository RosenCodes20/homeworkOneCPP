#include <string>
#pragma once
#include <stdexcept>

class Author {
    private:
        std::string name;
        int birthYear;

    public:
        Author() : name("Unknown"), birthYear(1900) {}

        Author(std::string name, int birthYear) : name(name), birthYear(birthYear) {}

        ~Author() = default;

        std::string toString() {
            return "Author name: " + name + " " + "Author Year: " + std::to_string(birthYear);
        }

        void setName(std::string name) {
            this->name = name;
        }

        void setBirthYear(int birthYear) {
            if (this->birthYear >= 1850 && this->birthYear <= 2025) {
                this->birthYear = birthYear;
            } else {
                throw std::invalid_argument("Not right entered birth year!");
            }
        }

        std::string getName() const {
            return this->name;
        }

        int getBirthYear() const {
            return this->birthYear;
        }
};