#include "Game.h"


int main()
{
    Game game;
    
    while (game.running())
    {
        game.updateDeltaTime();
        game.update();
        game.render();
    }

    return 0;
}