#include "ChangeSceneEffect.h"

void ChangeSceneEffect::Initialize() {
	/*_sideOut.SetTime(50);
	_sideIn.SetTime(50);*/
}

void ChangeSceneEffect::Update() {
	if (!_sideOut.IsEnd()) {
		_sideOut.Update();

		if (_sideOut.IsEnd()) {
			_changeSceneMethod();
		}
	}
	else if (!_sideIn.IsEnd()) _sideIn.Update();
}

void ChangeSceneEffect::StartEffect() {
	_sideOut.Start();
	_sideIn.Start();
}

void ChangeSceneEffect::Render() {
	if(!_sideOut.IsEnd())_sideOut.Render();
	else _sideIn.Render();
}

void ChangeSceneEffect::Release() {

}