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

	if (!goblinTexture.initialize(graphics, GOBLIN_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing goblin texture"));

	if (!goblin.initialize(this, goblinNS::WIDTH, goblinNS::HEIGHT, goblinNS::TEXTURE_COLS, &goblinTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing goblin"));

	menu.setY(0);
	menu.setX(0);

	
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

		goblin.update(frameTime);
		ground.update(frameTime);
		player.update(frameTime);
		
	}
	
	
}


void Discordia::startLevel() {
	player.setVelocity(VECTOR2(0, playerNS::SPEED));

	goblin.setVelocity(VECTOR2(goblinNS::SPEED, goblinNS::SPEED));

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
	//if playercolliding with goblin and is slicing
	//damage goblin
	//if player colliding with goblin and is idle
	//damage player

	VECTOR2 collisionVector;
	if (player.collidesWith(goblin, collisionVector) && player.isSlicing()) {
		goblin.damage();
	}
	if (player.collidesWith(goblin, collisionVector) && player.isSlicing() == false) {
		//player.bounce(collisionVector, goblin);
	}
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
		graphics->setBackColor(graphicsNS::BLUE);
		//Display list anyone??
		//these objects are drawn on top of each other
		ground.draw();
		
		goblin.draw();
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
	goblinTexture.onLostDevice();
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
	goblinTexture.onResetDevice();
	dxFont->onResetDevice();
	Game::resetAll();
	return;
}