#pragma once
#include "../../Frameworks/KeyInterpreter.h"
#include "../../Frameworks/DataArray.h"
#include "../../Core/GameScene.h"
#include "../../Core/GameState.h"
#include "DemoGameObject.h"

//class DemoKeyInterpreter : public KeyInterpreter
//{
//public:
//	DemoKeyInterpreter();
//	~DemoKeyInterpreter();
//
//	void ProcessKeyPresses(std::vector<int> keys, GameState *gameState, GameScene *gameScene) override;
//
//private:
//	//enum KeyConfiguration
//	//{
//	//	CONFIG_TOGGLE_PAUSE = 0x01,  
//	//	CONFIG_PLAYER_FORWARD = 0x02,  
//	//	CONFIG_PLAYER_BACKWARD = 0x03, 
//	//	CONFIG_PLAYER_LEFT = 0x04, 
//	//	CONFIG_PLAYER_RIGHT = 0x05,
//	//};
//
//	enum KeyConfiguration
//	{
//		CONFIG_TOGGLE_PAUSE = KEYBOARD_ESCAPE,
//		CONFIG_PLAYER_FORWARD = KEYBOARD_W,
//		CONFIG_PLAYER_BACKWARD = KEYBOARD_S,
//		CONFIG_PLAYER_LEFT = KEYBOARD_D,
//		CONFIG_PLAYER_RIGHT = KEYBOARD_A,
//		CONFIG_FORCE_END = KEYBOARD_C
//	};
//
//	void Force_End(GameState *gamestate);
//	void Toggle_Pause(GameState *gamestate);
//	void Player_Forward(GameScene *gamescene);
//	void Player_Backward(GameScene *gamescene);
//	void Player_Left(GameScene *gamescene);
//	void Player_Right(GameScene *gamescene);
//
//	vector<DemoGameObject*> controlledEntities;
//};

class DemoKeyInterpreter : public KeyInterpreter
{
public:
	DemoKeyInterpreter();
	~DemoKeyInterpreter();

	void ProcessKeyPresses(std::vector<int> keys, GameState &gameState, GameScene &gameScene) override;
	
private:
	//enum KeyConfiguration
	//{
	//	CONFIG_TOGGLE_PAUSE = 0x01,  
	//	CONFIG_PLAYER_FORWARD = 0x02,  
	//	CONFIG_PLAYER_BACKWARD = 0x03, 
	//	CONFIG_PLAYER_LEFT = 0x04, 
	//	CONFIG_PLAYER_RIGHT = 0x05,
	//};

	enum KeyConfiguration
	{
		CONFIG_TOGGLE_PAUSE = KEYBOARD_ESCAPE,
		CONFIG_PLAYER_FORWARD = KEYBOARD_W,
		CONFIG_PLAYER_BACKWARD = KEYBOARD_S,
		CONFIG_PLAYER_LEFT = KEYBOARD_D,
		CONFIG_PLAYER_RIGHT = KEYBOARD_A,
		CONFIG_FORCE_END = KEYBOARD_C
	};

	void Force_End(GameState &gamestate);
	void Toggle_Pause(GameState &gamestate);
	void Player_Forward(GameScene &gamescene);
	void Player_Backward(GameScene &gamescene);
	void Player_Left(GameScene &gamescene);
	void Player_Right(GameScene &gamescene);

	vector<DemoGameObject*> controlledEntities;
};