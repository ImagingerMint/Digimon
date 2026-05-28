#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Base/Digimon.hpp"
#include "Digimon/Agumon.hpp"
#include "Digimon/Gabumon.hpp"

void DigimonTo_String(Digimon &Target);

int main()
{
    Digimon *agumon = new Agumon;
    Digimon *gabumon = new Gabumon;

    for (int i = 0; i < 10; i++)
    {
        agumon->Attack(*gabumon);
        gabumon->Attack(*agumon);
    }
    DigimonTo_String(*agumon);
    DigimonTo_String(*gabumon);
    return 0;
}

void DigimonTo_String(Digimon &Target)
{
    cout << "-------------------" << endl;
    cout << "NAME: " << Target.Name << endl;
    cout << "LVL: " << Target.Level << endl;
    cout << "HP: " << Target.Health_Points << "/" << Target.maxHP << endl;
    cout << "SP: " << Target.Skill_Points << "/" << Target.maxSP << endl;
    cout << "DEF: " << Target.Defense << endl;
    cout << "SPD: " << Target.Speed << endl;
    cout << "FNT: " << Target.Fainted << endl;
    cout << "-------------------" << endl;
}