#include "GlowwormSwarmAlgorith.h"
//#include <thread>

void GlowwarmSwarmAlgorithm::run(int maxIterations)
{
	init();
	SDL_Event e;
	bool quit = false;
	int t = 0;
	bool end;
	while (!quit)
	{
		if (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;
		if (t < maxIterations)
		{
			for (int i = 0; i < glowworms.size(); ++i)
			{
				glowworms[i].N.clear();
				updateLucifein(i);
				glowworms[i].oldPosition = glowworms[i].position;
			}
			for (int i = 0; i < glowworms.size(); ++i)
			{
				for (int j = 0; j < glowworms.size(); ++j)
				{
					addNeighbours(i, j);
				}
				for (int j = 0; j < glowworms[i].N.size(); ++j)
				{
					int k = glowworms[i].N[j];
					double p = calculatePropability(i, k);
					updatePosition(i, k);
				}
				updateDistanceRadius(i);
			}
			++t;
		}
		drawingClass->drawPoinstOnFunction(v);
		//std::cin.get();
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << t << "\n";
	}
}
