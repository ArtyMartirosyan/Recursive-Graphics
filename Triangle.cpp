// Artyom Martirosyan Copyright 2021
#include "Triangle.h"
Triangle::Triangle(const sf::Vector2f& p1,
                    const sf::Vector2f& p2, const sf::Vector2f& p3) {
    triangle = sf::VertexArray(sf::LineStrip, 4);
    triangle[0].position = p1;
    triangle[1].position = p2;
    triangle[2].position = p3;
    triangle[3].position = triangle[0].position;
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(triangle);
}
