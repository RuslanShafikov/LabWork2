//
// Created by ruslan on 3/13/25.
//

#include "../../headers/Agility_roles/Ecnchantress.h"
#include <random>
void Enchantress::charm(Team& B) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 30) {
        std::cout<<"Attack worked"<<std::endl;
        B.getA()->setStrength(B.getA()->getStrength() - 1);
    }
}

void Enchantress::deathKissAttack(Role& B) {
  if(this->getHealth() < 20){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 20) {
        std::cout<<"Attack worked"<<std::endl;
        B.setAgility(1);
        B.setStrength(1);
        B.setIntelligence(1);
    }
    }
}

Enchantress::Enchantress(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}

RoleType Enchantress::getType() const { return RoleType::Enchantress; }
Role* Enchantress::clone() const {
    return new Enchantress(*this);
}