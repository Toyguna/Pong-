#include "Game.h"

int main() 
{
	Game game;
	game.game_loop();

	std::cout << std::endl << " > Closing application" << std::endl;
	return 0;
}