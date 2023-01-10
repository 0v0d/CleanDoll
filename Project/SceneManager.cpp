#include "SceneManager.h"
#include "TitleScene.h"
#include "StageSelectScene.h"
#include "GameScene.h"
#include "GalleryScene.h"
#include "AudioMixer.h"

SceneManager* SceneManager::_instance = nullptr;

TitleScene title;
StageSelectScene stageSelect;
GameScene game;
GalleryScene gallery;

void SceneManager::Initialize()
{
	_effect.Initialize();

	_sceneArray[SCENE_TYPE::TITLE] = &title;
	_sceneArray[SCENE_TYPE::STAGESELECT] = &stageSelect;
	_sceneArray[SCENE_TYPE::GAME] = &game;
	_sceneArray[SCENE_TYPE::GALLERY] = &gallery;

	stageSelect.GetCreateField()->GetSetFieldData()->SetField(game.GetField());

	for (auto iter = _sceneArray.begin(); iter != _sceneArray.end(); iter++) {
		iter->second->Initialize();
	}

	_currentScene = _sceneArray[SCENE_TYPE::TITLE];
	_effect.SetChangeSceneMethod([&]() {StartChangeScene();});
	AudioMixer::Instance().PlayBgm(_currentScene->GetBGM());
}

void SceneManager::Update(){
	
	_effect.Update();
	if (!_effect.CheckChangeScene()) return;
	_currentScene->Update();
}

void SceneManager::SetMousePos(Vector2 mousePos) {
	if (_effect.CheckEndEffect()) _currentScene->SetMousePos(mousePos);
}

void SceneManager::Push() {
	if (_effect.CheckEndEffect()) _currentScene->Push();
}

void SceneManager::Pull() {
	if (_effect.CheckEndEffect()) _currentScene->Pull();
}

void SceneManager::Render()
{
	_currentScene->Render();
}

void SceneManager::RenderEffect() {
	_effect.Render();
}

void SceneManager::Release()
{
	for (auto iter = _sceneArray.begin(); iter != _sceneArray.end(); iter++)
	{
		iter->second->Release();
	}
	_effect.Release();
}

void SceneManager::ChangeScene(SCENE_TYPE nextScene) {
	_effect.StartEffect();
	_nextSceneType = nextScene;
}

void SceneManager::StartChangeScene() {
	_currentScene = _sceneArray[_nextSceneType];
	_currentScene->ReLoad();
	_currentScene->SetMousePos(Vector2(0, 0));
	AudioMixer::Instance().PlayBgm(_currentScene->GetBGM());
}

SCENE_TYPE SceneManager::GetCurrentSceneType() {

	for (auto itr = _sceneArray.begin(); itr != _sceneArray.end(); itr++) {
		if (itr->second == _currentScene) return itr->first;
	}
	return SCENE_TYPE::TITLE;
}