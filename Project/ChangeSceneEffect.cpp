#include "ChangeSceneEffect.h"

void ChangeSceneEffect::Initialize() {
	_fadeOut.SetTime(50);
	_fadeIn.SetTime(50);
}

void ChangeSceneEffect::Update() {
	if (!_fadeOut.IsEnd()) {
		_fadeOut.Update();

		if (_fadeOut.IsEnd()) {
			_changeSceneMethod();
		}
	}
	else if (!_fadeIn.IsEnd()) _fadeIn.Update();
}

void ChangeSceneEffect::StartEffect() {
	_fadeOut.Start();
	_fadeIn.Start();
}

void ChangeSceneEffect::Render() {
	if(!_fadeOut.IsEnd())_fadeOut.Render();
	else _fadeIn.Render();
}

void ChangeSceneEffect::Release() {

}