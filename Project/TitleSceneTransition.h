#pragma once
#include	"Mof.h"
#include	"Button.h"

class TitleSceneTransition
{
	Button _transitionStageSelectButton;
	Button _transitionGalleryButton;
	Button _transitionCreditButton;

	CTexture _stageSelectTexture, _galleryTexture, _creditTexture;
	CSoundBuffer _buttonSe;

public:

	void Initialize();
	void ReLoad();

	void SetMousePos(Vector2 mousePos);
	void Push();
	void Pull();

	void Render();
	void Release();

private:
	void LoadTexture();
	void LoadSound();
	void CreateButton(Button*, Vector2 pos, CTexture*, std::function<void()>);
};