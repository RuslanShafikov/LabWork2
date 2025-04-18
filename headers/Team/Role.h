
#ifndef ROLE_H
#define ROLE_H

#include <string>
#include <iostream>
#include <memory>

enum class RoleType {
    Generic,
    Assassin,
    Doctor,
    Archer,
    Enchantress,
    Monk,
    Thief,
    Knight,
    Warrior,
    Gladiator,
    Alchemist,
    Necromancer,
    Druid,
    Mage,
    Shaman,
    Sorcerer
};

class Role {
private:
    int agility;
    int strength;
    int intelligence;
    double health;
    int critChance; //@note from 1 to 100 = probability of crit chance
    int amountOfHealingPotions;
    int amountOfExplosivePotions;
    bool poisonEffect;
public:
    explicit Role(const int agility,const int strength, const int intelligence, const double health,const int critChance,const int amountOfHealingPotions,const int amountOfExplosivePotions, bool PoisonEffect)
            : agility(agility), strength(strength), intelligence(intelligence), health(health), critChance(critChance),amountOfHealingPotions(amountOfHealingPotions), amountOfExplosivePotions(amountOfExplosivePotions), poisonEffect(PoisonEffect) {}

    Role(){}

    virtual RoleType getType() const = 0;

    virtual Role* clone() const = 0;

    Role(const Role& other);

    Role(Role&& other) noexcept;

    Role& operator=(const Role& other);

    Role& operator=(Role&& other) noexcept;

    virtual ~Role() noexcept;

    [[nodiscard]] int getAgility() const;

    [[nodiscard]] int getStrength() const;

    [[nodiscard]] int getIntelligence() const;

    [[nodiscard]] double getHealth() const;

    [[nodiscard]] int getCritChance() const;

    [[nodiscard]] int getAmountOfHealingPotions() const;

    [[nodiscard]] int getAmountOfExplosivePotions() const;

    [[nodiscard]] bool getPoisonEffect() const;


    void setAgility(int agility);

    void setStrength(int strength);

    void setIntelligence(int intelligence);

    void setHealth(double health);

    void setCritChance(int critChance);

    void setAmountOfHealingPotions(int amountOfPotions);

    void setAmountOfExplosivePotions(int amountOfPotions);

    void setPoisonEffect(bool effect);

    void basicAttack(Role& A) const;

    void healFromPoison(Role& A) const;

    void giveHealingPotion(Role& A);

    double basicIntAttack() const ;

    void giveExplosivePotion(Role& A);


    void basicFixedAttack(Role& A) const;
};

#endif

