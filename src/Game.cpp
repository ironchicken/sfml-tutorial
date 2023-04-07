#include <algorithm>
#include <memory>
#include "Game.hpp"
#include "Ball.hpp"
#include "InputHandler.hpp"

Game::Game() : window(sf::RenderWindow(sf::VideoMode(640, 480), "SFML Tutorial")), inputHandler(window)
{
    entities.emplace_back(std::make_unique<Ball>());
    ballIndex = entities.size() - 1;
}

Game::~Game() { }

void Game::run() {
    while (window.isOpen()) {
        processInput();

        auto elapsed = clock.restart();
        if (elapsed < targetDelayMS) {
            sf::sleep(targetDelayMS - elapsed);
        }

        update(elapsed);
        render(elapsed);
    }
}

void Game::processInput() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            auto command = inputHandler.handleInput(event);
            if (command != nullptr) {
                command->execute(entities[ballIndex]);
            }
        }
    }
}

void Game::update(sf::Time elapsed) {
    std::for_each(entities.cbegin(), entities.cend(), [&elapsed](auto &e) { e->update(elapsed); });
}

void Game::render(sf::Time elapsed) {
    window.clear();

    std::for_each(entities.cbegin(), entities.cend(), [this](auto &e) { e->render(window); });

    window.display();
}
