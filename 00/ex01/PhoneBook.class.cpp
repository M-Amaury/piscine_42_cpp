#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(): _contactCount(0), _oldestIndex(0) {

}

PhoneBook::~PhoneBook(){

}

void PhoneBook::addContact(const Contact& contact){
    if(_contactCount < 8){
        _contacts[_contactCount] = contact;
        _contactCount++;
    } else {
        _contacts[_oldestIndex] = contact;
        _oldestIndex = (_oldestIndex + 1) % 8;
    }
}

void PhoneBook::displayAllContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
            << std::setw(10) << "First Name" << "|"
            << std::setw(10) << "Last Name" << "|"
            << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "------------------------------" << std::endl;

    for (int i = 0; i < _contactCount; i++) {
        std::cout << std::setw(10) << i
                << std::setw(10) << _contacts[i].formatField(_contacts[i].getFirstName()) << "|"
                << std::setw(10) << _contacts[i].formatField(_contacts[i].getLastName()) << "|"
                << std::setw(10) << _contacts[i].formatField(_contacts[i].getNickName()) << std::endl;
    }
}

void PhoneBook::searchContacts() const {
    if(_contactCount == 0) {
        std::cout << "No countacts in phonebook" << std::endl;
        return;
    }

    displayAllContacts();

    std::string input;
    int index;

    std::cout << "Enter index of contact to display: ";
    std::getline(std::cin, input);

    if (isValidIndex(input, index)) {
        displayContact(index);
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if(index >= 0 && index < _contactCount) {
        _contacts[index].displayContact();
    } else {
        std::cout << "Contact not found" << std::endl;
    }
}

int PhoneBook::getContactCount() const {
    return _contactCount;
}

bool PhoneBook::isValidIndex(const std::string& input, int& index) const {
    std::stringstream ss(input);
    if (!(ss >> index) || !ss.eof()) {
        return false;
    }
    return (index >= 0 && index < _contactCount);
}
