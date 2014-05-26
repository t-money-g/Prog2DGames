// Discordia 
// player.h 


#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#define WIN32_LEAN_AND_MEAN

#include "entity.h"

namespace playerNS
{
	const int WIDTH = 96;
	const int HEIGHT = 120;
	const int X = GAME_WIDTH / 4;
	const int Y = GAME_HEIGHT / 4;
	const int TEXTURE_COLS = 1;
	const int PLAYER_START_FRAME = 0;
	const int PLAYER_END_FRAME = 0;
	const float SPEED = 200;
	const float JUMP_SPEED = 400;
	enum STATUS { IDLE, RUNNING, FALLING,JUMPING};
	const float MASS = 1.0f;

}
//Hopefully this will go well
class Player :	public Entity
{
private: 
	playerNS::STATUS status;

public:
	int jumpHeight;
	Player();
	// Inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height,int ncols, TextureManager *textureM);
	//update player position
	void update(float frameTime);
	
	void damage(int weapon);

	void jump();
	playerNS::STATUS getStatus();
	void setStatus(playerNS::STATUS playerStatus);
};
#endif
