#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
    sf::RenderWindow window{ sf::VideoMode(640, 480), "SFML Tutorial" };
    sf::CircleShape shape{ 100.f };
    shape.setFillColor(sf::Color::Green);
    shape.setRadius(5.0);

    const int frameRate { 30 };
    const sf::Time targetDelayMS = sf::milliseconds(1000 / frameRate);

    sf::Event event;
    sf::Clock clock;

    int circleX = 640 / 2;
    int circleY = 480 / 2;
    float velocityX = 140.0;
    float velocityY = 140.0;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        auto elapsed = clock.restart();
        if (elapsed < targetDelayMS) {
            sf::sleep(targetDelayMS - elapsed);
        }

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

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
