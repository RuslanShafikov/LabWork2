//
// Created by ruslan on 3/6/25.
//

#include "Thief.h"
#include <random>
bool Thief::isStolen(){ //@note  can stole opponents moves. Has only one try in 2 moves
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 30) {
      std::cout<<"Attack worked"<<std::endl;
        return true;
    }
    return false;
  }

  Thief::Thief(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}


RoleType Thief::getType() const { return RoleType::Thief; }
    Role* Thief::clone() const {
    return new Thief(*this);
}
