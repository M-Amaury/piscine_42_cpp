#include "Zombie.hpp"
#include <iostream>

int main(){
    std::string name;
    std::cout << "Chose a name for the zombies" << std::endl;
    std::getline(std::cin, name);

    std::cout << "Creation d'un horde de zombie" << std::endl;
    Zombie* horde = zombieHorde(5, name);
    for(int i = 0; i < 5; i++){
        horde[i].announce();
    }
    delete [] horde;
    
    return 0;
}
