/*# LabWork2
Shafikov Ruslan Alvirtovich, group 24.Б83 - мм
st112650@stdudent.spbu.ru
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "../headers/Agility_roles/Archer.h"
#include "../headers/Agility_roles/Assassin.h"
#include "../headers/Agility_roles/Doctor.h"
#include "../headers/Agility_roles/Ecnchantress.h"
#include "../headers/Agility_roles/Monk.h"
#include "../headers/Agility_roles/Thief.h"
#include "../headers/Ancherman_roles/Gladiator.h"
#include "../headers/Ancherman_roles/Knight.h"
#include "../headers/Ancherman_roles/Warrior.h"
#include "../headers/Magic_roles/Alchemist.h"
#include "../headers/Magic_roles/Druid.h"
#include "../headers/Magic_roles/Mage.h"
#include "../headers/Team/teamCreator.h"
#include "../headers/Magic_roles/Shaman.h"
#include "../headers/Magic_roles/Sorcerer.h"
#include "../headers/Magic_roles/Necromancer.h"
#include "../headers/Gameplay/GameReloader.h"
#include "../headers/Gameplay/Battle.h"
#include <unordered_set>
bool isCommandValid(RoleType type, const std::string& command) {
    static const std::unordered_map<RoleType, std::unordered_set<std::string>> commandMap = {
        {RoleType::Assassin,    {"assassinate", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Doctor,      {"heal", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Archer,      {"poisonAttack", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Enchantress, {"charm", "deathKissAttack", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Monk,        {"amplify", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Thief,       {"stole", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Gladiator,   {"deathFeelingAttack", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Knight,      {"splashAttack", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Warrior,     {"lastAttack", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Alchemist,   {"createExplosivePotion", "createHealingPotion", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Druid,       {"hide", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Mage,        {"shield", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Necromancer, {"arise", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Shaman,      {"deafen", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}},
        {RoleType::Sorcerer,    {"doubleMagicAttack", "attack", "giveHealingPotion", "giveExplosivePotion", "healFromPoison"}}
    };

    auto it = commandMap.find(type);
    if (it == commandMap.end()) {
        return false;
    }

    return it->second.find(command) != it->second.end();
}

bool isValidRoleName(std::string &input) {
    const std::vector<std::string> validRoles = {
        "monk", "assassin", "archer", "enchantress", "doctor",
        "gladiator", "knight", "thief", "warrior", "alchemist",
        "druid", "mage", "necromancer", "shaman", "sorcerer"
    };

    std::string lowerInput;
    for (char c: input) {
        lowerInput += tolower(c);
    }

    return std::find(validRoles.begin(), validRoles.end(), lowerInput) != validRoles.end();
}

void displayRoleOptions() {
    std::cout<<"Basic Role functions: "<<std::endl;

    std::cout<<"attack"<<std::endl;

    std::cout<<"giveHealingPotion"<<std::endl;

    std::cout<<"giveExplosivePotion"<<std::endl;

    std::cout<<"healFromPoison"<<std::endl;

    std::cout<< "=== CHOOSE YOUR ROLE ===\n\n";

    std::cout << "1. Monk\n";
    std::cout << "   - Special Ability: amplify\n";
    std::cout << "   - Doubles an ally's critical hit chance\n\n";
    std::cout << "   - max attack characteristic is 5\n";

    std::cout << "2. Assassin\n";
    std::cout << "   - Special Ability: assassinate\n";
    std::cout << "   - 20% chance to instantly kill an opponent\n\n";
    std::cout << "   - max attack characteristic is 5\n";

    std::cout << "3. Archer\n";
    std::cout << "   - Special Ability: poisonAttack\n";
    std::cout << "   - Deals intelligence-based poison damage (consumes explosive potions)\n";
    std::cout << "   - 20% chance for an additional hit\n\n";
    std::cout << "   - max attack characteristic is 5\n";

    std::cout << "4. Enchantress\n";
    std::cout << "   - Special Ability: charm\n";
    std::cout << "   - 30% chance to charm an opponent\n";
    std::cout << "   - deathKissAttack: 30% chance instant kill\n\n";
    std::cout << "   - max attack characteristic is 5\n";

    std::cout << "5. Doctor\n";
    std::cout << "   - Special Ability: heal\n";
    std::cout << "   - Restores 30% of missing health to an ally\n\n";
    std::cout << "   - max attack characteristic is 5\n";

    std::cout << "6. Gladiator\n";
    std::cout << "   - Special Ability: deathFeelingAttack\n";
    std::cout << "   - Chance to instantly kill weakened opponents (health ≤ 50)\n";
    std::cout << "   - Higher agility increases success chance\n\n";
    std::cout << "   - max attack characteristic is 6\n";

    std::cout << "7. Knight\n";
    std::cout << "   - Special Ability: splashAttack\n";
    std::cout << "   - Deals reduced damage to all enemies\n\n";
    std::cout << "   - max attack characteristic is 6\n";

    std::cout << "8. Thief\n";
    std::cout << "   - Special Ability: Steal\n";
    std::cout << "   - 30% chance to steal opponent's move\n\n";
    std::cout << "   - max attack characteristic is 5\n";

    std::cout << "9. Warrior\n";
    std::cout << "   - Special Ability: lastAttack\n";
    std::cout << "   - When health < 50, 20% chance for powerful attack\n\n";
    std::cout << "   - max attack characteristic is 7\n";

    std::cout << "10. Alchemist\n";
    std::cout << "   - Special Abilities:\n";
    std::cout << "     - createHealing/Explosive Potions\n";
    std::cout << "     - Give Potions to allies\n\n";
    std::cout << "   - max attack characteristic is 5\n";

    std::cout << "11. Druid\n";
    std::cout << "   - Special Ability: hide\n";
    std::cout << "   - 30% chance to avoid attacks\n\n";
    std::cout << "   - max attack characteristic is 6\n";

    std::cout << "12. Mage\n";
    std::cout << "   - Special Ability: shield\n";
    std::cout << "   - Random damage reduction (1-20)\n\n";
    std::cout << "   - max attack characteristic is 7\n";

    std::cout << "13. Necromancer\n";
    std::cout << "   - Special Ability: arise\n";
    std::cout << "   - Revives dead allies with 50 health\n\n";
    std::cout << "   - max attack characteristic is 6\n";

    std::cout << "14. Shaman\n";
    std::cout << "   - Special Ability: deafen\n";
    std::cout << "   - 20% chance to silence opponents\n\n";
    std::cout << "   - max attack characteristic is 6\n";

    std::cout << "15. Sorcerer\n";
    std::cout << "   - Special Ability: doubleMagicAttack\n";
    std::cout << "   - 20% chance to attack twice\n\n";
    std::cout << "   - max attack characteristic is 6\n\n";

    std::cout<<"In fixed mode damage = (max_attack_characteristic - 1) * 10.4\n";
}

bool isCorrectNum(int num) {
    if (num > 0 && num < 7) {
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    std::string name, isCurr, role1, role2, role3, command, mode = "";
    std::cout << "Enter your name" << std::endl;
    std::cin >> name;
    std::cout << "Do you want to use your current game?" << std::endl;
    std::cin >> isCurr;
    if (isCurr == "yes") {
        std::pair<Team, Team> a = GameReloader::readFile("base.txt");
        std::cout << "Welcome to the game " << name << std::endl;
        std::ifstream in_file("mode.txt");

        if (in_file.is_open()) {
            mode.assign(
                std::istreambuf_iterator<char>(in_file),
                std::istreambuf_iterator<char>()
            );
            in_file.close();
            std::cout << "Loaded mode: " << mode << std::endl;
        } else {
            std::cerr << "Error reading file!" << std::endl;
            return 1;
        }
        Team teamA = a.first;
        Team teamB = a.second;
        int num = 0;
        Battle battle(teamA, teamB);
        bool isRepeated = true;
        bool isHidden = false;
        std::cout << teamA.getA()->getHealth() << std::endl;
        std::cout << teamB.getA()->getHealth() << std::endl;
        while (!(battle.isTeamDefeated(teamA) || battle.isTeamDefeated(teamB))) {
            std::cout << "Move " << battle.getMoveCount() + 1 << std::endl;
            std::cout << "Your team current stats" << std::endl;
            battle.printTeamInfo(teamA, "teamA");
            std::cout << "Your opponent team current stats" << std::endl;
            battle.printTeamInfo(teamB, "teamB");
            while (isRepeated) {
                isRepeated = false;
                if (teamA.getA()->getHealth() > 0) {
                    std::cout << "Enter the command for your first team member" << std::endl;
                    std::cin >> command;
                    std::cout <<
                            "Enter the number from 1 to 6 where 1-3 your team members, 4-6 - opponents to perform action"
                            << std::endl;
                    std::cin >> num;
                  /*  while (!isCorrectNum((num))) {
                        std::cout<<"Enter the number from 1 to 6"<<std::endl;
                        std::cin>>num;
                    }*/
                    if (num < 1 || num > 6) {
                        std::cout << "You lost in numbers!" << std::endl;
                        return 1;
                    }
                    if (num == 4) {
                        battle.actionByRole(teamA.getA(), teamB.getA(), command,mode, teamA, teamB, isRepeated, isHidden);
                    } else if (num == 5) {
                        battle.actionByRole(teamA.getA(), teamB.getB(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 6) {
                        battle.actionByRole(teamA.getA(), teamB.getC(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 1) {
                        battle.actionByRole(teamA.getA(), teamA.getA(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 2) {
                        battle.actionByRole(teamA.getA(), teamA.getB(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 3) {
                        battle.actionByRole(teamA.getA(), teamA.getC(), command, mode, teamA, teamB, isRepeated, isHidden);
                    }
                }
                teamA.getA()->setHealth(teamA.getA()->getHealth() + teamA.getTeamShield() / 2);
            }
            isRepeated = true;
            while (isRepeated) {
                isRepeated = false;
                if (teamA.getB()->getHealth() > 0) {
                    std::cout << "Enter the command for your second team member" << std::endl;
                    std::cin >> command;
                    std::cout <<
                            "Enter the number from 1 to 6 where 1-3 your team members, 4-6 - opponents to perform action"
                            << std::endl;
                    std::cin >> num;
                    while (!isCorrectNum((num))) {
                        std::cout<<"Enter the number from 1 to 6"<<std::endl;
                        std::cin>>num;
                    }
                    if (num < 1 || num > 6) {
                        std::cout << "You lost in numbers!" << std::endl;
                        return 1;
                    }
                    if (num == 4) {
                        battle.actionByRole(teamA.getB(), teamB.getA(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 5) {
                        battle.actionByRole(teamA.getB(), teamB.getB(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 6) {
                        battle.actionByRole(teamA.getB(), teamB.getC(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 1) {
                        battle.actionByRole(teamA.getB(), teamA.getA(), command,mode, teamA, teamB, isRepeated, isHidden);
                    } else if (num == 2) {
                        battle.actionByRole(teamA.getB(), teamA.getB(), command,mode, teamA, teamB, isRepeated, isHidden);
                    } else if (num == 3) {
                        battle.actionByRole(teamA.getB(), teamA.getC(), command, mode,teamA, teamB, isRepeated, isHidden);
                    }
                }
                teamA.getB()->setHealth(teamA.getB()->getHealth() + teamA.getTeamShield() / 2);
            }
            isRepeated = true;
            while (isRepeated) {
                isRepeated = false;
                if (teamA.getC()->getHealth() > 0) {
                    std::cout << "Enter the command for your third team member" << std::endl;
                    std::cin >> command;
                    std::cout <<
                            "Enter the number from 1 to 6 where 1-3 your team members, 4-6 - opponents to perform action"
                            << std::endl;
                    std::cin >> num;
                    while (!isCorrectNum((num))) {
                        std::cout<<"Enter the number from 1 to 6"<<std::endl;
                        std::cin>>num;
                    }
                    if (num < 1 || num > 6) {
                        std::cout << "You lost in numbers!" << std::endl;
                        return 1;
                    }
                    if (num == 4) {
                        battle.actionByRole(teamA.getC(), teamB.getA(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 5) {
                        battle.actionByRole(teamA.getC(), teamB.getB(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 6) {
                        battle.actionByRole(teamA.getC(), teamB.getC(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 1) {
                        battle.actionByRole(teamA.getC(), teamA.getA(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 2) {
                        battle.actionByRole(teamA.getC(), teamA.getB(), command, mode,teamA, teamB, isRepeated, isHidden);
                    } else if (num == 3) {
                        battle.actionByRole(teamA.getC(), teamA.getC(), command, mode,teamA, teamB, isRepeated, isHidden);
                    }
                }
                teamA.getC()->setHealth(teamA.getC()->getHealth() + teamA.getTeamShield() / 2);
            }
            isRepeated = true;
            while (isRepeated) {
                isRepeated = false;
                if (teamB.getA()->getHealth() > 0) {
                    battle.aiAction(teamB.getA(), teamB, mode, teamA);
                    teamB.getA()->setHealth(teamB.getA()->getHealth() + teamB.getTeamShield() / 2);
                }
            }
            isRepeated = true;
            while (isRepeated) {
                isRepeated = false;
                if (teamB.getB()->getHealth() > 0) {
                    battle.aiAction(teamB.getB(), teamB, mode, teamA);
                    teamB.getB()->setHealth(teamB.getB()->getHealth() + teamB.getTeamShield() / 2);
                }
            }
            isRepeated = true;
            while (isRepeated) {
                isRepeated = false;
                if (teamB.getC()->getHealth() > 0) {
                    battle.aiAction(teamB.getC(), teamB, mode, teamA);
                    teamB.getC()->setHealth(teamB.getC()->getHealth() + teamB.getTeamShield() / 2);
                }
            }
            isRepeated = true;
            if (teamA.getA()->getPoisonEffect()) {
                teamA.getA()->setHealth(teamA.getA()->getHealth() - 10.0);
            }
            if (teamA.getB()->getPoisonEffect()) {
                teamA.getB()->setHealth(teamA.getB()->getHealth() - 10.0);
            }
            if (teamA.getC()->getPoisonEffect()) {
                teamA.getC()->setHealth(teamA.getC()->getHealth() - 10.0);
            }
            if (teamB.getA()->getPoisonEffect()) {
                teamB.getA()->setHealth(teamB.getA()->getHealth() - 10.0);
            }
            if (teamB.getB()->getPoisonEffect()) {
                teamB.getB()->setHealth(teamB.getB()->getHealth() - 10.0);
            }
            if (teamB.getC()->getPoisonEffect()) {
                teamB.getC()->setHealth(teamB.getC()->getHealth() - 10.0);
            }
            battle.setMoveCount(battle.getMoveCount() + 1);

            std::cout << "Do you want to save the current game data" << std::endl;
            std::cout << "Answer yes to save the data" << std::endl;
            std::cin >> command;
            if (command == "yes") {
                try {
                    std::ofstream out_file("mode.txt");

                    if (out_file.is_open()) {
                        out_file << mode;
                        out_file.close();
                    } else {
                        std::cerr << "Error writing to file!" << std::endl;
                        return 1;
                    }
                    GameReloader::saveGame(teamA, teamB, "base.txt");
                    std::cout << "Game saved. Thanks!" << std::endl;
                    return 0;
                } catch (const std::exception &e) {
                    std::cerr << "Error saving game: " << e.what() << "\n";
                }
            }
        }

        std::cout << "Your team current stats" << std::endl;
        battle.printTeamInfo(teamA, "teamA");
        std::cout << "Your opponent team current stats" << std::endl;
        battle.printTeamInfo(teamB, "teamB");

        if (battle.isTeamDefeated(teamA)) {
            std::cout << "Sorry, you lost(" << std::endl;
        } else {
            std::cout << "Congrats, you WON!" << std::endl;
        }

        std::cout << "Thanks for the Gaming!" << std::endl;
        const std::vector<std::string> heart = {
            "  ..... .....  ",
            " ............. ",
            "...............",
            "...............",
            " ............. ",
            "  ...........  ",
            "   .........   ",
            "    .......    ",
            "     .....     ",
            "      ...      ",
            "       .       "
        };

        std::cout << "\n";
        for (const auto &row: heart) {
            std::cout << row << "\n";
        }
        std::cout << "\n";
        return 0;
    }


    //@ note the else option


    else {
        std::cout<<"What mode do you prefer to play?"<<std::endl;
        std::cout<<"If you want to rely on your luck then choose mode 'standard' "<<std::endl;
        std::cout<<"If you want to count a little (a lot) choose mode with fixed attacks named 'fixed' "<<std::endl;
        std::cin >> mode;
        while (mode!="standard" && mode!="fixed") {
            std::cin >> mode;
        }
            std::cout << " Please, choose Team of 3 from following roles using only small letters: " << std::endl;
            displayRoleOptions();
            std::cin >> role1;
            while (!isValidRoleName((role1))) {
                std::cout << "Please, enter the role in the list, " << name << std::endl;
                std::cin >> role1;
            }

            std::cin >> role2;
            while (!isValidRoleName((role2))) {
                std::cout << "Please, enter the role in the list, " << name << std::endl;
                std::cin >> role2;
            }

            std::cin >> role3;
            while (!isValidRoleName((role3))) {
                std::cout << "Please, enter the role in the list, " << name << std::endl;
                std::cin >> role3;
            }


            TeamCreator creator;
            std::vector<std::string> teamRoles = {role1, role2, role3};
            Team teamA = creator.createTeam(teamRoles, 0.0);
            Team teamB = creator.createRandomTeam();


            std::string command;
            int num = 0;
            Battle battle(teamA, teamB);
            bool isRepeated = true;
            bool isHidden = false;
            std::cout << teamA.getA()->getHealth() << std::endl;
            std::cout << teamB.getA()->getHealth() << std::endl;
            while (!(battle.isTeamDefeated(teamA) || battle.isTeamDefeated(teamB))) {
                std::cout << "Move " << battle.getMoveCount() + 1 << std::endl;
                std::cout << "Your team current stats" << std::endl;
                battle.printTeamInfo(teamA, "teamA");
                std::cout << "Your opponent team current stats" << std::endl;
                battle.printTeamInfo(teamB, "teamB");
                while (isRepeated) {
                    isRepeated = false;
                    if (teamA.getA()->getHealth() > 0) {
                        std::cout << "Enter the command for your first team member" << std::endl;
                        std::cin >> command;
                        if (Role* role = teamA.getA()) {
                            while (!isCommandValid(role->getType(), command)) {
                                std::cout<<"Enter valid command"<<std::endl;
                                std::cin >> command;
                            }
                        }
                        std::cout <<
                                "Enter the number from 1 to 6 where 1-3 your team members, 4-6 - opponents to perform action"
                                << std::endl;
                        std::cin >> num;
                        while (!isCorrectNum((num))) {
                            std::cout<<"Enter the number from 1 to 6"<<std::endl;
                            std::cin>>num;
                        }
                        if (num < 1 || num > 6) {
                            std::cout << "You lost in numbers!" << std::endl;
                            return 1;
                        }
                        if (num == 4) {
                            battle.actionByRole(teamA.getA(), teamB.getA(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 5) {
                            battle.actionByRole(teamA.getA(), teamB.getB(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 6) {
                            battle.actionByRole(teamA.getA(), teamB.getC(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 1) {
                            battle.actionByRole(teamA.getA(), teamA.getA(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 2) {
                            battle.actionByRole(teamA.getA(), teamA.getB(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 3) {
                            battle.actionByRole(teamA.getA(), teamA.getC(), command, mode, teamA, teamB, isRepeated, isHidden);
                        }
                    }

                    teamA.getA()->setHealth(teamA.getA()->getHealth() + teamA.getTeamShield() / 2);
                }
                isRepeated = true;
                while (isRepeated) {
                    isRepeated = false;
                    if (teamA.getB()->getHealth() > 0) {
                        std::cout << "Enter the command for your second team member" << std::endl;
                        std::cin >> command;
                        if (Role* role = teamA.getB()) {
                            while (!isCommandValid(role->getType(), command)) {
                                std::cout<<"Enter valid command"<<std::endl;
                                std::cin >> command;
                            }
                        }
                        std::cout <<
                                "Enter the number from 1 to 6 where 1-3 your team members, 4-6 - opponents to perform action"
                                << std::endl;
                        std::cin >> num;
                        while (!isCorrectNum((num))) {
                            std::cout<<"Enter the number from 1 to 6"<<std::endl;
                            std::cin>>num;
                        }
                        if (num < 1 || num > 6) {
                            std::cout << "You lost in numbers!" << std::endl;
                            return 1;
                        }
                        if (num == 4) {
                            battle.actionByRole(teamA.getB(), teamB.getA(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 5) {
                            battle.actionByRole(teamA.getB(), teamB.getB(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 6) {
                            battle.actionByRole(teamA.getB(), teamB.getC(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 1) {
                            battle.actionByRole(teamA.getB(), teamA.getA(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 2) {
                            battle.actionByRole(teamA.getB(), teamA.getB(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 3) {
                            battle.actionByRole(teamA.getB(), teamA.getC(), command, mode, teamA, teamB, isRepeated, isHidden);
                        }
                    }
                    teamA.getB()->setHealth(teamA.getB()->getHealth() + teamA.getTeamShield() / 2);
                }
                isRepeated = true;
                while (isRepeated) {
                    isRepeated = false;
                    if (teamA.getC()->getHealth() > 0) {
                        std::cout << "Enter the command for your third team member" << std::endl;
                        std::cin >> command;
                        if (Role* role = teamA.getC()) {
                            while (!isCommandValid(role->getType(), command)) {
                                std::cout<<"Enter valid command"<<std::endl;
                                std::cin >> command;
                            }
                        }
                        std::cout <<
                                "Enter the number from 1 to 6 where 1-3 your team members, 4-6 - opponents to perform action"
                                << std::endl;
                        std::cin >> num;
                        while (!isCorrectNum((num))) {
                            std::cout<<"Enter the number from 1 to 6"<<std::endl;
                            std::cin>>num;
                        }
                        if (num < 1 || num > 6) {
                            std::cout << "You lost in numbers!" << std::endl;
                            return 1;
                        }
                        if (num == 4) {
                            battle.actionByRole(teamA.getC(), teamB.getA(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 5) {
                            battle.actionByRole(teamA.getC(), teamB.getB(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 6) {
                            battle.actionByRole(teamA.getC(), teamB.getC(), command, mode, teamA, teamB, isRepeated, isHidden);
                        } else if (num == 1) {
                            battle.actionByRole(teamA.getC(), teamA.getA(), command, mode,teamA, teamB, isRepeated, isHidden);
                        } else if (num == 2) {
                            battle.actionByRole(teamA.getC(), teamA.getB(), command, mode,teamA, teamB, isRepeated, isHidden);
                        } else if (num == 3) {
                            battle.actionByRole(teamA.getC(), teamA.getC(), command, mode, teamA, teamB, isRepeated, isHidden);
                        }
                    }
                    teamA.getC()->setHealth(teamA.getC()->getHealth() + teamA.getTeamShield() / 2);
                }
                isRepeated = true;
                while (isRepeated) {
                    isRepeated = false;
                    if (teamB.getA()->getHealth() > 0) {
                        battle.aiAction(teamB.getA(), teamB, mode, teamA);
                        teamB.getA()->setHealth(teamB.getA()->getHealth() + teamB.getTeamShield() / 2);
                    }
                }
                isRepeated = true;
                while (isRepeated) {
                    isRepeated = false;
                    if (teamB.getB()->getHealth() > 0) {
                        battle.aiAction(teamB.getB(), teamB,mode, teamA);
                        teamB.getB()->setHealth(teamB.getB()->getHealth() + teamB.getTeamShield() / 2);
                    }
                }
                isRepeated = true;
                while (isRepeated) {
                    isRepeated = false;
                    if (teamB.getC()->getHealth() > 0) {
                        battle.aiAction(teamB.getC(), teamB, mode, teamA);
                        teamB.getC()->setHealth(teamB.getC()->getHealth() + teamB.getTeamShield() / 2);
                    }
                }
                isRepeated = true;
                if (teamA.getA()->getPoisonEffect()) {
                    teamA.getA()->setHealth(teamA.getA()->getHealth() - 10.0);
                }
                if (teamA.getB()->getPoisonEffect()) {
                    teamA.getB()->setHealth(teamA.getB()->getHealth() - 10.0);
                }
                if (teamA.getC()->getPoisonEffect()) {
                    teamA.getC()->setHealth(teamA.getC()->getHealth() - 10.0);
                }
                if (teamB.getA()->getPoisonEffect()) {
                    teamB.getA()->setHealth(teamB.getA()->getHealth() - 10.0);
                }
                if (teamB.getB()->getPoisonEffect()) {
                    teamB.getB()->setHealth(teamB.getB()->getHealth() - 10.0);
                }
                if (teamB.getC()->getPoisonEffect()) {
                    teamB.getC()->setHealth(teamB.getC()->getHealth() - 10.0);
                }
                battle.setMoveCount(battle.getMoveCount() + 1);

                std::cout << "Do you want to save the current game data" << std::endl;
                std::cout << "Answer yes to save the data" << std::endl;
                std::cin >> command;
                if (command == "yes") {
                    try {
                        std::ofstream out_file("mode.txt");

                        if (out_file.is_open()) {
                            out_file << mode;
                            out_file.close();
                        } else {
                            std::cerr << "Error writing to file!" << std::endl;
                            return 1;
                        }
                        GameReloader::saveGame(teamA, teamB, "base.txt");
                        std::cout << "Game saved. Thanks!" << std::endl;
                        return 0;
                    } catch (const std::exception &e) {
                        std::cerr << "Error saving game: " << e.what() << "\n";
                    }
                }
            }

            std::cout << "Your team current stats" << std::endl;
            battle.printTeamInfo(teamA, "teamA");
            std::cout << "Your opponent team current stats" << std::endl;
            battle.printTeamInfo(teamB, "teamB");

            if (battle.isTeamDefeated(teamA)) {
                std::cout << "Sorry, you lost(" << std::endl;
            } else {
                std::cout << "Congrats, you WON!" << std::endl;
            }


            std::cout << "Thanks for the Gaming!" << std::endl;
            const std::vector<std::string> heart = {
                "  ..... .....  ",
                " ............. ",
                "...............",
                "...............",
                " ............. ",
                "  ...........  ",
                "   .........   ",
                "    .......    ",
                "     .....     ",
                "      ...      ",
                "       .       "
            };

            std::cout << "\n";
            for (const auto &row: heart) {
                std::cout << row << "\n";
            }
            std::cout << "\n";

            return 0;
    }
}
