#include "Role.h"
#include <random>
Role::Role(int agility = 5, int strength = 5, int intelligence = 5, double health = 200.0, int critChance = 10, int amountOfHealingPotions = 0, int amountOfExplosivePotions = 0)
        : agility(agility), strength(strength), intelligence(intelligence), health(health), critChance(critChance),amountOfHealingPotions(amountOfHealingPotions), amountOfExplosivePotions(amountOfExplosivePotions) {}

Role::Role(const Role& other): agility(other.agility), strength(other.strength), intelligence(other.intelligence), health(other.health), critChance(other.critChance), amountOfHealingPotions(other.amountOfHealingPotions), amountOfExplosivePotions(other.amountOfExplosivePotions) {}

Role::Role(Role&& other) noexcept
    : agility(other.agility), strength(other.strength), intelligence(other.intelligence), health(other.health), critChance(other.critChance), amountOfHealingPotions(other.amountOfHealingPotions), amountOfExplosivePotions(other.amountOfExplosivePotions){
    other.agility = 0;
    other.strength = 0;
    other.intelligence = 0;
    other.health = 0;
    other.critChance = 0;
    other.amountOfHealingPotions = 0;
    other.amountOfExplosivePotions = 0;
}

Role& Role::operator=(const Role& other) {
    if (this == &other) {
        return *this;
    }
    agility = other.agility;
    strength = other.strength;
    intelligence = other.intelligence;
    health = other.health;
    critChance = other.critChance;
    amountOfHealingPotions = other.amountOfExplosivePotions;
    return *this;
}

Role& Role::operator=(Role&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    agility = other.agility;
    strength = other.strength;
    intelligence = other.intelligence;
    health = other.health;
    critChance = other.critChance;
    amountOfHealingPotions = other.amountOfHealingPotions;
    amountOfExplosivePotions = other.amountOfExplosivePotions;

    other.agility = 0;
    other.strength = 0;
    other.intelligence = 0;
    other.health = 0;
    other.critChance = 0;
    other.amountOfHealingPotions = 0;
    other.amountOfExplosivePotions =0;
    return *this;
}

Role::~Role() noexcept = default;


int Role::getAgility() const {
    return agility;
}

int Role::getStrength() const {
    return strength;
}

int Role::getIntelligence() const {
    return intelligence;
}

double Role::getHealth() const {
    return health;
}

int Role::getCritChance() const {
    return critChance;
}

int Role::getAmountOfHealingPotions() const {
    return amountOfHealingPotions;
}

int Role::getAmountOfExplosivePotions() const {
    return amountOfExplosivePotions;
}


void Role::setAgility(int agility) {
    this->agility = agility;
}

void Role::setStrength(int strength) {
    this->strength = strength;
}

void Role::setIntelligence(int intelligence) {
    this->intelligence = intelligence;
}

void Role::setHealth(double health) {
    this->health = health;
}

void Role::setCritChance(int critChance) {
    this->critChance = critChance;
}

void Role::setAmountOfHealingPotions(int amountOfPotions) {
    this->amountOfHealingPotions = amountOfPotions;
}

void Role::setAmountOfExplosivePotions(int amountOfPotions) {
    this->amountOfExplosivePotions = amountOfPotions;
}

double Role::basicAttack() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    int random_number1 = dis(gen);
    int random_number2 = dis(gen);
    if (this->getStrength()> this->getIntelligence()) {
        return this->getStrength()*0.02*(random_number+random_number1+random_number2);
    }

    return this->getIntelligence()*0.02*(random_number+random_number1+random_number2);
}
