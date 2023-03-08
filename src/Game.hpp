#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

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
    sf::CircleShape shape;
    const int frameRate { 60 };
    const sf::Time targetDelayMS = sf::milliseconds(1000 / frameRate);

    sf::Event event;
    sf::Clock clock;

    int circleX = 640 / 2;
    int circleY = 480 / 2;
    float velocityX = 140.0;
    float velocityY = 140.0;
};

#endif
