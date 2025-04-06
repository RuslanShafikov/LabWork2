//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Agility_roles/Archer.h"
#include <iostream>
bool Archer::AdditionalHit() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number < 20) {
        return true;
    }
    return false;
}

void Archer::poisonousArrowAttack(Role& B){
        if (this->getAmountOfExplosivePotions() <= 0) {
            std::cout<<"You need explosive potions"<<std::endl;
            return;
        }

        this->setAmountOfExplosivePotions(getAmountOfExplosivePotions()-1); // Consume an explosive potion

        bool isPois = (std::rand() % 100) < getCritChance();

        this->basicAttack(B);
        if (isPois) {
            this->basicAttack(B);
            B.setPoisonEffect(true);
            std::cout<<"Attack worked"<<std::endl;
        }
    }

Archer::Archer(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) { }
RoleType Archer::getType() const { return RoleType::Archer; }
Role* Archer::clone() const {
    return new Archer(*this); // Uses the copy constructor
}

Archer::~Archer() {};