#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>

int main()
{
    mt::Game game(1400, 600, "Game");
    game.Setup(3);

    game.LifeCycle();

    return 0;
}