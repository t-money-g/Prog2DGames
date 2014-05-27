#include "goblin.h"


Goblin::Goblin() : Entity()
{
	spriteData.width = goblinNS::WIDTH;
	spriteData.height = goblinNS::HEIGHT;
	spriteData.x = goblinNS::X;
	spriteData.y = goblinNS::Y;
	spriteData.rect.bottom = goblinNS::HEIGHT;
	startFrame = goblinNS::GOBLIN_START_FRAME;
	endFrame = goblinNS::GOBLIN_END_FRAME;
	collisionType = entityNS::CIRCLE;

	status = goblinNS::IDLE;
	active = true;
	
}

bool Goblin::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return (Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//Draw goblin
void Goblin::draw()
{
	Image::draw();
}

void Goblin::update(float frameTime)
{
	Entity::update(frameTime);
}

void Goblin::walkForward()
{

}

void Goblin::damage()
{

}

goblinNS::STATUS Goblin::getStatus() {
	return status;
}