
#ifndef GLADIATOR_H
#define GLADIATOR_H
#include "../Team/Role.h"


class Gladiator : public Role {
public:
    RoleType getType() const override ;
    Role* clone() const override;
    void deathFeeling(Role& A);
    Gladiator(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};




#endif //GLADIATOR_H
