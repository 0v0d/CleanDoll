#include "SceneManager.h"
#include "TitleScene.h"
#include "StageSelectScene.h"
#include "GameScene.h"

SceneManager* SceneManager::_instance = nullptr;

TitleScene title;
StageSelectScene stageSelect;
GameScene game;

void SceneManager::Initialize()
{

	_sceneArray[SCENE_TYPE::TITLE] = &title;
	_sceneArray[SCENE_TYPE::STAGESELECT] = &stageSelect;
	_sceneArray[SCENE_TYPE::GAME] = &game;

	game.SetContactFile(stageSelect.GetGetDataFromFile()->GetContactFile());
	game.SetMenu(&_menu);
	stageSelect.SetMenu(&_menu);

	for (auto iter = _sceneArray.begin(); iter != _sceneArray.end(); iter++) 
	{
		iter->second->Initialize();
	}
	_menu.Initialize();

	_currentScene = _sceneArray[SCENE_TYPE::STAGESELECT];
}

void SceneManager::Update()
{
	_menu.Update();

	if (!_menu.IsOpenMenu())
	{
		_currentScene->Update();
	}
}

void SceneManager::Render()
{
	_currentScene->Render();
	_menu.Render();
}

void SceneManager::Release()
{
	for (auto iter = _sceneArray.begin(); iter != _sceneArray.end(); iter++)
	{
		iter->second->Release();
	}
	_menu.Release();
}

void SceneManager::ChangeScene(SCENE_TYPE nextScene)
{
	_currentScene = _sceneArray[nextScene];
	_currentScene->ReLoad();
}