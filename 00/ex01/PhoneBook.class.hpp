#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int _contactCount;
        int _oldestIndex;

    public:
        PhoneBook();
        ~PhoneBook();

        void addContact(const Contact& contact);
        void searchContacts() const;
        void displayContact(int index) const;
        void displayAllContacts() const;
        int getContactCount() const;

    private:
        bool isValidIndex(const std::string& input, int& index) const;
};

#endif
