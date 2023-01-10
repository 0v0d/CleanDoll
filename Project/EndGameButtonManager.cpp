#include "EndGameButtonManager.h"

void EndGameButtonManager::Initialize(){

	_buttonSe.Load("BottanClick.mp3");
}

void EndGameButtonManager::ReLoad(){
	for (int i = 0;i < _animationArray.size();i++) {
		_animationArray[i]->ReLoad();
	}
}

void EndGameButtonManager::CreateButton(CTexture* texture, float sizeX, float sizeY, Vector2 centerPos,std::function<void()> method){
	Button* button = new Button();
	
	button->SetTexture(texture);
	button->CalcuScale(sizeX, sizeY);
	button->SetPosition(centerPos);
	button->SetStatu(false,true,method);
	button->SetSeSound(&_buttonSe);

	EndGameButtonAnimation* animation = new EndGameButtonAnimation();

	const int animationTime = 10;
	animation->Initialize();
	animation->SetTexture(texture);
	animation->CalcuTargetScale(sizeY);
	animation->CalcuCenterPos(centerPos);
	animation->CalcuAnimationSpeed(animationTime);

	_buttonArray.push_back(button);
	_animationArray.push_back(animation);
}

void EndGameButtonManager::Update() {
	if (_animationArray[_animationArray.size() - 1]->IsEndAnimation()) return;

	for (int i = 0;i < _animationArray.size();i++) {
		_animationArray[i]->Update();
	}
}

void EndGameButtonManager::SetMousePos(Vector2 mousePos){
	for (int i = 0;i < _buttonArray.size();i++) {
		_buttonArray[i]->SetMousePos(mousePos);
	}
}

void EndGameButtonManager::Push(){
	if (!_animationArray[_animationArray.size() - 1]->IsEndAnimation()) return;

	for (int i = 0;i < _buttonArray.size();i++) {
		_buttonArray[i]->Push();
	}
}

void EndGameButtonManager::Pull(){
	if (!_animationArray[_animationArray.size() - 1]->IsEndAnimation()) return;

	for (int i = 0;i < _buttonArray.size();i++) {
		_buttonArray[i]->Pull();
	}
}

bool EndGameButtonManager::IsEndAnimation() {
	if (_animationArray.size() <= 0) return true;
	return _animationArray[_animationArray.size() - 1]->IsEndAnimation(); 
}


void EndGameButtonManager::Render(){

	if (_animationArray[_animationArray.size() - 1]->IsEndAnimation()) {
		for (int i = 0;i < _buttonArray.size();i++) {
			_buttonArray[i]->Render();
		}
	}
	else {
		for (int i = 0;i < _animationArray.size();i++) {
			_animationArray[i]->Render();
		}
	}
}

void EndGameButtonManager::Release(){

	for (int i = 0;i < _buttonArray.size();i++) {
		delete _buttonArray[i];
		delete _animationArray[i];
	}
	_buttonSe.Release();
}