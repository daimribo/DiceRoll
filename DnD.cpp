#include <iostream>
#include <string>
#include <cstdlib>
#include "CharacterSheet.h"
MENU_ACTION Starting_Menu() 
{
    int users_choice;
    std::cout << "0*------------------*0\n";
    std::cout << "I  [1]New Character  I\n";
    std::cout << "I  [2]Load Character I\n";
    std::cin >> users_choice;
    return static_cast<MENU_ACTION>(users_choice - 1);
}
MENU_ACTION Available_Saves() 
{
    int users_choice;
    std::cout << "save slot 1: " << Save_Print(1) << std::endl;
    std::cout << "save slot 2: " << Save_Print(2) << std::endl;
    std::cout << "save slot 3: " << Save_Print(3) << std::endl;
    std::cin >> users_choice;
    return static_cast<MENU_ACTION>(users_choice + 1);
}
void Create_Character() 
{
    std::cin.ignore();
    attributes attr;
    skills skill;
    std::string character_name;
    int species_input;
    int attribute_input;
    int class_input;
    std::cout << "enter character's name:\n";
    getline(std::cin, character_name);
    std::cout << "[1]human\n[2]half-elf\n[3]elf\n[4]tiefling\n";
    std::cout << "what's your character's race?\n";
    std::cin >> species_input;
    std::cout << "[1]Barbarian\n[2]Bard\n[3]Cleric\n[4]Druid\n[5]Fighter\n[6]Monk\n[7]Paladin\n[8]Ranger\n[9]Rogue\n[10]Sorcerer\n[11]Warlock\n[12]Wizard\n";
    std::cout << "what's your character's class?\n";
    std::cin >> class_input;
    Get_Character_Attributes();
    for (int i = 0; i < 6; i++) 
    {
        switch (i) 
        {
        case 0:
            std::cout << "pick number for Strength: ";
            std::cin >> attribute_input;
            attr.strength += attribute_pick[attribute_input -1];
            break;
        case 1:
            std::cout << "pick number for Dexterity: ";
            std::cin >> attribute_input;
            attr.dexterity += attribute_pick[attribute_input -1];
            break;
        case 2:
            std::cout << "pick number for Constitution: ";
            std::cin >> attribute_input;
            attr.constitution += attribute_pick[attribute_input -1];
            break;
        case 3:
            std::cout << "pick number for Intelligence: ";
            std::cin >> attribute_input;
            attr.intelligence += attribute_pick[attribute_input -1];
            break;
        case 4:
            std::cout << "pick number for Wisdom: ";
            std::cin >> attribute_input;
            attr.wisdom += attribute_pick[attribute_input -1];
            break;
        case 5:
            std::cout << "pick number for Charisma: ";
            std::cin >> attribute_input;
            attr.charisma += attribute_pick[attribute_input -1];
            break;
        }
    }
    Character new_character(character_name, static_cast<SPECIES>(species_input - 1), static_cast<CLASS>(class_input - 1), attr, skill);
    MENU_ACTION save_slot_choice = Available_Saves();
    Enter_Character_Save(save_slot_choice, new_character);
    std::cout << "Select slot to save character in" << std::endl;
}
Character Load_Saved_Character() 
{
    std::cout << "Select character to use:\n";
    MENU_ACTION slot_number = Available_Saves();
    return Save_Slot_Selection_Load(slot_number);
}
int main()
{
    MENU_ACTION menu_selection = Starting_Menu();
    if (menu_selection == new_character)
        Create_Character();
    else if (menu_selection == load_character)
        Load_Saved_Character();
}