//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Ancherman_roles/Knight.h"

void Knight::splashAttack(Team& T) const {
  std::cout<<"Attack worked"<<std::endl;
    T.getA()->setHealth(T.getA()->getHealth() - this->basicIntAttack()/2.8);
    T.getB()->setHealth(T.getB()->getHealth() - this->basicIntAttack()/2.8);
    T.getC()->setHealth(T.getC()->getHealth() - this->basicIntAttack()/2.8);
}


RoleType Knight::getType() const { return RoleType::Knight; }
    Role* Knight::clone() const {
    return new Knight(*this);
}

 Knight::Knight(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {}

