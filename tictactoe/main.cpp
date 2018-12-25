#include "AcsGE/Game.h"
#include "AcsGE/GameStateManager.h"
#include <iostream>
#include <utility> //std::pair

#include "MainState.h"
#include "StartMenuState.h"

int main(int argc, char *argv[])
{
    AcsGameEngine::Game game{ "Test", {-1, -1}, {800, 600} };

    try {
        game.Init();

        game
            .getGSM()
            ->addState<MainState>("FirstState")
            ->addState<StartMenuState>("StartMenu")
            ->init()
        ;

        //Call init on the GameStates....


        game.Run();
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << '\n';
    }

    game.Cleanup();

    return 0;
}