#include "Digimon.hpp"

void Digimon::Attack(Digimon &Target)
{
    cout << this->Name << " Attacks " << Target.Name << "\n"
         << endl;
    this->Skill_Points -= 5;
}

void Digimon::Guard()
{
    cout << this->Name << " Guards\n"
         << endl;
    this->Skill_Points -= 5;
}

void Digimon::Heal()
{
    cout << this->Name << " Heals 50 HP\n"
         << endl;
    this->Skill_Points -= 5;
}

void Digimon::Faint()
{
    cout << this->Name << "Fainted\n"
         << endl;
    this->Fainted = true;
}