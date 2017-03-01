#include "RiverFormationDynamic.h"
#include <Windows.h>
//#pragma managed(push, off)
//#include <thread>
void RiverFormationDynamic::run()
{
	end = false;
	int t = 0;
	initializeGraph();
	while (!end)
	{
		std::cout << "start nr " << t << "\n";
		++t;
		//std::cin.get();
		//std::this_thread::sleep_for(std::chrono::seconds(2));
		Sleep(2000);
		through();
		drawGraph->draw(bestPath);
	}
	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		if (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;
		drawGraph->draw(bestPath);
	}
}
//#pragma managed(pop)