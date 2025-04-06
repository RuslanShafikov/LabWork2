
#ifndef BATTLE_H
#define BATTLE_H
#include "Role.h"
#include "Team.h"
#include <iostream>
#include "GameReloader.h"
#include "Archer.h"
#include "Assassin.h"
#include "Doctor.h"
#include "Ecnchantress.h"
#include "Monk.h"
#include "Thief.h"
#include "Gladiator.h"
#include "Knight.h"
#include "Warrior.h"
#include "Alchemist.h"
#include "Druid.h"
#include "Mage.h"
#include "Necromancer.h"
#include "Shaman.h"
#include "Sorcerer.h"

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
