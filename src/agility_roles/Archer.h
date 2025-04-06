

#ifndef ARCHER_H
#define ARCHER_H
#include "../Role.h"
#include <random>
class Archer : public Role {
public:
    static bool AdditionalHit();
    Archer(): Role() {
    }
    RoleType getType() const override ;
    Role* clone() const override;
    ~Archer() override;
    void poisonousArrowAttack(Role& B);
    Archer(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);
};

#endif //ARCHER_H
