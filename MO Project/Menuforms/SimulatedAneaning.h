#ifndef SIMULATED_ANEANING_H
#define SIMULATED_ANEANING_H

#include <memory>
#include "DrawingClass.h"
#include "functions.h"
#include <functional>
#include "MyRandom.h"


class SilumatedAneaning
{
public:
	
	SilumatedAneaning(std::function<double(double, double)> f, const glm::vec2& v1, const glm::vec2& v2, double T0 = 800.0, double Tf = 10e-6, double alpha = 0.999);



	void run();
private:

private:
	std::unique_ptr<DrawingClass> drawingClass;
	double T0, Tf, alpha;
	std::function<double(double,double)> fun;
	glm::vec2 v,v1,v2;
	bool quit;
};

#endif // !SIMULATED_ANEANING_H
