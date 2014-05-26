// Discordia 
// player.h 


#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#define WIN32_LEAN_AND_MEAN

#include "entity.h"

namespace playerNS
{
	const int WIDTH = 270;
	const int HEIGHT =176;
	const int X = GAME_WIDTH / 4;
	const int Y = GAME_HEIGHT / 4;
	const int TEXTURE_COLS = 2;
	const int PLAYER_START_FRAME = 0;
	const int PLAYER_END_FRAME = 0;

	const int PLAYER_SLICE_START_FRAME = 1;
	const int PLAYER_SLICE_END_FRAME = 0;
	const int PLAYER_SLICE_WIDTH = 167;
	const int PLAYER_SLICE_HEIGHT = 138;

	const float PLAYER_ATTACK_ANIMATION_DELAY = 0.2f;

	const float SPEED = 200;
	const float JUMP_SPEED = 400;
	enum STATUS { IDLE, RUNNING, FALLING,JUMPING,SLICE};
	const float MASS = 1.0f;

}



class Player :	public Entity
{
private: 
	playerNS::STATUS status;
	bool slicing;
	Image playerSlice;

public:
	int jumpHeight;
	Player();
	// Inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height,int ncols, TextureManager *textureM);
	//update player position
	void update(float frameTime);
	
	void damage(int weapon);
	//Moves the player verticle by a few pixels and flips the Jumping state
	void jump();
	
	playerNS::STATUS getStatus();
	
	void setStatus(playerNS::STATUS playerStatus);
	
	//Will play slicing frame
	void slice();
};
#endif
