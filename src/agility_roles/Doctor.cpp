//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Agility_roles/Doctor.h"

void Doctor::heal(Role& A) {
    A.setHealth((200-A.getHealth())*0.3);
}
RoleType Doctor::getType() const { return RoleType::Doctor; }
    Role* Doctor::clone() const {
    return new Doctor(*this);
}

Doctor::Doctor(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect)
    : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect) {
}
