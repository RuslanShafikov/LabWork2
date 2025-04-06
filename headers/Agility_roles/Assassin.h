
#ifndef ASSASSIN_H
#define ASSASSIN_H
#include "../Team/Role.h"
#include <random>
class Assassin : public Role{
public:
    RoleType getType() const override ;
    Role* clone() const override;
    void assassinate (Role& A);
    Assassin(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};





#endif //ASSASSIN_H
