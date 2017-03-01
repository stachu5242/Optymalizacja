#ifndef BLACK_HOLES_ALGORITHM_H
#define BLACK_HOLES_ALGORITHM_H

#include <glm\glm.hpp>
#include <functional>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>
#include <memory>
#include <iostream>
#include "MyRandom.h"
#include "DrawingClass.h"

class BlackHolesAlgorithm
{
	struct BlackHole
	{
		glm::vec2 position;
		double f;
	};
public:
	BlackHolesAlgorithm(std::function<double(double, double)> fun, const glm::vec2& v1, const glm::vec2& v2, int N = 20, double F = 0.3);

	void run(int maxIterations = 50);

private:
	void initialize();

	void moveToNextPosition();

	void fuzzyRadiation();
	
	void boundsLimit(BlackHole& bh);

	void evaluateFunction();

	void checkBest();

	BlackHole getBest()
	{
		return *std::min_element(std::begin(blackHoles), std::end(blackHoles), [](BlackHole& bh1, BlackHole& bh2) { return bh1.f < bh2.f; });
	}

private:
	std::valarray<BlackHole> blackHoles;
	BlackHole bestGlobal, bestLocal;
	std::valarray<glm::vec2> u;
	glm::vec2 v1, v2;
	std::function<double(double, double)> f;
	std::unique_ptr<DrawingClass> drawingClass;
	TwoDimensionUniformRandom rv;
	std::uniform_real_distribution<double> rnd;
	std::default_random_engine engine;
	std::uniform_int_distribution<int> rnd2;
	double F;
};


#endif // !BLACK_HOLES_ALGORITHM_H
