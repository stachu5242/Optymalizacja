#include "CuckooSearch.h"
//#include <thread>

CuckooSearch::CuckooSearch(std::function<double(double, double)> fun, const glm::vec2 & v1, const glm::vec2 & v2, int N, double pa)
{
	f = fun;
	this->v1 = v1;
	this->v2 = v2;
	this->pa = pa;
	engine = std::default_random_engine(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	vd = TwoDimensionUniformRandom(v1, v2);
	uid = std::uniform_int_distribution<int>(0, N - 1);
	cuckoos.resize(N);
	u.resize(N);
	ran = std::uniform_real_distribution<double>(0.0, 1.0);
	drawingClass.reset(new DrawingClass(f, v1, v2));
}

void CuckooSearch::run(int maxIterations)
{
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
		std::cout << bestCuckoo.position.x << " " << bestCuckoo.position.y << "\n";
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
		if (t < maxIterations)
		{
			evalutaEFunctionsValue();
			for (auto& cuckoo : cuckoos)
			{
				actualizePositionWithLevyFlight(cuckoo);
				actualizeNest(cuckoo);
			}
			Cuckoo temp = getBestCucko();
			if (temp.f < bestCuckoo.f)
				bestCuckoo = temp;
			toDraw();
			++t;
		}
		drawingClass->drawPoinstOnFunction(u);
	}
}

void CuckooSearch::initialize()
{
	for (int i = 0; i < cuckoos.size(); ++i)
	{
		cuckoos[i].position = vd(engine);
		cuckoos[i].f = f(cuckoos[i].position.x, cuckoos[i].position.y);
	}
	bestCuckoo = getBestCucko();
}
