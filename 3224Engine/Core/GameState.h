#pragma once

//#pragma comment(lib, "nclgl.lib")

#include "../Renderer/nclgl/Window.h"
#include "../Renderer/nclglExpansion/Renderer.h"

class GameState
{
public:
	GameState();
	~GameState();

	//States
	bool paused;
	bool end;

	//Renderer Data
	Window gameWindow = Window("Terrain Generation!", 1600, 1200, false);
	Renderer renderer = Renderer(gameWindow);
};