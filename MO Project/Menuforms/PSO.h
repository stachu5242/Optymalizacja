#ifndef PSO_H
#define PSO_H

#include <iostream>
#include <memory>
#include "DrawingClass.h"
#include "functions.h"
#include <functional>
#include "MyRandom.h"
#include <chrono>
#include <random>
#include <valarray>

class Pso
{
	struct Particle
	{
		glm::vec2 pos;
		glm::vec2 vel;
		double f;
	};
public:
	Pso(std::function<double(double, double)> fun, const glm::vec2& v1, const glm::vec2& v2, std::size_t N = 100, double w = 0.7, double alpha = 2.0, double beta = 2.0)
	{
		this->f = fun;
		this->v1 = v1;
		this->v2 = v2;
		this->N = N;
		this->alpha = alpha;
		this->beta = beta;
		this->w = w;
		drawingClass.reset(new DrawingClass(fun, v1, v2));
		v.resize(N);
		p.resize(N);
	}


public:
	void run(int maxIterations = 25);

private:
	std::unique_ptr<DrawingClass> drawingClass;
	glm::vec2 v1, v2;
	std::valarray<Particle> v;
	std::valarray<glm::vec2> p;
	glm::vec2 g;
	std::function<double(double, double)> f;
	std::size_t N;
	double w, alpha, beta;
};
#endif // !PSO_H
