// A generic container for our goblin friend
#pragma once
#ifndef _GOBLIN_H
#define _GOBLIN_H

#include "entity.h"

#define WIN32_LEAN_AND_MEAN

namespace goblinNS {
	const int WIDTH = 60;
	const int HEIGHT = 50;
	const int X = GAME_WIDTH / 4;
	const int Y = GAME_HEIGHT / 4;
	const int TEXTURE_COLS = 1;
	const int GOBLIN_START_FRAME = 0;
	const int GOBLIN_END_FRAME = 0;
	enum STATUS { IDLE, WALKFORWARD};
	const float MASS = .50f;
	const int SPEED = 100;
}
class Goblin :	public Entity
{
	private:
		goblinNS::STATUS status;
public:
	Goblin();

	virtual void draw();

	virtual bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	
	//update Goblin position
	void update(float frameTime);

	/* For now our Goblin has no higher reasoning but to 
	walk back and forth between two boundaries.*/
	void walkForward();

	void damage();

	goblinNS::STATUS getStatus();
	
};

#endif