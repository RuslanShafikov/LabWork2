//
// Created by ruslan on 3/6/25.
//

#include "Gladiator.h"
#include <random>
void Gladiator::deathFeeling(Role& A) {
    if (A.getHealth() <= 50) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        int random_number = dis(gen);
        int highPoint = A.getAgility();
        if(random_number < highPoint) {
          std::cout<<"Attack worked"<<std::endl;
            A.setHealth(0.0);
        }
    }
}

Gladiator::Gladiator(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}


RoleType Gladiator::getType() const { return RoleType::Gladiator; }
Role* Gladiator::clone() const {
    return new Gladiator(*this);
}

