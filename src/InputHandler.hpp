#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <memory>

#include <SFML/Window.hpp>
#include "SFML/Graphics/RenderWindow.hpp"
#include "Command.hpp"

class InputHandler {
public:
    InputHandler(sf::RenderWindow& window);
    virtual ~InputHandler() { };
    std::shared_ptr<Command> handleInput(const sf::Event& event);

private:
    std::shared_ptr<QuitCommand> quit;
    std::shared_ptr<MoveCommand> moveUp;
    std::shared_ptr<MoveCommand> moveDown;
    std::shared_ptr<MoveCommand> moveLeft;
    std::shared_ptr<MoveCommand> moveRight;
};

#endif
