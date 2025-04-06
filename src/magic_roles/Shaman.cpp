//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Shaman.h"
void Shaman::deafen(Role& A){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 80){
      std::cout<<"Attack worked"<<std::endl;
        A.setCritChance(0);
    }
}

Shaman::Shaman(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}

RoleType Shaman::getType() const { return RoleType::Shaman; }
Role* Shaman::clone() const {
    return new Shaman(*this);
}