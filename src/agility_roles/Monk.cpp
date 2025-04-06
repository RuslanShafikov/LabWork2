//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Monk.h"

void Monk::amplify(Role& A) {
    A.setCritChance(A.getCritChance() * 2);
    std::cout<<"AAmplifying worked"<<std::endl;
}


Monk::Monk(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}


RoleType Monk::getType() const { return RoleType::Monk; }
    Role* Monk::clone() const {
    return new Monk(*this);
}