#include "Ball.h"

void Ball::init()
{
	// sprite 
	this->sprite.setPosition(this->x, this->y);
	this->sprite.setRadius(this->size_radius);
	this->sprite.setFillColor(Color::Black);
	this->sprite.setOutlineColor(Color::Cyan);
	this->sprite.setOutlineThickness(2.0f);

	if (rand() % 2)
	{
		direction[0] = -1;
	}

	this->width = this->sprite.getGlobalBounds().width;
	this->height = this->sprite.getGlobalBounds().height;
}

Ball::Ball(float x, float y, int window_w, int window_h)
{
	this->x = x;
	this->y = y;

	this->window_w = window_w;
	this->window_h = window_h;

	this->init();
}

Ball::~Ball()
{
	delete& this->sprite;
}


// funcs

void Ball::move()
{
	this->x += this->speed * this->direction[0];
	this->y += this->speed * this->direction[1];

	this->update();
}

void Ball::bounce(Player* player1, Player* player2)
{
	Vector2f p1_pos = player1->sprite.getPosition();
	Vector2f p2_pos = player2->sprite.getPosition();

	float* p1_size = player1->get_size();

	float* p2_size = player2->get_size();

	// window border
	if (this->y < 0 || this->y > this->window_h - this->sprite.getGlobalBounds().height)
	{
		this->direction[1] *= -1;
	}

	// player 1

	if (float_range(this->y, p1_pos.y, p1_pos.y + 100.f) &&
		float_range(this->x, p1_pos.x, p1_pos.x + 40.f))
	{
		this->direction[0] *= -1;
		this->x = p1_pos.x + 45.f;
	}

	// player 2

	if (float_range(this->y, p2_pos.y, p2_pos.y + 100.f) &&
		float_range(this->x, p2_pos.x - 40.f, p2_pos.x))
	{
		this->direction[0] *= -1;
		this->x = p2_pos.x - 45.f;
	}

	this->update();
}

void Ball::update()
{
	this->sprite.setPosition(this->x, this->y);
}

int* Ball::get_position()
{
	int position[2] = { this->x, this->y };
	return position;
}

void Ball::reset()
{
	this->x = this->window_w / 2.f;
	this->y = this->window_h / 2.f;

	if (rand() % 2)
	{
		direction[1] = -1;
	}
}