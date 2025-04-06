
#ifndef BATTLE_H
#define BATTLE_H
#include "../Role.h"
#include "../../src/Team/Team.h"
#include <iostream>
#include "../../src/Gameplay/GameReloader.h"
#include "../../src/agility_roles/Archer.h"
#include "../../src/agility_roles/Assassin.h"
#include "../../src/agility_roles/Doctor.h"
#include "../../src/agility_roles/Ecnchantress.h"
#include "../../src/agility_roles/Monk.h"
#include "../../src/agility_roles/Thief.h"
#include "../../src/ancherman_roles/Gladiator.h"
#include "../../src/ancherman_roles/Knight.h"
#include "../../src/ancherman_roles/Warrior.h"
#include "../../src/magic_roles/Alchemist.h"
#include "../../src/magic_roles/Druid.h"
#include "../../src/magic_roles/Mage.h"
#include "../../src/magic_roles/Necromancer.h"
#include "../../src/magic_roles/Shaman.h"
#include "../../src/magic_roles/Sorcerer.h"

class Battle {
    Team team1;
    Team team2;
    int moveCount = 0;
    Role& findMostInjured(Team& team);

public:
    bool isTeamDefeated(Team& team) const;
    Battle(Team t1, Team t2);
    int getMoveCount();
    void setMoveCount(int moveCount_);
    void actionByRole(Role* A, Role* B, std::string& command, Team& my, Team& opponent, bool& isRepeated, bool& isHidden);
    void aiAction(Role* A, Team& myTeam, Team& opponentTeam);
    Role* selectAITarget(Role* attacker, Team& opponentTeam);
    bool shouldHeal(const Role* healer, const Team& team) const;
    void printTeamInfo(const Team& team, const std::string& teamName);
};


#endif //BATTLE_H
