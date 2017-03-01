#include "IntelligentWaterDrops.h"
#include <Windows.h>
//#include <thread>

void IntelligentWaterDrops::run(int maxIteratiins)
{
	end = false;
	int t = 0;

	while (!end)
	{
		if (t < maxIteratiins)
		{
			std::cout << "start nr " << t << "\n";

			initializeDynamicsParametrs();
			while (!allIwdSIsEnd())
			{
				int k = 0;
				for (auto& iwd : IWDs)
				{
					iwd.doCycle = false;
					if (iwd.actualVertex != graph[graphSize - 1].index)
					{
						int i = calculatePropability(iwd);;
						if (i>-1)
							modeDropsandUpdateVelocity(iwd, i);
					}
					//std::cout << "Iwd nr " << k << " " << iwd.actualVertex << "\n";
					//std::cin.get();
					k++;
				}

			}
			for (auto& iwd : IWDs)
			{
				if (iwd.actualVertex != graph[graphSize - 1].index && iwd.path.size()>1 && !iwd.doCycle)
					updateSoils(iwd);
				//updateVistedNodes(iwd);
			}
			findIterationBestPath();
			++t;
			//std::cin.get();
			//std::this_thread::sleep_for(std::chrono::seconds(2));
			Sleep(2000);
		}
		else
			end = true;
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
