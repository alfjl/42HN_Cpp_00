#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <ios>

int main()
{
    PhoneBook   myphonebook;
    std::string input;

    std::cout << "\n### YOUR PHONEBOOK ###\n\n" << std::endl;
    while (1)
    {
        std::cout << "\nWhat do you want to do?" << std::endl
        << "<A> ADD a new contact" << std::endl
        << "<S> SEARCH for a contact" << std::endl
        << "<E> EXIT the program" << std::endl;
        std::cout << ">> ";
        getline(std::cin, input);
        if (std::cin.good() == false)
        {
            std::cout << "\nError: STRG+D/CMD+D not allowed" << std::endl;
            break ;
        }
        else if (input == "A" || input == "a"
                || input == "ADD" || input == "add")
            myphonebook.add_contact();
        else if (input == "S" || input == "s"
                || input == "SEARCH" || input == "search")
            myphonebook.search_contact();
        else if (input == "E" || input == "e"
                || input == "EXIT" || input == "exit")
            break ;
        else
            std::cout << "Wrong input: Choose again" << std::endl;
        if (std::cin.good() == false)
        {
            std::cout << "\nError: STRG+D/CMD+D not allowed" << std::endl;
            break ;
        }
    }

    std::cout << "\n#####   END OF PROGRAM    #####" << std::endl;
    std::cout << "##### ALL CONTACTS ERASED #####" << std::endl;
    
    return (0);
}
