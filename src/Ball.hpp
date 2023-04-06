#ifndef BALL_H
#define BALL_H

#include "GameEntity.hpp"

class Ball : public GameEntity {
public:
    Ball();
    virtual ~Ball();
    void render(sf::RenderWindow& window) override;
    void update(sf::Time elapsed) override;

private:
    sf::CircleShape shape;
};

#endif
