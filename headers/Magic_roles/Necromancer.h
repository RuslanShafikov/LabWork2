
#ifndef NECROMANCER_H
#define NECROMANCER_H
#include "../Team/Role.h"

class Necromancer : public Role {
public:
  void arise(Role& A);

    RoleType getType() const override ;
    Role* clone() const override;
    Necromancer(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};
#endif //NECROMANCER_H
