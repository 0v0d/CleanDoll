#include "TitleScene.h"

void TitleScene::Initialize()
{
	_titleBackTexture.Load("titleback.png");
	_backGround.SetTextureStatus(&_titleBackTexture, FULLSCREEN);
	_startTexture.Load("clictostart.png");
	_titleLogoTexture.Load("taitlelog.png");
	_titleLogoLoopTexture.Load("titleloop.png");
	_music.Load("BGM.mp3");
	SetTitleLogoAnimationStatus();
	_bgm.SetBGM(&_music, true);
	_bgm.Play();
	_alpha = 255;
}

void TitleScene::SetTitleLogoAnimationStatus()
{
	SpriteAnimationCreate anim[] = 
  {
	{
		"1-1",
		0,0,
		750,625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-2",
		0,625,
		750,625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-3",
		0,1250,
		750,625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-4",
		0,1875,
		750,625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-5",
		0,2500,
		750,625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-6",
		0, 3125,
		750, 625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-7",
		0,3750,
		750, 625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-8",
		0,4375,
		750,625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-9",
		0, 5000,
		750, 625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-10",
		0, 5625,
		750, 625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"1-11",
		0,6250,
		750, 625,
		FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	},
	{
		"2-1",
		0,0,
		750,625,
		FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	},
	{
		"2-2",
		0,625,
		750,625,			
		FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	},
	{
		"2-3",
		0,1250,
		750,625,
		FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	},
	{
		"2-4",
		0,1875,
		750,625,
		FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	},
	{
		"2-5",
		0,2500,
		750,625,
		FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	}

 };
	_logo.Create(anim, 14);
}

void TitleScene::ReLoad()
{
	_bgm.Play();
}

void TitleScene::Update()
{
	//Click to startのアニメーション用
//_alphaIncreaseが1秒の増加量
	_time += _alphaIncrease;
	//増加量が0.5を超えて丸めるためにfmodを使っている
	//0.5というのは、yの増加量が0になるときのxの増加量
	_alpha = CalcAlpha(fmod(_time, 0.5));

	_logo.AddTimer(CUtilities::GetFrameSecond());
	//最初に流れるアニメーション
	if (_logo.IsEndMotion()&&_logoCount<=9)
	{
		_logo.ChangeMotion(_logoCount);
		_logoCount += 1;
		
	}
	//ループ用のアニメーション
	if (_logo.IsEndMotion() && _logoCount >= 10)
	{
		_loop = true;
		_logo.ChangeMotion(_logoCount);
		_logoCount += 1;
		if (_logoCount == 15)
		{
			_logoCount = 10;
		}
	}
	
	_titleLogoRect = _logo.GetSrcRect();

	//デバッグ
	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) SceneManager::Instance().ChangeScene(SCENE_TYPE::GALLERY);
}

void TitleScene::SetMousePos(Vector2) {

}

void TitleScene::Push() {
	SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	_bgm.Stop();
}

void TitleScene::Pull() {

}

void TitleScene::Render()
{
	_backGround.Render();
	_startTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _startTexture.GetWidth() / 2, 800, MOF_ARGB(_alpha, 255, 255, 255));
	if (!_loop)
	{
		_titleLogoTexture.RenderScale(_titleLogoPos.x, _titleLogoPos.y, _titleLogoScale, _titleLogoRect);
	}
	else
	{
		_titleLogoLoopTexture.RenderScale(_titleLogoPos.x, _titleLogoPos.y, _titleLogoScale, _titleLogoRect);
	}
}

void TitleScene::Release()
{
	_titleBackTexture.Release();
	_startTexture.Release();
	_titleLogoTexture.Release();
	_titleLogoLoopTexture.Release();
	_music.Release();
}

void TitleScene::StopBGM()
{
	_bgm.Stop();
}

namespace detail
{
	//Easing(表示の仕方)
	//2次関数を使うことで、アルファ値の増加と減少を表しやすくなる
	//時間の経過に伴うパラメーターの変化率
	float EasingFunction(float time)
	{
		//2次関数y=-(4 x-1)^(2)+1
		return  -pow((4 * time - 1), 2) + 1;
	}

}

int TitleScene::CalcAlpha(float time)
{
	//255はアルファ値の最大値
	const uint8_t _maxAlpha = 255;
	return detail::EasingFunction(time) * _maxAlpha;
}