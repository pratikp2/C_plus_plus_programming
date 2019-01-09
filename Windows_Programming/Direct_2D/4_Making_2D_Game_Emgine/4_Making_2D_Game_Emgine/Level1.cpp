#include "Level1.h"


void Level1::LoadLevel()
{
	y = ySpeed = 0.0f;
	ptrSprisheet = new SpriteSheet(L"Test.png",gfx);

}

void Level1::UnLoadLevel()
{
	delete ptrSprisheet;
}

void Level1::UpdateLevel()
{
	ySpeed = ySpeed + 1.0f;
	y = y + ySpeed;
	if (y > 600)
	{
		y = 600;
		ySpeed = -30.0f;
	}
}

void Level1::RenderLevel()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);
	gfx->DrawCircle(400.0f, y, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	ptrSprisheet->Draw();
}