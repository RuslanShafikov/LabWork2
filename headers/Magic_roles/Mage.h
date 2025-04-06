
#ifndef MAGE_H
#define MAGE_H
#include "../Team/Role.h"
class Mage : public Role {
public:
   RoleType getType() const override ;
   Role* clone() const override;
   Mage(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
   double shield();
};
#endif //MAGE_H
