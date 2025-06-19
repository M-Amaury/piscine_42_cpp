#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){

}

Zombie::~Zombie(){
    std::cout << this->_name << " has been destroyed" << std::endl;
};

void Zombie::announce(void) const{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
    _name = name;
}

Zombie* zombieHorde(int N, std::string name){
    Zombie* horde = new Zombie[N];
    for(int i = 0; i < N; i++){
        horde[i].setName(name);
    }
    return horde;
}