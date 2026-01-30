#include <iostream>
#include <string>
#include <cstdlib>
#include "CharacterSheet.h"
int starting_menu() 
{
    int UsersChoice;
    std::cout << "0*------------------*0\n";
    std::cout << "I  [1]New Character  I\n";
    std::cin >> UsersChoice;
    return UsersChoice;
}
int available_saves() 
{
    int UsersChoice;
    std::cout << "save slot 1: " << save_print(1) << std::endl;
    std::cout << "save slot 2: " << save_print(2) << std::endl;
    std::cout << "save slot 3: " << save_print(3) << std::endl;
    std::cout << "Select slot to save character in" << std::endl;
    std::cin >> UsersChoice;
    return UsersChoice;
}
void create_character() 
{
    std::cin.ignore();
    attributes attr;
    std::string character_name;
    int SpecieInput;
    int AttrInput;
    int ClassInput;
    std::cout << "enter character's name:\n";
    getline(std::cin, character_name);
    std::cout << "[1]human\n[2]half-elf\n[3]elf\n[4]tiefling\n";
    std::cout << "what's your character's race?\n";
    std::cin >> SpecieInput;
    getAttributes();
    for (int i = 0; i < 6; i++) 
    {
        switch (i) 
        {
        case 0:
            std::cout << "pick number for Strength: ";
            std::cin >> AttrInput;
            attr.strength += attribute_pick[AttrInput-1];
            break;
        case 1:
            std::cout << "pick number for Dexterity: ";
            std::cin >> AttrInput;
            attr.dexterity += attribute_pick[AttrInput-1];
            break;
        case 2:
            std::cout << "pick number for Constitution: ";
            std::cin >> AttrInput;
            attr.constitution += attribute_pick[AttrInput-1];
            break;
        case 3:
            std::cout << "pick number for Intelligence: ";
            std::cin >> AttrInput;
            attr.intelligence += attribute_pick[AttrInput-1];
            break;
        case 4:
            std::cout << "pick number for Wisdom: ";
            std::cin >> AttrInput;
            attr.wisdom += attribute_pick[AttrInput-1];
            break;
        case 5:
            std::cout << "pick number for Charisma: ";
            std::cin >> AttrInput;
            attr.charisma += attribute_pick[AttrInput-1];
            break;
        }
    }
    std::cout << "[1]palladin\n[2]wizard\n";
    std::cout << "what's your character's class?\n";
    std::cin >> ClassInput;
    Character new_character(character_name, static_cast<SPECIE>(SpecieInput - 1), static_cast<CLASS>(ClassInput - 1), attr);
    int save_slot_choice = available_saves();
    enter_character_save(save_slot_choice, new_character);
}
int main()
{
    int menu_selection = starting_menu();
    if (menu_selection == 1)
        create_character();
}