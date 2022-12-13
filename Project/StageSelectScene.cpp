#include "StageSelectScene.h"
#include "SceneManager.h"

void StageSelectScene::Initialize()
{
    _createField.SetBarManager(&_barManager);
    _createField.Initialize();
    
    LoadTexture();

    _barManager.Initialize();
    _stageSelectDialog.Initialize();
    _preview.Initialize();
    _backGround.SetTextureStatus(&_backGroundTexture,SCREEN_TYPE::FULLSCREEN);

    _preview.CalcuBaseScale(_barManager.GetBaseSizeY());
    _preview.CalcuBasePos();
    _preview.SetPreviewTexture(_barManager.GetBar(0)->GetPreviewTexture());
    _music.Load("BGM.mp3");
    _bgm.SetBGM(&_music, true);
    _stageSelectDialog.SetLoadStageMethod([&](int stageNumber) {return LoadStage(stageNumber);});
}

void StageSelectScene::LoadTexture()
{
    _backGroundTexture.Load("menu_back.png");
}

void StageSelectScene::ReLoad()
{
    _barManager.ReLoad();
    _stageSelectDialog.ReLoad();
    _bgm.Play();
}

void StageSelectScene::Update()
{
    _barManager.Update();
}

void StageSelectScene::SetMousePos(Vector2 mousePos) {
    _mousePos = mousePos;

    if (!_stageSelectDialog.IsOpenDialog()) {
        _barManager.SetMousePos(mousePos);
    }

    _stageSelectDialog.SetMousePos(mousePos);
}

void StageSelectScene::Push() {

    if (!_stageSelectDialog.IsOpenDialog()) {
        _barManager.Push();

        Bar* mouseOnBar = _barManager.GetBar(_barManager.GetBarNumber(_mousePos));
        if (mouseOnBar != nullptr) {
            _preview.SetPreviewTexture(mouseOnBar->GetPreviewTexture());
            _stageSelectDialog.SetStageNumber(_barManager.GetBarNumber(_mousePos));
        }
    }

    _stageSelectDialog.Push();
}

void StageSelectScene::Pull() {
    if (!_stageSelectDialog.IsOpenDialog()) {
        _barManager.Pull();
    }
    _stageSelectDialog.Pull();
}

void StageSelectScene::StartNextStage() {
    _barManager.StartNextStage();
    _createField.LoadStage(_barManager.GetBar(_barManager.GetCurrentStageNumber())->GetStageDataTextName());
}

void StageSelectScene::CreateTutorialField()
{
    _createField.LoadStage("tutorial.txt");
}

void StageSelectScene::StageClear() {
    _barManager.StageClear(); 
}

void StageSelectScene::LoadStage(int stageNumber) {
    _createField.LoadStage(_barManager.GetBar(stageNumber)->GetStageDataTextName());
    SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
}


void StageSelectScene::Render()
{
    _backGround.Render();
    _barManager.Render();
    _preview.Render();

    _stageSelectDialog.Render();
}

void StageSelectScene::Release()
{
    _backGroundTexture.Release();

    _barManager.Release();
    _stageSelectDialog.Release();
    _preview.Release();

    _createField.Release();
    _music.Release();
}

void StageSelectScene::StopBGM()
{
    _bgm.Stop();
}
