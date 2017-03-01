#ifndef BAT_ALGORITHM_H
#define BAT_ALGORITHM_H

#include <iostream>
#include <memory>
#include "DrawingClass.h"
#include "functions.h"
#include <functional>
#include "MyRandom.h"
#include <chrono>
#include <random>
#include <valarray>
#include <vector>
#include <algorithm>
#include <numeric>

class BatAlgorithm
{
	struct Bat
	{
		glm::vec2 position, veliocity;
		double f, A, r;
		double fun;
	};
public:
	BatAlgorithm(std::function<double(double, double)> f, const glm::vec2& v1, const glm::vec2 v2, int N = 50, double alpha = 0.9, double gamma = 0.9, double fmin = 0, double fmax = 2);

	void run(int maxIterations = 50);

private:
	void initialize();

	void calculateFunction();

	glm::vec2 sortBatsAndReturnBest();

	void actualizeFrequencyPositionVelocity(int i, const glm::vec2& besPosition);

	void calculateAverangeLaught();

	void bestLocalSolutions(int i, int t);

	void calculateNewRandomSolution(int i, int t, const glm::vec2& best);

	void positionsToDraw();

	void correctPosition(int indx);

private:
	std::valarray<Bat> bats;
	std::valarray<glm::vec2> v;
	glm::vec2 v1, v2,bestSoluion;
	double fbest;
	double alpha, gamma, fmax, fmin;
	std::unique_ptr<DrawingClass> drawingClass;
	TwoDimensionUniformRandom random;
	TwoDimensionUniformRandom random2;
	std::uniform_real_distribution<double> beta,r;
	std::default_random_engine engine;
	std::function<double(double, double)> f;
	int N;
	double averangeLaught;
};
#endif //!BAT_ALGORITHM_H