#include "GameScene.h"
#include "Ship.h"

GameScene::GameScene() {
  ShipPtr ship = std::make_shared<Ship>();
  addGameObject(ship);
}
