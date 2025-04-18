//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Magic_roles/Necromancer.h"

void Necromancer::arise(Role& A) {
    if (A.getHealth()<=0) {
        A.setHealth(50);
        std::cout<<"Your teammate arised"<<std::endl;
    }
}

Necromancer::Necromancer(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}

RoleType Necromancer::getType() const { return RoleType::Necromancer; }
Role* Necromancer::clone() const {
  return new Necromancer(*this);
}

