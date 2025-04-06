
#ifndef WARRIOR_H
#define WARRIOR_H

#include "../Role.h"

class Warrior : public Role {
public:
    RoleType getType() const override ;
    Role* clone() const override;
  void lastBreathAttack(Role& A);
  Warrior(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};
#endif // WARRIOR_H
