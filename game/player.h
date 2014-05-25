// Discordia 
// player.h 


#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#define WIN32_LEAN_AND_MEAN

#include "entity.h"

namespace playerNS
{
	const int WIDTH = 120;
	const int HEIGHT = 92;
	const int X = GAME_WIDTH / 4;
	const int Y = GAME_HEIGHT / 4;
	const int TEXTURE_COLS = 1;
	const int PLAYER_START_FRAME = 0;
	const int PLAYER_END_FRAME = 0;
	const float SPEED = 100;
	enum STATUS { IDLE, RUNNING, FALLING};
}
//Hopefully this will go well
class Player :	public Entity
{
private: 
	playerNS::STATUS status;

public:

	Player();
	// Inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height,int ncols, TextureManager *textureM);
	//update player position
	void update(float frameTime);
	
	void damage(int weapon);


};
#endif
