// Artyom Martirosyan Copyright 2021
#include "Triangle.h"

void fTree(int depth, double x, double y,
                double length, sf::RenderWindow &window);
int main(int argc, char*argv[]) {
    double length = atof(argv[1]);
    int depth = atoi(argv[2]);

    sf::RenderWindow window(sf::VideoMode(1000, 1000),
                                "Sierpinski's Triangle Variation");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window.close();
        }

        fTree(depth, 500, 500, length, window);
        window.display();
    }

    return 0;
}

void fTree(int depth, double x, double y,
            double length, sf::RenderWindow &window) {
    if (depth < 0)
        return;
    double h = (sqrt(3)/2.0) * length;

    sf::Vector2f xy1(x - (length/2.0), y - (h/3.0));
    sf::Vector2f xy2(x + (length/2.0), y - (h/3.0));
    sf::Vector2f xy3(x, y + (2.0 * (h/3.0)));

    Triangle triangle(xy1, xy2, xy3);
    window.draw(triangle);
    fTree(depth - 1, x - (length/2.0), y - (2.0 * (h/3.0)), length/2.0, window);
    fTree(depth - 1, x + ((3 * length)/4.0), y - (h/6.0), length/2.0, window);
    fTree(depth - 1, x - (length/4.0), y + (5 * (h/6.0)), length/2.0, window);
}
