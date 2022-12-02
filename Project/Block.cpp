#include "Block.h"

void Block::Initialize()
{
	_passed = false;
	_blockOnObject.SetBlockCenterPosition(GetCenterPosition());
	_blockOnObject.SetBlockSize(Vector2(_blockSizeX, _blockSizeY));
	_blockOnObject.SetBlockScale(_scale);
}

void Block::SetTexture(CTexture* blockTexture)
{
	_blockTexture = blockTexture;
	_blockSizeX = _blockTexture->GetWidth();
	_blockSizeY = _blockTexture->GetHeight();
}

void Block::SetPosition(int x, int y, float topSpace)
{
	_position.x = g_pGraphics->GetTargetWidth() / 2 - _blockSizeX * _scale / 2 + (_blockSizeX * _scale / 2 * x) - (_blockSizeX * _scale / 2 * y);
	_position.y = topSpace + (_blockSizeY * _scale / 2 * y) + (_blockSizeY * _scale / 2 * x);

	_x = x;
	_y = y;
}


void Block::SetAdjoinBlockValue(int adjoinBlockValue)
{
	_adjoinBlockArray = new Block * [adjoinBlockValue];
}

void Block::SetAdjoinBlock(Block* block, int number)
{
	_adjoinBlockArray[number] = block;
}

void Block::CreateWall()
{
	if (_wallArray != nullptr) return;
	_wallArray = new Wall[_wallValue];
}

void Block::SetWall(CTexture* wallTexture, int number)
{
	_wallArray[number].SetScale(_scale);
	_wallArray[number].SetBlockSize(_blockTexture->GetHeight());
	_wallArray[number].SetNumber(number);
	_wallArray[number].SetWallTexture(wallTexture);
	_wallArray[number].SetWallPosition(GetCenterPosition());
}

void Block::SetWallObject(CTexture* wallTexture, int number)
{
	if (_wallArray == nullptr) return;
	_wallArray[number].SetWallObjectTexture(wallTexture);
	_wallArray[number].SetWallObjectPosition(GetCenterPosition());
}

void Block::ReLoad()
{
	_passed = false;
	if (_blockOnObject.GetAccessories() != nullptr)
	{
		_blockOnObject.HiddenAccessoriesFlg(false);
	}
}

void Block::Update()
{

}

bool Block::CheckMouseOnBlock(Vector2 mousePos)
{
	if (_blockTexture == nullptr) return false;
	if (mousePos.y<_position.y || mousePos.y>_position.y + _blockTexture->GetHeight() * _scale)return false;

	float wariai = mousePos.y < _position.y + _blockTexture->GetHeight() * _scale / 2 ? (mousePos.y - _position.y) / (_blockTexture->GetHeight() * _scale / 2) : 1 - ((mousePos.y - _position.y - _blockTexture->GetHeight() * _scale / 2) / (_blockTexture->GetHeight() * _scale / 2));

	if ((_position.x + _blockTexture->GetWidth() * _scale / 2) - _blockTexture->GetWidth() * _scale / 2 * wariai < mousePos.x && (_position.x + _blockTexture->GetWidth() * _scale / 2) + _blockTexture->GetWidth() * _scale / 2 * wariai > mousePos.x) return true;
	return false;
}

void Block::Render()
{
	if (_blockTexture == nullptr) return;

	if (_passed) {
		_blockTexture->RenderScale(_position.x, _position.y, _scale, _passedBlockColor);
	}
	else{
		_blockTexture->RenderScale(_position.x, _position.y, _scale);
	}

	if (_wallArray != nullptr){
		for (int i = _wallValue - 1; i >= 0; i--){
			_wallArray[i].Render();
		}
	}

}

void Block::RenderBlcokOnObject() {
	_blockOnObject.Render();
}

void Block::Delete()
{
	_blockOnObject.Delete();
}

void Block::Release()
{
	Delete();
}