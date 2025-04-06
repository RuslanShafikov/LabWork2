//
// Created by ruslan on 3/6/25.
//

#ifndef ALCHEMIST_H
#define ALCHEMIST_H
#include "../Role.h"
class Alchemist : public Role {
    public:

    RoleType getType() const override ;

    Role* clone() const override;

    void createHealingPotion();

    void createExplosivePotion();

    explicit Alchemist(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions, bool poisonousEffect);

    ~Alchemist() noexcept override = default;
};
#endif //ALCHEMIST_H
