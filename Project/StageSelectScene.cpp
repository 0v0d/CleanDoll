#include "StageSelectScene.h"
#include "SceneManager.h"

void StageSelectScene::Initialize()
{
    _contactFile.SetCreateField(&_createField);
    _contactFile.SetBarManager(&_barManager);
    _contactFile.Initialize();
    
    LoadTexture();
    _StSelectbackGround.Initialize();
    _StSelectbackGround.SetTextureStatus(&_stageBackTexture);

    _barManager.Initialize();
    _stageSelectDialog.Initialize();
    _preview.Initialize();

    _preview.SetPreviewTexture(_barManager.GetBar(0)->GetPreviewTexture());
    _preview.CalcuBaseScale(_barManager.GetBaseSizeY());
    _preview.CalcuBasePos();
}

void StageSelectScene::LoadTexture()
{
    _stageBackTexture.Load("menu_back.png");
}

void StageSelectScene::ReLoad()
{
    _barManager.ReLoad();
    _stageSelectDialog.ReLoad();
}

void StageSelectScene::Update()
{
    _barManager.Update();
    _StSelectbackGround.Update();
}

void StageSelectScene::SetMousePos(Vector2 mousePos) {
    _mousePos = mousePos;
    _barManager.SetMousePos(mousePos);
}

void StageSelectScene::Push() {
    _barManager.Push();

    Bar* mouseOnBar = _barManager.GetBar(_barManager.GetBarNumber(_mousePos));
    if (mouseOnBar != nullptr) {
        _preview.SetPreviewTexture(mouseOnBar->GetPreviewTexture());
    }

    if (mouseOnBar != nullptr) {
        _contactFile.LoadStage(_barManager.GetBar(_barManager.GetBarNumber(_mousePos))->GetStageDataTextName());
        SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
    }
}

void StageSelectScene::Pull() {
    _barManager.Pull();
}

void StageSelectScene::StartNextStage() {
    _barManager.StartNextStage();
    _contactFile.LoadStage(_barManager.GetBar(_barManager.GetCurrentStageNumber())->GetStageDataTextName());
}

void StageSelectScene::StageClear() {
    _barManager.StageClear(); 
}


void StageSelectScene::Render()
{
    _StSelectbackGround.Render();
    //CGraphicsUtilities::RenderString(30, 30, "StageSelect");
    _barManager.Render();
    _stageSelectDialog.Render();

    _preview.Render();
}

void StageSelectScene::Release()
{
    _stageBackTexture.Release();
    _stageBackTexture.Release();

    _barManager.Release();
    _stageSelectDialog.Release();
    _preview.Release();

    _contactFile.Release();
}