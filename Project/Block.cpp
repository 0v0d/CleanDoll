#include "Block.h"

void Block::Initialize()
{
	_passed = false;
	_hiddenAccessories = false;
}

void Block::SetTexture(CTexture* blockTexture)
{
	_blockTexture = blockTexture;
	_blockSizeX = _blockTexture->GetWidth();
	_blockSizeY = _blockTexture->GetHeight();
}

void Block::SetPosition(int x, int y, int blockValueY)
{
	_position.x = g_pGraphics->GetTargetWidth() / 2 - _blockSizeX * _scale / 2 + (_blockSizeX * _scale / 2 * x) - (_blockSizeX * _scale / 2 * y);
	_position.y = g_pGraphics->GetTargetHeight() / 2 - blockValueY * _blockSizeY * _scale / 2  + (_blockSizeY * _scale / 2 * y) + (_blockSizeY * _scale / 2 * x);
}


void Block::SetAdjoinBlockValue(int adjoinBlockValue)
{
	_adjoinBlockArray = new Block * [adjoinBlockValue];
}

void Block::SetAdjoinBlock(Block* block, int number)
{
	_adjoinBlockArray[number] = block;
}

void Block::SetObject(Object* object, bool onSwap)
{
	_object = object;
	_object->CalcuScale(_blockSizeX*_scale);
	_object->SetBlockSize(_blockSizeX, _blockSizeY);
	_object->SetPosition(GetCenterPosition());
	if (onSwap)
	{
		_object->Swap();
	}
}

void Block::SetAccessories(IBaseAccessories* accessories)
{
	_accessories = accessories;
	_accessories->CalcuScale(_blockSizeX*_scale);
	_accessories->SetPosotion(GetCenterPosition());
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
	if (_accessories != nullptr)
	{
		_hiddenAccessories = false;
	}
}

void Block::Update()
{

}

bool Block::CheckMouseOnBlock(Vector2 mousePos)
{
	if (mousePos.y<_position.y || mousePos.y>_position.y + _blockTexture->GetHeight() * _scale)return false;

	float wariai = mousePos.y < _position.y + _blockTexture->GetHeight() * _scale / 2 ? (mousePos.y - _position.y) / (_blockTexture->GetHeight() * _scale / 2) : 1 - ((mousePos.y - _position.y - _blockTexture->GetHeight() * _scale / 2) / (_blockTexture->GetHeight() * _scale / 2));

	if ((_position.x + _blockTexture->GetWidth() * _scale / 2) - _blockTexture->GetWidth() * _scale / 2 * wariai < mousePos.x && (_position.x + _blockTexture->GetWidth() * _scale / 2) + _blockTexture->GetWidth() * _scale / 2 * wariai > mousePos.x) return true;
	return false;
}

void Block::Render()
{
	if (_blockTexture == nullptr) return;

	if (_passed) 
	{
		_blockTexture->RenderScale(_position.x, _position.y, _scale, _passedBlockColor);
	}
	else
	{
		_blockTexture->RenderScale(_position.x, _position.y, _scale);
	}

	if (_wallArray != nullptr)
	{
		for (int i = _wallValue - 1; i >= 0; i--)
		{
			_wallArray[i].Render();
		}
	}

	if (_object != nullptr)
	{
		_object->Render();
	}

	if (_accessories != nullptr && !_hiddenAccessories)
	{
		_accessories->Render();
	}
}

void Block::Delete()
{

	if (_object != nullptr) 
	{
		DeleteObject();
	}

	if (_accessories != nullptr)
	{
		DeleteAccessories();
	}
}

void Block::DeleteObject()
{
	_object->Release();
	delete _object;
	_object = nullptr;
}

void Block::DeleteAccessories()
{
	_accessories->Release();
	delete _accessories;
	_accessories = nullptr;
}

void Block::Release()
{
	Delete();
}