#include "../../headers/Team/Role.h"
#include <random>
#include <sstream>

#include "../../headers/Agility_roles/Archer.h"
#include "../../headers/Agility_roles/Assassin.h"
#include "../../headers/Agility_roles/Doctor.h"
#include "../../headers/Agility_roles/Ecnchantress.h"
#include "../../headers/Agility_roles/Monk.h"
#include "../../headers/Agility_roles/Thief.h"
#include "../../headers/Ancherman_roles/Gladiator.h"
#include "../../headers/Ancherman_roles/Knight.h"
#include "../../headers/Ancherman_roles/Warrior.h"
#include "../../headers/Magic_roles/Alchemist.h"
#include "../../headers/Magic_roles/Druid.h"
#include "../../headers/Magic_roles/Mage.h"
#include "../../headers/Magic_roles/Necromancer.h"
#include "../../headers/Magic_roles/Shaman.h"
#include "../../headers/Magic_roles/Sorcerer.h"
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
    poisonEffect =other.poisonEffect;
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
    poisonEffect = other.poisonEffect;
    other.agility = 0;
    other.strength = 0;
    other.intelligence = 0;
    other.health = 0;
    other.critChance = 0;
    other.amountOfHealingPotions = 0;
    other.amountOfExplosivePotions =0;
    other.poisonEffect = false;
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

bool Role::getPoisonEffect() const {
    return poisonEffect;
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

void Role::setPoisonEffect(bool poisonEffect) {
    this->amountOfExplosivePotions = poisonEffect;
}

void Role::basicAttack(Role& A) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    int random_number1 = dis(gen);
    int random_number2 = dis(gen);
    if(critChance > random_number2){
    if (this->getStrength()> this->getIntelligence()) {
        A.setHealth(A.getHealth()-this->getStrength()*0.04*(random_number+random_number1+random_number2)*this->getStrength());
        return;
    }

    A.setHealth(A.getHealth()-this->getIntelligence()*0.04*(random_number+random_number1+random_number2)*this->getIntelligence());
    }
    if (this->getStrength()> this->getIntelligence()) {
        A.setHealth(A.getHealth()-this->getStrength()*0.02*(random_number+random_number1+random_number2)*this->getStrength());
        return;
    }

    A.setHealth(A.getHealth()-this->getIntelligence()*0.02*(random_number+random_number1+random_number2)*this->getIntelligence());
}

double Role::basicIntAttack() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    int random_number1 = dis(gen);
    int random_number2 = dis(gen);
    if(random_number2<critChance){


    if (this->getStrength()> this->getIntelligence()) {
        return 0.04*(random_number+random_number1+random_number2)*this->getStrength();
    }


    return 0.04*(random_number+random_number1+random_number2)*this->getIntelligence();

    }

    if (this->getStrength()> this->getIntelligence()) {
        return 0.02*(random_number+random_number1+random_number2)*this->getStrength();
    }


    return 0.02*(random_number+random_number1+random_number2)*this->getIntelligence();
}

void Role::basicFixedAttack(Role& A) const {
    if (this->getStrength()> this->getIntelligence()) {
        A.setHealth(A.getHealth()-(this->getStrength()-1)*10.4);
        return;
    }

    A.setHealth(A.getHealth()-(this->getIntelligence()-1)*10.4);


}

void Role::healFromPoison(Role& A) const {
  if(A.getPoisonEffect()==true){
  if(A.getAmountOfHealingPotions()>0){
    A.setAmountOfHealingPotions(A.getAmountOfHealingPotions()-1);
    }
    A.setPoisonEffect(false);
    }
}

RoleType getType() { return RoleType::Generic; }

void Role::giveExplosivePotion(Role& A) {
    if (this->getAmountOfExplosivePotions() > 0) {
        this->setAmountOfExplosivePotions(this->getAmountOfExplosivePotions() - 1);
        A.setAmountOfExplosivePotions(A.getAmountOfExplosivePotions() + 1);
    }
}

void Role::giveHealingPotion(Role& A) {
    if (this->getAmountOfHealingPotions() > 0) {
        this->setAmountOfHealingPotions(this->getAmountOfHealingPotions() - 1);
        A.setAmountOfHealingPotions(A.getAmountOfHealingPotions() + 1);
    }
}
