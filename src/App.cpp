#include "App.h"

App::App() {
    window.create(sf::VideoMode(constant::APP_WIDTH, constant::APP_HEIGHT), constant::APP_TITLE);
    window.setFramerateLimit(constant::APP_FPS);
}

App::~App() {
}

void App::run() {
    TextureHolder* textureHolder = TextureHolder::getInstance();
    SoundHolder& soundHolder     = SoundHolder::getInstance();

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
    }
}

void App::update() {
   
}

// Render
void App::render() {
    window.clear(constant::BLACK);

    window.display();
}
