#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){};

Harl::~Harl(void){};

void Harl::debug(void){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << DEBUG << std::endl << std::endl;
}

void Harl::info(void){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << INFO << std::endl << std::endl;
}

void Harl::warning(void){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << WARNING << std::endl << std::endl;
}

void Harl::error(void){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << ERROR << std::endl << std::endl;
}

void Harl::complain(std::string level){
    t_levels debugLevels[4] = {
        { "DEBUG", &Harl::debug},
        { "INFO", &Harl::info},
        { "WARNING", &Harl::warning},
        { "ERROR", &Harl::error}    
    };
    for ( int i = 0; i < 4; i++){
        if(debugLevels[i].debugString == level){
            (this->*(debugLevels[i].f))();
            return;
        }
    }
}