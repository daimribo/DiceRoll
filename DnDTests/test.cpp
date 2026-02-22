#include "pch.h"
#include "../DnD/CharacterSheet.h"
TEST(CharacterCreationTests, Get_ClassFunctionTest) 
{
	Character test_character("Alfira", tiefling, bard, {}, {});
	ASSERT_EQ(test_character.Get_Class(), "Bard");
}