//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Magic_roles/Sorcerer.h"

void Sorcerer::doubleMagicAttack(Role& A){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 20){
      std::cout<<"Attack worked"<<std::endl;
        A.setHealth(A.getHealth()-A.basicIntAttack());
        A.setHealth(A.getHealth()-A.basicIntAttack());
    }
    else{
      A.setHealth(A.getHealth()-A.basicIntAttack());
      }
}

Sorcerer::Sorcerer(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}

RoleType Sorcerer::getType() const { return RoleType::Sorcerer; }
    Role* Sorcerer::clone() const {
    return new Sorcerer(*this);
}