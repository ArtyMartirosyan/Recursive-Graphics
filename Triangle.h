// Artyom Martirosyan Copyright 2021
#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable {
 public:
  Triangle(const sf::Vector2f& p1,
                const sf::Vector2f& p2, const sf::Vector2f& p3);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
 private:
  sf::VertexArray triangle;
};
