#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   myphonebook;
    std::string input;

    std::cout << "### YOUR PHONEBOOK ###\n\n" << std::endl;
    while (1)
    {
            std::cout << "What do you want to do?" << std::endl
            << "<A> ADD a new contact" << std::endl
            << "<S> SEARCH for a contact" << std::endl
            << "<E> EXIT the program" << std::endl;
        getline(std::cin, input);
        if (input == "A" || input == "a")
            myphonebook.add_contact();
        else if (input == "S" || input == "s")
            myphonebook.search_contact();
        else if (input == "E" || input == "e")
            break ;
        else
            std::cout << "Wrong input: Choose again" << std::endl;
    }

    std::cout << "##### SHUTTING DOWN #####" << std::endl;
    
    return (0);
}
