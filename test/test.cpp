#include <gtest/gtest.h>
#include <sstream>
#include "CharacterSheet.h"
Character test_character("Winning Ticket", human, cleric, { 9,7,11,16,15,10 });
std::string character_in_string = "Winning Ticket\nhuman\nCleric\n9\n7\n11\n16\n15\n10\n";
TEST(CharacterCreationTests, Get_ClassANDGet_SpeciesFunctionsTest) 
{
	ASSERT_EQ(test_character.Get_Class(), "Cleric");
	ASSERT_EQ(test_character.Get_Species(), "human");
}
TEST(CharacterCreationTests, Get_Species_Attribute_BonusFunctionTest)
{
	ASSERT_EQ(test_character._attr.strength, 10);
	ASSERT_EQ(test_character._attr.dexterity, 8);
	ASSERT_EQ(test_character._attr.constitution, 12);
	ASSERT_EQ(test_character._attr.intelligence, 17);
	ASSERT_EQ(test_character._attr.wisdom, 16);
	ASSERT_EQ(test_character._attr.charisma, 11);
}
TEST(CharacterCreationTests, Assign_SkillsFunctionTest) 
{
	ASSERT_EQ(test_character._skill.religion, 5);
	ASSERT_EQ(test_character._skill.persuasion, 2);
	ASSERT_EQ(test_character._skill.survival, 3);
}
TEST(CharacterCreationTests, Get_Skill_ModifierFunctionTest)
{
	ASSERT_EQ(test_character.Get_Skill_Modifier(athletics), 0);
	ASSERT_EQ(test_character.Get_Skill_Modifier(survival), 3);
	ASSERT_EQ(test_character.Get_Skill_Modifier(acrobatics), -1);
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
TEST(CharacterLoadingTests, Enter_Into_FileFunctionTest)
{
	std::string character = "Winning Ticket\nhuman\nCleric\n10\n8\n12\n17\n16\n11\n";
	std::stringstream ss;
	Enter_Into_File(test_character, ss);
	ASSERT_EQ(ss.str(), character);
}
TEST(CharacterLoadingTests, Load_Text_Into_CharacterFunctionTest)
{
	std::stringstream ss(character_in_string);
	Character loaded = Load_Text_Into_Character(ss);
	EXPECT_TRUE(loaded == test_character);
}