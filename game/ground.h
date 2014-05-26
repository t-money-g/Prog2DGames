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
	
	void update(float frameTime);
};

#endif