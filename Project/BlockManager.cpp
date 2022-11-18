#include "BlockManager.h"

void BlockManager::Initialize()
{
	_topSpace = 300;
	_bottomSpace = 100;
}

void BlockManager::ReLoad()
{
	for (int y = 0;y < _blockValueY;y++) 
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			_blockArray[x][y].ReLoad();
		}
	}
}

void BlockManager::CreateField(int blockValueX, int blockValueY)
{
	_blockValueX = blockValueX;
	_blockValueY = blockValueY;

	_blockArray = new Block * [_blockValueX];
	for (int i = 0; i < _blockValueX; i++)
	{
		_blockArray[i] = new Block[_blockValueY];
	}
	SetAdjoinBlock();
}

void BlockManager::CalcuBlockPosition() {
	for (int y = 0; y < _blockValueY; y++)
	{
		for (int x = 0; x < _blockValueX; x++)
		{
			_blockArray[x][y].SetPosition(x, y, _topSpace);
		}
	}
}

void BlockManager::SetAdjoinBlock()
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			_blockArray[x][y].SetAdjoinBlockValue(_adjoinBlockValue);
			if (x > 0)
			{
				_blockArray[x][y].SetAdjoinBlock(&_blockArray[x - 1][y], 0);
			}
			if (y > 0) 
			{
				_blockArray[x][y].SetAdjoinBlock(&_blockArray[x][y - 1], 1);
			}
			if (x + 1 < _blockValueX)
			{
				_blockArray[x][y].SetAdjoinBlock(&_blockArray[x + 1][y], 2);
			}
			if (y + 1 < _blockValueY)
			{
				_blockArray[x][y].SetAdjoinBlock(&_blockArray[x][y + 1], 3);
			}
		}
	}
}

void BlockManager::CalcuScale(float blockSizeY) {
	_scale = (g_pGraphics->GetTargetHeight() - (_topSpace + _bottomSpace)) / ((0.5f * _blockValueY + 0.5f * _blockValueX) * blockSizeY);

	for (int y = 0;y < _blockValueY;y++) 
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			_blockArray[x][y].SetScale(_scale);
		}
	}
}

void BlockManager::SetDollOnPositon(int blockX, int blockY) {
	_dollOnBlockX = blockX;
	_dollOnBlockY = blockY;
}

void BlockManager::Update()
{

}

Block* BlockManager::GetMouseOnBlock(Vector2 mousePos)
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0; x < _blockValueX; x++)
		{
			if (_blockArray[x][y].CheckMouseOnBlock(mousePos))
			{
				return &_blockArray[x][y];
			}
		}
	}
	return nullptr;
}

void BlockManager::Render()
{
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0; x < _blockValueX; x++) {
			_blockArray[x][y].Render();
		}
	}
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0; x < _blockValueX; x++) {
			_blockArray[x][y].RenderBlcokOnObject();
			if (x == _dollOnBlockX && y == _dollOnBlockY)_doll->Render();
		}
	}
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0; x < _blockValueX; x++) {
			if (x == _dollOnBlockX && y == _dollOnBlockY)_doll->Render();
		}
	}
}

void BlockManager::Delete()
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0; x < _blockValueX; x++)
		{
			_blockArray[x][y].Delete();
		}
	}
		
}

void BlockManager::Release()
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0; x < _blockValueX; x++)
		{
			_blockArray[x][y].Delete();
		}
	}
	Delete();
}