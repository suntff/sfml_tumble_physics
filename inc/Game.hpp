#pragma once
#include <string>
#include <thread>
#include <Circle.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

namespace mt
{
	const float pi = acos(-1);

	class Game
	{
		int width;
		int height;
		std::string capture;
		mt::Circle* m_c;
		int m_n;
		int r;
		int x;
		int y;
		sf::RenderWindow m_window;
		sf::Vector2f v;
		bool und_border = false;
	public:
		Game(int width, int height, const std::string& capture);

		void Setup(int n);

		bool TouchBorder(Circle& obj);

		float random(float min, float max);

		void LifeCycle();
	};
}
