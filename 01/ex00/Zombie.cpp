#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): _name(name){
}

Zombie::~Zombie(){
    std::cout << _name << " has been destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);
    return zombie;
}

void randomChump(std::string name){
    Zombie zombie(name);
    zombie.announce();

}