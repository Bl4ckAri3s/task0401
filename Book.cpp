//
// Created by alex on 7. 10. 20.
//

#include "Book.h"
#include <sstream>
#include <random>

int Book::id_counter = 10000;

Book::Book() : title(""), publisher(""), pages(), price(0) {
    authors.emplace_back(std::make_unique<Author>());
    id = id_counter++;
}


Book::Book(const std::string& title1, const std::string& publisher1, const int& pages1, const double& price1, std::unique_ptr<Author> author) : title(title1), publisher(publisher1), pages(pages1), price(price1) {
    authors.emplace_back(std::move(author));
    id = id_counter++;
}

Book::Book(const Book& b) : title(b.title), publisher(b.publisher), pages(b.pages), price(b.price) {
    id_counter++;
}

Book::~Book() {
}


void Book::set_title(const std::string &title) {
    this->title = title;
}

void Book::set_publisher(const std::string& publisher) {
    this->publisher = publisher;
}

void Book::set_pages(const int& pages) {
    this->pages = pages;
}

void Book::set_price(const double& price) {
    this->price = price;
}


const std::string Book::get_title() {
    return title;
}

const std::string Book::get_publisher() {
    return publisher;
}

const int Book::get_pages() {
    return pages;
}

const double Book::get_price() {
    return price;
}

const int Book::get_id() {
    return id;
}

const void Book::print() const {
    std::cout << "=== Book info ===";
    std::cout << "\nTitle: " << title;
    std::cout << "\nPublisher: " << publisher;
    std::cout << "\nPages: " << pages;
    std::cout << "\nPrice: " << price;
    std::cout << "\nID: " << id;
}

const std::string Book::to_string() {
    std::stringstream ss;

    ss << "=== Book info ===";
    ss << "\nTitle: " << title;
    ss << "\nPublisher: " << publisher;
    ss << "\nPages: " << pages;
    ss << "\nPrice: " << price;
    ss << "\nID: " << id;

    return ss.str();
}

int Book::get_id_counter() {
    return id_counter;
}

Book Book::create_demo_book() {
    std::random_device rd;
    std::uniform_int_distribution<int> strings(0, 3);
    std::uniform_int_distribution<int> pages(20, 400);
    std::uniform_real_distribution<double> prices(2.50, 39.99);

    std::string title[4] = {"Janko in Metka", "Košarkar naj bo", "Nogometaš", "Pod Soncem"};
    std::string publisher[4] = {"Zalozba 1", "Zalozba 2", "Zalozba 3", "Zalozba 4"};

    return (Book(title[strings(rd)], publisher[strings(rd)], pages(rd), prices(rd), std::make_unique<Author>("Janko", "janko@gmail.com", 'M')));
}


const void Book::add_author(std::unique_ptr<Author> author) {
    authors.emplace_back(std::move(author));
}


const void Book::get_author_names() const {
    std::cout << "= Authors =\n";
    for (const auto& a : authors)
        std::cout << a->get_name() << "\n";
}