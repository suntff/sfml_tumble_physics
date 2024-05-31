#include "circle.hpp"
#include <cmath>
#include <cstdlib>

namespace mt
{
    Circle::Circle() {}

    Circle::Circle(float x, float y, float r, sf::Vector2f v, float air_res, float e, float g, int height)
    {
        Setup(x, y, r, v, air_res, e, g, height);
    }

    void Circle::Setup(float x, float y, float r, sf::Vector2f v, float air_res, float e, float g, int height)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->v = v;
        this->air_res = air_res;
        this->e = e;
        this->g = g;
        this->height = height;
        pr_x = x - 5;
        shape.setOrigin(r, r);
        shape.setRadius(r);
        shape.setPosition(x, y);
        int color_r = rand() % 226 + 30;
        int color_g = rand() % 226 + 30;
        int color_b = rand() % 226 + 30;
        shape.setFillColor(sf::Color(color_r, color_b, color_g, 255));
    }

    sf::CircleShape Circle::Get()
    {
        return shape;
    }

    float Circle::Y() { return y; }

    float Circle::R() { return r; }

    void Circle::Update()
    {
        if (x - pr_x < 5)
        {
            v.x = 0;
            v.y = 0;
        }
        v.y *= -e;
        y = height - r - 0.1;
        shape.setPosition(x, y);
        v.x = -0.1 * v.y;
        pr_x = x;
    }

    void Circle::Move(float dt)
    {
        v.y += g * dt;
        y += v.y * dt;
        x += v.x * dt;
        shape.setPosition(x, y);
        v.y *= std::pow(air_res, dt);
    }
}
