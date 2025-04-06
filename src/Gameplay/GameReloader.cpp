#include "GameReloader.h"
#include "../Role.h"
#include <fstream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "../agility_roles/Archer.h"
#include "../agility_roles/Assassin.h"
#include "../agility_roles/Doctor.h"
#include "../agility_roles/Ecnchantress.h"
#include "../agility_roles/Monk.h"
#include "../agility_roles/Thief.h"
#include "../ancherman_roles/Gladiator.h"
#include "../ancherman_roles/Knight.h"
#include "../ancherman_roles/Warrior.h"
#include "../magic_roles/Alchemist.h"
#include "../magic_roles/Druid.h"
#include "../magic_roles/Mage.h"
#include "../magic_roles/Necromancer.h"
#include "../magic_roles/Shaman.h"
#include "../magic_roles/Sorcerer.h"
#include <sstream>
#include <string>
std::unique_ptr<Role> createGameRole(const std::string& line) {
    std::istringstream ss(line);
    std::string className;
    int agi, str, intel, crit, heal, exp;
    double hp;
    std::string isPoisonousStr;

    if (!(ss >> className >> agi >> str >> intel >> hp >> crit >> heal >> exp >> isPoisonousStr)) {
        throw std::runtime_error("Invalid role data format");
    }

    bool isPoisonous = (isPoisonousStr == "t");

    if (className == "Assassin") {
        return std::make_unique<Assassin>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Necromancer") {
        return std::make_unique<Necromancer>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Archer") {
        return std::make_unique<Archer>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Doctor") {
        return std::make_unique<Doctor>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Enchantress") {
        return std::make_unique<Enchantress>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Monk") {
        return std::make_unique<Monk>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Thief") {
        return std::make_unique<Thief>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Gladiator") {
        return std::make_unique<Gladiator>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Knight") {
        return std::make_unique<Knight>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Warrior") {
        return std::make_unique<Warrior>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Alchemist") {
        return std::make_unique<Alchemist>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Druid") {
        return std::make_unique<Druid>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Mage") {
        return std::make_unique<Mage>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Shaman") {
        return std::make_unique<Shaman>(agi, str, intel, hp, crit, heal, exp, isPoisonous);
    } else if (className == "Sorcerer") {
            return std::make_unique<Sorcerer>(agi, str, intel, hp, crit, heal, exp, isPoisonous);}


    else{
    throw std::runtime_error("Unsupported class: " + className);
  }
}

// Forward declaration for factory function
std::unique_ptr<Role> createRole(const std::string& className, int agi, int str, int intel, double hp, int crit, int heal, int exp, bool isPoisonous);

std::pair<Team, Team> GameReloader::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    if (lines.size() != 8) {
        throw std::runtime_error("Invalid file format. Expected 8 lines.");
    }

    // Parse Team A (lines 0-2: roles, line 3: shield)
    auto a1 = createGameRole(lines[0]);
    auto a2 = createGameRole(lines[1]);
    auto a3 = createGameRole(lines[2]);
    double shieldA = std::stod(lines[3]);

    // Parse Team B (lines 4-6: roles, line 7: shield)
    auto b1 = createGameRole(lines[4]);
    auto b2 = createGameRole(lines[5]);
    auto b3 = createGameRole(lines[6]);
    double shieldB = std::stod(lines[7]);

    Team teamA(std::move(a1), std::move(a2), std::move(a3), shieldA);
    Team teamB(std::move(b1), std::move(b2), std::move(b3), shieldB);

    return {std::move(teamA), std::move(teamB)};


}

std::string roleTypeToClassName(RoleType type) {
    switch(type) {
        case RoleType::Assassin:    return "Assassin";
        case RoleType::Doctor:      return "Doctor";
        case RoleType::Archer:      return "Archer";
        case RoleType::Enchantress: return "Enchantress";
        case RoleType::Monk:        return "Monk";
        case RoleType::Thief:       return "Thief";
        case RoleType::Gladiator:   return "Gladiator";
        case RoleType::Knight:      return "Knight";
        case RoleType::Warrior:     return "Warrior";
        case RoleType::Alchemist:   return "Alchemist";
        case RoleType::Druid:       return "Druid";
        case RoleType::Mage:        return "Mage";
        case RoleType::Necromancer: return "Necromancer";
        case RoleType::Shaman:      return "Shaman";
        case RoleType::Sorcerer:    return "Sorcerer";
        default:                    return "Unknown";
    }
}

void GameReloader::saveGame(const Team& teamA, const Team& teamB, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to save game to: " + filename);
    }

    auto writeRole = [&](const Role* role) {
        file << roleTypeToClassName(role->getType()) << " "
             << role->getAgility() << " "
             << role->getStrength() << " "
             << role->getIntelligence() << " "
             << role->getHealth() << " "
             << role->getCritChance() << " "
             << role->getAmountOfHealingPotions() << " "
             << role->getAmountOfExplosivePotions() << " "
             << (role->getPoisonEffect() ? "t" : "f") << "\n";
    };

    writeRole(teamA.getA());
    writeRole(teamA.getB());
    writeRole(teamA.getC());
    file << teamA.getTeamShield() << "\n";

    // Save Team B
    writeRole(teamB.getA());
    writeRole(teamB.getB());
    writeRole(teamB.getC());
    file << teamB.getTeamShield() << "\n";
}