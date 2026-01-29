//CharacterSheet.h
#include <iostream>
#include <fstream>
#include <chrono>
enum SPECIE {human, halfelf, elf, tiefling};
enum CLASS {palladin, wizard};
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
	}
	std::string getSpecie()
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
			return "human";
			break;
		case halfelf:
			_attr.charisma += 2;
			free_attribute_points = 2;
			return "half - elf";
			break;
		case elf:
			_attr.dexterity+= 2;
			return "elf";
			break;
		case tiefling:
			_attr.intelligence += 1;
			_attr.charisma += 2;
			return "tiefling";
			break;
		}
	}
	std::string getClass() 
	{
		switch (_class)
		{
		case palladin:
			return "palladin";
			break;
		case wizard:
			return "wizard";
			break;
		}
	}
};
int attribute_pick[6] = {};
void getAttributes()
{
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		attribute_pick[i] = (rand() % 14) + 4;
		std::cout << "[" << i + 1 << "]" << " " << attribute_pick[i] << std::endl;
	}
}
void enter_character_informations(Character new_character) 
{
	std::ofstream file;
	file.open("character_save.txt");
	std::fstream character_save("character_save.txt", std::ios::app);
	character_save << new_character._name << std::endl;
	character_save << new_character.getSpecie() << std::endl;
	character_save << new_character.getClass() << std::endl;
	character_save << new_character._attr.strength << std::endl;
	character_save << new_character._attr.dexterity << std::endl;
	character_save << new_character._attr.constitution << std::endl;
	character_save << new_character._attr.intelligence << std::endl;
	character_save << new_character._attr.wisdom << std::endl;
	character_save << new_character._attr.charisma << std::endl;
	file.close();
}