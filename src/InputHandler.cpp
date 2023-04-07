#include "InputHandler.hpp"
#include "Command.hpp"

InputHandler::InputHandler(sf::RenderWindow& window) {
    quit = std::make_shared<QuitCommand>(window);
    moveUp = std::make_shared<MoveCommand>(sf::Vector2f{0.0, -140.0});
    moveDown = std::make_shared<MoveCommand>(sf::Vector2f{0.0, 140.0});
    moveLeft = std::make_shared<MoveCommand>(sf::Vector2f{-140.0, 0.0});
    moveRight = std::make_shared<MoveCommand>(sf::Vector2f{140.0, 0.0});
}

std::shared_ptr<Command> InputHandler::handleInput(const sf::Event& event) {
    switch (event.key.code) {
    case sf::Keyboard::Q:
        return quit;
    case sf::Keyboard::W:
        return moveUp;
    case sf::Keyboard::S:
        return moveDown;
    case sf::Keyboard::A:
        return moveLeft;
    case sf::Keyboard::D:
        return moveRight;
    default:
        return nullptr;
    }
}
