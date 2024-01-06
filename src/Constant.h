#pragma once
#include <SFML/Graphics.hpp>

// namespace constant (GLOBAL)
namespace constant {
    // Font
    extern sf::Font fontArial;
    void loadFont();

    // Color
    sf::Color const BACKGROUND_COLOR = sf::Color(255, 255, 153);
    sf::Color const YELLOW           = sf::Color::Yellow;
    sf::Color const BLACK            = sf::Color::Black;
    sf::Color const WHITE            = sf::Color::White;

    // APP
    const int APP_FPS                = 60;
    const int APP_WIDTH              = 1600;
    const int APP_HEIGHT             = 900;
    const std::string APP_TITLE      = "Crossy Road";

    // TEXT
    const std::string ERROR   = "[ERROR] ";
    const std::string WARN    = "[WARNING] ";
    const std::string SUCCESS = "[SUCCESS] ";
    const std::string INFO    = "[INFO] ";

} // namespace constant