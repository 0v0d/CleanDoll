#include "TitleClickAnimation.h"

void TitleClickAnimation::Initialize(){
	LoadTexture();
	_time = 0.5f;
	CalcAlpha();
}

void TitleClickAnimation::LoadTexture(){
	_texture.Load("clictostart.png");
}

void TitleClickAnimation::ReLoad(){
	_time = 0.5f;
}

void TitleClickAnimation::Update() {
	//Click to start�̃A�j���[�V�����p
	//_alphaIncrease��1�b�̑�����
	_time += _alphaIncrease;
	if (_time > 1) _time = 0;
	//�����ʂ�0.5�𒴂��Ċۂ߂邽�߂�fmod���g���Ă���
	//0.5�Ƃ����̂́Ay�̑����ʂ�0�ɂȂ�Ƃ���x�̑�����

	CalcAlpha();
}

namespace detail
{
	//Easing(�\���̎d��)
	//2���֐����g�����ƂŁA�A���t�@�l�̑����ƌ�����\���₷���Ȃ�
	//���Ԃ̌o�߂ɔ����p�����[�^�[�̕ω���
	float EasingFunction(float time)
	{
		//2���֐�y=-(4 x-1)^(2)+1
		return  -pow((2 * time - 1), 2) + 1;
	}
}

void TitleClickAnimation::CalcAlpha()
{
	_alpha = detail::EasingFunction(_time) * (_maxAlpha * (1 - miniAlphaPercentage))+ (_maxAlpha *  miniAlphaPercentage);
}

void TitleClickAnimation::Render(){
	_texture.Render(g_pGraphics->GetTargetWidth() / 2 - _texture.GetWidth() / 2, 800, MOF_ARGB(_alpha, 255, 255, 255));
}

void TitleClickAnimation::Release(){
	_texture.Release();
}