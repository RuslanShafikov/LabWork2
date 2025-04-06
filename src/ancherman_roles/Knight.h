
#ifndef KNIGHT_H
#define KNIGHT_H
#include "../Role.h"
#include "../Team/Team.h"
class Knight  : public Role {
public:
    RoleType getType() const override ;
    Role* clone() const override;
    void splashAttack(Team& T) const;
    Knight(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};
#endif //KNIGHT_H
