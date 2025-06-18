#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <string>
class Contact {
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phonenumber;
        std::string _darkestsecret;

    public:

        Contact();
        ~Contact();
        
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkSecret() const;

        void setFirstName(const std::string& firstname);
        void setLastName(const std::string& lastname);
        void setNickName(const std::string& nickname);
        void setPhoneNumber(const std::string& phonenumber);
        void setDarkestSecret(const std::string& darkestsecret);

        bool isEmpty() const;
        void displayContact() const;
        std::string formatField(const std::string& field) const;
};

#endif
