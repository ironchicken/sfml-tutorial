#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameEntity.hpp"
#include "InputHandler.hpp"

class Game {
public:
    Game();
    virtual ~Game();
    void run();

private:
    void processInput();
    void update(sf::Time elapsed);
    void render(sf::Time elapsed);

    sf::RenderWindow window;
    const int frameRate { 60 };
    const sf::Time targetDelayMS = sf::milliseconds(1000 / frameRate);

    sf::Event event;
    sf::Clock clock;

    std::vector<std::unique_ptr<GameEntity>> entities;
    unsigned int ballIndex;

    InputHandler inputHandler;
};

#endif
