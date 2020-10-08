#include "Author.h"
#include "Book.h"
#include <iostream>


int main() {

    auto book = std::make_unique<Book>("Janko in metka", "Zalozba1", 222, 25.44, std::make_unique<Author>("Pero", "pero@gmail.com", 'M'));
    std::cout << book->to_string() << std::endl << std::endl;

    book->add_author(std::make_unique<Author>("Perica JR", "perica.jr@gmail.com", 'M'));
    book->get_author_names();


    return 0;
}
