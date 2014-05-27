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
	// 18 pixel high Adventure
	if (dxFont->initialize(graphics, 18, true, false, "Adventure") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	// player image
	if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture"));

	if (!player.initialize(this, playerNS::WIDTH,playerNS::HEIGHT,playerNS::TEXTURE_COLS, &playerTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initalizing player"));

	if (!groundTexture.initialize(graphics, GROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ground texture"));

	if (!ground.initialize(this, 0, 0, 0, &groundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initalizing player"));

	menu.setY(0);
	menu.setX(0);

	player.setFrames(playerNS::PLAYER_START_FRAME, playerNS::PLAYER_END_FRAME);
	player.setCurrentFrame(playerNS::PLAYER_START_FRAME);

	player.setX(GAME_WIDTH / 4);
	player.setY(GAME_HEIGHT / 4);
	player.setVelocity(VECTOR2(0, playerNS::SPEED));
	

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Discordia::update()
{
	if (menuOn)
	{
		if (input->anyKeyPressed()){
			menuOn = false;
			input->clearAll();
			//start the game
			startLevel();
		}
	}
	else {
		//we should implement a state 
		//machine here
		if (input->isKeyDown(PLAYER_RIGHT))
		{
			player.walkInDirection(playerNS::RIGHT, frameTime);
		
		}
		if (input->isKeyDown(PLAYER_LEFT))
		{
			//player.moveLeft
			player.walkInDirection(playerNS::LEFT, frameTime);
			
		
		}
		
		if (input->isKeyDown(PLAYER_UP))
		{
		
			if (player.getStatus() != playerNS::FALLING) {
				player.jump();
			}
		}

		if (input->getMouseLButton())
		{
			player.slice();
		}
		
	}
	player.update(frameTime);
	ground.update(frameTime);
}


void Discordia::startLevel() {

}
//=============================================================================
// Artificial Intelligence
//=============================================================================
void Discordia::ai()
{

}

//=============================================================================
// Handle collisions
//=============================================================================
void Discordia::collisions()
{
	
}

//=============================================================================
// Render game items
//=============================================================================
void Discordia::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	if (menuOn) {
		menu.draw();
		dxFont->setFontColor(graphicsNS::ORANGE);
		dxFont->print(message, 20, (int)messageY);
	}
	else {
		//Display list anyone??
		ground.draw();
		player.draw();
		
	}
	

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
	playerTexture.onLostDevice();
	groundTexture.onLostDevice();
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
	playerTexture.onResetDevice();
	groundTexture.onResetDevice();
	dxFont->onResetDevice();
	Game::resetAll();
	return;
}