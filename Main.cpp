// LIBRARIES
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Base/Digimon.hpp"
#include "Digimon/Agumon.hpp"
#include "Digimon/Gabumon.hpp"
#include <sstream>
// NAMESPACES
using std::ostringstream;

// AUXILIARY FUNCTIONS
string DigimonTo_String(Digimon &Target);

// MAIN FUNCTION
int main()
{
    //----------------------------------------------------------------------------------
    // CREATE THE MAIN WINDOW
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Digimon Battle");

    // CREATE DIGIMON FOR MAIN LOGIC
    Digimon *agumon = new Agumon;
    Digimon *gabumon = new Gabumon;

    // LOAD BACKGROUND / DIGIMON TO DISPLAY
    sf::Texture background;
    if (!background.loadFromFile("Images/background.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(background);
    sprite.setScale(1, 1);

    sf::Texture digimon1;
    if (!digimon1.loadFromFile("Images/agumon.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite1(digimon1);

    sf::Texture digimon2;
    if (!digimon2.loadFromFile("Images/gabumon.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite2(digimon2);

    // CHOOSE FONT FOR TEXT
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/vlgothic/VL-PGothic-Regular.ttf"))
        return EXIT_FAILURE;

    // STATS BOX 1
    sf::RectangleShape box1;
    sf::Vector2f vect1;
    vect1.x = 215;
    vect1.y = 250;
    box1.setSize(vect1);
    box1.setPosition(90, 220);
    box1.setOutlineColor(sf::Color::Black);
    box1.setFillColor(sf::Color::White);
    box1.setOutlineThickness(3.75);

    // STATS BOX 2
    sf::RectangleShape box2;
    sf::Vector2f vect2;
    vect2.x = 215;
    vect2.y = 250;
    box2.setSize(vect2);
    box2.setPosition(975, 220);
    box2.setOutlineColor(sf::Color::Black);
    box2.setFillColor(sf::Color::White);
    box2.setOutlineThickness(3.75);

    // LOAD STATS STRING TO BOX 1
    /*
    sf::Text text1(DigimonTo_String(*gabumon), font, 25);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(90, 220);

    // LOAD STATS STRING TO BOX 2
    sf::Text text2(DigimonTo_String(*agumon), font, 25);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(975, 220);
    */

    // INTEGERS FOR SPRITE SHEET
    int xDigimon1 = 0, yDigimon1 = 0;
    int xDigimon2 = 0, yDigimon2 = 0;

    sf::Clock frames;
    sf::Clock combat;
    cout << "Start\n"
         << endl;
    //----------------------------------------------------------------------------------

    // START THE GAME LOOP
    while (window.isOpen())
    {
        // PROCESS EVENTS
        sf::Event event;
        while (window.pollEvent(event))
        {
            // CLOSE WINDOW: EXIT
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // CLEAR SCREEN
        window.clear();

        // SET POSITION OF BACKGROUND
        sprite.setPosition(0, 0);
        sprite.setScale(2,2);
        // DRAW BACKGROUND
        window.draw(sprite);

        // DRAW BOXES
        /*
        window.draw(box1);
        window.draw(box2);

        // STATS FOR TEXT
        sf::Text text1(DigimonTo_String(*gabumon), font, 25);
        text1.setFillColor(sf::Color::Black);
        text1.setPosition(90, 220);

        sf::Text text2(DigimonTo_String(*agumon), font, 25);
        text2.setFillColor(sf::Color::Black);
        text2.setPosition(975, 220);

        // DRAW TEXT
        window.draw(text1);
        window.draw(text2);
        */

        // STATS FOR DIGIMON 1
        sprite1.setPosition(900, 50);
        sprite1.setScale(7.5, 7.5);
        sprite1.setTextureRect(sf::IntRect(xDigimon1, yDigimon1, 32, 32));

        // STATS FOR DIGIMON 2
        sprite2.setPosition(135, 350);
        sprite2.setScale(7.5, 7.5);
        sprite2.setTextureRect(sf::IntRect(xDigimon2, yDigimon2, 32, 32));

        if (frames.getElapsedTime() >= sf::seconds(0.15))
        {
            if ((yDigimon1 + 32) < 128)
            {
                if (xDigimon1 += 32 >= 64)
                {
                    xDigimon1 = 0;
                }
                else
                {
                    xDigimon1 += 32;
                }
                yDigimon1 += 32;
            }
            else
            {
                yDigimon1 = 0;
            }

            if ((yDigimon2 + 32) < 128)
            {
                if (xDigimon2 += 32 >= 64)
                {
                    xDigimon2 = 0;
                }
                else
                {
                    xDigimon2 += 32;
                }
                yDigimon2 += 32;
            }
            else
            {
                yDigimon2 = 0;
            }
            frames.restart();
        }
        window.draw(sprite1);
        window.draw(sprite2);

        if (agumon->Fainted == true || gabumon->Fainted == true)
        {
            cout << "End" << endl;
            break;
        }
        if (combat.getElapsedTime() >= sf::seconds(5))
        {
            agumon->Attack(*gabumon);
            gabumon->Attack(*agumon);
            combat.restart();
        }
        window.display();
    }

    //----------------------------------------------
    return EXIT_SUCCESS;
}

string DigimonTo_String(Digimon &Target)
{
    ostringstream stream;
    stream << "NAME: " << Target.Name;
    stream << "\nLVL: " << Target.Level;
    stream << "\nHP: " << Target.Health_Points << "/" << Target.maxHP;
    stream << "\nSP: " << Target.Skill_Points << "/" << Target.maxSP;
    stream << "\nDEF: " << Target.Defense;
    stream << "\nSPD: " << Target.Speed;

    stream << "\nFNT: ";
    if (Target.Fainted == false)
    {
        stream << "No";
    }
    else
    {
        stream << "Yes";
    }

    stream.str();
    return stream.str();
}