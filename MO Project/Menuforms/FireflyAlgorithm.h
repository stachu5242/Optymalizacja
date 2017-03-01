#ifndef FIREFLY_ALGORITHM_H
#define FIREFLY_ALGORITHM_H

#include <iostream>
#include <memory>
#include "DrawingClass.h"
#include "functions.h"
#include <functional>
#include "MyRandom.h"
#include <chrono>
#include <random>
#include <valarray>

class FireflyAlgorithm
{
	struct FireFly
	{
		glm::vec2 position;
		glm::vec2 oldPosition;
		double I;
	};
public:
	FireflyAlgorithm(std::function<double(double, double)> fun, glm::vec2& v1, glm::vec2& v2, std::size_t N = 20, double beta = 1.0, double alpha = 1.0, double delta = 0.97)
	{
		this->f = fun;
		this->v1 = v1;
		this->v2 = v2;
		this->beta = beta;
		this->alpha = alpha;
		this->delta = delta;
		this->gamma = glm::vec2(1.0) / glm::sqrt(glm::vec2(v2 - v1));
		drawingClass.reset(new DrawingClass(fun, v1, v2));
		fireFlyes.resize(N);
	}
	void run(int maxIterations = 50);

private:
	std::valarray<FireFly> fireFlyes;
	double beta,delta,alpha;
	std::unique_ptr<DrawingClass> drawingClass;
	std::function<double(double, double)> f;
	glm::vec2 v1, v2, gamma;
};
#endif // !FIREFLY_ALGORITHM_H
