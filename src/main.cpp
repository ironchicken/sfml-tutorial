#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
    sf::RenderWindow window{ sf::VideoMode(640, 480), "SFML Tutorial" };
    sf::CircleShape shape{ 100.f };
    shape.setFillColor(sf::Color::Green);

    const int frameRate { 30 };
    const sf::Time targetDelayMS = sf::milliseconds(1000 / frameRate);

    sf::Event event;
    sf::Clock clock;

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

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
