//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Magic_roles/Alchemist.h"

void Alchemist::createHealingPotion() {
    this->setAmountOfHealingPotions(this->getAmountOfHealingPotions() + 1);
}


void Alchemist::createExplosivePotion() {
    this->setAmountOfExplosivePotions(this->getAmountOfExplosivePotions() + 1);
}

RoleType Alchemist::getType() const { return RoleType::Alchemist; }
Role* Alchemist::clone() const {
    return new Alchemist(*this);
}

        Alchemist::Alchemist(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {}




