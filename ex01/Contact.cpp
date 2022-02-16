#include <string>
#include "Contact.hpp"


//Contact::Contact(std::string f_name, std::string l_name, std::string nname,
//    std::string phone, std::string d_secret)
//    :   _first_name(f_name), _last_name(l_name), _nickname(nname)
//    , _phone(phone), _darkest_secret(d_secret)
//{
//    // >> has to be deletet after testing
//    std::cout << this->_first_name << endl;
//    std::cout << this->_last_name << endl;
//    std::cout << this->_nicknname << endl;
//    std::cout << this->_phone << endl;
//    std::cout << this->_darkest_secret << endl;
//    // has to be deletet after testing <<
//}

//void    display_contact() const
//{
//    std::cout << _first_name << std::endl;
//    std::cout << _last_name << std::endl;
//    std::cout << _nickname << std::endl;
//    std::cout << _phone << std::endl;
//    std::cout << _darkest_secret << std::endl;
//}

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::get_first_name() const
{
    return this->_first_name;
}

std::string Contact::get_last_name() const
{
    return this->_last_name;
}

std::string Contact::get_nickname() const
{
    return this->_nickname;
}

std::string Contact::get_phone() const
{
    return this->_phone;
}

std::string Contact::get_darkest_secret() const
{
    return this->_darkest_secret;
}

void    Contact::set_contact_details(std::string f_name, std::string l_name,
            std::string nname, std::string phone, std::string d_secret)
{
    this->_first_name = f_name;
    this->_last_name = l_name;
    this->_nickname = nname;
    this->_phone = phone;
    this->_darkest_secret = d_secret;
}
