#include <iostream>
#include <string>
#include <cstdlib>
#include "CharacterSheet.h"
std::fstream character_save_1("character_save_1.txt", std::ios::app);
int main()
{
    std::string character_name;
    int SpecieInput;
    int ClassInput;
    std::cout << "enter character's name:\n";
    getline(std::cin, character_name);
    std::cout << "[1]human\n[2]half-elf\n[3]elf\n[4]tiefling\n";
    std::cout << "what's your character's race?\n";
    std::cin >> SpecieInput;
    std::cout << "[1]palladin\n[2]wizard\n";
    std::cout << "what's your character's class?\n";
    std::cin >> ClassInput;
    Character new_character(character_name, static_cast<SPECIE>(SpecieInput -1), static_cast<CLASS>(ClassInput -1));
    print_character_informations(new_character);
}