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
	flipHorizontal(true);
	
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

	spriteData.x += frameTime * velocity.x;
	spriteData.y += frameTime * velocity.y;
	//if we hit the right of the screen
	if (spriteData.x > GAME_WIDTH - goblinNS::WIDTH * getScale())
	{
		flipHorizontal(false);
		spriteData.x = GAME_WIDTH - goblinNS::WIDTH * getScale();
		velocity.x = -velocity.x;
	}

	if (spriteData.x < 0) {
		flipHorizontal(true);
		spriteData.x = 0;
		velocity.x = -velocity.x;
	}

	//the floor is 80px high and we want to appear on the ground which is at 15px
	if (spriteData.y > GAME_HEIGHT - 65 - (goblinNS::HEIGHT  * getScale()))
	{
		spriteData.y = GAME_HEIGHT - 65 - (goblinNS::HEIGHT  * getScale());
	}

}

void Goblin::walkForward()
{
	//setVelocity()
}

void Goblin::damage()
{
	if (getX() > GAME_WIDTH / 2) {
		setX(getX() + 50);
	}
	if (getX() < GAME_WIDTH / 2) {
		setX(getX() - 50);
	}
}

goblinNS::STATUS Goblin::getStatus() {
	return status;
}