#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
    class Circle
    {
        float r;
        float x, y;
        float pr_x;
        sf::Vector2f v;
        sf::CircleShape shape;
        float air_res;
        float e;
        float g;
        int height;
    public:
        Circle();

        Circle(float x, float y, float r, sf::Vector2f v, float air_res, float e, float g, int height);

        void Setup(float x, float y, float r, sf::Vector2f v, float air_res, float e, float g, int height);

        sf::CircleShape Get();

        float Y();

        float R();

        void Update();

        void Move(float dt);
    };
}

