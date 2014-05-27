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

	status = playerNS::FALLING;
	active = true;
	velocity.x = 0;
	velocity.y = 0;
	mass = playerNS::MASS;
	jumpHeight = playerNS::HEIGHT + playerNS::HEIGHT / 2;

	edge.top = -playerNS::HEIGHT / 2;             // set collision edges
	edge.bottom = playerNS::HEIGHT / 2;
	edge.left = -playerNS::WIDTH / 2;
	edge.right = playerNS::WIDTH / 2;
	collisionType = entityNS::ROTATED_BOX;
	slicing = false;
	direction = playerNS::DIRECTION::RIGHT;
}

//initalize the player
bool Player::initialize(Game *gamePtr, int width, int height, int ncols,
                            TextureManager *textureM)
{
	playerSlice.initialize(gamePtr->getGraphics(),width,height, ncols,textureM);
	playerSlice.setFrames(playerNS::PLAYER_SLICE_START_FRAME, playerNS::PLAYER_SLICE_END_FRAME);
	playerSlice.setCurrentFrame(playerNS::PLAYER_SLICE_START_FRAME);
	playerSlice.setFrameDelay(playerNS::PLAYER_ATTACK_ANIMATION_DELAY);
	playerSlice.setLoop(false);
	
	return (Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//Draw hero
void Player::draw()
{
	if (slicing) {
		playerSlice.draw(spriteData);
		slicing = false;
	}
	else {
		Image::draw();
	}
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

	//the floor is 80px high and we want to appear on the ground which is at 15px
	if (spriteData.y > GAME_HEIGHT - 65 - (playerNS::HEIGHT  * getScale()))
	{
		spriteData.y = GAME_HEIGHT - 65 -(playerNS::HEIGHT  * getScale());	
		status = playerNS::IDLE;
	}

	//if (spriteData.y ) is equal to the height of one jump
	//then we are falling
	if (spriteData.y <  GAME_HEIGHT - 65 - (jumpHeight * getScale())) {
		//gravity is arbitrary at the moment 
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
void Player::setStatus(playerNS::STATUS inStatus) {
	status = inStatus;
}
void Player::slice() {
	slicing = true;
}

void Player::walkInDirection(playerNS::DIRECTION newDirection,float frameTime) {
	
	if (newDirection == playerNS::LEFT) {
		flipHorizontal(true);
		direction = newDirection;
		setX(getX() - frameTime * playerNS::SPEED);
	}
	
	if (newDirection == playerNS::RIGHT) {
		flipHorizontal(false);
		direction = newDirection;
		setX(getX() + frameTime * playerNS::SPEED);
	}

	
}