#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

void    PhoneBook::add_contact()
{
    std::string  f_name;
    std::string  l_name;
    std::string  nname;
    std::string  phone;
    std::string  d_secret;

    std::cout << "ADD new contact:" << std::endl;
    std::cout << "  First name >> ";
    getline(std::cin, f_name);
    std::cout << "  Last name >> ";
    getline(std::cin, l_name);
    std::cout << "  Nickname >> ";
    getline(std::cin, nname);
    std::cout << "  Phone number >> ";
    getline(std::cin, phone); // check if digits only?????
    std::cout << "  Darkest secret >> ";
    getline(std::cin, d_secret);
    
    if (_s_next_contact_nbr <= 7)
    {
        //if (contacts[contact_nbr]._first_name.empty() == true)
            //contacts[0] and add new Contact
        //else
            //contact[contact_nbr].set_contact_details()
        _contacts[_s_next_contact_nbr].set_contact_details(f_name, l_name, nname, phone, d_secret);
    }
    else
    {
        _s_next_contact_nbr = 0;
        _contacts[_s_next_contact_nbr].set_contact_details(f_name, l_name, nname, phone, d_secret);
    }
    _s_next_contact_nbr++;
    if (_s_max_len <= 7)
        _s_max_len++;
}

void    PhoneBook::search_contact() const
{
    std::string str_input;
    int         int_input;
    int         wrong_input;

    if (!display_contacts_preview())
        return;
    while (1)
    {
        std::cout << "Which contact do you want to display fully?\n"
        "Please type in the corresponding index" << std::endl;
        getline(std::cin, str_input);
        wrong_input = false;
        for (size_t i = 0; i < str_input.length(); i++)
        {
            if (isdigit(str_input[i]))
                i++;
            else
            {
                std::cout << "Wrong input: Digits between 1 and " << _s_next_contact_nbr << " only" << std::endl;
                wrong_input = true;
                break ;
            }
        }
        if (wrong_input == false)
        {
            int_input = std::stoi(str_input);
            if (int_input < 1 || int_input > _s_max_len)
                std::cout << "Wrong input: Digits between 1 and " << _s_next_contact_nbr << " only" << std::endl;
            else
            {
                display_full_contact(int_input);
                break ;
            }
        }
    }

}

int    PhoneBook::display_contacts_preview() const
{
    int ret_val;

    if (_s_next_contact_nbr == 0)
    {
        std::cout << "Phone book is empty!" << std::endl;
        ret_val = 0;
    }
    else
    {
        for (int i = 0; i < _s_next_contact_nbr - 1; i++)
        {
            std::cout << std::setw(10) << i + 1 << "|";
            std::cout << _contacts[i].get_first_name() << "|";
            std::cout << _contacts[i].get_last_name() << "|";
            std::cout << _contacts[i].get_nickname() << std::endl;
        }
        ret_val = 1;
    }
    return (ret_val);
}

void    PhoneBook::display_full_contact(int contact_number) const
{
    std::cout << _contacts[contact_number].get_first_name() << std::endl;
    std::cout << _contacts[contact_number].get_last_name() << std::endl;
    std::cout << _contacts[contact_number].get_nickname() << std::endl;
    std::cout << _contacts[contact_number].get_phone() << std::endl;
    std::cout << _contacts[contact_number].get_darkest_secret() << std::endl;
}
