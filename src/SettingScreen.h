#pragma once
#include <SFML/Graphics.hpp>
#include "/HK4/CS202/CS202-Crossy-Road/src/Constant.h"
#include "/HK4/CS202/CS202-Crossy-Road/src/Components/Button.h"
#include "/HK4/CS202/CS202-Crossy-Road/src/Components/ImageButton.h"
#include "/HK4/CS202/CS202-Crossy-Road/src/Components/Label.h"
#include "/HK4/CS202/CS202-Crossy-Road/src/TextureHolder.h"
#include "/HK4/CS202/CS202-Crossy-Road/src/Game/Player.h"
#include "/HK4/CS202/CS202-Crossy-Road/src/Util/sfml.h"
#include <map>
#include <iostream>
#include <string>

#include "/HK4/CS202/CS202-Crossy-Road/src/Screen.h"

class SettingScreen : public Screen {
private:
    enum class Type {
        Up,
        Down,
        Left,
        Right,
        Volume,
        Character,
        Menu,
        Back,
        Count,
    };

    Button *buttons[(int)Type::Count];
    Label keyLabels[(int)Player::Movement::Count];
    sf::RectangleShape background;
    int isActiveId = 0;
    bool isPressed = false;

public:
    SettingScreen();
    ~SettingScreen();

public:
    void setSoundPlayer(SoundPlayer *soundPlayer) override;

public:
    // Event Handler
    void handleEvent(sf::RenderWindow &window, sf::Event &event);

    // Update
    void update(sf::RenderWindow &window);

    // draw
    void draw(sf::RenderWindow &window);

    // Utility
private:
    Player::Movement getMovement(int id);
};