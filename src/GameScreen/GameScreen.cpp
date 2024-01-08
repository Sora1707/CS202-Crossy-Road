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

void GameScreen::setStaticText(){
    gameOverText.setString(std::string("Game Over"));
    gameOverText.setCharacterSize(100);
    gameOverText.setFont(constant::fontArial);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(constant::APP_WIDTH / 2 - gameOverText.getLocalBounds().width / 2, 200);

    pressEnterText.setString(std::string("Press Enter to continue..."));
    pressEnterText.setCharacterSize(50);
    pressEnterText.setFont(constant::fontArial);
    pressEnterText.setFillColor(sf::Color::Black);
    pressEnterText.setPosition(constant::APP_WIDTH / 2 - gameOverText.getLocalBounds().width / 2, 400);

    scoreText.setCharacterSize(50);
    scoreText.setFont(constant::fontArial);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(10, 10);

    highestScoreText.setCharacterSize(50);
    highestScoreText.setFont(constant::fontArial);
    highestScoreText.setFillColor(sf::Color::Red);
    highestScoreText.setPosition(1300, 10);
};    