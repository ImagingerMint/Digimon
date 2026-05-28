#include "../Base/Digimon.hpp"

class Gabumon : public Digimon
{
public:
    virtual void Attack(Digimon &Target) override;
    virtual void Guard() override;
    virtual void Heal() override;
    virtual void Faint() override;

    Gabumon() : Digimon("Gabumon", 5, 300, 35, 55, 50, 30) {}
};