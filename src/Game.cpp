#include "Game.hpp"

Game::Game() : window(sf::RenderWindow(sf::VideoMode(640, 480), "SFML Tutorial"))
             , shape(sf::CircleShape(100.f))
{
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(5.0);
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
                velocityY = -140.0;
                break;
            case sf::Keyboard::S:
                velocityY = 140.0;
                break;
            case sf::Keyboard::A:
                velocityX = -140.0;
                break;
            case sf::Keyboard::D:
                velocityX = 140.0;
                break;
            default:
                break;
            }
        }
    }
}

void Game::update(sf::Time elapsed) {
    if (circleX >= 640 && velocityX > 0.0) {
        velocityX = -140.0;
    }
    if (circleX <= 0 && velocityX < 0.0) {
        velocityX = 140.0;
    }
    if (circleY >= 480 && velocityY > 0.0) {
        velocityY = -140.0;
    }
    if (circleY <= 0 && velocityY < 0.0) {
        velocityY = 140.0;
    }

    circleX += elapsed.asSeconds() * velocityX;
    circleY += elapsed.asSeconds() * velocityY;

    shape.setPosition(circleX, circleY);
}

void Game::render(sf::Time elapsed) {
    window.clear();
    window.draw(shape);
    window.display();
}
