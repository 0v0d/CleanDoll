#include "GalleryCoin.h"

GalleryCoin::GalleryCoin(ACCESSORIES_TYPE accessoriesType) :
	_accessoriesType(accessoriesType)
{}

void GalleryCoin::Initialize()
{
	LoadTexture();
	_time = 0;
}

void GalleryCoin::LoadTexture() {
	_coinTexture.Load("coin.png");
	_coinShadowTexture.Load("coinshadow.png");
}

void GalleryCoin::ReLoad()
{
	_time = 0;
}
void  GalleryCoin::CalcuScale(float blockSizeX)
{
	_coinScale = blockSizeX / _coinTexture.GetWidth(); 
	_coinShadowScale = blockSizeX / _coinShadowTexture.GetWidth();
}
void GalleryCoin::SetPosotion(Vector2 pos)
{
	_coinPos.x = pos.x - _coinTexture.GetWidth() * _coinScale / 2;
	_coinPos.y = pos.y - _coinTexture.GetHeight() * _coinScale;
	_coinShadowPos.x = pos.x - _coinShadowTexture.GetWidth() * _coinShadowScale / 2;
	_coinShadowPos.y = pos.y - _coinShadowTexture.GetHeight() * _coinShadowScale;

}

void GalleryCoin::Update()
{
	//XÇÃëùâ¡ó 
	const float _incX = 0.01;
	_time += _incX;
	if (_time >= 4)_time = 0;
	CalcPosY();
	CalcAlpha();
}


void  GalleryCoin::CalcPosY()
{
	const float  _pi = 3.14159265359;
	//è„â∫Ç…Ç»ÇÒÇ⁄ìÆÇ≠Ç©
	const float  _incY = 8;
	_incPosY= _incY*(sin(0.5*_time * _pi))-_incY;
}
void GalleryCoin::CalcAlpha()
{
	const float  _pi = 3.14159265359;
	const float  _incAlpha = 50;
	_alpha = _incAlpha * (sin(0.5 * _time * _pi)) + _incAlpha;
}

void GalleryCoin::Render()
{
	_coinShadowTexture.RenderScale(_coinShadowPos.x, _coinShadowPos.y, _coinShadowScale, MOF_ARGB(100+_alpha, 255, 255, 255));
	_coinTexture.RenderScale(_coinPos.x, _coinPos.y+ _incPosY, _coinScale);
	
}

void GalleryCoin::Release()
{
	_coinTexture.Release();
	_coinShadowTexture.Release();
}