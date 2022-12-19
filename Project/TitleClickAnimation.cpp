#include "TitleClickAnimation.h"

void TitleClickAnimation::Initialize(){
	LoadTexture();

	_alpha = _maxAlpha;
}

void TitleClickAnimation::LoadTexture(){
	_texture.Load("clictostart.png");
}

void TitleClickAnimation::ReLoad(){

}

void TitleClickAnimation::Update() {
	//Click to startのアニメーション用
	//_alphaIncreaseが1秒の増加量
	_time += _alphaIncrease;
	//増加量が0.5を超えて丸めるためにfmodを使っている
	//0.5というのは、yの増加量が0になるときのxの増加量
	_alpha = CalcAlpha(fmod(_time, 0.5));
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

int TitleClickAnimation::CalcAlpha(float time)
{
	return detail::EasingFunction(time) * _maxAlpha;
}

void TitleClickAnimation::Render(){
	_texture.Render(g_pGraphics->GetTargetWidth() / 2 - _texture.GetWidth() / 2, 800, MOF_ARGB(_alpha, 255, 255, 255));
}

void TitleClickAnimation::Release(){
	_texture.Release();
}