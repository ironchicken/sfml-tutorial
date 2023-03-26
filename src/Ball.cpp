#include "Ball.hpp"

Ball::Ball() : GameEntity({ 640.f / 2.f, 480.f / 2.f }, 10, 10)
             , shape(sf::CircleShape(100.f))
             , velocity({ 140.f, 140.f })
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

    if (position.x >= 640 && velocity.x > 0.f) {
        velocity.x = -140.f;
    }
    if (position.x <= 0 && velocity.x < 0.f) {
        velocity.x = 140.f;
    }
    if (position.y >= 480 && velocity.y > 0.f) {
        velocity.y = -140.f;
    }
    if (position.y <= 0 && velocity.y < 0.f) {
        velocity.y = 140.f;
    }

    position.x += elapsed.asSeconds() * velocity.x;
    position.y += elapsed.asSeconds() * velocity.y;

    shape.setPosition(position.x, position.y);
}
