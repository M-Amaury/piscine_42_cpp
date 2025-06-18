#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <string>

std::string getInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "The input couldn't be empty" << std::endl;
        }
    } while (input.empty());
    return input;
}

Contact createContact() {
    Contact contact;

    std::cout << "Enter the information of the contact: " << std::endl;
    contact.setFirstName(getInput("Enter First name: "));
    contact.setLastName(getInput("Enter Last name: "));
    contact.setNickName(getInput("Enter Nickname: "));
    contact.setPhoneNumber(getInput("Enter phone number: "));
    contact.setDarkestSecret(getInput("Enter darkest secret: "));

    return contact;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the phone book !" << std::endl;
    std::cout << "The commands are : ADD, SEARCH, EXIT" << std::endl;

    while(true) {
        std::cout << "Enter a command: " << std::endl;
        std::getline(std::cin, command);

        if(command == "ADD") {
            Contact newContact = createContact();
            phoneBook.addContact(newContact);
            std::cout << "Contact created successfully" << std::endl;
        } 
        else if(command == "SEARCH") {
            phoneBook.searchContacts();
        }
        else if(command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if(!command.empty()) {
            std::cout << "Invalid command, available ones : ADD, SERACH, EXIT" << std::endl;
        }
    }

    return 0;
}