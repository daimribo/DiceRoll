//CharacterSheet.h
#include <iostream>
#include <fstream>
enum SPECIE {human, halfelf, elf, tiefling};
enum CLASS {palladin, wizard};
class Character 
{
public:
	SPECIE _specie;
	CLASS _class;
	std::string _name;
	Character(std::string name, SPECIE specie, CLASS char_class) 
	{
		_name = name;
		_specie = specie;
		_class = char_class;
	}
	std::string getSpecie()
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
void write_character_informations(Character new_character) 
{
	std::ofstream file;
	file.open("character_save.txt");
	std::fstream character_save("character_save.txt", std::ios::app);
	character_save << new_character._name << std::endl;
	character_save << new_character.getSpecie() << std::endl;
	character_save << new_character.getClass() << std::endl;
	file.close();
}