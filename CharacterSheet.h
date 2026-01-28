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
void print_character_informations(Character new_character) 
{
	std::cout << "my name is" << " " << new_character._name << std::endl;
	std::cout << "I am a" << " " << new_character.getSpecie() << std::endl;
	std::cout << "I'm also a" << " " << new_character.getClass() << std::endl;
}