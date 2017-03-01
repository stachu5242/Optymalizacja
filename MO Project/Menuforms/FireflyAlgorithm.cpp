#include "FireflyAlgorithm.h"
//#include <thread>

void FireflyAlgorithm::run(int maxIterations)
{
	std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
	TwoDimensionUniformRandom dist1(v1, v2);
	TwoDimensionUniformRandom dist2(glm::vec2(-.5), glm::vec2(.5));
	glm::vec2 g = dist1(engine);
	double fxy = f(g.x, g.y);
	std::valarray<glm::vec2> v(fireFlyes.size());
	for (int i = 0; i < fireFlyes.size(); ++i)
	{
		v[i] = fireFlyes[i].position = dist1(engine);
		fireFlyes[i].I = f(fireFlyes[i].position.x, fireFlyes[i].position.y);
		if (fireFlyes[i].I < fxy)
		{
			fxy = fireFlyes[i].I;
			g = fireFlyes[i].position;
		}
	}

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
			for (int i = 0; i < fireFlyes.size(); ++i)
			{
				fireFlyes[i].oldPosition = fireFlyes[i].position;
			}
			for (int i = 0; i < fireFlyes.size(); ++i)
			{
				for (int j = 0; j < fireFlyes.size(); ++j)
				{
					if (i != j)
					{
						if (fireFlyes[i].I > fireFlyes[j].I)
						{
							double distance = glm::distance(fireFlyes[i].oldPosition, fireFlyes[j].oldPosition);
							glm::vec2 atractivnes = glm::exp(-gamma*glm::vec2(distance*distance));
							v[i] = fireFlyes[i].position = fireFlyes[i].oldPosition + atractivnes*(fireFlyes[j].oldPosition - fireFlyes[i].oldPosition) + glm::vec2(alpha)*dist2(engine);
							glm::vec2 temp = dist1(engine);
							if (v[i].x<v1.x || v[i].x>v2.x)
								v[i].x = fireFlyes[i].position.x = temp.x;
							if (v[i].y<v1.y || v[i].y>v2.y)
								v[i].y = fireFlyes[i].position.y = temp.y;
							fireFlyes[i].I = f(fireFlyes[i].position.x, fireFlyes[i].position.y);
							if (fireFlyes[i].I < fxy)
							{
								fxy = fireFlyes[i].I;
								g = fireFlyes[i].position;
							}
						}
					}
				}
			}
			alpha *= delta;
			++t;
		}
		drawingClass->drawPoinstOnFunction(v);
		std::cout << t << "\n";
		std::cout << g.x << " " << g.y << "\n";
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));

	}
}
