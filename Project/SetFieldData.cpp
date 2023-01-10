#include "SetFieldData.h"
#include	"Object.h"
#include	"Item.h"
#include	"Dump.h"

void SetFieldData::SetField(Field* field)
{
	_field = field;
	_blockManager = _field->GetBlockManager();
}

void SetFieldData::SetFieldStatu(int blockValueX, int blockValueY)
{
	_blockValueX = blockValueX;
	_blockValueY = blockValueY;

	_blockManager->Delete();
	_blockManager->CreateField(blockValueX, blockValueY);
}

void SetFieldData::SetBlockData(CTexture* TextureArray, char** dataArray)
{
	if (TextureArray == nullptr)return;

	_blockManager->CalcuScale(TextureArray[0].GetHeight());

	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			if (dataArray[x][y] == 0)continue;

			Block* block = _blockManager->GetBlock(x, y);
			block->SetTexture(&TextureArray[dataArray[x][y] - 1]);
			_blockManager->CalcuBlockPosition();
			block->Initialize();
		}
	}
}

void SetFieldData::SetObjectData(CTexture* TextureArray, char** dataArray)
{
	for (int y = 0;y < _blockValueY;y++)
	{
		for (int x = 0;x < _blockValueX;x++)
		{
			int textureNumber = dataArray[x][y];
			if (textureNumber == 0)continue;

			Block* block = _blockManager->GetBlock(x, y);
			bool onSwap = false;
			if (textureNumber < 0)
			{
				textureNumber *= -1;
				onSwap = true;
			}
			block->GetBlockOnObject()->SetObject(new Object(&TextureArray[textureNumber - 1]), onSwap);
		}
	}
}

void SetFieldData::SetItemData(CTexture* TextureArray, char** dataArray, bool isCandy)
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
			block->GetBlockOnObject()->SetAccessories(new Item(&TextureArray[dataArray[x][y] - 1], accessoriesType));
		}
	}
}

void SetFieldData::SetDumpData(CTexture* TextureArray, char** dataArray, bool isDustDump)
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
			block->GetBlockOnObject()->SetAccessories(new Dump(&TextureArray[dataArray[x][y] - 1], dumpType));
		}
	}

	isDustDump ? _field->SetDustDumpValue(dumpValue) : _field->SetWaterDumpValue(dumpValue);
}

void SetFieldData::SetWallData(CTexture* TextureArray, char** dataArray, int lineValueX)
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

void SetFieldData::SetWallObjectkData(CTexture* TextureArray, char** dataArray,int lineValueX){
	
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

void SetFieldData::SetDoll(int x, int y)
{
	_field->SetDollPosition(x,y);
}

void SetFieldData::SetCoin(int x, int y,bool getCoin) {
	if(!getCoin)_blockManager->SetCoin(x, y);
	_field->SetGettedCoinFlg(getCoin);
}