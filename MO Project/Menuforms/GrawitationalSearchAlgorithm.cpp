#include "GrawitationalSearchAlgorithm.h"
//#include <thread>

void GrawitationalSearchAlgorithm::run(int maxIterations)
{
	hLinearDecreasse = kBestSize / maxIterations;
	initialize();

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
		std::cout << agents[0].position.x << " " << agents[0].position.x << "\n";
		//		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//std::cin.get();
		if (t < maxIterations && kBestSize >= 1)
		{
			positionToOldPOsition();
			double g = evaluateCostant(t, maxIterations);
			evaluateFitness();
			calculateMasses();
			for (int i = 0; i < agents.size(); ++i)
			{
				computeAccelerate(i, g);
				updatePositionAndVelocity(i);
				correctPosition(i);
			}
			linearDecreasseOfKBest();
			++t;

		}
		drawingClass->drawPoinstOnFunction(v);
	}
}
