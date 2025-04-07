
#ifndef DRUID_H
#define DRUID_H
#include "../Team/Role.h"

class Druid : public Role {
public:
    RoleType getType() const override ;
    Role* clone() const override;
    bool hide();
    Druid(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
   };
#endif //DRUID_H
