#include "Command.hpp"

void QuitCommand::execute(std::unique_ptr<GameEntity>& entity) {
    window.close();
}

void MoveCommand::execute(std::unique_ptr<GameEntity>& entity) {
    if (velocity.x != 0.0) {
        entity->setVelocityX(velocity.x);
    }
    if (velocity.y != 0.0) {
        entity->setVelocityY(velocity.y);
    }
}
