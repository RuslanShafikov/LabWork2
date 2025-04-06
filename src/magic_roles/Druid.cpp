//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Druid.h"
#include <random>
bool Druid::hide() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 10) {
      std::cout<<"Attack worked"<<std::endl;
        return true;
    }
    return false;
}

Druid::Druid(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}


RoleType Druid::getType() const { return RoleType::Druid; }
    Role* Druid::clone() const {
    return new Druid(*this);
}