#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

class GameEntity {
public:
    GameEntity() : position({0, 0}), velocity({0, 0}), width(0), height(0) {};
    GameEntity(const sf::Vector2f p, const sf::Vector2f v, unsigned int w, unsigned int h) : position(p), velocity(v), width(w), height(h) {};
    virtual ~GameEntity() { };

    virtual void render(sf::RenderWindow& window) = 0;
    virtual void update(sf::Time elapsed) = 0;

    const sf::Vector2u& getPosition() const { return position; };
    void setPosition(const sf::Vector2u p) { position = p; };
    const sf::Vector2f& getVelocity() const { return velocity; };
    void setVelocity(const sf::Vector2f v) { velocity = v; };
    void setVelocityX(const float x) { velocity.x = x; };
    void setVelocityY(const float y) { velocity.y = y; };
    unsigned int getWidth() const { return width; };
    void setWidth(unsigned int w) { width = w; };
    unsigned int getHeight() const { return height; };
    void setHeight(unsigned int h) { height = h; };

private:
    sf::Vector2u position;
    sf::Vector2f velocity;
    unsigned int width;
    unsigned int height;
};

#endif
