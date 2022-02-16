#pragma once
#include "Contact.hpp"

class   PhoneBook
{
private:
    Contact     _contacts[8];
    static int  _s_next_contact_nbr;
    static int  _s_max_len;

public:
    PhoneBook();
    ~PhoneBook();

    void    add_contact();
    void    search_contact() const;
    int     display_contacts_preview() const;
    void    display_full_contact(int contact_number) const;
};

