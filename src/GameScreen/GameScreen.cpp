#include "GameScreen.h"

GameScreen::GameScreen(): player(Player::getInstance()) {
    isPause = true;

    setCurrentScreenId((int)constant::Screen::Game);

    //lanes.push_back(createRailLane(0 * constant::TILE_SIZE));
    for (int i = 0; i < constant::APP_ROW - constant::APP_SAFE_LANE; ++i) {
        lanes.push_back(createRandomLane(i * constant::TILE_SIZE));
    }

    for (int i = constant::APP_ROW - constant::APP_SAFE_LANE; i < constant::APP_ROW + 1; ++i) {
        lanes.push_back(createGrassLane(i * constant::TILE_SIZE));
    }

    setStaticText();

    // Player setting
    sf::Vector2f enviVelocity = player.getEnviVelocity();
    enviVelocity.y            = constant::APP_VELOCITY;
    player.setEnviVelocity(enviVelocity);
    player.setIsMounting(false);
    player.setLanes(lanes);
    player.setDirection(constant::Direction::Up);

    int playerX = constant::PLAYER_START_X * constant::TILE_SIZE + constant::TILE_SIZE / 2.f - constant ::PLAYER_WIDTH / 2.f;
    int playerY = constant::PLAYER_START_Y * constant::TILE_SIZE + constant::TILE_SIZE / 2.f - constant ::PLAYER_HEIGHT / 2.f;
    player.setPosition(sf::Vector2f(playerX, playerY));

    player.resetScore();

}

GameScreen::~GameScreen(){
    std::cout << constant::INFO << "Game Screen destructor\n";
    while (!lanes.empty()) {
        Lane* lane = lanes.back();
        lanes.pop_back();
        delete lane;
    }
    std::cout << constant::INFO << "Game Screen finished deallocation\n";
}