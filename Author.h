//
// Created by alex on 7. 10. 20.
//

#ifndef TASK0401_AUTHOR_H
#define TASK0401_AUTHOR_H

#include <iostream>

class Author {
private:
    std::string name, email;
    char gender;

public:
    Author();
    Author(std::string name, std::string email, const char& gender);
    Author(const Author& a);
    ~Author();

    void set_name(const std::string& n);
    void set_email(const std::string& e);
    void set_gender(const char& gender);

    const std::string get_name() const;
    const std::string get_email() const;
    const char get_gender() const;

    const std::string to_string() const;
};


#endif //TASK0401_AUTHOR_H
