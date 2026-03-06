//CharacterSheet.h
#include <iostream>
#include <fstream>
#include <cmath>
#include "DnDMechanics.h"
enum SKILL_ACTION { acrobatics, animal_handling, arcana, athletics, deception, history, insight, intimidation, investigation, medicine, nature, perception, performance, persuasion, religion, sleight_of_hand, stealth, survival };
enum MENU_ACTION { new_character, load_character, slot_select_1, slot_select_2, slot_select_3 };
enum SPECIES {human, halfelf, elf, tiefling};
enum CLASS {barbarian, bard, cleric, druid, fighter, monk, paladin, ranger, rogue, sorcerer, warlock, wizard};
struct attributes
{
	int strength = 0;
	int dexterity = 0;
	int constitution = 0;
	int intelligence = 0;
	int wisdom = 0;
	int charisma = 0;
};
int level_proficiency[20]{ 2,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0 };
struct skills 
{
	int acrobatics = 0;
	int animal_handling = 0;
	int arcana = 0;
	int athletics = 0;
	int deception = 0;
	int history = 0;
	int insight = 0;
	int intimidation = 0;
	int investigation = 0;
	int medicine = 0;
	int nature = 0;
	int perception = 0;
	int performance = 0;
	int persuasion = 0;
	int religion = 0;
	int sleight_of_hand = 0;
	int stealth = 0;
	int survival = 0;
};
class Character 
{
public:
	skills _skill;
	int free_attribute_points = 0;
	SPECIES _species;
	CLASS _class;
	attributes _attr;
	std::string _name;
	int _speed = 0;
	Character(std::string name, SPECIES species, CLASS char_class, attributes attr) 
	{
		_name = name;
		_species = species;
		_class = char_class;
		_attr = attr;
		Get_Species_Attribute_Bonus();
		Assign_Skills();
		Get_Skill_Proficiencies(0);
	}
	void Get_Species_Attribute_Bonus() 
	{
		switch (_species) 
		{
		case human:
			_attr.strength++;
			_attr.dexterity++;
			_attr.constitution++;
			_attr.intelligence++;
			_attr.wisdom++;
			_attr.charisma++;
			break;
		case halfelf:
			_attr.charisma += 2;
			free_attribute_points = 2;
			break;
		case elf:
			_attr.dexterity += 2;
			break;
		case tiefling:
			_attr.intelligence += 1;
			_attr.charisma += 2;
			break;
		}
	}
	std::string Get_Species()
	{
		switch (_species)
		{
		case human:
			return "human";
			break;
		case halfelf:
			return "half - elf";
			break;
		case elf:
			return "elf";
			break;
		case tiefling:
			return "tiefling";
			break;
		}
	}
	std::string Get_Class() 
	{
		switch (_class)
		{
		case barbarian:
			return "Barbarian";
			break;
		case bard:
			return "Bard";
			break;
		case cleric:
			return "Cleric";
			break; 
		case druid:
			return "Druid";
			break;
		case fighter:
			return "Fighter";
			break;
		case monk:
			return "Monk";
			break;
		case paladin:
			return "Paladin";
			break;
		case ranger:
			return "Ranger";
			break;
		case rogue:
			return "Rogue";
			break;
		case sorcerer:
			return "Sorcerer";
			break;
		case warlock:
			return "Warlock";
			break;
		case wizard:
			return "Wizard";
			break;
		}
	}
	void Assign_Skills() 
	{
		_skill.athletics = floor((_attr.strength - 10) / 2);
		_skill.acrobatics = floor((_attr.dexterity - 10) / 2);
		_skill.sleight_of_hand = floor((_attr.dexterity - 10) / 2);
		_skill.stealth = floor((_attr.dexterity - 10) / 2);
		_skill.arcana = floor((_attr.intelligence - 10) / 2);
		_skill.history = floor((_attr.intelligence - 10) / 2);
		_skill.investigation = floor((_attr.intelligence - 10) / 2);
		_skill.nature = floor((_attr.intelligence - 10) / 2);
		_skill.religion = floor((_attr.intelligence - 10) / 2);
		_skill.animal_handling = floor((_attr.wisdom - 10) / 2);
		_skill.insight = floor((_attr.wisdom - 10) / 2);
		_skill.medicine = floor((_attr.wisdom - 10) / 2);
		_skill.perception = floor((_attr.wisdom - 10) / 2);
		_skill.survival = floor((_attr.wisdom - 10) / 2);
		_skill.deception = floor((_attr.charisma - 10) / 2);
		_skill.intimidation = floor((_attr.charisma - 10) / 2);
		_skill.performance = floor((_attr.charisma - 10) / 2);
		_skill.persuasion = floor((_attr.charisma - 10) / 2);
	}
	void Get_Skill_Proficiencies(int level)
	{
		switch (_class)
		{
		case barbarian:
			_skill.survival += level_proficiency[level];
			_skill.athletics += level_proficiency[level];
			break;
		case bard:
			_skill.performance += level_proficiency[level];
			_skill.persuasion += level_proficiency[level];
			_skill.deception += level_proficiency[level];
			break;
		case cleric:
			_skill.religion += level_proficiency[level];
			_skill.persuasion += level_proficiency[level];
			break;
		case druid:
			_skill.animal_handling += level_proficiency[level];
			_skill.nature += level_proficiency[level];
			break;
		case fighter:
			_skill.athletics += level_proficiency[level];
			_skill.intimidation += level_proficiency[level];
			break;
		case monk:
			_skill.acrobatics += level_proficiency[level];
			_skill.stealth += level_proficiency[level];
			break;
		case paladin:
			_skill.persuasion += level_proficiency[level];
			_skill.insight += level_proficiency[level];
			break;
		case ranger:
			_skill.survival += level_proficiency[level];
			_skill.nature += level_proficiency[level];
			_skill.stealth += level_proficiency[level];
			break;
		case rogue:
			_skill.stealth += level_proficiency[level];
			_skill.sleight_of_hand += level_proficiency[level];
			_skill.persuasion += level_proficiency[level];
			_skill.investigation += level_proficiency[level];
			break;
		case sorcerer:
			_skill.arcana += level_proficiency[level];
			_skill.deception += level_proficiency[level];
			break;
		case warlock:
			_skill.arcana += level_proficiency[level];
			_skill.religion += level_proficiency[level];
			break;
		case wizard:
			_skill.arcana += level_proficiency[level];
			_skill.history += level_proficiency[level];
			break;
		}
	}
	int Get_Skill_Modifier(SKILL_ACTION skill_choice) 
	{
		switch (skill_choice) 
		{
		case acrobatics:
			return _skill.acrobatics;
			break;
		case animal_handling:
			return _skill.animal_handling;
			break;
		case arcana:
			return _skill.arcana;
			break;
		case athletics:
			return _skill.athletics;
			break;
		case deception:
			return _skill.deception;
			break;
		case history:
			return _skill.history;
			break;
		case insight:
			return _skill.insight;
			break;
		case intimidation:
			return _skill.intimidation;
			break;
		case investigation:
			return _skill.investigation;
			break;
		case medicine:
			return _skill.medicine;
			break;
		case nature:
			return _skill.nature;
			break;
		case perception:
			return _skill.perception;
			break;
		case performance:
			return _skill.performance;
			break;
		case persuasion:
			return _skill.persuasion;
			break;
		case religion:
			return _skill.religion;
			break;
		case sleight_of_hand:
			return _skill.sleight_of_hand;
			break;
		case stealth:
			return _skill.stealth;
			break;
		case survival:
			return _skill.survival;
			break;
		deafult:
			return _skill.investigation;
		}
	}
	void Skill_Check(SKILL_ACTION skill_choice) 
	{
		int result = die(20);
		if(result == 20)
			std::cout<<"CRITICAL SUCCESS\n";
		else if(result == 1)
			std::cout<<"CRITICAL FAILURE\n";
		else
		{
			result += Get_Skill_Modifier(skill_choice);
			std::cout<<_name<<" Rolled a "<< result<<std::endl;
		}
	}
	bool operator== (Character const& rhs) const
	{
		bool if_equal = true;
		if (rhs._name != _name)
			if_equal = false;
		if (rhs._species != _species)
			if_equal = false;
		if (rhs._class != _class)
			if_equal = false;
		if (rhs._attr.strength != _attr.strength)
			if_equal = false;
		if (rhs._attr.dexterity != _attr.dexterity)
			if_equal = false;
		if (rhs._attr.constitution != _attr.constitution)
			if_equal = false;
		if (rhs._attr.intelligence != _attr.intelligence)
			if_equal = false;
		if (rhs._attr.wisdom != _attr.wisdom)
			if_equal = false;
		if (rhs._attr.charisma != _attr.charisma)
			if_equal = false;
		return if_equal;
	}
};
int attribute_pick[6] = {};
void Get_Character_Attributes()
{
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		attribute_pick[i] = (rand() % 14) + 3;
		std::cout << "[" << i + 1 << "]" << " " << attribute_pick[i] << std::endl;
	}
}
void Enter_Into_File(Character new_character, std::fstream &save) 
{
	save << new_character._name << std::endl;
	save << new_character.Get_Species() << std::endl;
	save << new_character.Get_Class() << std::endl;
	save << new_character._attr.strength << std::endl;
	save << new_character._attr.dexterity << std::endl;
	save << new_character._attr.constitution << std::endl;
	save << new_character._attr.intelligence << std::endl;
	save << new_character._attr.wisdom << std::endl;
	save << new_character._attr.charisma << std::endl;
}
void Enter_Character_Save(MENU_ACTION save_number, Character new_character) 
{
	std::ofstream save;
	if (save_number == slot_select_1) 
	{
		save.open("character_save_1.txt");
		std::fstream save("character_save_1.txt", std::ios::app);
		Enter_Into_File(new_character, save);
	}
	if (save_number == slot_select_2)
	{
		save.open("character_save_2.txt");
		std::fstream save("character_save_2.txt", std::ios::app);
		Enter_Into_File(new_character, save);
	}
	if (save_number == slot_select_3)
	{
		save.open("character_save_3.txt");
		std::fstream save("character_save_3.txt", std::ios::app);
		Enter_Into_File(new_character, save);
	}
	save.close();
}
std::string Save_Print(int save_number) 
{
	std::string line = "";
	std::fstream save_1_read("character_save_1.txt");
	std::fstream save_2_read("character_save_2.txt");
	std::fstream save_3_read("character_save_3.txt");
	switch (save_number) 
	{
	case 1:
		save_1_read >> line;
		return line;
		break;
	case 2:
		save_2_read >> line;
		return line;
		break;
	case 3:
		save_3_read >> line;
		return line;
		break;
	}
}
SPECIES Retrieve_Species(std::string text) 
{
	if (text == "human")
		return human;
	else if (text == "half - elf")
		return halfelf;
	else if (text == "elf")
		return elf;
	else if (text == "tiefling")
		return tiefling;
	else
		return human;
}
CLASS Retrieve_Class(std::string text)
{
	if (text == "Barbarian")
		return barbarian;
	else if (text == "Bard")
		return bard;
	else if (text == "Cleric")
		return cleric;
	else if (text == "Druid")
		return druid;
	else if (text == "Fighter")
		return fighter;
	else if (text == "Monk")
		return monk;
	else if (text == "Paladin")
		return paladin;
	else if (text == "Ranger")
		return ranger;
	else if (text == "Rogue")
		return rogue;
	else if (text == "Sorcerer")
		return sorcerer;
	else if (text == "Warlock")
		return warlock;
	else if (text == "Wizard")
		return wizard;
	else
		return paladin;
};
Character Load_Text_Into_Character(std::istream &save) 
{
	std::string name;
	getline(save, name);
	std::string species;
	getline(save, species);
	std::string character_class;
	getline(save, character_class);
	attributes attr;
	save >> attr.strength;
	save >> attr.dexterity;
	save >> attr.constitution;
	save >> attr.intelligence;
	save >> attr.wisdom;
	save >> attr.charisma;
	Character Current(name,Retrieve_Species(species), Retrieve_Class(character_class), attr);
	return Current;
}
Character Save_Slot_Selection_Load(MENU_ACTION character_selection_slot) 
{
	std::fstream save_1("character_save_1.txt");
	std::fstream save_2("character_save_2.txt");
	std::fstream save_3("character_save_3.txt");
	if (character_selection_slot == slot_select_1)
		return Load_Text_Into_Character(save_1);
	else if (character_selection_slot == slot_select_2)
		return Load_Text_Into_Character(save_2);
	else if (character_selection_slot == slot_select_3)
		return Load_Text_Into_Character(save_3);
}
MENU_ACTION Available_Saves() 
{
    std::cout << "save slot 1: " << Save_Print(1) << std::endl;
    std::cout << "save slot 2: " << Save_Print(2) << std::endl;
    std::cout << "save slot 3: " << Save_Print(3) << std::endl;
	int users_choice;
	std::cin >> users_choice;
    return static_cast<MENU_ACTION>(users_choice + 1);
}
Character Load_Saved_Character() 
{
    std::cout << "Select character to use:\n";
    MENU_ACTION slot_number = Available_Saves();
    return Save_Slot_Selection_Load(slot_number);
}