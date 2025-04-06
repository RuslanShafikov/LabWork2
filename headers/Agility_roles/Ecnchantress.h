

#ifndef ENCHANTRESS_H
#define ENCHANTRESS_H
#include "../Team/Role.h"
#include "../Team/Team.h"

class Enchantress : public Role {
public:
    void charm(Team& B);
    void deathKissAttack(Role& B);
    RoleType getType() const override ;
    Role* clone() const override;
Enchantress (int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);  //: Role(agility, strength, intelligence, health, critChance, amountOfHealingPotions, amountOfExplosivePotions, poisonousEffect){}
};
#endif //ENCHANTRESS_H