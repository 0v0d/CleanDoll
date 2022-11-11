#include "StageSelectScene.h"
#include    "SceneManager.h"

void StageSelectScene::Initialize()
{
    Vector2 _barSize2 = Vector2(30, 680);
    Vector2 _buttonSize2 = Vector2(35, 35);
    Vector2 _barPos2 = Vector2(g_pGraphics->GetTargetWidth() * 0.5 - 100, g_pGraphics->GetTargetHeight() / 4);
    _inputInStageSelect.SetBarManager(&_barManager);
    _inputInStageSelect.SetSlider(&_slider);
    _getDataFromFile.SetBarManager(&_barManager);
    Load();
    _stageBackRect = CRectangle(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
    _slider.SetStatu(_barPos2, &_barTexture, &_buttonTexture, 0, VERTICAL);
    _getDataFromFile.LoadStageSelectData();
    _getDataFromFile.Initialize();
    _barManager.Initialize();
    _StDiaLog.Initialize();

}

void StageSelectScene::Load()
{
    _barTexture.Load("âπó ÉoÅ[.png");
    _buttonTexture.Load("s (3).png");
    _stageBackTexture.Load("menu_back.png");
}

void StageSelectScene::ReLoad()
{

}

void StageSelectScene::Update()
{
    _inputInStageSelect.Update();
    _barManager.Update();
    _slider.Update();
    _barManager.MoveBar(_slider.GetValue());
}

void StageSelectScene::Render()
{
    _stageBackTexture.Render(0, 0, _stageBackRect);
    CGraphicsUtilities::RenderString(30, 30, "StageSelect");
    _barManager.Render();
    _slider.Render();

}

void StageSelectScene::Release()
{
    _barTexture.Release();
    _buttonTexture.Release();
    _barManager.Release();
    _getDataFromFile.Release();
    _stageBackTexture.Release();
    _StDiaLog.Release();
}