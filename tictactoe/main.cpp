﻿#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "AcsGameEngine/EventManager.h"
#include "AcsGameEngine/Renderer.h"
#include "AcsGameEngine/Util/ColorList.h"
#include "AcsGameEngine/Window.h"
#include "AcsGameEngine/Texture.h"
#include "Game.h"

int main(int  /*argc*/, char**  /*argv*/) {
	using AcsGameEngine::Util::ColorList;    

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Unable to initialize SDL: " << SDL_GetError() << '\n';
	}

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if ((IMG_Init(imgFlags) & imgFlags) == 0) {
		std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << '\n';
	}

	AcsGameEngine::Window window{ "Tic tac toe" };
	AcsGameEngine::Renderer renderer(window);
	AcsGameEngine::EventManager em;

	bool running{ true };

	em.onQuit([&running](SDL_Event & e) {
		running = false;
	});


	em.onKeyDown([&running](SDL_Event & e) {
		if (e.key.keysym.sym == SDLK_ESCAPE)
			running = false;
	});

	constexpr uint8_t framesPerSecond = 60;
	constexpr std::chrono::milliseconds frameDelay{ 1000 / framesPerSecond };

	std::chrono::system_clock::time_point frameStart;
	std::chrono::system_clock::duration frameTime{};
    
    Game game{ renderer, em };

	while (running) {
		frameStart = std::chrono::system_clock::now();
		em.processEvents();

		renderer.Clear(ColorList::white);

        game.update();
        game.draw();

		renderer.Present();

		frameTime = std::chrono::system_clock::now() - frameStart;

		if (frameDelay > frameTime) {
			std::this_thread::sleep_for(frameDelay - frameTime);
		}
	}

	IMG_Quit();
	SDL_Quit();

	return 0;
}
