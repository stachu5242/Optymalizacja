#include "BatAlgorithm.h"
//#include <thread>

BatAlgorithm::BatAlgorithm(std::function<double(double, double)> f, const glm::vec2 & v1, const glm::vec2 v2, int N, double alpha, double gamma, double fmin, double fmax)
{
	this->f = f;
	this->v1 = v1;
	this->v2 = v2;
	this->alpha = alpha;
	this->gamma = gamma;
	this->N = N;
	this->fmin = fmin;
	this->fmax = fmax;
	glm::vec2 temp = (v2 - v1)*glm::vec2(0.1);
	this->fmax = temp.x;
	this->random = TwoDimensionUniformRandom(v1, v2);
	this->random2 = TwoDimensionUniformRandom(glm::vec2(-1), glm::vec2(1));
	this->beta = std::uniform_real_distribution<double>(0.0, 1.0);
	this->r = std::uniform_real_distribution<double>(0.0, 1);
	this->drawingClass.reset(new DrawingClass(f, v1, v2));
	this->bats.resize(N);
	this->v.resize(N);
	engine = std::default_random_engine(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}

void BatAlgorithm::run(int maxIterations)
{
	initialize();
	SDL_Event e;
	bool quit = false;
	int t = 0;
	bool end;
	calculateFunction();
	bestSoluion = sortBatsAndReturnBest();
	while (!quit)
	{
		if (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;



		std::cout << t << "\n";
		std::cout << bestSoluion.x << " " << bestSoluion.y << "\n";
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//std::cin.get();
		if (t < maxIterations)
		{
			calculateAverangeLaught();
			for (int i = 0; i < N; ++i)
			{
				actualizeFrequencyPositionVelocity(i, bestSoluion);
				bestLocalSolutions(i, t);
				calculateNewRandomSolution(i, t, bestSoluion);
				correctPosition(i);
			}
			calculateFunction();
			glm::vec2 temp = sortBatsAndReturnBest();
			//if (f(temp.x, temp.y) < f(bestSoluion.x, bestSoluion.y))
			//bestSoluion = temp;
			positionsToDraw();
			++t;
		}
		drawingClass->drawPoinstOnFunction(v);
		//std::cin.get();
	}
}

void BatAlgorithm::initialize()
{
	for (int i = 0; i < bats.size(); ++i)
	{
		v[i] = bats[i].position = random(engine);
		bats[i].f = fmin + (fmax - fmin)*beta(engine);
		bats[i].A = 1;
		bats[i].r = 1;
		bats[i].veliocity = glm::vec2(0.0);
	}
}

void BatAlgorithm::calculateFunction()
{
	for (size_t i = 0; i < bats.size(); i++)
	{
		bats[i].fun = f(bats[i].position.x, bats[i].position.y);
	}
}

glm::vec2 BatAlgorithm::sortBatsAndReturnBest()
{
	std::sort(std::begin(bats), std::end(bats), [](Bat a, Bat b) { return (a.fun < b.fun); });
	return bats[0].position;
}

void BatAlgorithm::actualizeFrequencyPositionVelocity(int i, const glm::vec2 & besPosition)
{
	bats[i].f = fmin + (fmax - fmin)*beta(engine);
	bats[i].veliocity = ((bestSoluion - bats[i].position)*glm::vec2(bats[i].f));
	//if (i == 0)
	//std::cout << "v " << bats[i].veliocity.x << " " << bats[i].veliocity.y << "\n";
	bats[i].position += bats[i].veliocity;
	correctPosition(i);
}

void BatAlgorithm::calculateAverangeLaught()
{
	averangeLaught = std::accumulate(std::begin(bats), std::end(bats), 0.0, [](double val, const Bat& b2) { return val + b2.A; }) / N;
}

void BatAlgorithm::bestLocalSolutions(int i, int t)
{
	int localN = N / 4;
	if (r(engine) > bats[i].r)
	{
		bats[i%localN].position += random2(engine)*glm::vec2(averangeLaught);
		correctPosition(i%localN);
	}
}

void BatAlgorithm::calculateNewRandomSolution(int i, int t, const glm::vec2 & best)
{
	//glm::vec2 newSolution = random(engine);
	if (r(engine) < bats[i].A && bats[i].fun < f(best.x, best.y))
	{
		bestSoluion = bats[i].position;
		bats[i].A *= alpha;
		bats[i].r = (1 - std::exp(-gamma*t));
	}
}

void BatAlgorithm::positionsToDraw()
{
	for (int i = 0; i < bats.size(); ++i)
		v[i] = bats[i].position;
}

void BatAlgorithm::correctPosition(int indx)
{
	glm::vec2 newPos = random(engine);
	if (bats[indx].position.x<v1.x || bats[indx].position.x>v2.x)
		bats[indx].position.x = newPos.x;
	if (bats[indx].position.y<v1.y || bats[indx].position.y>v2.y)
		bats[indx].position.y = newPos.y;
}
