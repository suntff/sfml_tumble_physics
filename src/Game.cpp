#include "game.hpp"
#include <cstdlib>
#include <ctime>

namespace mt
{
	Game::Game(int width, int height, const std::string& capture)
	{
		this->width = width;
		this->height = height;
		this->capture = capture;
	}

	void Game::Setup(int n)
	{
		m_n = n;

		m_window.create(sf::VideoMode(width, height), capture);

		srand(time(0));
		r = 25;
		x = 100;
		y = 100;
		m_c = new mt::Circle[m_n];
		for (int i = 0; i < m_n; i++)
		{
			float air_res = random(0.9, 0.99);
			float e = random(0.7, 0.95);
			float g = random(3000, 10000);
			m_c[i].Setup(x, y, r, v, air_res, e, g, height);
		}
	}

	bool Game::TouchBorder(Circle& obj)
	{
		float y = obj.Y();
		float r = obj.R();
		if (y + r >= height)
		{
			return 1;
		}
		return 0;
	}

	float Game::random(float min, float max) {
		return (double)(rand()) / RAND_MAX * (max - min) + min;
	}

	void Game::LifeCycle()
	{
		sf::Clock clock;
		m_window.setVerticalSyncEnabled(true);
		while (m_window.isOpen())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();
			}
			float dt = clock.getElapsedTime().asSeconds();
			clock.restart();
			for (int i = 0; i < m_n; i++)
				m_c[i].Move(dt);

			for (int i = 0; i < m_n; i++) {
				if (TouchBorder(m_c[i])) {
					m_c[i].Update();
				}
			}
			m_window.clear();
			for (int i = 0; i < m_n; i++) {
				m_window.draw(m_c[i].Get());
				//std::cout << m_c[i].Vy() << std::endl;
			}

			m_window.display();
		}
	}
}
