#ifndef CAUCHY_RANDOM_NUMBERS_H
#define CAUCHY_RANDOM_NUMBERS_H

#include "MyRandom.h"
#include <SDL\SDL.h>
#include <glm\glm.hpp>
#include <chrono>

class CauchyRandomNumbers
{
public:
	CauchyRandomNumbers(const glm::ivec2& windowPos = glm::ivec2(20), const glm::vec2& windowSize = glm::ivec2(300));

	void run();

	~CauchyRandomNumbers()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}
private:
	glm::ivec2 size;
	MyRandom::basic_linear_generator generator;
	MyRandom::cauchy_distribution<float> dist;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif // !CAUCHY_RANDOM_NUMBERS_H
