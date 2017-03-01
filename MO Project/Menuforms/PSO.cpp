#include "PSO.h"
//#include <thread>

void Pso::run(int maxIterations)
{
	std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
	TwoDimensionUniformRandom dist1(v1, v2);
	TwoDimensionUniformRandom dist2(glm::vec2(0.0), glm::vec2(1.0));
	g = dist1(engine);
	double fxy = 0;
	for (int i = 0; i < N; ++i)
	{
		p[i] = v[i].pos = dist1(engine);
		v[i].vel = glm::vec2(0.0);
		if (f(p[i].x, p[i].y) < f(g.x, g.y))
			g = p[i];
	}
	fxy = f(g.x, g.y);
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
			for (int i = 0; i < N; ++i)
			{
				glm::vec2 rp = dist2(engine);
				glm::vec2 rg = dist2(engine);
				v[i].vel = (v[i].vel*glm::vec2(w) + rp*(p[i] - v[i].pos)*glm::vec2(alpha) + rg*(g - v[i].pos)*glm::vec2(beta));
				v[i].pos += v[i].vel;

				glm::vec2 temp = dist1(engine);
				if (v[i].pos.x<v1.x || v[i].pos.x>v2.x)
					v[i].pos.x = temp.x;
				if (v[i].pos.y<v1.y || v[i].pos.y>v2.y)
					v[i].pos.y = temp.y;

				if (f(v[i].pos.x, v[i].pos.y) < f(p[i].x, p[i].y))
				{
					p[i] = v[i].pos;
					if (f(p[i].x, p[i].y) < f(g.x, g.y))
					{
						g = p[i];
						fxy = f(g.x, g.y);
					}
				}
			}
			t++;
		}
		drawingClass->drawPoinstOnFunction(p);
		std::cout << t << "\n";
		std::cout << g.x << " " << g.y << "\n";
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
