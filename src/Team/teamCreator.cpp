#include "teamCreator.h"
#include <stdexcept>
std::vector<std::string> TeamCreator::getAvailableRoles() const {
    std::vector<std::string> roles;
    for (const auto& entry : roleBaseStats) {
        roles.push_back(entry.first);
    }
    return roles;
}

std::unique_ptr<Role> TeamCreator::createRole(const std::string& roleName) {
    const std::string lowerName = [&]{
        std::string s;
        for (char c : roleName) s += tolower(c);
        return s;
    }();

    const auto& stats = roleBaseStats.find(lowerName);
    if (stats == roleBaseStats.end()) {
        throw std::invalid_argument("Unknown role " + roleName);
    }


    const int DEFAULT_POTIONS = 0;
    const bool DEFAULT_POISON = false;


    if (lowerName == "monk")
        return std::make_unique<Monk>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "assassin")
        return std::make_unique<Assassin>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "archer")
        return std::make_unique<Archer>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "enchantress")
        return std::make_unique<Enchantress>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "doctor")
        return std::make_unique<Doctor>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "gladiator")
        return std::make_unique<Gladiator>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "knight")
        return std::make_unique<Knight>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "thief")
        return std::make_unique<Thief>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "warrior")
        return std::make_unique<Warrior>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "alchemist")
        return std::make_unique<Alchemist>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "druid")
        return std::make_unique<Druid>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "mage")
        return std::make_unique<Mage>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "necromancer")
        return std::make_unique<Necromancer>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "shaman")
        return std::make_unique<Shaman>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    else if (lowerName == "sorcerer")
        return std::make_unique<Sorcerer>(
            stats->second[0], stats->second[1], stats->second[2],
            stats->second[3], stats->second[4],
            DEFAULT_POTIONS, DEFAULT_POTIONS, DEFAULT_POISON
        );

    throw std::runtime_error("Unknown role: " + roleName);
}


Team TeamCreator::createTeam(const std::vector<std::string>& roleNames, double shield) {
    if (roleNames.size() != 3) {
        throw std::invalid_argument("A team must have exactly 3 members");
    }

    return Team(
        createRole(roleNames[0]),
        createRole(roleNames[1]),
        createRole(roleNames[2]),
        shield
    );
}

Team TeamCreator::createRandomTeam() {
    const std::vector<std::string> availableRoles = getAvailableRoles();
    if (availableRoles.empty()) {
        throw std::runtime_error("No roles available to create a team");
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<size_t> dist(0, availableRoles.size() - 1);

    std::vector<std::string> selectedRoles;
    for (int i = 0; i < 3; ++i) {
        size_t index = dist(rng);
        selectedRoles.push_back(availableRoles[index]);
    }

    return createTeam(selectedRoles, 0.0);
}

