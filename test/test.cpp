#include <gtest/gtest.h>
#include "CharacterSheet.h"
TEST(CharacterCreationTests, Get_ClassFunctionTest) 
{
	Character test_character("Alfira", tiefling, bard, {});
	ASSERT_EQ(test_character.Get_Class(), "Bard");
}

TEST(CharacterCreationTests, Get_SpeciesFunctionTest) 
{
	Character test_character("Gogurt", halfelf, fighter, {4,5,6,7,8,9});
	ASSERT_EQ(test_character.Get_Class(), "Fighter");
}
TEST(CharacterCreationTests, Get_Species_Attribute_BonusFunctionTest)
{
	Character test_character("Gogurt", halfelf, fighter, { 4,5,6,7,8,9 });
	ASSERT_EQ(test_character._attr.strength, 4);
	ASSERT_EQ(test_character._attr.charisma, 11);
}
TEST(CharacterCreationTests, Assign_SkillsFunctionTest) 
{
	Character test_character("Winning Ticket", human, cleric, { 9,7,11,16,15,10 });
	ASSERT_EQ(test_character._skill.religion, 5);
	ASSERT_EQ(test_character._skill.persuasion, 2);
	ASSERT_EQ(test_character._skill.survival, 3);
}