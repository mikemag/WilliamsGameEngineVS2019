#include "GameScene.h"
#include "Ship.h"
#include "Meteor.h"

GameScene::GameScene() {
  ShipPtr ship = std::make_shared<Ship>();
  addGameObject(ship);

  MeteorPtr m = std::make_shared<Meteor>(sf::Vector2f(400, 100));
  addGameObject(m);
}
