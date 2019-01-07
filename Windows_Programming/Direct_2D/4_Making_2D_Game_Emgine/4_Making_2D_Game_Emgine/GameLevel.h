#pragma once

class GameLevel 
{
public : 
	bool Loading;

	virtual void LoadLevel() = 0;
	virtual void UnLoadLevel() = 0;
	virtual void RenderLevel() = 0;
	virtual void UpdateLevel() = 0;
};