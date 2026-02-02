//CharacterSheet.h
#include <iostream>
#include <fstream>
#include <chrono>
enum MENU_ACTION { new_character, load_character, slot_select_1, slot_select_2, slot_select_3 };
enum SPECIE {human, halfelf, elf, tiefling};
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
class Character 
{
public:
	
	int free_attribute_points = 0;
	SPECIE _specie;
	CLASS _class;
	attributes _attr;
	std::string _name;
	Character(std::string name, SPECIE specie, CLASS char_class, attributes attr) 
	{
		_name = name;
		_specie = specie;
		_class = char_class;
		_attr = attr;
		Get_Specie_Attribute_Bonus();
	}
	attributes Get_Attributes() 
	{
		return _attr;
	}
	void Get_Specie_Attribute_Bonus() 
	{
		switch (_specie) 
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
	std::string Get_Specie()
	{
		switch (_specie)
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
void enter_into_file(Character new_character, std::fstream &save) 
{
	save << new_character._name << std::endl;
	save << new_character.Get_Specie() << std::endl;
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
		enter_into_file(new_character, save);
	}
	if (save_number == slot_select_2)
	{
		save.open("character_save_2.txt");
		std::fstream save("character_save_2.txt", std::ios::app);
		enter_into_file(new_character, save);
	}
	if (save_number == slot_select_3)
	{
		save.open("character_save_3.txt");
		std::fstream save("character_save_3.txt", std::ios::app);
		enter_into_file(new_character, save);
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
SPECIE Retrieve_Specie(std::string text) 
{
	if (text == "human")
		return human;
	else if (text == "half - elf")
		return halfelf;
	else if (text == "elf")
		return elf;
	else if (text == "tiefling")
		return tiefling;
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
	else if(text == "Wizard")
		return wizard;
}
Character Load_Text(std::fstream &save) 
{
	std::string name;
	SPECIE specie;
	CLASS character_class;
	attributes attr;
	int line_number = 0;
	std::string line;
	while (getline(save, line)) 
	{
		line_number++;
		switch (line_number) 
		{
		case 1:
			name = line;
			break;
		case 2:
			specie = Retrieve_Specie(line);
			break;
		case 3:
			character_class = Retrieve_Class(line);
			break;
		case 4:
			attr.strength = stoi(line);
			break;
		case 5:
			attr.dexterity = stoi(line);
			break;
		case 6:
			attr.constitution = stoi(line);
			break;
		case 7:
			attr.intelligence = stoi(line);
			break;
		case 8:
			attr.wisdom = stoi(line);
			break;
		case 9:
			attr.charisma = stoi(line);
			break;
		}
	}
	Character Current(name, static_cast<SPECIE>(specie), static_cast<CLASS>(character_class), attr);
	return Current;
}
Character Save_Slot_Selection_Load(MENU_ACTION character_selection_slot) 
{
	std::fstream save_1("character_save_1.txt");
	std::fstream save_2("character_save_2.txt");
	std::fstream save_3("character_save_3.txt");
	if (character_selection_slot == slot_select_1)
		return Load_Text(save_1);
	else if (character_selection_slot == slot_select_2)
		return Load_Text(save_2);
	else if (character_selection_slot == slot_select_3)
		return Load_Text(save_3);
}