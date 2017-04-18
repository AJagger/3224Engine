#include "stdafx.h"
#include "GameInitialise.h"
#include "../Frameworks/DataArray.h"
#include "../Frameworks/DataArray.cpp" //Temp fix to Visual Studio linker errors
#include "GameObject.h"

GameInitialise::GameInitialise()
{
}

GameInitialise::~GameInitialise()
{
}

void GameInitialise::StartGame()
{
	//Will be a lot of shit here

	//=====TEST CODE BELOW=====
	auto testImplementation = DataArray<GameObject>();

	GameObject *working = testImplementation.CreateNew();
	working->entityName = "ObjId1";

	GameObject *returned = testImplementation.TryToGet(0);
}
