#include "player.h"


Player::Player() : Entity()
{
	spriteData.width = playerNS::WIDTH;
	spriteData.height = playerNS::HEIGHT;
	spriteData.x = playerNS::X;
	spriteData.y = playerNS::Y;
	spriteData.rect.bottom = playerNS::HEIGHT;
	spriteData.rect.bottom = playerNS::WIDTH;
	startFrame = playerNS::PLAYER_START_FRAME;
	endFrame = playerNS::PLAYER_END_FRAME;

	status = playerNS::IDLE;

}

//initalize the player
bool Player::initialize(Game *gamePtr, int width, int height, int ncols,
                            TextureManager *textureM)
{
	return (Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//Draw hero
void Player::draw()
{
	Image::draw();
}

// called once per frame
// frameTime is used to regulate he speed of movement and animation
void Player::update(float frameTime)
{
	Entity::update(frameTime);
}

void Player::damage(int Weapon)
{

}