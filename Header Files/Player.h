#ifndef PLAYER_H
#define PLAYER_H

#include "Include.h"

class Player
{
private:

	int window_h;

	const float size_w = 20.0f;
	const float size_h = 100.0f;
	const float speed = 2.5f;

	void init();

public:
	RectangleShape sprite;

	int x;
	float y;

	Player(int x, float y, int window_h);
	~Player();

	// funcs
	void move(int direction);
	void update();
	float* get_size();
};

#endif
