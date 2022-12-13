#include "GalleryCoin.h"

GalleryCoin::GalleryCoin(ACCESSORIES_TYPE accessoriesType) :
	_accessoriesType(accessoriesType)
{}

void GalleryCoin::Initialize()
{
	_coinTexture.Load("coin.png");
}

void GalleryCoin::ReLoad()
{
}

void GalleryCoin::SetPosotion(Vector2 pos)
{
	_position.x = pos.x - _coinTexture.GetWidth() * _scale / 2;
	_position.y = pos.y - _coinTexture.GetHeight() * _scale / 2;
}

void GalleryCoin::Update()
{

}

void GalleryCoin::Render()
{
	_coinTexture.RenderScale(_position.x, _position.y, _scale);
}

void GalleryCoin::Release()
{
	_coinTexture.Release();
}