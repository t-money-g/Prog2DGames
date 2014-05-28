#include "ground.h"


Ground::Ground() : Entity()
{
	spriteData.width = groundNS::WIDTH;         // size of Ship1
	spriteData.height = groundNS::HEIGHT;
	spriteData.x = groundNS::X;                 // location on screen
	spriteData.y = groundNS::Y;
	spriteData.rect.bottom = groundNS::HEIGHT;  // rectangle to select parts of an image
	spriteData.rect.right = groundNS::WIDTH;
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	edge.top = -groundNS::HEIGHT / 2;             // set collision edges
	edge.bottom = groundNS::HEIGHT / 2;
	edge.left = -groundNS::WIDTH / 2;
	edge.right = groundNS::WIDTH / 2;
	collisionType = entityNS::ROTATED_BOX;
	mass = groundNS::MASS;
}

bool Ground::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return (Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//Draw ground
void Ground::draw()
{
	Image::draw();
}


void Ground::update(float frameTime) {

	Entity::update(frameTime);
}

