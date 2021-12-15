#include "Button.hpp"


Button::Button(sf::Vector2f pos, sf::Vector2f size) {
    rect.setSize(size);
    rect.setPosition(pos);
    rect.setFillColor(sf::Color::Red);
}
Button::Button(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
    rect.setSize(size);
    rect.setPosition(pos);
    rect.setFillColor(color);
}
void Button::draw(sf::RenderWindow &window) {
    window.draw(rect);
}
void Button::setOrigin(sf::Vector2f Origin) {
    rect.setOrigin(Origin);
}
bool Button::press(sf::RenderWindow &window, sf::Color color){
    if (sf::Mouse::getPosition(window).x >= rect.getPosition().x - rect.getOrigin().x &&
        sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x - rect.getOrigin().x &&
        sf::Mouse::getPosition(window).y >= rect.getPosition().y - rect.getOrigin().y &&
        sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y - rect.getOrigin().y) {
        rect.setFillColor(color);
        timer = clock.getElapsedTime();
        pressed = true;
        return true;
    }
    return false;
}
bool Button::press(sf::RenderWindow &window){
    if (sf::Mouse::getPosition(window).x >= rect.getPosition().x - rect.getOrigin().x &&
        sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x - rect.getOrigin().x &&
        sf::Mouse::getPosition(window).y >= rect.getPosition().y - rect.getOrigin().y &&
        sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y - rect.getOrigin().y) {  
        timer = clock.getElapsedTime();
        pressed = true;
        return true;
    }
    return false;
}
void Button::release(sf::Color color){
    rect.setFillColor(color);
    if (pressed) {
        std::cout << "The button was pressed for " << clock.getElapsedTime().asSeconds() - timer.asSeconds() << " seconds" << std::endl;
    }
    pressed = false;
}
void Button::release(){
    if (pressed) {
        std::cout << "The button was pressed for " << clock.getElapsedTime().asSeconds() - timer.asSeconds() << " seconds" << std::endl;
    }
    pressed = false;
}
