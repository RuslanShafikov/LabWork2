
#ifndef MONK_H
#define MONK_H
#include "Role.h"

class Monk : public Role {
public:
     void amplify(Role& A);
     Monk(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
    RoleType getType() const override ;
    Role* clone() const override;
    };



#endif //MONK_H
