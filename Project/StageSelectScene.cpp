#include "StageSelectScene.h"
#include	"SceneManager.h"

void StageSelectScene::Initialize()
{
	Vector2 _barSize2 = Vector2(30, 680);
	Vector2 _buttonSize2 = Vector2(35, 35);
	Vector2 _barPos2 = Vector2(g_pGraphics->GetTargetWidth() * 0.5 - 100, g_pGraphics->GetTargetHeight() /4);
	_inputInStageSelect.SetBarManager(&_barManager);
	_inputInStageSelect.SetSlider(&_slider);
	_getDataFromFile.SetBarManager(&_barManager);
	_barTexture.Load("���ʃo�[.png");
	_buttonTexture.Load("s (3).png");
	_slider.SetStatu(_barPos2, &_barTexture, &_buttonTexture, 0,VERTICAL);
	_getDataFromFile.LoadStageSelectData();
	_getDataFromFile.Initialize();
	_barManager.Initialize();
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
}