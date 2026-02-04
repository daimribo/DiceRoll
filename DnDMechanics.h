//DnDMechanics.h
#include "CharacterSheet.h"
std::string character_name;
SPECIES character_species;
CLASS character_class;
attributes character_attr;
skills character_skills;
Character Current(character_name, character_species, character_class, character_attr, character_skills);
int die(int die_type) 
{
	return (rand() % (die_type - 1)) + 1;
}
int Get_Skill_Modifier(SKILL_ACTION skill_choice) 
{
	switch (skill_choice) 
	{
	case acrobatics:
		return character_skills.acrobatics;
		break;
	case animal_handling:
		return character_skills.animal_handling;
		break;
	case arcana:
		return character_skills.arcana;
		break;
	case athletics:
		return character_skills.athletics;
		break;
	case deception:
		return character_skills.deception;
		break;
	case history:
		return character_skills.history;
		break;
	case insight:
		return character_skills.insight;
		break;
	case intimidation:
		return character_skills.intimidation;
		break;
	case investigation:
		return character_skills.investigation;
		break;
	case medicine:
		return character_skills.medicine;
		break;
	case nature:
		return character_skills.nature;
		break;
	case perception:
		return character_skills.perception;
		break;
	case performance:
		return character_skills.performance;
		break;
	case persuasion:
		return character_skills.persuasion;
		break;
	case religion:
		return character_skills.religion;
		break;
	case sleight_of_hand:
		return character_skills.sleight_of_hand;
		break;
	case stealth:
		return character_skills.stealth;
		break;
	case survival:
		return character_skills.survival;
		break;
	}

}
int Skill_Check(int skill_modifier) 
{
	return die(20) + skill_modifier;
}