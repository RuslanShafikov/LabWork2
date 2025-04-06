#ifndef TEAM_CREATOR_H
#define TEAM_CREATOR_H

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>
#include "../../src/Role.h"
#include "../../src/Team/Team.h"
#include "../../src/magic_roles/Alchemist.h"
#include "../../src/magic_roles/Druid.h"
#include "../../src/magic_roles/Mage.h"
#include "../../src/magic_roles/Necromancer.h"
#include "../../src/magic_roles/Shaman.h"
#include "../../src/magic_roles/Sorcerer.h"
#include "../../src/Gameplay/GameReloader.h"
#include "../../src/Role.h"
#include "../../src/agility_roles/Archer.h"
#include "../../src/agility_roles/Assassin.h"
#include "../../src/agility_roles/Doctor.h"
#include "../../src/agility_roles/Ecnchantress.h"
#include "../../src/agility_roles/Monk.h"
#include "../../src/agility_roles/Thief.h"
#include "../../src/ancherman_roles/Gladiator.h"
#include "../../src/ancherman_roles/Knight.h"
#include "../../src/ancherman_roles/Warrior.h"
class TeamCreator {
private:
    const std::unordered_map<std::string, std::vector<int>> roleBaseStats = {
        {"monk",        {6, 5, 5, 200, 10}},
        {"assassin",    {6, 5, 5, 200, 10}},
        {"archer",      {6, 5, 5, 200, 10}},
        {"enchantress", {6, 5, 5, 200, 10}},
        {"doctor",      {6, 5, 5, 250, 10}},
        {"gladiator",   {5, 6, 5, 200, 10}},
        {"knight",      {5, 6, 5, 200, 10}},
        {"thief",       {7, 5, 5, 200, 10}},
        {"warrior",     {5, 7, 5, 200, 10}},
        {"alchemist",   {5, 5, 6, 200, 10}},
        {"druid",       {5, 5, 6, 200, 10}},
        {"mage",        {5, 5, 7, 200, 10}},
        {"necromancer", {5, 5, 6, 200, 10}},
        {"shaman",      {5, 5, 6, 200, 10}},
        {"sorcerer",    {5, 5, 6, 200, 10}}
    };
    std::vector<std::string> getAvailableRoles() const;
    public:
        std::unique_ptr<Role> createRole(const std::string& roleName);
        Team createTeam(const std::vector<std::string>& roleNames, double shield);
        Team createRandomTeam();
    };

#endif // TEAM_CREATOR_H