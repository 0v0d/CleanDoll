#include "TitleScene.h"

void TitleScene::Initialize()
{
	_titleLogoAnimation.Initialize();
	_titleClickAnimation.Initialize();
	_transition.Initialize();

	_titleBackTexture.Load("titleback.png");
	_backGround.SetTextureStatus(&_titleBackTexture, FULLSCREEN);

	_music.Load("BGM.mp3");
	_openTransition = false;

	_fadeIn.SetTime(100);
	_fadeIn.Start();
}

void TitleScene::ReLoad()
{
	_titleLogoAnimation.ReLoad();
	_titleClickAnimation.ReLoad();
	_transition.ReLoad();

	_openTransition = false;
}

void TitleScene::Update()
{
	_fadeIn.Update();
	if (!_fadeIn.IsEnd()) return;

	_titleLogoAnimation.Update();
	_titleClickAnimation.Update();
}

void TitleScene::SetMousePos(Vector2 mousePos) {
	if (_openTransition)_transition.SetMousePos(mousePos);

}

void TitleScene::Push() {
	if(_openTransition)_transition.Push();
}

void TitleScene::Pull() {

	if (_openTransition)_transition.Pull();
	else _openTransition = true;
}

void TitleScene::Render()
{

	_backGround.Render();
	_titleLogoAnimation.Render();

	if (_openTransition) {
		_transition.Render();
	}
	else {
		_titleClickAnimation.Render();
	}

	_fadeIn.Render();
}

void TitleScene::Release()
{
	_titleLogoAnimation.Release();
	_titleClickAnimation.Release();
	_titleBackTexture.Release();
	_transition.Release();

	_music.Release();
}