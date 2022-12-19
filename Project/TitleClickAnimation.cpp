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
	//Click to start�̃A�j���[�V�����p
	//_alphaIncrease��1�b�̑�����
	_time += _alphaIncrease;
	//�����ʂ�0.5�𒴂��Ċۂ߂邽�߂�fmod���g���Ă���
	//0.5�Ƃ����̂́Ay�̑����ʂ�0�ɂȂ�Ƃ���x�̑�����
	_alpha = CalcAlpha(fmod(_time, 0.5));
}

namespace detail
{
	//Easing(�\���̎d��)
	//2���֐����g�����ƂŁA�A���t�@�l�̑����ƌ�����\���₷���Ȃ�
	//���Ԃ̌o�߂ɔ����p�����[�^�[�̕ω���
	float EasingFunction(float time)
	{
		//2���֐�y=-(4 x-1)^(2)+1
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