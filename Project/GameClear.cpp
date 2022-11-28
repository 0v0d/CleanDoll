#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"


void GameClear::TextureLoad()
{
	_stageClearTecture.Load("ゲームクリア.png");
	_nextStageTexture.Load("nextStage.png");
	_stageSelectTexture.Load("returnstageselect.png");
	_retryTexture.Load("retry.png");
	_backStageClearTexture.Load("BackStageClear.png");
}
void GameClear::SetAnimation()
{
	SpriteAnimationCreate anim[] =
	{
		{
			"No1",
			0,0,
			480,270,
			FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0},{5,8,0},{5,9,0},{5,10,0},{5,11,0},{5,12,0},
					{5,13,0},{5,14,0},{5,15,0},{5,16,0},{5,17,0},{5,18,0},{5,19,0},{5,20,0},{5,21,0},{5,22,0}}
		},

	};
	_animation.Create(anim, 23);
}


void GameClear::Initialize()
{
	TextureLoad();
	SetAnimation();
	_nextButtonPos = Vector2(400, 300);
	_stageSelectButtonPos = Vector2(400, 500);
	_retryButtonPos = Vector2(400, 700);
	Vector2 _size = Vector2(300, 120);
	


	_stageSelectButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_retryButton.SetStatu(_retryButtonPos, &_retryTexture);
	_goal = false;
	_remove = false;
	_mousePos = Vector2(0, 0);
}

void GameClear::Reload()
{
	_goal = false;
	_remove = false;
}

void GameClear::Update()
{
	if (IsGoal())
	{
		g_pInput->GetMousePos(_mousePos);
		if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
		{
			if (_nextStageButton.CheckOnButton(_mousePos))
			{
				//次のステージへ
				_remove = true;
				dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StartNextStage();
			}			
			if (_stageSelectButton.CheckOnButton(_mousePos))
			{
				_remove = true;
				SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
			}

			if (_retryButton.CheckOnButton(_mousePos))
			{
				SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
			}
			
		}
	}
}


void GameClear::Render()
{
	if (IsGoal())
	{
		if (_scale <= 1.0f)
		{
			CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
			_backStageClearTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - _backStageClearTexture.GetWidth() / 2 * _scale,
				g_pGraphics->GetTargetHeight() / 2 - _backStageClearTexture.GetHeight() / 2 * _scale,_scale );

			_scale += 0.1f;
		}
		else
		{
			CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
			_backStageClearTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - _backStageClearTexture.GetWidth() / 2 ,
												g_pGraphics->GetTargetHeight() / 2 - _backStageClearTexture.GetHeight() / 2 , 1.0f);
			_nextStageTexture.Render(400, 300);
			_stageSelectButton.Render();
			_retryButton.Render();
		}
		
		
		
	}
}

void GameClear::Release()
{
	_nextStageTexture.Release();
	_stageSelectTexture.Release();
	_retryTexture.Release();
	_backStageClearTexture.Release();
}
