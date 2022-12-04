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

	stageSelect.GetCreateField()->SetField(game.GetField());

	for (auto iter = _sceneArray.begin(); iter != _sceneArray.end(); iter++) 
	{
		iter->second->Initialize();
	}

	_currentScene = _sceneArray[SCENE_TYPE::TITLE];
}

void SceneManager::Update()
{
	_currentScene->Update();
}

void SceneManager::SetMousePos(Vector2 mousePos) {
	_currentScene->SetMousePos(mousePos);
}

void SceneManager::Push() {
	_currentScene->Push();
}

void SceneManager::Pull() {
	_currentScene->Pull();
}

void SceneManager::Render()
{
	_currentScene->Render();
}

void SceneManager::Release()
{
	for (auto iter = _sceneArray.begin(); iter != _sceneArray.end(); iter++)
	{
		iter->second->Release();
	}
}

void SceneManager::ChangeScene(SCENE_TYPE nextScene)
{
	_currentScene->StopBGM();
	_currentScene = _sceneArray[nextScene];
	_currentScene->ReLoad();
}

SCENE_TYPE SceneManager::GetCurrentSceneType() {

	for (auto itr = _sceneArray.begin(); itr != _sceneArray.end(); itr++) {
		if (itr->second == _currentScene) return itr->first;
	}
	return SCENE_TYPE::TITLE;
}