
#ifndef DOCTOR_H
#define DOCTOR_H
#include "../Team/Role.h"

class Doctor : public Role {
public:
    void heal(Role& A);
    Doctor (int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);  // : Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect {}
    RoleType getType() const override ;
    Role* clone() const override;
};



#endif //DOCTOR_H
