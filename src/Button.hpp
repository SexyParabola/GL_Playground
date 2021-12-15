#ifndef i3BUTTON_H
#define i3BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
private:
    sf::Clock clock;
    sf::Time timer;
    bool pressed = false;
public:
    sf::RectangleShape rect;
    Button(sf::Vector2f pos, sf::Vector2f size);
    Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
    void draw(sf::RenderWindow &window);
    void setOrigin(sf::Vector2f Origin);
    bool press(sf::RenderWindow &window, sf::Color color);
    bool press(sf::RenderWindow &window);
    void release(sf::Color color);
    void release();
};


#endif