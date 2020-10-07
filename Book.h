//
// Created by alex on 7. 10. 20.
//

#ifndef TASK0401_BOOK_H
#define TASK0401_BOOK_H
#include "Author.h"
#include <iostream>
#include <vector>
#include <memory>

class Book {
private:
    std::string title;
    std::string publisher;
    int pages;
    double price;
    int id;
    static int id_counter;
    std::vector<std::unique_ptr<Author>> authors;

public:
    Book();
    Book(const std::string& title1, const std::string& publisher1, const int& pages1, const double& price1);
    Book(const Book& t);
    ~Book();

    // Set
    void set_title(const std::string& title);
    void set_publisher(const std::string& publisher);
    void set_pages(const int& pages);
    void set_price(const double& price);

    // Get
    const std::string get_title();
    const std::string get_publisher();
    const int get_pages();
    const double get_price();
    const int get_id();
    static int get_id_counter();

    const void print() const;
    const std::string to_string();

    void add_author(Author* author);
    const std::string get_author_names() const;

    static Book create_demo_book();
};


#endif //TASK0401_BOOK_H
