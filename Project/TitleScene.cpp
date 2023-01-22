#include "TitleScene.h"

#include "AudioMixer.h"

void TitleScene::Initialize()
{
	LoadTexture();
	LoadSound();
	_titleLogoAnimation.Initialize();
	_titleClickAnimation.Initialize();
	_transition.Initialize();

	_backGround.SetTextureStatus(&_titleBackTexture, FULLSCREEN);

	_openTransition = false;

	_fadeIn.SetTime(100);
	_fadeIn.Start();

}

void TitleScene::LoadTexture() {
	_titleBackTexture.Load("BackGround.png");
}

void TitleScene::LoadSound() {
	_music.Load("BGM.mp3");
	_clickSound.Load("ClicktoStart.mp3");
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
	else {
		_openTransition = true;
		AudioMixer::Instance().PlaySe(&_clickSound);
	}
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
	_clickSound.Release();
}