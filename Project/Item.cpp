#include "Item.h"

Item::Item(CTexture* itemTexture, ACCESSORIES_TYPE accessoriesType) :
	_itemTexture(itemTexture) ,
	_accessoriesType(accessoriesType)
{}

void Item::Initialize()
{

}

void Item::SetPosotion(Vector2 pos)
{
	_position.x = pos.x - _itemTexture->GetWidth() * _scale / 2;
	_position.y = pos.y - _itemTexture->GetHeight() * _scale / 2;
}

void Item::Update()
{

}

void Item::Render()
{
	_itemTexture->RenderScale(_position.x, _position.y,_scale,MOF_COLOR_HYELLOW);
}

void Item::Release()
{

}