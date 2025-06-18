#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::setFirstName(const std::string& firstname) {
    this->_firstname = firstname;
}

void Contact::setLastName(const std::string& lastname) {
    this->_lastname = lastname;
}

void Contact::setNickName(const std::string& nickname) {
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    this->_phonenumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    this->_darkestsecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return this->_firstname;
}

std::string Contact::getLastName() const {
    return this->_lastname;
}

std::string Contact::getNickName() const {
    return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->_phonenumber;
}

std::string Contact::getDarkSecret() const {
    return this->_darkestsecret;
}

bool Contact::isEmpty() const {
    return (this->_firstname.empty() && this->_lastname.empty() && 
            this->_nickname.empty() && this->_phonenumber.empty() && this->_darkestsecret.empty());
}

void Contact::displayContact() const {
    std::cout << "First Name: " << this->_firstname << std::endl;
    std::cout << "Last Name: " << this->_lastname << std::endl;
    std::cout << "Nick name: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phonenumber << std::endl;
    std::cout << "Darkest secret: " << this->_darkestsecret << std::endl;
}

std::string Contact::formatField(const std::string& field) const {
    if(field.length() > 10) {
        return field.substr(0,9) + ".";
    }
    return field;
}
