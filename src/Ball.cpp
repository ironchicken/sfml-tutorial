#include "Ball.hpp"

Ball::Ball() : GameEntity({ 640.f / 2.f, 480.f / 2.f }, { 140.f, 140.f }, 10, 10)
             , shape(sf::CircleShape(100.f))
{
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(5.f);
}

Ball::~Ball() { }

void Ball::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ball::update(sf::Time elapsed) {
    auto position = getPosition();

    if (position.x >= 640 && getVelocity().x > 0.f) {
        setVelocityX(-140.f);
    }
    if (position.x <= 0 && getVelocity().x < 0.f) {
        setVelocityX(140.f);
    }
    if (position.y >= 480 && getVelocity().y > 0.f) {
        setVelocityY(-140.f);
    }
    if (position.y <= 0 && getVelocity().y < 0.f) {
        setVelocityY(140.f);
    }

    position.x += elapsed.asSeconds() * getVelocity().x;
    position.y += elapsed.asSeconds() * getVelocity().y;

    setPosition(position);

    shape.setPosition(position.x, position.y);
}
