#include "CreateField.h"

void CreateField::SetField(Field* field)
{
	_field = field;
	SetBlockManager();
}

void CreateField::SetFieldStatu(int blockValueX, int blockValueY)
{
	_blockValueX = blockValueX;
	_blockValueY = blockValueY;

	_blockManager->CreateField(blockValueX, blockValueY);
}

void CreateField::SetBlockData(CTexture* TextureArray, char** dataArray)
{
	if (TextureArray == nullptr)return;

	_blockManager->CalcuScale(TextureArray[0].GetHeight());

	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			if (dataArray[x][y] == 0)
			{
				continue;
			}

			Block* block = _blockManager->GetBlock(x, y);
			block->SetTexture(&TextureArray[dataArray[x][y] - 1]);
			_blockManager->CalcuBlockPosition();
			block->Initialize();
		}
	}
}

void CreateField::SetObjectData(CTexture* TextureArray, char** dataArray)
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			int textureNumber = dataArray[x][y];
			if (textureNumber == 0)
			{
				continue;
			}

			Block* block = _blockManager->GetBlock(x, y);
			bool onSwap = false;
			if (textureNumber < 0)
			{
				textureNumber *= -1;
				onSwap = true;
			}
			block->SetObject(new Object(&TextureArray[textureNumber - 1]), onSwap);
		}
	}
}

void CreateField::SetItemData(CTexture* TextureArray, char** dataArray, bool isCandy)
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			if (dataArray[x][y] == 0)
			{
				continue;
			}

			Block* block = _blockManager->GetBlock(x, y);

			ACCESSORIES_TYPE accessoriesType = isCandy ? ACCESSORIES_TYPE::ITEM : ACCESSORIES_TYPE::MOP;
			block->SetAccessories(new Item(&TextureArray[dataArray[x][y] - 1], accessoriesType));
		}
	}
}

void CreateField::SetDumpData(CTexture* TextureArray, char** dataArray, bool isDustDump)
{
	int dumpValue = 0;

	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			if (dataArray[x][y] == 0) 
			{
				continue;
			}

			dumpValue++;
			Block* block = _blockManager->GetBlock(x, y);

			DUMP_TYPE dumpType = isDustDump ? DUMP_TYPE::DUST : DUMP_TYPE::WATER;
			block->SetAccessories(new Dump(&TextureArray[dataArray[x][y] - 1], dumpType));
		}
	}

	isDustDump ? _field->SetDustDumpValue(dumpValue) : _field->SetWaterDumpValue(dumpValue);
}

void CreateField::SetWallData(CTexture* TextureArray, char** dataArray, int lineValueX)
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			for (int i = 0;i < lineValueX;i++)
			{
				if (dataArray[x * lineValueX + i][y] == 0)
				{
					continue;
				}
				Block* block = _blockManager->GetBlock(x, y);
				block->CreateWall();
				block->SetWall(&TextureArray[dataArray[x * lineValueX + i][y] - 1], i);
			}
		}
	}
}

void CreateField::SetWallObjectkData(CTexture* TextureArray, char** dataArray,int lineValueX){
	
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			for (int i = 0;i < lineValueX;i++)
			{
				if (dataArray[x * lineValueX + i][y] == 0)
				{
					continue;
				}
				Block* block = _blockManager->GetBlock(x, y);
				block->SetWallObject(&TextureArray[dataArray[x * lineValueX + i][y] - 1], i);
			}
		}
	}
}

void CreateField::SetDoll(int x, int y)
{
	_field->SetDollPosition(x,y);
}