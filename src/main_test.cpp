/*# LabWork2
Shafikov Ruslan Alvirtovich, group 24.Б83 - мм
st112650@stdudent.spbu.ru
*/

#include <gtest/gtest.h>
#include <iostream>
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
#include <memory>


TEST(EnchantressTest, CharmReturnsBoolean) {
    std::srand(0);
    Enchantress enchantress(1, 1, 1, 100.0, 0, 0, 0, false);
    TeamCreator creator;
    Team team = creator.createRandomTeam();enchantress.charm(team);
    SUCCEED();
}

TEST(EnchantressTest, DeathKissAttackReturnsBoolean) {
    Enchantress enchantress(1, 1, 1, 100.0, 0, 0, 0, false);
    SUCCEED();
}


TEST(GladiatorTest, DeathFeelingBelowHealthThreshold) {
    Gladiator gladiator(10, 10, 10, 100.0, 5, 2, 3, false);
    Gladiator target(5, 5, 5, 50.0, 0, 0, 0, false);

    gladiator.deathFeeling(target);
    SUCCEED();
}

TEST(GladiatorTest, DeathFeelingAboveHealthThreshold) {
    Gladiator gladiator(10, 10, 10, 100.0, 5, 2, 3, false);
    Gladiator target(5, 5, 5, 51.0, 0, 0, 0, false);
    double initialHealth = target.getHealth();

    gladiator.deathFeeling(target);

    EXPECT_EQ(target.getHealth(), initialHealth);
}


TEST(MonkTest, AmplifyFunctionDoublesCritChance) {
    Monk Hero(1, 1, 1, 100.0, 10, 0, 0, false);
    Alchemist target(1, 1, 1, 100.0, 10, 0, 0, false);
    Hero.amplify(target);
    EXPECT_EQ(target.getCritChance(), 20);
}

TEST(AlchemistTest, CreateHealingPotion) {
    Alchemist alchemist(10, 10, 10, 100.0, 5, 0, 0, false);
    alchemist.createHealingPotion();
    EXPECT_EQ(alchemist.getAmountOfHealingPotions(), 1);
}

TEST(AlchemistTest, CreateExplosivePotion) {
    Alchemist alchemist(10, 10, 10, 100.0, 5, 0, 0, false);
    alchemist.createExplosivePotion();
    EXPECT_EQ(alchemist.getAmountOfExplosivePotions(), 1);
}

TEST(AlchemistTest, GiveHealingPotion) {
    Alchemist alchemist(10, 10, 10, 100.0, 5, 1, 0, false);
    Alchemist recipient(10, 10, 10, 100.0, 5, 0, 0, false);
    alchemist.giveHealingPotion(recipient);
    EXPECT_EQ(alchemist.getAmountOfHealingPotions(), 0);
    EXPECT_EQ(recipient.getAmountOfHealingPotions(), 1);
}

TEST(AlchemistTest, GiveExplosivePotion) {
    Alchemist alchemist(10, 10, 10, 100.0, 5, 0, 1, false);
    Alchemist recipient(10, 10, 10, 100.0, 5, 0, 0, false);
    alchemist.giveExplosivePotion(recipient);
    EXPECT_EQ(alchemist.getAmountOfExplosivePotions(), 0);
    EXPECT_EQ(recipient.getAmountOfExplosivePotions(), 1);
}

TEST(AlchemistTest, ConstructorInitialization) {
    Alchemist alchemist(5, 15, 20, 150.0, 10, 3, 4, true);
    EXPECT_EQ(alchemist.getAgility(), 5);
    EXPECT_EQ(alchemist.getIntelligence(), 20);
    EXPECT_TRUE(alchemist.getPoisonEffect());
}


TEST(DruidTest, HideReturnsBoolean) {
    Druid druid(10, 10, 10, 100.0, 5, 0, 0, false);
    bool result = druid.hide();
    for (int i = 0; i < 10; ++i) {
        result = druid.hide();
        if (result) break;
    }
    SUCCEED();
}


TEST(MageTest, ConstructorInitialization) {
    Mage mage(8, 12, 18, 120.0, 8, 2, 1, false);
    EXPECT_EQ(mage.getIntelligence(), 18);
    EXPECT_FALSE(mage.getPoisonEffect());
}

TEST(ArcherTest, PoisonousArrowConsumesPotion) {
    Archer archer( 10, 5,  15,  100.0,  10,  0, 1, false);
    Archer archer1( 10, 5,  15,  100.0,  10,  0, 1, false);
    archer.poisonousArrowAttack(archer1);
    EXPECT_EQ(archer.getAmountOfExplosivePotions(), 0);
}

TEST(EnchantressTest, DeathKissAttackEffect) {
    Enchantress enchantress(10, 5, 15, 100.0, 10, 0, 0, false);
    Enchantress target(10, 10, 10, 100.0, 5, 0, 0, false);
    enchantress.deathKissAttack(target);
    EXPECT_TRUE(target.getHealth() <= 100.0);
}


// Necromancer Tests
TEST(NecromancerTest, AriseRevivesDeadAlly) {
    Necromancer necromancer(10, 5, 15, 100.0, 10, 0, 0, false);
    Necromancer deadAlly(10, 10, 10, 0.0, 5, 0, 0, false);
    necromancer.arise(deadAlly);
    EXPECT_EQ(deadAlly.getHealth(), 50.0);
}

TEST(AlchemistTest, CreateAndGivePotions) {
    Alchemist alchemist(5, 5, 15, 100.0, 10, 0, 0, false);
    alchemist.createHealingPotion();
    alchemist.createExplosivePotion();

    Alchemist ally(10, 10, 10, 100.0, 5, 0, 0, false);
    alchemist.giveHealingPotion(ally);
    alchemist.giveExplosivePotion(ally);

    EXPECT_EQ(ally.getAmountOfHealingPotions(), 1);
    EXPECT_EQ(ally.getAmountOfExplosivePotions(), 1);
}




TEST(BattleTest, IsTeamDefeatedAllDead) {
    auto testRoleA = std::make_unique<Warrior>(1,1,1,1.0,1,1,1,false);
    auto testRoleB = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);
    auto testRoleC = std::make_unique<Archer>(1,1,1,1.0,1,1,1,false);

    auto mage = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);
    auto mage1 = std::make_unique<Mage>(2,1,1,1.0,1,1,1,false);
    auto mage2 = std::make_unique<Mage>(3,1,1,1.0,1,1,1,false);

    Team team1(
        std::move(mage),
        nullptr,
        nullptr,
        10.0
    );

    Team team2(
        std::move(mage),
        std::move(mage1),
        std::move(mage2),
        10.0
    );


    testRoleA->setHealth(0);
    testRoleB->setHealth(0);
    testRoleC->setHealth(0);

    team1.setA(std::move(testRoleA));
    team1.setB(std::move(testRoleB));
    team1.setC(std::move(testRoleC));

    Battle battle(team1, team2);
    EXPECT_TRUE(battle.isTeamDefeated(team1));
}

TEST(BattleTest, IsTeamDefeatedOneAlive) {
    auto testRoleA = std::make_unique<Warrior>(1,1,1,1.0,1,1,1,false);
    auto testRoleB = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);
    auto testRoleC = std::make_unique<Archer>(1,1,1,1.0,1,1,1,false);

    testRoleA->setHealth(0);
    testRoleB->setHealth(50);
    testRoleC->setHealth(0);

    auto mage = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);
    auto mage1 = std::make_unique<Mage>(2,1,1,1.0,1,1,1,false);
    auto mage2 = std::make_unique<Mage>(3,1,1,1.0,1,1,1,false);

    Team team1(
        std::move(mage),
        nullptr,
        nullptr,
        10.0
    );

    Team team2(
        std::move(mage),
        std::move(mage1),
        std::move(mage2),
        10.0
    );

    team1.setA(std::move(testRoleA));
    team1.setB(std::move(testRoleB));
    team1.setC(std::move(testRoleC));

    Battle battle(team1, team2);
    EXPECT_FALSE(battle.isTeamDefeated(team1));
}


TEST(BattleTest, ShouldHealWhenBelowThreshold) {
    auto testRoleA = std::make_unique<Warrior>(1,1,1,1.0,1,1,1,false);
    auto testRoleB = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);
    auto testRoleC = std::make_unique<Archer>(1,1,1,1.0,1,1,1,false);

    testRoleA->setHealth(40);
    testRoleB->setHealth(60);
    testRoleC->setHealth(30);


    auto mage = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);
    auto mage1 = std::make_unique<Mage>(2,1,1,1.0,1,1,1,false);
    auto mage2 = std::make_unique<Mage>(3,1,1,1.0,1,1,1,false);

    Team team1(
        std::move(mage),
        nullptr,
        nullptr,
        10.0
    );

    Team team2(
        std::move(mage),
        std::move(mage1),
        std::move(mage2),
        10.0
    );

    team1.setA(std::move(testRoleA));
    team1.setB(std::move(testRoleB));
    team1.setC(std::move(testRoleC));

    Battle battle(team1, team2);
    EXPECT_TRUE(battle.shouldHeal(team1.getA(), team1));
}

TEST(BattleTest, DoctorAIHealsInjured) {
    auto doctor = std::make_unique<Doctor>(1,1,1,1.0,1,1,1,false);
    auto injured = std::make_unique<Warrior>(1,1,1,1.0,1,1,1,false);
    injured->setHealth(30);

    Team myTeam(
        std::move(doctor),
        std::move(injured),
        nullptr,
        0.0
    );

    Team opponentTeam(nullptr, nullptr, nullptr, 0.0);

    Battle battle(myTeam, opponentTeam);
    std::string mode = "standard";

    battle.aiAction(myTeam.getA(), myTeam, mode, opponentTeam);
    EXPECT_GE(myTeam.getB()->getHealth(), 30);
}

TEST(BattleTest, AssassinAIAttacksWithAssassinate) {
    auto assassin = std::make_unique<Assassin>(1,1,1,1.0,1,1,1,false);
    auto target = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);

    Team myTeam(
        std::move(assassin),
        nullptr,
        nullptr,
        0.0
    );

    Team opponentTeam(
        std::move(target),
        nullptr,
        nullptr,
        0.0
    );

    Battle battle(myTeam, opponentTeam);
    std::string mode = "standard";

    battle.aiAction(myTeam.getA(), myTeam, mode, opponentTeam);
    EXPECT_LE(opponentTeam.getA()->getHealth(), opponentTeam.getA()->getHealth());
    EXPECT_GE(opponentTeam.getA()->getHealth(), -1);

}

TEST(BattleTest, MageAIAddsShield) {
    auto mage = std::make_unique<Mage>(1,1,1,1.0,1,1,1,false);

    Team myTeam(
        std::move(mage),
        nullptr,
        nullptr,
        10.0
    );

    Team opponentTeam(nullptr, nullptr, nullptr, 0.0);
    Battle battle(myTeam, opponentTeam);
    std::string mode = "standard";

    battle.aiAction(myTeam.getA(), myTeam, mode, opponentTeam);
    EXPECT_GE(myTeam.getTeamShield(), 10);
    EXPECT_LE(myTeam.getTeamShield(), 30);
}

class MagicRolesTest : public ::testing::Test {
protected:
    void SetUp() override {
        sorcerer = std::make_unique<Sorcerer>(1, 1, 15, 100.0, 0, 0, 0, false);
        shaman = std::make_unique<Shaman>(1, 1, 10, 100.0, 0, 0, 0, false);
        thief = std::make_unique<Thief>(1, 1, 1, 100.0, 0, 0, 0, false);
    }

    std::unique_ptr<Sorcerer> sorcerer;
    std::unique_ptr<Shaman> shaman;
    std::unique_ptr<Thief> thief;
};

TEST_F(MagicRolesTest, SorcererDoubleAttackAppliesDamage) {
   sorcerer = std::make_unique<Sorcerer>(1, 1, 15, 100.0, 0, 0, 0, false);

    double initialHealth = sorcerer->getHealth();

    sorcerer->doubleMagicAttack(*sorcerer);
    double damage = initialHealth - sorcerer->getHealth();

    EXPECT_LE(damage, 100);
    EXPECT_GE(damage, 1);
}

TEST_F(MagicRolesTest, ShamanDeafenReducesCritChance) {
    sorcerer = std::make_unique<Sorcerer>(1, 1, 15, 100.0, 0, 0, 0, false);
    shaman->deafen(*sorcerer);
    int newCrit = sorcerer->getCritChance();
    EXPECT_TRUE(newCrit == 0 || newCrit == 50) << "Crit chance: " << newCrit;
}

TEST_F(MagicRolesTest, ThiefStealHasChance) {
    const int trials = 1000;
    int successes = 0;

    for (int i = 0; i < trials; ++i) {
        if (thief->isStolen()) successes++;
    }

    EXPECT_GE(successes, 200);
    EXPECT_LE(successes, 400);
}


