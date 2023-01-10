#pragma once
#include	"map"
#include	"IBaseScene.h"
#include	"ChangeSceneEffect.h"

enum class SCENE_TYPE
{
	TITLE,
	STAGESELECT,
	GAME,
	GALLERY
};

class SceneManager
{
	static SceneManager* _instance;
	IBaseScene* _currentScene;
	std::map<SCENE_TYPE, IBaseScene*> _sceneArray;
	SCENE_TYPE _nextSceneType;
	ChangeSceneEffect _effect;

public:
	void Initialize();

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();

	void Render();
	void RenderEffect();
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
	IBaseScene* GetScene(SCENE_TYPE scene) { return _sceneArray[scene]; }
	SCENE_TYPE GetCurrentSceneType();
	bool CheckEndEffect() { return _effect.CheckEndEffect(); }

private:
	void StartChangeScene();
};