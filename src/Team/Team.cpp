//
// Created by ruslan on 3/6/25.
//

#include "../../headers/Team.h"
#include <iostream>


// Constructor with unique_ptr parameters
Team::Team(std::unique_ptr<Role> a, std::unique_ptr<Role> b, std::unique_ptr<Role> c, double shield)
    : A(std::move(a)), B(std::move(b)), C(std::move(c)), teamShield(std::move(shield)) {}

// Copy constructor
Team::Team(const Team& other)
    : A(other.A ? std::unique_ptr<Role>(other.A->clone()) : nullptr),
      B(other.B ? std::unique_ptr<Role>(other.B->clone()) : nullptr),
      C(other.C ? std::unique_ptr<Role>(other.C->clone()) : nullptr),
      teamShield(other.teamShield)
{}

// Copy assignment operator
Team& Team::operator=(const Team& other) {
    if (this != &other) {
        A = other.A ? std::unique_ptr<Role>(other.A->clone()) : nullptr;
        B = other.B ? std::unique_ptr<Role>(other.B->clone()) : nullptr;
        C = other.C ? std::unique_ptr<Role>(other.C->clone()) : nullptr;
        teamShield = other.teamShield;
    }
    return *this;
}

// Getters
Role* Team::getA() const { return A.get(); }
Role* Team::getB() const { return B.get(); }
Role* Team::getC() const { return C.get(); }
double Team::getTeamShield() const { return teamShield;}

// Setters
void Team::setA(std::unique_ptr<Role> newA) noexcept { A = std::move(newA); }
void Team::setB(std::unique_ptr<Role> newB) noexcept { B = std::move(newB); }
void Team::setC(std::unique_ptr<Role> newC) noexcept { C = std::move(newC); }
void Team::setTeamShield(double shield) noexcept { teamShield = std::move(shield); }

std::string Team::getMemberType(Role* member) const {
    if (!member) return "Invalid member";
    switch (member->getType()) {
        case RoleType::Assassin: return "Assassin";
        case RoleType::Doctor:    return "Doctor";
        case RoleType::Archer:    return "Archer";
        case RoleType::Alchemist: return "Alchemist";
        case RoleType::Enchantress: return "Enchantress";
        case RoleType::Monk:    return "Monk";
        case RoleType::Thief:    return "Thief";
        case RoleType::Gladiator: return "Gladiator";
        case RoleType::Knight: return "Knight";
        case RoleType::Warrior:    return "Warrior";
        case RoleType::Druid: return "Druid";
        case RoleType::Mage: return "Mage";
        case RoleType::Necromancer:    return "Necromancer";
        case RoleType::Shaman:    return "Shaman";
        case RoleType::Sorcerer: return "Sorcerer";
        default: return "Unknown";
    }
}