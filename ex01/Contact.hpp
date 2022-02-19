#pragma once
#include <string>

class   Contact
{
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone;
    std::string _darkest_secret;

public:
    Contact();
    ~Contact();

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone() const;
    std::string get_darkest_secret() const;
    void    set_contact_details(std::string f_name, std::string l_name,
                std::string nname, std::string phone, std::string d_secret);
};

