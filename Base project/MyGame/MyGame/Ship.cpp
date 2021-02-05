#include "Ship.h"

Ship::Ship() {
  sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
  sprite_.setPosition(sf::Vector2f(100, 100));
}

void Ship::draw() {
  GAME.getRenderWindow().draw(sprite_);
}