#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>
#include <glm\glm.hpp>
#include <functional>
#include <tuple>

enum Functions
{
	ROSENBROCK,
	RASTIGIN,
	PARABOLOID,
	FOUR_PICK_INVERSE,
	FOUR_PEAKS_INVERSE,
	BAEALE,
	GOLDSTEIN_PRICE,
	BOOTH,
	BUKIN,
	MATYAS,
	ACKLEY,
	LEVI,
	TREE_HUMP_CAMMEL,
	EASOM,
	CROSS_TRAY,
	EGGHOLDER,
	HOLDER_TABLE,
	MC_CORMICK,
	SHAFFER_N2,
	SHAFFER_N4,
	STYBINSKI_TANG
};

double rossenbrock(double x, double y);

double rastigrin(double x, double y);

double paraboloid(double x, double y);

double rossenbrockv(glm::vec2 v);

double rastigrinv(glm::vec2 v);

double parabloloidv(glm::vec2 v);

double fourPicksInverse(double x, double y);

double fourPeaksInverse(double x, double y);

double baele(double x, double y);

double goldstein_price(double x, double y);

double booth(double x, double y);

double bukin(double x, double y);

double matyas(double x, double y);

double ackley(double x, double y);

double levi(double x, double y);

double tree_hump_cammel(double x, double y);

double easom(double x, double y);

double cross_tray(double x, double y);

double eggholder(double x, double y);

double holder_table(double x, double y);

double mcCormick(double x, double y);

double schafferN2(double x, double y);

double schafferN4(double x, double y);

double stybinski_tang(double x, double y);

std::tuple<std::function<double(double, double)>, glm::vec2, glm::vec2> getFunction(Functions function);

#endif // !FUNCTIONS_H
