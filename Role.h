
#ifndef ROLE_H
#define ROLE_H
class Role {
private:
    int agility;
    int strength;
    int intelligence;
    double health;
    int critChance; //@note from 1 to 100 = probability of crit chance
    int amountOfHealingPotions;
    int amountOfExplosivePotions;
public:
    Role(int agility, int strength, int intelligence, double health, int critChance, int amountOfHealingPotions, int amountOfExplosivePotions);

    Role(const Role& other);

    Role(Role&& other) noexcept;

    Role& operator=(const Role& other);

    Role& operator=(Role&& other) noexcept;

    ~Role() noexcept;

    [[nodiscard]] int getAgility() const;

    [[nodiscard]] int getStrength() const;

    [[nodiscard]] int getIntelligence() const;

    [[nodiscard]] double getHealth() const;

    [[nodiscard]] int getCritChance() const;

    [[nodiscard]] int getAmountOfHealingPotions() const;

    [[nodiscard]] int getAmountOfExplosivePotions() const;


    void setAgility(int agility);

    void setStrength(int strength);

    void setIntelligence(int intelligence);

    void setHealth(double health);

    void setCritChance(int critChance);

    void setAmountOfHealingPotions(int amountOfPotions);

    void setAmountOfExplosivePotions(int amountOfPotions);

     double basicAttack() const;
};

#endif

