//#ifndef CHARGED_SYSTEM_SEARCH_H
//#define CHARGED_SYSTEM_SEARCH_H

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

class ChargedSystemSearch
{
	struct ChargedParticle
	{
		glm::vec2 position, oldPosition, veloicity;
		double q,f;
		bool operator<(const ChargedParticle& cp)
		{
			return this->q < cp.q;
		}
	};
public:
	ChargedSystemSearch(std::function<double(double, double)> fun, const glm::vec2& v1, glm::vec2& v2, int N = 20);

	void run(int maxIterations = 50);

private:
	double a,r,epsilon;
	glm::vec2 v1, v2;
	std::function<double(double, double)> f;
	std::valarray<ChargedParticle> chargedParticles;
	std::valarray<ChargedParticle> cm;
	std::valarray<glm::vec2> v;
	std::unique_ptr<DrawingClass> drawingClass;
	TwoDimensionUniformRandom random;
	TwoDimensionUniformRandom random2;
	std::default_random_engine engine;
	double ka, kv;

	void initialize();

	void ranking();

	void createCm();

	glm::vec2 determineTheImpact(int indx);

	void updatePositionAndVeliocity(int indx);

	void correctPosition(int indx);

	void actualizeCm();

};
//#endif // !CHARGED_SYSTEM_SEARCH_H