//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Ancherman_roles/Warrior.h"
#include "random"
void Warrior::lastBreathAttack(Role& A){
  if(this->getHealth()<50){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 25) {
        std::cout<<"Attack worked"<<std::endl;
      A.setHealth(0);
      return;
    }
    this->setHealth(0);
    }

   }


RoleType Warrior::getType() const { return RoleType::Warrior; }
Role* Warrior::clone() const {
    return new Warrior(*this);
}

Warrior::Warrior(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
 : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}