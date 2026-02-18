#include <iostream>
#include <cstdlib>
#include <map>
#include <random>
#include <string>
using namespace std;
string user_choice;

enum GENDER {woman, man, intersex};
enum RACE { dragonborn,dwarf,elf,gnome,half_elf,halfling, half_orc, human, tiefling};
enum CLASS {wizard,warlock,bard};
enum PIECE { copper_pieces, silver_pieces, electrum_pieces, gold_pieces, platonium_pieces };
struct attributes 
{
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
};
class character 
{
public:
    character(GENDER gender, RACE race, string name, attributes attr, CLASS chclass)
    {
        _gender = gender;
        _race = race;
        _name = name;
        _attr = attr;
        _class = chclass;
        add_race_bonus();
        add_class_bonus();
    }
    string GetGender() 
    {
        switch (_gender)
        {
            case woman:
                return "woman";

            case man:
                return"man";

            case intersex:
                return"intersex";
            default:
                return"other";
        }
    }

    string GetRace() 
    {
        switch (_race) 
        {
        case dragonborn:
            return "dragonborn";
        case dwarf:
            return "dwarf";
        case elf:
            return "elf";
        case gnome:
            return "gnome";
        case half_elf:
            return "half-elf";
        case halfling:
            return "halfling";
        case half_orc:
            return "half-orc";
        case human:
            return "human";
        case tiefling:
            return "tiefling";
        }
        
    }

    string GetClass() 
    {
        switch (_class) 
        {
        case wizard:
            return "wizard";
        case warlock:
            return "warlock";
        case bard:
            return "bard";
        }
    }

    void add_race_bonus() 
    {
        switch (_race) 
        {
        case dragonborn:
            _attr.strength += 2;
            _attr.charisma += 1;
            break;
        case dwarf:
            _attr.constitution += 2;
            break;
        case elf:
            _attr.dexterity += 2;
            break;
        case gnome:
            _attr.intelligence += 2;
            break;
        case half_elf:
            _attr.charisma += 2;
            break;
        case halfling:
            _attr.dexterity += 2;
            break;

        }
    }
    void add_class_bonus() 
    {
        switch (_class) 
        {
        case wizard:
            _attr.intelligence += 2;
            _attr.wisdom += 1;
            break;
        case warlock:
            _attr.charisma += 2;
            _attr.wisdom += 1;
            break;
        case bard:
            _attr.charisma += 2;
            _attr.dexterity += 1;
            break;
        }
    }

    RACE _race;
    string _name;
    attributes _attr;
    CLASS _class;
    GENDER _gender;
};

int GetRandom()
{
    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(4, 18);
    return distrib(gen);
}

void print_character(character new_character) 
{
    cout << "my gender is " << new_character.GetGender() << endl;
    cout << "I am a" << " " << new_character.GetRace() << endl;
    cout << "I'm also a" << " " << new_character.GetClass() << endl;
    cout << "my name is" << " " <<new_character._name << endl;
    cout << "my strength is" << " " << new_character._attr.strength << endl;
    cout << "my dexternity is" << " " << new_character._attr.dexterity << endl;
    cout << "my constitution is" << " " << new_character._attr.constitution << endl;
    cout << "my intelligence is" << " " << new_character._attr.intelligence << endl;
    cout << "my wisdom is" << " " << new_character._attr.wisdom << endl;
    cout << "my charisma is" << " " << new_character._attr.charisma << endl;
}

int D20_roll() 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(3,18);
    return distrib(gen);
}

int main()
{
    /*character Silverhand(man, human, "Johnny Silverhand");
    print_character(Silverhand);
    character Katrine(woman, elf, "Katrine", {10, 20, 14, 16, 13, 10});
    print_character(Katrine);*/
    int Gender_input;
    int Race_input;
    int Class_input;
    string Name_input;
    attributes attr;
    string answer;
    string roll;
    cout << "What is the gender of your character" << endl;
    cout << "[0]woman" << " " << "[1]man" << " " << "[2]intersex" << " " << "[3]other" << endl;
    cin >> Gender_input;
    cout << "what race is your character" << endl;
    cout << "[0]dragonborn" << " " << "[1]dwarf" << " " << "[2]elf" << endl;
    cout << "[3]gnome" << " " << "[4]half-elf" << " " << "[5]halfling" << endl;
    cout << "[6]half-orc" << " " << "[7]human" << " " << "[8]tiefling" << endl;
    cin >> Race_input;
    cout << "What class is your character" << endl;
    cout << "[0]wizard" << " " << "[1]warlock" << " " << "[2]bard" << endl;
    cin >> Class_input;
    cout << "Name your character" << endl;
    cin.ignore();
    getline(cin ,Name_input);
    cout << "Do you wish to input attributes manually or generate them?" << endl;
    cout << "[m]anually" << " " << "[g]enerate" << endl;
    cin >> answer;
    if (answer == "m")
    {
        cout << "my strength is" << endl;
        cin >> attr.strength;
        cout << "my dexternity is" << endl;
        cin >> attr.dexterity;
        cout << "my constitution is" << endl;
        cin >> attr.constitution;
        cout << "my intelligence is" << endl;
        cin >> attr.intelligence;
        cout << "my wisdom is" << endl;
        cin >> attr.wisdom;
        cout << "my charisma is" << endl;
        cin >> attr.charisma;
    }
    if (answer == "g") 
    {
        attr.strength = GetRandom();
        attr.dexterity = GetRandom();
        attr.constitution = GetRandom();
        attr.intelligence = GetRandom();
        attr.wisdom = GetRandom();
        attr.charisma = GetRandom();
    }

    character player(static_cast<GENDER>(Gender_input), static_cast<RACE>(Race_input), Name_input, attr, static_cast<CLASS>(Class_input));
    print_character(player);
}

//equipment
class equipment
{
public:
    attributes attr;
    int carry_copacity = attr.strength * 15;

    struct weapon
    {
        string weapon_name;
        int cost;
        PIECE money_type;
        int rolls;
        int die;
        double weight;
        string weapon_type;
        string attack_type;
    };
    struct Club :public weapon {
        string weapon_name = "Club";
        int cost = 1;
        PIECE money_type = silver_pieces;
        int rolls = 1;
        int die = 4;
        double weight = 2;
        string weapon_type = "Simple Melee";
        string attack_type = "bludgeoned";
    };
    struct Dagger : public weapon {
        string weapon_name = "Dagger";
        int cost = 2;
        PIECE money_type = gold_pieces;
        int rolls = 1;
        int die = 4;
        double weight = 1;
        string weapon_type = "Simple Melee";
        string attack_type = "pierced";
    };
};