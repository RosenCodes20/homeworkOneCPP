#include <iostream>
#pragma once

class Member {
    private:
        std::string name;
        std::string memberId;
        int yearJoined;

    public:
        Member() : name("Rosen Ivanov"), 
        memberId("1251121252"), yearJoined(2018) {}

        Member(std::string name, std::string memberId, int yearJoined) :
        name(name), memberId(memberId), yearJoined(yearJoined) {
            setName(name);
            setMemberId(memberId);
            setYearJoined(yearJoined);
        }

        std::string getName() const {
            return this->name;
        }

        std::string getMemberId() const {
            return this->memberId;
        }

        int getYearJoined() const {
            return this->yearJoined;
        }

        void setName(std::string name) {
            if (name.empty()) {
                throw std::invalid_argument("Please enter a name next time :)");
            } else {
                this->name = name;
            }
        }

        void setMemberId(std::string memberId) {
            if (memberId.empty() || memberId.length() != 10) {
                throw std::invalid_argument("Not entered id, or id length is not 10!");
            } else {
                this->memberId = memberId;
            }
        }

        void setYearJoined(int yearJoined) {
            this->yearJoined = yearJoined;
        }

        std::string to_string() const {
            return "Member name: " + this->name + "\n" +
                   "Member id: " + this->memberId + "\n" +
                   "Member year joined: " + std::to_string(this->yearJoined);
        }
};