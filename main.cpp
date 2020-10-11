#include "Author.h"
#include "Book.h"
#include <iostream>


int main() {
    std::vector<std::unique_ptr<Book>> books;

    books.emplace_back(std::make_unique<Book>(std::make_unique<Author>("Pero", "pero@gmail.com", 'M'), "Janko in metka", "Zalozba1", 222, 25.44));
    books[0]->add_author(std::make_unique<Author>("Perica JR", "perica.jr@gmail.com", 'M'));

    books.emplace_back(std::make_unique<Book>(*books[0]));
    books.emplace_back(std::make_unique<Book>());


    for (const auto& b : books)
        std::cout << b->to_string() << "\n\n";


    auto a1 = std::make_unique<Author>("Svetlana Makarovic", "svetlanamakarovic@gmail.com", 'F');
    std::cout << a1->to_string() << "\n\n";


    return 0;
}
