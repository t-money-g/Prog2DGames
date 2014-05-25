#include "Discordia.h"
// This class is the core of the game

Discordia::Discordia()
{
	dxFont = new TextDX();  // DirectX font
	messageY = 0;
}


Discordia::~Discordia()
{
	releaseAll();           // call onLostDevice() for every graphics item
	safeDelete(dxFont);
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Discordia::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError

	// menu texture
	if (!menuTexture.initialize(graphics, MENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	// menu image
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// initialize DirectX font
	// 18 pixel high Arial
	if (dxFont->initialize(graphics, 18, true, false, "Adventure") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	menu.setDegrees(300);
	menu.setScale(0.002861f);

	message = "\n\n\nDiscordia\n\n";
	
	messageY = GAME_HEIGHT;

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Discordia::update()
{
	if (menu.getDegrees() > 0)
	{
		menu.setDegrees(menu.getDegrees() - frameTime * 120);
		menu.setScale(menu.getScale() + frameTime * 0.4f);
	}
	else if (messageY > -500)
	{
		menu.setDegrees(0);
		menu.setY(menu.getY() - frameTime * 50);
		messageY -= frameTime * 50;
	}
	else    // start over
	{
		menu.setDegrees(300);
		menu.setScale(0.002861f);
		menu.setY(0);
		messageY = GAME_HEIGHT;
	}
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Discordia::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Discordia::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void Discordia::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	menu.draw();
	dxFont->setFontColor(graphicsNS::ORANGE);
	dxFont->print(message, 20, (int)messageY);

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Discordia::releaseAll()
{
	dxFont->onLostDevice();
	menuTexture.onLostDevice();
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Discordia::resetAll()
{
	menuTexture.onResetDevice();
	dxFont->onResetDevice();
	Game::resetAll();
	return;
}