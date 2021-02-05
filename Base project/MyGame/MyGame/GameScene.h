#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();

  // Get the current score
  int getScore();
  
  // Increase the score 
void increaseScore(); 

private:
  int score_ = 0;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
