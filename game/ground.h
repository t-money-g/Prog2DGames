#ifndef _GROUND_H
#define _GROUND_H
#include "entity.h"
#include "constants.h"
#define WIN32_LEAN_AND_MEAN

namespace groundNS
{
	const int WIDTH = 1023;
	const int HEIGHT = 80;
	const int X = 0;
	const int Y = GAME_HEIGHT - HEIGHT;
	const float MASS = 1.0e6f;
}
class Ground :	public Entity
{
public:
	Ground();

	virtual void draw();

	virtual bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	// shouldn't haven't to update the position	
	void update(float frameTime);
};

#endif