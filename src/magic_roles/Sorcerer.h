
#ifndef SORCERER_H
#define SORCERER_H
#include "../Role.h"
#include <random>


class Sorcerer : public Role{
public:
    RoleType getType() const override ;
    Role* clone() const override;
    void doubleMagicAttack(Role& A);
    Sorcerer(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};



#endif //SORCERER_H
