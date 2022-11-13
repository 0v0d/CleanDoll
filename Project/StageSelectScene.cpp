#include "StageSelectScene.h"
#include "SceneManager.h"


BackGround _backGround;

void StageSelectScene::Initialize()
{
    Vector2 _barPos = Vector2(g_pGraphics->GetTargetWidth() / 2, g_pGraphics->GetTargetHeight() / 2);
    _inputInStageSelect.SetBarManager(&_barManager);
    _getDataFromFile.SetBarManager(&_barManager);
    Load();
    _backGround.SetTextureStatus(&_stageBackTexture,REPEATSCREEN);
    _getDataFromFile.LoadStageSelectData();
    _getDataFromFile.Initialize();
    _barManager.Initialize();
}

void StageSelectScene::Load()
{
    _stageBackTexture.Load("menu_back.png");
}

void StageSelectScene::ReLoad()
{
}
void StageSelectScene::Update()
{
    _inputInStageSelect.Update();
    _barManager.Update();
}

void StageSelectScene::Render()
{
    _backGround.Render();
    CGraphicsUtilities::RenderString(30, 30, "StageSelect");
    _barManager.Render();

}

void StageSelectScene::Release()
{
    _stageBackTexture.Release();
    _barManager.Release();
    _getDataFromFile.Release();
    _stageBackTexture.Release();
}