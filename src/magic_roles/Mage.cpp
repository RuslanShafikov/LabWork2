//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Magic_roles/Mage.h"
#include <random>

double Mage::shield(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 20);
    int random_number = dis(gen);
    std::cout<<"Shield set"<<std::endl;
    return static_cast<double>(random_number);
  }

Mage::Mage(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
  : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}


RoleType Mage::getType() const { return RoleType::Mage; }
Role* Mage::clone() const {
  return new Mage(*this);
}