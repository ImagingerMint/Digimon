#include "../Base/Digimon.hpp"

class Agumon : public Digimon
{
public:
    virtual void Attack(Digimon &Target) override;
    virtual void Guard() override;
    virtual void Heal() override;
    virtual void Faint() override;

    Agumon() : Digimon("Agumon", 5, 250, 35, 75, 50, 30) {}
};