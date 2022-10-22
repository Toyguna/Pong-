#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Ball.h"

class Game
{
private:
	const int window_width = 640;
	const int window_height = 640;

	const int max_fps = 144;

	RenderWindow* window;
	Event event;

	Clock dtClock;
	float deltatime;

	Player* Player1;
	Player* Player2;
	Ball* ball;

	Font font;

	Text scoretxt_p1;
	Text scoretxt_p2;

	int p1_score = 0;
	int p2_score = 0;

	void init();

public:
	Game();
	virtual ~Game();

	// funcs
	void updateDt();
	void game_loop();
	void update();
	void render();
	void playerMove();
	void score();
};

#endif

