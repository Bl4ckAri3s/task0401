//
// Created by alex on 7. 10. 20.
//

#include "Author.h"
#include <sstream>
#include <utility>


Author::Author() : name("Unknown"), email("None"), gender('U') {
}

Author::Author(std::string  name, std::string  email, const char& gender) : name(std::move(name)), email(std::move(email)), gender(gender) {
}

Author::Author(const Author& a) : name(a.name), email(a.email), gender(a.gender) {
}

Author::~Author() {
}


void Author::set_name(const std::string& n) {
    this->name = n;
}

void Author::set_email(const std::string& e) {
    this->email = e;
}

void Author::set_gender(const char& g) {
    this->gender = g;
}


const std::string Author::get_name() const {
    return name;
}

const std::string Author::get_email() const {
    return email;
}

const char Author::get_gender() const {
    return gender;
}


const std::string Author::to_string() const {
    std::stringstream ss;

    ss << "Name: " << name;
    ss << "\nEmail: " << email;
    ss << "\nGender: " << gender;

    return ss.str();
}