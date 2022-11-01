#pragma once
#include	"map"
#include	"Menu.h"
#include	"IBaseScene.h"

enum class SCENE_TYPE
{
	TITLE,
	STAGESELECT,
	GAME
};

class SceneManager
{
	static SceneManager* _instance;
	IBaseScene* _currentScene;
	std::map<SCENE_TYPE, IBaseScene*> _sceneArray;
	Menu _menu;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	
	static SceneManager& Instance()
	{
		if (_instance == nullptr)
		{
			_instance = new SceneManager();
		}
		return *_instance;

	}

	void ChangeScene(SCENE_TYPE nextScene);
};