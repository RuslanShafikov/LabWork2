
#ifndef BATTLE_H
#define BATTLE_H
#include "../Team/Role.h"
#include "../Team/Team.h"
#include <iostream>
#include "GameReloader.h"
#include "../Agility_roles/Archer.h"
#include "../Agility_roles/Assassin.h"
#include "../Agility_roles/Doctor.h"
#include "../Agility_roles/Ecnchantress.h"
#include "../Agility_roles/Monk.h"
#include "../Agility_roles/Thief.h"
#include "../Ancherman_roles/Gladiator.h"
#include "../Ancherman_roles/Knight.h"
#include "../Ancherman_roles/Warrior.h"
#include "../Magic_roles/Alchemist.h"
#include "../Magic_roles/Druid.h"
#include "../Magic_roles/Mage.h"
#include "../Magic_roles/Necromancer.h"
#include "../Magic_roles/Shaman.h"
#include "../Magic_roles/Sorcerer.h"

class Battle {
    Team team1;
    Team team2;
    int moveCount = 0;
    Role& findMostInjured(Team& team);

public:
    static bool isTeamDefeated(Team& team) ;
    Battle(Team t1, Team t2);
    int getMoveCount() const;
    void setMoveCount(int moveCount_);
    void actionByRole(Role* A, Role* B, std::string& command, std::string & mode, Team& my, Team& opponent, bool& isRepeated, bool& isHidden);
    void aiAction(Role* A, Team& myTeam, std::string & mode, Team& opponentTeam);
    Role* selectAITarget(Role* attacker, Team& opponentTeam);
    bool shouldHeal(const Role* healer, const Team& team) const;
    void printTeamInfo(const Team& team, const std::string& teamName);
};


#endif //BATTLE_H
