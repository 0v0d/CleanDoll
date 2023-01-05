#include "EndGameButtonManager.h"

void EndGameButtonManager::Initialize(){

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

	EndGameButtonAnimation* animation = new EndGameButtonAnimation();

	const int animationTime = 10;
	animation->Initialize();
	animation->SetTexture(texture);
	animation->CalcuTargetScale(sizeY);
	animation->CalcuCenterPos(centerPos);
	animation->CalcuAnimationSpeed(animationTime);

	auto pair = new std::pair<Button*, std::function<void()>>{ button,method };
	_buttonArray.push_back(pair);
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
		_buttonArray[i]->first->SetMousePos(mousePos);
	}
}

void EndGameButtonManager::Push(){
	if (!_animationArray[_animationArray.size() - 1]->IsEndAnimation()) return;

	for (int i = 0;i < _buttonArray.size();i++) {
		_buttonArray[i]->first->Push();
	}
}

void EndGameButtonManager::Pull(){
	if (!_animationArray[_animationArray.size() - 1]->IsEndAnimation()) return;

	for (int i = 0;i < _buttonArray.size();i++) {
		_buttonArray[i]->first->Pull();
		if (_buttonArray[i]->first->IsPullButton())_buttonArray[i]->second();
	}
}

bool EndGameButtonManager::IsEndAnimation() {
	if (_animationArray.size() <= 0) return true;
	return _animationArray[_animationArray.size() - 1]->IsEndAnimation(); 
}


void EndGameButtonManager::Render(){

	if (_animationArray[_animationArray.size() - 1]->IsEndAnimation()) {
		for (int i = 0;i < _buttonArray.size();i++) {
			_buttonArray[i]->first->Render();
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
		delete _buttonArray[i]->first;
		delete _animationArray[i];
	}
}