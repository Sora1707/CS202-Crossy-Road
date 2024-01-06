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
    const int TILE_SIZE              = 100;
    const int APP_ROW                = 9;
    const int APP_COLUMN             = 16;
    const int APP_SAFE_LANE          = 4;
    const float APP_VELOCITY         = 0.5;
    const float APP_SPEEDUP_VELOCITY = 5;

    // TEXT
    const std::string ERROR   = "[ERROR] ";
    const std::string WARN    = "[WARNING] ";
    const std::string SUCCESS = "[SUCCESS] ";
    const std::string INFO    = "[INFO] ";

    /* COMPONENTS */
    // BUTTON
    const float BUTTON_WIDTH  = 200;
    const float BUTTON_HEIGHT = 50;

    // CHARACTER BUTTON
    const float CHARACTER_BUTTON_WIDTH  = 200;
    const float CHARACTER_BUTTON_HEIGHT = 200;

} // namespace constant

namespace Textures {
    enum class Player {
        StartIndex = 1000,
        Left01     = 1000,
        Right01,
        Up01,
        Down01,
        Left02,
        Right02,
        Up02,
        Down02,
        Left03,
        Right03,
        Up03,
        Down03,
        Left04,
        Right04,
        Up04,
        Down04,
        Left05,
        Right05,
        Up05,
        Down05,
        Texture01 = Left01,
        Texture02 = Left02,
        Texture03 = Left03,
        Texture04 = Left04,
        Texture05 = Left05,
    };

    enum class Grass {
        StartIndex = 10,
        Grass01    = 10,
        Grass02,
        Grass03,
        Grass04,
        Grass05,
        Grass06,
        Count = 6
    };

    enum class Obstacle {
        StartIndex = 20,
        Statue     = 20,
        SmallRock,
        BigRock,
        Tomb,
        BrokenTomb,
        Count = 5,
    };

    enum class River {
        StartIndex = 30,
        Default    = 30,
        WithGrass,
        LilyPad,
        Count = 2,
    };

    enum class Road {
        StartIndex = 40,
        Default    = 40,
        Count      = 1,
    };

    enum class Rail {
        StartIndex = 50,
        Default    = 50,
        Traffic,
        TrafficActive,
        Count = 3,
    };

    enum class Car {
        Count  = 5,
        Left01 = 100,
        Left02,
        Left03,
        Left04,
        Left05,
        Right01,
        Right02,
        Right03,
        Right04,
        Right05,
    };

    enum class Train {
        Left = 110,
        Right,
    };

    enum class Mountable {
        Wood = 200,
    };

    enum class Background {
        Main = 500,
    };

    enum class Button {
        Normal = 600,
        Active,
        Hovered
    };
} // namespace Textures

namespace Sound {
    enum Sound {
        Start,
        ButtonMove,
        ButtonEnter,
        Car,
        Train,
        Log,
        Hit,
        PlayerMove,
        RiverJump,
        RiverFlow,
    };
}