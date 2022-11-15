#include "TitleScene.h"

void TitleScene::Initialize()
{
	_titleBackTexture.Load("titleback.png");
	_backGround.SetTextureStatus(&_titleBackTexture, FULLSCREEN);
	_startTexture.Load("clictostart.png");
	_alpha = 255;
}

void TitleScene::ReLoad()
{
}

void TitleScene::Update()
{
	InputMouseKey();
	//Click to startのアニメーション用
	_time += _increase;
	_alpha = CalcSequence(fmod(_time,1));
}

void TitleScene::InputMouseKey()
{
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void TitleScene::Render()
{
	_backGround.Render();
	_startTexture.Render(g_pGraphics->GetTargetWidth()/2-_startTexture.GetWidth()/2,800, MOF_ARGB(_alpha, 255, 255, 255));
	CGraphicsUtilities::RenderString(30, 30, "TitleScene");
}

void TitleScene::Release()
{
	_titleBackTexture.Release();
	_startTexture.Release();
}

namespace detail
{
	//Easing(表示の仕方)
	float f(float x)
	{
		//式
		return  -pow((4 * x - 1), 2) + 1;
	}
	float g(float x)
	{
		//式
		return  -pow((4 * x - 3), 2) + 1;
	}
}

int TitleScene::CalcSequence(float x)
{
	if(x >=0.5f)
	{
		return detail::g(x) * 255;
	}
	else
	{
		return detail::f(x) * 255;
	}
}