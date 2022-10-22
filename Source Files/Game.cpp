#include "Game.h"
#include "Player.h"

void Game::init()
{
	this->window = new RenderWindow(VideoMode(this->window_width, this->window_height), "Pong++");
	this->window->setFramerateLimit(this->max_fps);

	this->Player1 = new Player(40, this->window_height/2 - 100 / 2.0f, this->window_height);
	this->Player2 = new Player(this->window_width-60, this->window_height/2 - 100 / 2.0f, this->window_height);

	this->ball = new Ball(this->window_height / 2, this->window_height / 2, this->window_width, this->window_height);

	this->font.loadFromFile("arial.ttf");

	this->scoretxt_p1.setString("0");
	this->scoretxt_p2.setString("0");

	this->scoretxt_p1.setCharacterSize(32);
	this->scoretxt_p2.setCharacterSize(32);
	this->scoretxt_p1.setFillColor(Color::White);
	this->scoretxt_p2.setFillColor(Color::White);
}


Game::Game()
{
	this->init();
}

Game::~Game()
{
	delete this->window;
}

// funcs
void Game::updateDt()
{
	this->deltatime = this->dtClock.restart().asSeconds();
}

void Game::game_loop()
{
	while (this->window->isOpen()) 
	{
		while (this->window->pollEvent(this->event))
		{
			if (this->event.type == Event::Closed)
			{
				this->window->close();
			}
		}

		// update
		this->update();

		// render
		this->render();
	}

}

void Game::update()
{
	this->playerMove();

	this->ball->bounce(this->Player1, this->Player2);
	this->ball->move();

	this->score();
}

void Game::render()
{
	this->window->clear(Color::Black);

	this->window->draw(this->Player1->sprite);
	this->window->draw(this->Player2->sprite);
	this->window->draw(this->ball->sprite);

	this->window->draw(this->scoretxt_p1);
	this->window->draw(this->scoretxt_p2);

	this->window->display();
}


// functions

void Game::playerMove()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->Player1->move(-1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->Player1->move(1);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->Player2->move(-1);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->Player2->move(1);
	}
}

void Game::score()
{
	if (this->ball->x < 0 )
	{
		this->p2_score++;

		this->scoretxt_p2.setString(std::to_string(p2_score));

		sleep(Time(seconds(2)));
		this->ball->x = this->window_width / 2.f;
		this->ball->y = this->window_height / 2.f;

		if (rand() % 2)
		{
			this->ball->direction[0] = -1;
		}

		this->ball->update();

		this->Player1->x = 40;
		this->Player1->y = this->window_height / 2 - 100 / 2.0f;

		this->Player2->x = this->window_width - 60;
		this->Player2->y = this->window_height / 2 - 100 / 2.0f;

		this->Player1->update();
		this->Player2->update();
	}
	else if (this->ball->x > this->window_width) 
	{
		this->p1_score++;

		this->scoretxt_p1.setString(std::to_string(p1_score));


		sleep(Time(seconds(2)));
		this->ball->x = this->window_width / 2.f;
		this->ball->y = this->window_height / 2.f;

		if (rand() % 2)
		{
			this->ball->direction[0] = -1;
		}

		this->ball->update();

		this->Player1->x = 40;
		this->Player1->y = this->window_height / 2 - 100 / 2.0f;

		this->Player2->x = this->window_width - 60;
		this->Player2->y = this->window_height / 2 - 100 / 2.0f;

		this->Player1->update();
		this->Player2->update();
	}
}
