#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

#include "GameEntity.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

class Command {
public:
    Command() { };
    virtual ~Command() { };
    virtual void execute(std::unique_ptr<GameEntity>& entity) = 0;
};

class QuitCommand : public Command {
public:
    QuitCommand(sf::RenderWindow& w) : window(w) { };
    void execute(std::unique_ptr<GameEntity>& entity) override;

private:
    sf::RenderWindow& window;
};

class MoveCommand : public Command {
public:
    MoveCommand(sf::Vector2f v) : velocity(v) { };
    void execute(std::unique_ptr<GameEntity>& entity) override;

private:
    sf::Vector2f velocity;
};

#endif
