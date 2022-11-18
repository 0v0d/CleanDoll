#include "TitleScene.h"
void TitleScene::Initialize()
{
	_titleBackTexture.Load("titleback.png");
	_backGround.SetTextureStatus(&_titleBackTexture, FULLSCREEN);
	_startTexture.Load("clictostart.png");
	_titleLogoTexture.Load("タイトルロゴ.png");
	SetTitleLogoAnimationStatus();
	_alpha = 255;
}
void TitleScene::SetTitleLogoAnimationStatus()
{
	SpriteAnimationCreate anim[] = {
	{
		"No1",
		0,0,
		750,625,
		FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No2",
		0,1250,
		750,625,
		FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No3",
		0,1875,
		750,625,
		FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No4",
		0,2500,
		750,625,
		FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No5",
		0,3125,
		750,625,
		FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No6",
		0, 3750,
		750, 625,
		FALSE, {{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No7",
		0, 4375,
		750, 625,
		FALSE, {{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No8",
		0,5000,
		750,625,
		FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No9",
		0, 5625,
		750, 625,
		FALSE, {{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	{
		"No10",
		0, 6250,
		750, 625,
		FALSE, {{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},{5,13,0},{5,14,0}}
	},
	};
	_controller.Create(anim, 10);
}
void TitleScene::ReLoad()
{
}
void TitleScene::Update()
{
	InputMouseKey();
	//Click to startのアニメーション用
	_time += _increase;
	_alpha = CalcSequence(fmod(_time, 1));

	_controller.AddTimer(CUtilities::GetFrameSecond());

	if (_controller.IsEndMotion())
	{
		if (_logoCount < 8)
		{
			_controller.ChangeMotion(_logoCount);
			_logoCount += 1;
			_beginTime = timeGetTime();
		}
		if (_logoCount == 8)
		{
			_nowTime = timeGetTime();
			if (_nowTime - _beginTime >= 2500)
			{
				_logoCount = 7;
			}
		}

	}
	_titleLogoRect = _controller.GetSrcRect();
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
	_startTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _startTexture.GetWidth() / 2, 800, MOF_ARGB(_alpha, 255, 255, 255));
	_titleLogoTexture.RenderScale(-230, -550, 3.0f, _titleLogoRect);

}

void TitleScene::Release()
{
	_titleBackTexture.Release();
	_startTexture.Release();
	_titleLogoTexture.Release();
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
	if (x >= 0.5f)
	{
		return detail::g(x) * 255;
	}
	else
	{
		return detail::f(x) * 255;
	}
}