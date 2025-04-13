
#include "../../headers/Gameplay/Battle.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
std::string roleTypeToString(RoleType type) {
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

Battle::Battle(Team t1, Team t2)
    : team1(std::move(t1)),
      team2(std::move(t2))
{}

bool Battle::isTeamDefeated(Team& team) {
    return (team.getA() == nullptr || team.getA()->getHealth() <= 0) &&
           (team.getB() == nullptr || team.getB()->getHealth() <= 0) &&
           (team.getC() == nullptr || team.getC()->getHealth() <= 0);
}

// Find the most injured (lowest health) team member
Role& Battle::findMostInjured(Team& team) {
    Role* mostInjured = nullptr;
    double minHealth = std::numeric_limits<double>::max();

    auto checkMember = [&](Role* member) {
        if (member && member->getHealth() > 0 && member->getHealth() < minHealth) {
            mostInjured = member;
            minHealth = member->getHealth();
        }
    };

    checkMember(team.getA());
    checkMember(team.getB());
    checkMember(team.getC());

    if (!mostInjured) throw std::runtime_error("No injured members");
    return *mostInjured;
}

void Battle::printTeamInfo(const Team& team, const std::string& teamName) {
    auto printMember = [](Role* member, const std::string& slot) {
        std::cout << std::left << std::setw(12) << slot;

        if(!member) {
            std::cout << "[Empty Slot]\n";
            return;
        }

        std::cout << std::setw(15) << roleTypeToString(member->getType())
                  << " HP: " << std::setw(6) << member->getHealth()
                  << "Healing Potions: " << std::setw(2) << member->getAmountOfHealingPotions()
                  << "Explosive Potions: " << std::setw(2) << member->getAmountOfExplosivePotions()
                  << " Poison: " << (member->getPoisonEffect() ? "Yes" : "No")
                  << "\n";
    };

    printMember(team.getA(), "Member A:");
    printMember(team.getB(), "Member B:");
    printMember(team.getC(), "Member C:");
    std::cout << "Team Shield: " << team.getTeamShield() << "\n";
}


int Battle::getMoveCount() const { return moveCount; }
void Battle::setMoveCount(int moveCount_) { moveCount = moveCount_; }
void Battle::actionByRole(Role* A, Role* B, std::string & command, std::string & mode, Team& my, Team &opponent, bool& isRepeated, bool& isHidden) {
    if (!A || !B) {
        std::cout << "Invalid target!" << std::endl;
        return;
    }
    if (mode=="standard") {
        if (A->getType() == RoleType::Doctor) {
            Doctor* doctor = dynamic_cast<Doctor*>(A);
            if (command == "heal") {
                doctor->heal(*B);
            }

            else if (command == "attack") {
                doctor->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                doctor->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                doctor->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                doctor->healFromPoison(*B);
            }

        }

        else if(A->getType() == RoleType::Archer) {
            Archer* archer = dynamic_cast<Archer*>(A);
            if (command == "poisonAttack") {
                archer->poisonousArrowAttack(*B);
            }

            else if (command == "attack") {
                archer->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                archer->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                archer->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                archer->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Assassin) {
            Assassin* assassin = dynamic_cast<Assassin*>(A);
            if (command == "assassinate") {
                assassin->assassinate(*B);
            }

            else if (command == "attack") {
                assassin->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                assassin->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                assassin->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                assassin->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Enchantress) {
            Enchantress* enchantress = dynamic_cast<Enchantress*>(A);
            if (command == "charm") {
                enchantress->charm(opponent);
            }

            else if (command =="deathKissAttack") {
                enchantress->deathKissAttack(*B);
            }

            else if (command == "attack") {
                enchantress->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                enchantress->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                enchantress->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                enchantress->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Monk) {
            Monk* monk = dynamic_cast<Monk*>(A);
            if (command == "amplify") {
                monk->amplify(*B);
            }

            else if (command == "attack") {
                monk->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                monk->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                monk->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                monk->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Thief) {
            auto thief = dynamic_cast<Thief*>(A);
            if (command == "stole") {
                isRepeated = thief->isStolen();
            }

            else if (command == "attack") {
                thief->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                thief->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                thief->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                thief->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Gladiator) {
            Gladiator* gladiator = dynamic_cast<Gladiator*>(A);
            if (command == "deathFeelingAttack") {
                gladiator->deathFeeling(*B);
            }

            else if (command == "attack") {
                gladiator->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                gladiator->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                gladiator->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                gladiator->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Gladiator) {
            Gladiator* gladiator = dynamic_cast<Gladiator*>(A);
            if (command == "deathFeelingAttack") {
                gladiator->deathFeeling(*B);
            }

            else if (command == "attack") {
                gladiator->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                gladiator->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                gladiator->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                gladiator->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Knight) {
            Knight* knight = dynamic_cast<Knight*>(A);
            if (command == "splashAttack") {
                knight->splashAttack(opponent);
            }

            else if (command == "attack") {
                knight->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                knight->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                knight->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                knight->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Warrior) {
            Warrior* warrior = dynamic_cast<Warrior*>(A);
            if (command == "lastAttack") {
                warrior->lastBreathAttack(*B);
            }

            else if (command == "attack") {
                warrior->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                warrior->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                warrior->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                warrior->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Alchemist) {
            Alchemist* alchemist = dynamic_cast<Alchemist*>(A);
            if (command == "createExplosivePotion") {
                alchemist->createExplosivePotion();
            }

            else if (command == "createHealingPotion") {
                alchemist->createHealingPotion();
            }

            else if (command == "attack") {
                alchemist->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                alchemist->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                alchemist->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                alchemist->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Druid) {
            Druid* druid = dynamic_cast<Druid*>(A);
            if (command == "hide") {

                isHidden = druid->hide();
            }

            else if (command == "attack") {
                druid->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                druid->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                druid->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                druid->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Mage) {
            Mage* mage = dynamic_cast<Mage*>(A);
            if (command == "shield") {

                my.setTeamShield(my.getTeamShield()+mage->shield());
            }

            else if (command == "attack") {
                mage->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                mage->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                mage->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                mage->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Necromancer) {
            Necromancer* necromancer = dynamic_cast<Necromancer*>(A);
            if (command == "arise") {

                necromancer->arise(*B);
            }

            else if (command == "attack") {
                necromancer->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                necromancer->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                necromancer->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                necromancer->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Shaman) {
            Shaman* shaman = dynamic_cast<Shaman*>(A);
            if (command == "deafen") {

                shaman->deafen(*B);
            }

            else if (command == "attack") {
                shaman->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                shaman->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                shaman->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                shaman->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Sorcerer) {
            Sorcerer* sorcerer = dynamic_cast<Sorcerer*>(A);
            if (command == "doubleMagicAttack") {
                sorcerer->doubleMagicAttack(*B);
            }

            else if (command == "attack") {
                sorcerer->basicAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                sorcerer->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                sorcerer->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                sorcerer->healFromPoison(*B);
            }
        }

        else{
            std::cout<<"What happened"<<std::endl;
        }
    }
    else {
        if (A->getType() == RoleType::Doctor) {
            Doctor* doctor = dynamic_cast<Doctor*>(A);
            if (command == "heal") {
                doctor->heal(*B);
            }

            else if (command == "attack") {
                doctor->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                doctor->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                doctor->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                doctor->healFromPoison(*B);
            }

        }

        else if(A->getType() == RoleType::Archer) {
            Archer* archer = dynamic_cast<Archer*>(A);
            if (command == "poisonAttack") {
                archer->poisonousArrowAttack(*B);
            }

            else if (command == "attack") {
                archer->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                archer->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                archer->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                archer->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Assassin) {
            Assassin* assassin = dynamic_cast<Assassin*>(A);
            if (command == "assassinate") {
                assassin->assassinate(*B);
            }

            else if (command == "attack") {
                assassin->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                assassin->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                assassin->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                assassin->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Enchantress) {
            Enchantress* enchantress = dynamic_cast<Enchantress*>(A);
            if (command == "charm") {
                enchantress->charm(opponent);
            }

            else if (command =="deathKissAttack") {
                enchantress->deathKissAttack(*B);
            }

            else if (command == "attack") {
                enchantress->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                enchantress->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                enchantress->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                enchantress->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Monk) {
            Monk* monk = dynamic_cast<Monk*>(A);
            if (command == "amplify") {
                monk->amplify(*B);
            }

            else if (command == "attack") {
                monk->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                monk->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                monk->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                monk->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Thief) {
            auto thief = dynamic_cast<Thief*>(A);
            if (command == "stole") {
                isRepeated = thief->isStolen();
            }

            else if (command == "attack") {
                thief->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                thief->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                thief->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                thief->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Gladiator) {
            Gladiator* gladiator = dynamic_cast<Gladiator*>(A);
            if (command == "deathFeelingAttack") {
                gladiator->deathFeeling(*B);
            }

            else if (command == "attack") {
                gladiator->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                gladiator->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                gladiator->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                gladiator->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Gladiator) {
            Gladiator* gladiator = dynamic_cast<Gladiator*>(A);
            if (command == "deathFeelingAttack") {
                gladiator->deathFeeling(*B);
            }

            else if (command == "attack") {
                gladiator->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                gladiator->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                gladiator->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                gladiator->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Knight) {
            Knight* knight = dynamic_cast<Knight*>(A);
            if (command == "splashAttack") {
                knight->splashAttack(opponent);
            }

            else if (command == "attack") {
                knight->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                knight->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                knight->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                knight->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Warrior) {
            Warrior* warrior = dynamic_cast<Warrior*>(A);
            if (command == "lastAttack") {
                warrior->lastBreathAttack(*B);
            }

            else if (command == "attack") {
                warrior->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                warrior->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                warrior->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                warrior->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Alchemist) {
            Alchemist* alchemist = dynamic_cast<Alchemist*>(A);
            if (command == "createExplosivePotion") {
                alchemist->createExplosivePotion();
            }

            else if (command == "createHealingPotion") {
                alchemist->createHealingPotion();
            }

            else if (command == "attack") {
                alchemist->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                alchemist->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                alchemist->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                alchemist->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Druid) {
            Druid* druid = dynamic_cast<Druid*>(A);
            if (command == "hide") {

                isHidden = druid->hide();
            }

            else if (command == "attack") {
                druid->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                druid->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                druid->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                druid->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Mage) {
            Mage* mage = dynamic_cast<Mage*>(A);
            if (command == "shield") {

                my.setTeamShield( my.getTeamShield()+mage->shield());
            }

            else if (command == "attack") {
                mage->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                mage->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                mage->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                mage->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Necromancer) {
            Necromancer* necromancer = dynamic_cast<Necromancer*>(A);
            if (command == "arise") {

                necromancer->arise(*B);
            }

            else if (command == "attack") {
                necromancer->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                necromancer->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                necromancer->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                necromancer->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Shaman) {
            Shaman* shaman = dynamic_cast<Shaman*>(A);
            if (command == "deafen") {

                shaman->deafen(*B);
            }

            else if (command == "attack") {
                shaman->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                shaman->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                shaman->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                shaman->healFromPoison(*B);
            }
        }

        else if(A->getType() == RoleType::Sorcerer) {
            Sorcerer* sorcerer = dynamic_cast<Sorcerer*>(A);
            if (command == "doubleMagicAttack") {
                sorcerer->doubleMagicAttack(*B);
            }

            else if (command == "attack") {
                sorcerer->basicFixedAttack(*B);
            }

            else if (command == "giveHealingPotion") {
                sorcerer->giveHealingPotion(*B);
            }

            else if (command == "giveExplosivePotion") {
                sorcerer->giveExplosivePotion(*B);
            }

            else if (command == "healFromPoison") {
                sorcerer->healFromPoison(*B);
            }
        }

    }
}


void Battle::aiAction(Role* A, Team& myTeam, std::string & mode, Team& opponentTeam) {
    if(!A || A->getHealth() <= 0) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    Role* target = nullptr;
    std::string command;
    bool isRepeated = false;
    bool isHidden = false;

    try {
        if(A->getAmountOfHealingPotions() > 0 && A->getHealth() < 50) {
            command = "healFromPoison";
            actionByRole(A, A, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            return;
        }

        if(auto doctor = dynamic_cast<Doctor*>(A)) {
            if(dis(gen) < 70 && shouldHeal(A, myTeam)) {
                Role& injured = findMostInjured(myTeam);
                command = "heal";
                actionByRole(A, &injured, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            } else {
                command = "attack";
                target = selectAITarget(A, opponentTeam);
                actionByRole(A, target, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            }
        }
        else if(auto assassin = dynamic_cast<Assassin*>(A)) {
            if(dis(gen) < 40) {
                command = "assassinate";
                target = selectAITarget(A, opponentTeam);
                actionByRole(A, target, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            } else {
                command = "attack";
                target = selectAITarget(A, opponentTeam);
                actionByRole(A, target, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            }
        }
        else if(auto mage = dynamic_cast<Mage*>(A)) {
            if(myTeam.getTeamShield() < 20 && dis(gen) < 60) {
                command = "shield";
                actionByRole(A, nullptr, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            } else {
                command = "attack";
                target = selectAITarget(A, opponentTeam);
                actionByRole(A, target, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            }
        }
        else {
            if(dis(gen) < 20 && A->getAmountOfHealingPotions() > 0) {
                command = "giveHealingPotion";
                Role* ally = selectAITarget(A, myTeam);
                actionByRole(A, ally, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            } else {
                command = "attack";
                target = selectAITarget(A, opponentTeam);
                actionByRole(A, target, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
            }
        }
    } catch(const std::exception& e) {
        command = "attack";
        target = selectAITarget(A, opponentTeam);
        actionByRole(A, target, command, mode, myTeam, opponentTeam, isRepeated, isHidden);
    }
}

Role* Battle::selectAITarget(Role* attacker, Team& targetTeam) {
    std::vector<Role*> candidates;
    if(targetTeam.getA() && targetTeam.getA()->getHealth() > 0) candidates.push_back(targetTeam.getA());
    if(targetTeam.getB() && targetTeam.getB()->getHealth() > 0) candidates.push_back(targetTeam.getB());
    if(targetTeam.getC() && targetTeam.getC()->getHealth() > 0) candidates.push_back(targetTeam.getC());

    if(candidates.empty()) return nullptr;

    std::sort(candidates.begin(), candidates.end(), [](Role* a, Role* b) {
        return a->getHealth() < b->getHealth();
    });

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    if(dis(gen) < 70) return candidates.front();

    std::shuffle(candidates.begin(), candidates.end(), gen);
    return candidates.front();
}

bool Battle::shouldHeal(const Role* healer, const Team& team) const {
    const double healThreshold = 50.0;
    return (team.getA() && team.getA()->getHealth() < healThreshold) ||
           (team.getB() && team.getB()->getHealth() < healThreshold) ||
           (team.getC() && team.getC()->getHealth() < healThreshold);
}
