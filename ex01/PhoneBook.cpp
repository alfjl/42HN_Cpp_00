#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

int PhoneBook::_s_next_contact_nbr = 0;
int PhoneBook::_s_max_len = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void    PhoneBook::add_contact()
{
    std::string f_name;
    std::string l_name;
    std::string nname;
    std::string phone;
    std::string d_secret;
    int         err_flg;

    std::cout << "ADD new contact:" << std::endl;
    std::cout << "  First name >> ";
    getline(std::cin, f_name);
    if (std::cin.good() == false)
        return ;
    std::cout << "  Last name >> ";
    getline(std::cin, l_name);
    if (std::cin.good() == false)
        return ;
    std::cout << "  Nickname >> ";
    getline(std::cin, nname);
    if (std::cin.good() == false)
        return ;
    while (true)
    {
        err_flg = false;
        std::cout << "  Phone number >> ";
        getline(std::cin, phone);
        if (std::cin.good() == false)
            return ;
        for (size_t i = 0; i < phone.length(); i++)
        {
            if (!isdigit(phone[i]))
            {
                std::cout << "\n  Wrong input: Digits only" << std::endl;
                err_flg = true;
                break ;
            }
        }
        if (err_flg == false)
            break ;
    }
    std::cout << "  Darkest secret >> ";
    getline(std::cin, d_secret);
    if (std::cin.good() == false)
        return ;
    
    if (_s_next_contact_nbr <= 7)
        _contacts[_s_next_contact_nbr].set_contact_details(f_name, l_name, nname, phone, d_secret);
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
        std::cout << "\nWhich contact do you want to display fully?\n"
        "Please type in the corresponding index" << std::endl;
        std::cout << ">> ";
        getline(std::cin, str_input);
        if (std::cin.good() == false)
            return ;
        wrong_input = false;
        for (size_t i = 0; i <= str_input.length(); i++)
        {
            if (isdigit(str_input[i]))
                i++;
            else
            {
                std::cout << "\nWrong input: Digits between 1 and " << _s_next_contact_nbr << " only" << std::endl;
                wrong_input = true;
                break ;
            }
        }
        if (wrong_input == false)
        {
            int_input = std::stoi(str_input);
            if (int_input < 1 || int_input > _s_max_len)
                std::cout << "\nWrong input: Digits between 1 and " << _s_next_contact_nbr << " only" << std::endl;
            else
            {
                display_full_contact(int_input - 1);
                break ;
            }
        }
    }
}

int    PhoneBook::display_contacts_preview() const
{
    int         ret_val;

    if (_s_next_contact_nbr == 0)
    {
        std::cout << "\nPhone book is empty!\n" << std::endl;
        ret_val = 0;
    }
    else
    {
        for (int i = 0; i < _s_max_len; i++)
        {
            std::cout << std::setw(10) << i + 1 << "|";
            if (_contacts[i].get_first_name().length() > 10)
                std::cout << std::setw(9) << _contacts[i].get_first_name().substr(0, 9) << "." << "|";
            else
                std::cout << std::setw(10) << _contacts[i].get_first_name() << "|";
            if (_contacts[i].get_last_name().length() > 10)
                std::cout << std::setw(9) << _contacts[i].get_last_name().substr(0, 9) << "." << "|";
            else
                std::cout << std::setw(10) << _contacts[i].get_last_name() << "|";
            if (_contacts[i].get_nickname().length() > 10)
                std::cout << std::setw(9) << _contacts[i].get_nickname().substr(0, 9) << "." << std::endl;
            else
                std::cout << std::setw(10) << _contacts[i].get_nickname() << std::endl;
        }
        ret_val = 1;
    }
    return (ret_val);
}

void    PhoneBook::display_full_contact(int contact_number) const
{
    std::cout << std::left << std::setw(14) << "First name: " << _contacts[contact_number].get_first_name() << std::endl;
    std::cout << std::left << std::setw(14) << "Last name: " << _contacts[contact_number].get_last_name() << std::endl;
    std::cout << std::left << std::setw(14) << "Nickname: " << _contacts[contact_number].get_nickname() << std::endl;
    std::cout << std::left << std::setw(14) << "Phone number: " << _contacts[contact_number].get_phone() << std::endl;
    std::cout << std::left << std::setw(14) << "Dark secret: " << _contacts[contact_number].get_darkest_secret() << std::endl;
}
