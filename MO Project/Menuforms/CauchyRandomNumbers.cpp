#include "CauchyRandomNumbers.h"

CauchyRandomNumbers::CauchyRandomNumbers(const glm::ivec2 & windowPos, const glm::vec2 & windowSize)
{
	size = windowSize;
	generator = MyRandom::basic_linear_generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	window = SDL_CreateWindow("cauchy generator", windowPos.x, windowPos.y, size.x, size.y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void CauchyRandomNumbers::run()
{
	int timerFps;
	SDL_Event e;
	bool quit = false;
	int t = 0;
	bool end;
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);
	while (!quit)
	{
		timerFps = SDL_GetTicks();
		if (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;

		glm::ivec2 pos;
		while ((pos.x = size.x*(dist(generator) / 10 + 0.5)) > size.x || (pos.x = size.x*(dist(generator) / 10 + 0.5)) < 0);
		while ((pos.y = size.y*(dist(generator) / 10 + 0.5))> size.y || (pos.y = size.y*(dist(generator) / 10 + 0.5)) < 0);

		SDL_RenderDrawPoint(renderer, pos.x, pos.y);
		SDL_RenderPresent(renderer);
		timerFps = SDL_GetTicks() - timerFps;
		if (timerFps < 1000 / 30)
		{
			SDL_Delay((1000 / 30) - timerFps);
		}
	}
}
