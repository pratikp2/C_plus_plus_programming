#include "GameController.h"

GameLevel * GameController :: currentLevel;

void GameController::LoadInitialLevel(GameLevel * level)
{
	level->Loading = true;
	currentLevel = level;
	currentLevel->LoadLevel();
	currentLevel->Loading = false;
}

void GameController :: SwitchLevel(GameLevel * level)
{
	
}