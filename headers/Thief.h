
#ifndef THIEF_H
#define THIEF_H
#include "Role.h"

class Thief : public Role {
public:
    RoleType getType() const override ;
    Role* clone() const override;
    Thief(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
    bool isStolen();
};



#endif //THIEF_H
