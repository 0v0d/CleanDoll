#include "GalleryCoin.h"

GalleryCoin::GalleryCoin(ACCESSORIES_TYPE accessoriesType) :
	_accessoriesType(accessoriesType)
{}

void GalleryCoin::Initialize()
{
	LoadTexture();
}

void GalleryCoin::LoadTexture() {
	_coinTexture.Load("coin.png");
	_time = 0;
}

void GalleryCoin::ReLoad()
{
	_time = 0;
}

void GalleryCoin::SetPosotion(Vector2 pos)
{
	_position.x = pos.x - _coinTexture.GetWidth() * _scale / 2;
	_position.y = pos.y - _coinTexture.GetHeight() * _scale;
}

void GalleryCoin::Update()
{
	//XÇÃëùâ¡ó 
	const float _incX = 0.01;
	_time += _incX;
	CalcPosY();
}


void  GalleryCoin::CalcPosY()
{
	const float  _pi = 3.14159265359;
	//è„â∫Ç…Ç»ÇÒÇ⁄ìÆÇ≠Ç©
	const float  _incY = 10;
	_incPosY= _incY*(sin(0.5*_time * _pi))+_incY;
}

void GalleryCoin::Render()
{
	_coinTexture.RenderScale(_position.x, _position.y+ _incPosY, _scale);
}

void GalleryCoin::Release()
{
	_coinTexture.Release();
}