#include "DifferentialEvolution.h"
//#include <thread>

void DifferentialEvolution::run(int maxIterations)
{
	initializePopulation();
	SDL_Event e;
	bool quit = false;
	int t = 0;
	bool end;
	while (!quit)
	{
		if (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;



		std::cout << t << "\n";
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
		if (t < maxIterations)
		{
			mutation();
			recombination();
			selection();
			++t;
		}
		drawingClass->drawPoinstOnFunction(u);
	}
}
