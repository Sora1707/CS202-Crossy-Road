#include "App.h"

App::App() {
    window.create(sf::VideoMode(constant::APP_WIDTH, constant::APP_HEIGHT), constant::APP_TITLE);
    window.setFramerateLimit(constant::APP_FPS);

    /* MENU */
    // Change Screen to Menu Screen later
    screens[(int)constant::Screen::Menu] = std::make_shared<MenuScreen>(); 
    screens[(int)constant::Screen::Menu]->setSoundPlayer(&soundPlayer);

    /* SETTING */
    // Change Screen to Setting Screen later
    screens[(int)constant::Screen::Setting] = std::make_shared<SettingScreen>(); 
    screens[(int)constant::Screen::Setting]->setSoundPlayer(&soundPlayer);

    /* GAME */
    // Change Screen to Game Screen later
    screens[(int)constant::Screen::Game] = std::make_shared<GameScreen>(); 
    screens[(int)constant::Screen::Game]->setSoundPlayer(&soundPlayer);

    // Start at Menu Screen when game opens
    currentScreenId = (int)constant::Screen::Game;

    std::string bgmFile = "resource/music/Leap to the Beat.mp3";
    if (!bgm.openFromFile(bgmFile)) {
        std::cout << constant::ERROR << "Cannot open file " << bgmFile << "\n";
        window.close();
        return;
    }
    bgm.setLoop(true);
    bgm.setVolume(50);
}

App::~App() {
}

void App::run() {
    TextureHolder* textureHolder = TextureHolder::getInstance();
    SoundHolder& soundHolder     = SoundHolder::getInstance();
    Player& player               = Player::getInstance();

    player.setSoundPlayer(&soundPlayer);

    bgm.play();

    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }

    std::cout << constant::INFO << "App closing...\n";
}

void App::close() {
    window.close();
}

void App::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }
        screens[currentScreenId]->handleEvent(window, event);
    }
}

void App::update() {
    screens[currentScreenId]->update(window);
}

// Render
void App::render() {
    window.clear(constant::BLACK);

    screens[currentScreenId]->draw(window);

    window.display();
}
