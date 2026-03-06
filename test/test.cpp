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
TEST(CharacterCreationTests, Get_Skill_ModifierFunctionTest)
{
	Character test_character("Johnny Silverhand", human, barbarian, {16,9,15,11,11,12});
	ASSERT_EQ(test_character.Get_Skill_Modifier(athletics), 5);
	ASSERT_EQ(test_character.Get_Skill_Modifier(survival), 3);
	ASSERT_EQ(test_character.Get_Skill_Modifier(acrobatics), 0);
}
TEST(CharacterLoadingTests, RetrieveFunctionsTest)
{
	ASSERT_EQ(Retrieve_Species("human"), human);
	ASSERT_EQ(Retrieve_Species("tiefling"), tiefling);
	ASSERT_EQ(Retrieve_Species(""), human);
	ASSERT_EQ(Retrieve_Class("Barbarian"), barbarian);
	ASSERT_EQ(Retrieve_Class("Wizard"), wizard);
	ASSERT_EQ(Retrieve_Class(""), paladin);
}