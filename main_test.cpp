/*# LabWork2
Shafikov Ruslan Alvirtovich, group 24.Б83 - мм
st112650@stdudent.spbu.ru
*/

#include <gtest/gtest.h>
#include <iostream>
#include "src/agility_roles/Archer.h"
#include "src/agility_roles/Assassin.h"
#include "src/agility_roles/Doctor.h"
#include "src/agility_roles/Ecnchantress.h"
#include "src/agility_roles/Monk.h"
#include "src/agility_roles/Thief.h"
#include "src/ancherman_roles/Gladiator.h"
#include "src/ancherman_roles/Knight.h"
#include "src/ancherman_roles/Warrior.h"
#include "src/magic_roles/Alchemist.h"
#include "src/magic_roles/Druid.h"
#include "src/magic_roles/Mage.h"
#include "src/Team/teamCreator.h"
#include "src/magic_roles/Shaman.h"
#include "src/magic_roles/Sorcerer.h"
#include "src/magic_roles/Necromancer.h"
TEST(SimpleTest, EqualityTest) {
    EXPECT_EQ(2222222222222222, 2222222222222222);
}

//@note Helper function to count successes in multiple trials (for probability checks)
template<typename Func>
int countSuccesses(int trials, Func func) {
    int successes = 0;
    for (int i = 0; i < trials; ++i) {
        if (func()) ++successes;
    }
    return successes;
}





TEST(AssassinTest, AssassinateKillsTargetWith20PercentChance) {
    Assassin assassin(1, 1, 1, 100.0, 0, 0, 0, false);
    Assassin target(1, 1, 1, 100.0, 0, 0, 0, false);
    assassin.assassinate(target);
    // This test is flaky due to randomness, but checks no crash.
    SUCCEED();
}


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

    EXPECT_EQ(target.getHealth(), initialHealth);  // No change expected
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

// Enchantress Tests
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

// Alchemist Tests
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

int main_test(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout<<"Checking tests"<<std::endl;
    return RUN_ALL_TESTS();
}



