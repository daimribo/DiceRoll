//DnDMechanics.h
#include "CharacterSheet.h"
Character Current = Load_Saved_Character();

int die(int die_type) 
{
	return (rand() % (die_type - 1)) + 1;
}
int Get_Skill_Modifier(SKILL_ACTION skill_choice) 
{
	switch (skill_choice) 
	{
	case acrobatics:
		return Current._skill.acrobatics;
		break;
	case animal_handling:
		return Current._skill.animal_handling;
		break;
	case arcana:
		return Current._skill.arcana;
		break;
	case athletics:
		return Current._skill.athletics;
		break;
	case deception:
		return Current._skill.deception;
		break;
	case history:
		return Current._skill.history;
		break;
	case insight:
		return Current._skill.insight;
		break;
	case intimidation:
		return Current._skill.intimidation;
		break;
	case investigation:
		return Current._skill.investigation;
		break;
	case medicine:
		return Current._skill.medicine;
		break;
	case nature:
		return Current._skill.nature;
		break;
	case perception:
		return Current._skill.perception;
		break;
	case performance:
		return Current._skill.performance;
		break;
	case persuasion:
		return Current._skill.persuasion;
		break;
	case religion:
		return Current._skill.religion;
		break;
	case sleight_of_hand:
		return Current._skill.sleight_of_hand;
		break;
	case stealth:
		return Current._skill.stealth;
		break;
	case survival:
		return Current._skill.survival;
		break;
	}

}
int Skill_Check(int skill_modifier) 
{
	return die(20) + skill_modifier;
}