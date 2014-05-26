#include "player.h"


Player::Player() : Entity()
{
	spriteData.width = playerNS::WIDTH;
	spriteData.height = playerNS::HEIGHT;
	spriteData.x = playerNS::X;
	spriteData.y = playerNS::Y;
	spriteData.rect.bottom = playerNS::HEIGHT;
	spriteData.rect.right = playerNS::WIDTH;
	startFrame = playerNS::PLAYER_START_FRAME;
	endFrame = playerNS::PLAYER_END_FRAME;

	status = playerNS::IDLE;
	active = true;
	velocity.x = 0;
	velocity.y = 0;
	mass = playerNS::MASS;
	jumpHeight = playerNS::HEIGHT + playerNS::HEIGHT / 2;
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

	spriteData.x += frameTime * velocity.x;
	spriteData.y += frameTime * velocity.y;
	//if we hit the right of the screen
	if (spriteData.x > GAME_WIDTH - playerNS::WIDTH * getScale())
	{
		spriteData.x = GAME_WIDTH - playerNS::WIDTH * getScale();
	}

	if (spriteData.y > GAME_HEIGHT - playerNS::HEIGHT * getScale())
	{
		spriteData.y = GAME_HEIGHT - playerNS::HEIGHT * getScale();	
		status = playerNS::IDLE;
	}

	//if (spriteData.y ) is equal to the height of one jump
	//then we are falling
	if (spriteData.y <  GAME_HEIGHT - (jumpHeight)* getScale()) {
		velocity.y += frameTime * 2000.0f;
		status = playerNS::FALLING;
	}
}

void Player::damage(int Weapon)
{

}

void Player::jump()
{	
		status = playerNS::JUMPING;
		setVelocity(VECTOR2(0, -playerNS::JUMP_SPEED));
}

playerNS::STATUS Player::getStatus() {

	return status;

}