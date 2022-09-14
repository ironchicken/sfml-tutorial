#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
    sf::RenderWindow window{ sf::VideoMode(640, 480), "SFML Tutorial" };
    sf::CircleShape shape{ 100.f };
    shape.setFillColor(sf::Color::Green);

    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
