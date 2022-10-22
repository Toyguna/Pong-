#include "Player.h"

void Player::init()
{
	// sprite
	this->sprite.setPosition(this->x, this->y);
	this->sprite.setSize(Vector2f(this->size_w, this->size_h));
	this->sprite.setFillColor(Color::Black);
	this->sprite.setOutlineColor(Color::White);
	this->sprite.setOutlineThickness(5.0f);
}

Player::Player(int x, float y, int window_h)
{
	this->x = x;
	this->y = y;

	this->window_h = window_h;

	this->init();
}

Player::~Player()
{
	delete &this->sprite;
}

// funcs
void Player::move(int direction)
{
	if (!(this->y < 0))
	{
		this->y += this->speed * direction;
	}
	else 
	{
		this->y = 0;
	}

	if (!(this->y > this->window_h - this->size_h))
	{
		this->y += this->speed * direction;
	}
	else
	{
		this->y = this->window_h - this->size_h;
	}

	this->update();
}

void Player::update()
{
	this->sprite.setPosition(this->x, this->y);
}

float* Player::get_size()
{
	float size[2] = { this->size_w, this->size_h };
	return size;
}