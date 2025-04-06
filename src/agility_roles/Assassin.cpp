//
// Created by ruslan on 3/6/25.
//

#include "Assassin.h"
void Assassin::assassinate (Role& A) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 20) {
        A.setHealth(0);
        std::cout<<"Attack worked"<<std::endl;
    }
}


RoleType Assassin::getType() const { return RoleType::Assassin; }
Role* Assassin::clone() const {
    return new Assassin(*this);
}
Assassin::Assassin(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}

