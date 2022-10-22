#ifndef BALL_H
#define BALL_H

#include "Include.h"
#include "Player.h"

class Ball
{
private:
	const float size_radius = 10.0f;

	const float speed = 1.0f;

	int window_w;
	int window_h;

	float width;
	float height;

	void init();

public:
	CircleShape sprite;

	float x;
	float y;

	int direction[2] = { 1, -1 };

	Ball(float x, float y, int window_w, int window_h);	
	~Ball();

	// funcs

	void move();
	void bounce(Player* player1, Player* player2);
	void update();
	void reset();

	int* get_position();
};

#endif

