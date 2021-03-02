#include "Meteor.h"
#include "Explosion.h"
#include "GameScene.h"

const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos) {
  sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
  sprite_.setPosition(pos);
  assignTag("meteor");
  setCollisionCheckEnabled(true); // NB: he doesn't show putting this one here!
}

void Meteor::draw() {
  GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed) {
  int msElapsed = elapsed.asMilliseconds();
  sf::Vector2f pos = sprite_.getPosition();

  if (pos.x < sprite_.getGlobalBounds().width * -1) {
    GameScene& scene = (GameScene&)GAME.getCurrentScene(); 
    scene.decreaseLives();
    makeDead();
  }
  else {
    sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
  }
}

sf::FloatRect Meteor::getCollisionRect() {
  return sprite_.getGlobalBounds();
} 

void Meteor::handleCollision(GameObject& otherGameObject) { 
  if (otherGameObject.hasTag("laser")) {
    otherGameObject.makeDead(); 
  }
  
  makeDead();

  // This part is also missing: described, but not shown.
  GameScene& scene = (GameScene&)GAME.getCurrentScene();
  scene.increaseScore();

  // This is the part that is left out of the tutorial. It's similar to creating a laser in Ship.cpp
  sf::Vector2f pos = sprite_.getPosition();
  sf::FloatRect bounds = sprite_.getGlobalBounds();
  float laserX = pos.x + (bounds.width / 2.0f);
  float laserY = pos.y + (bounds.height / 2.0f);
  ExplosionPtr ex = std::make_shared<Explosion>(sf::Vector2f(laserX, laserY));
  GAME.getCurrentScene().addGameObject(ex);
}