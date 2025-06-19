#include "Zombie.hpp"
#include <iostream>

int main() {
    std::cout << "Création d'un zombie sur la stack" << std::endl;
    randomChump("Bernard");
    std::cout << "Bernard disparait automatiquement" << std::endl;

    std::cout << "Création d'un zombie sur le heap" << std::endl;
    Zombie* Jean = newZombie("Jean");
    Jean->announce();
    std::cout << "Jean doit etre delete manuellement" << std::endl;
    delete Jean;

    return 0;
}