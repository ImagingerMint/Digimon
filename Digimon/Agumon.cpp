#include "Agumon.hpp"

void Agumon::Attack(Digimon &Target)
{
    if (this->Fainted == false)
    {
        if (this->Skill_Points < 5)
        {
            cout << "Not enough 'Mana points'\n"
                 << endl;
            return;
        }

        if (Target.Fainted == false)
        {
            cout << this->Name << " Attacks " << Target.Name
                 << endl;
            if (Target.Health_Points < this->Attack_Points)
            {
                cout << this->Name << " Did " << Target.Health_Points << " Damage\n"
                     << endl;
                Target.Health_Points = 0;
                Target.Faint();
            }
            else
            {
                Target.Health_Points = Target.Health_Points - this->Attack_Points;
                cout << this->Name << " Did " << this->Attack_Points << " Damage\n"
                     << endl;
            }
            this->Skill_Points = this->Skill_Points - 5;
        }
        else
        {
            cout << this->Name << " Attacks, but " << Target.Name << " is fainted\n"
                 << endl;
        }
    }
    else
    {
        cout << this->Name << " Is fainted\n"
             << endl;
    }
}

void Agumon::Guard()
{
    if (this->Skill_Points < 5)
    {
        cout << "Not enough 'Mana points'\n"
             << endl;
        return;
    }

    cout << this->Name << " Guards\n"
         << endl;
    this->Skill_Points = this->Skill_Points - 5;
}

void Agumon::Heal()
{
    if (this->Skill_Points < 5)
    {
        cout << "Not enough 'Mana points'\n"
             << endl;
        return;
    }

    cout << this->Name << " Heals 50 HP\n"
         << endl;
    this->Skill_Points = this->Skill_Points - 5;
}

void Agumon::Faint()
{
    if (this->Fainted == true)
    {
        return;
    }

    cout << this->Name << "Fainted\n"
         << endl;
    this->Fainted = true;
}