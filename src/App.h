#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constant.h"
#include <iostream>

class App {
public:
    App();
    ~App();

public: 
    void run();
    void close();

private:
    sf::RenderWindow window;

private:
    int currentScreenId;


private:
    void processEvents();
    void update();
    void render();
};