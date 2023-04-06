#include <algorithm>
#include <memory>
#include "Game.hpp"
#include "Ball.hpp"

Game::Game() : window(sf::RenderWindow(sf::VideoMode(640, 480), "SFML Tutorial"))
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
            switch (event.key.code) {
            case sf::Keyboard::Q:
                window.close();
                break;
            case sf::Keyboard::W:
                entities[ballIndex]->setVelocityY(-140.f);
                break;
            case sf::Keyboard::S:
                entities[ballIndex]->setVelocityY(140.f);
                break;
            case sf::Keyboard::A:
                entities[ballIndex]->setVelocityX(-140.f);
                break;
            case sf::Keyboard::D:
                entities[ballIndex]->setVelocityX(140.f);
                break;
            default:
                break;
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
