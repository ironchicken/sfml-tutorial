#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/System/Vector2.hpp"

class GameEntity {
public:
    GameEntity() : position({0, 0}), width(0), height(0) {};
    GameEntity(const sf::Vector2f p, unsigned int w, unsigned int h) : position(p), width(w), height(h) {};
    virtual ~GameEntity() = 0;

    virtual void render(sf::RenderWindow& window) = 0;
    virtual void update(sf::Time elapsed) = 0;

    const sf::Vector2u& getPosition() const { return position; };
    void setPosition(const sf::Vector2u p) { position = p; };
    unsigned int getWidth() const { return width; };
    void setWidth(unsigned int w) { width = w; };
    unsigned int getHeight() const { return height; };
    void setHeight(unsigned int h) { height = h; };

private:
    sf::Vector2u position;
    unsigned int width;
    unsigned int height;
};

#endif
