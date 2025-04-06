
#ifndef SHAMAN_H
#define SHAMAN_H
#include "Role.h"
#include <random>

class Shaman : public Role {

public:
    void deafen(Role& A);
    RoleType getType() const override ;
    Role* clone() const override;
    Shaman(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};



#endif //SHAMAN_H
