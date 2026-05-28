#pragma once
#include <iostream>
using std::cout, std::endl, std::string;

class Digimon
{
public:
    // IDENTIFIERS
    string Name;
    int Level; // NO USE YET
    // STATISTICS
    int Health_Points;
    int Skill_Points;
    int Attack_Points;
    int Defense; // NO USE YET
    int Speed;   // NO USE YET
    // STATUS
    bool Fainted;
    // ACTIVE
    int maxHP;
    int maxSP;

    virtual void Attack(Digimon &Target);
    virtual void Guard();
    virtual void Heal();
    virtual void Faint();

    Digimon(string Name, int LVL, int HP, int SP, int ATK, int DEF, int SPD)
    {
        // IDENTIFIERS
        this->Name = Name;
        this->Level = LVL; // NO USE YET
        // STATISTICS
        this->Health_Points = HP;
        this->Skill_Points = SP;
        this->Attack_Points = ATK;
        this->Defense = DEF; // NO USE YET
        this->Speed = SPD;   // NO USE YET
        // STATUS
        this->Fainted = false;
        // ACTIVE
        this->maxHP = HP;
        this->maxSP = SP;
    }
};