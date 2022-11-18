#include "Doll.h"
#include "Field.h"
#include "Dump.h"

void Doll::Initialize()
{
	_dollTexture.Load("test.png");
	_renderRect = CRectangle(0, 0, _dollTexture.GetWidth(), _dollTexture.GetHeight());
	_field->SetDollMove(&_move);
}

void Doll::ReLoad()
{
	_move = false;
	_moveCount = 0;
	_inversion = false;
	_heldMop = false;
	_currentUnderBlockNumber = 0;
	_routeBlockArray.clear();
}

void Doll::CalcuScale(float boxSizeY, float scale)
{
	const float blockPercentDoll = 2;
	_scale = boxSizeY * blockPercentDoll * scale / _dollTexture.GetHeight();
}

void Doll::SetDumpValue(int dustDumpValue, int waterDumpValue)
{
	_dustDumpValue = dustDumpValue;
	_waterDumpValue = waterDumpValue;
}

void Doll::SetPosition(Vector2 blockCenterPosition)
{
	_dollPosition.x = blockCenterPosition.x - _dollTexture.GetWidth() * _scale / 2;
	_dollPosition.y = blockCenterPosition.y - _dollTexture.GetHeight() * _scale;
}

void Doll::SetRouteBlockArray(std::vector<Block*> blockArray)
{
	_routeBlockArray = blockArray; 
	_move = true;

	SetNextPosition();
}

void Doll::SetNextPosition()
{

	_nextPosition.x =  _routeBlockArray[_currentUnderBlockNumber]->GetCenterPosition().x -_dollPosition.x - _dollTexture.GetWidth() * _scale / 2;
	_nextPosition.y =  _routeBlockArray[_currentUnderBlockNumber]->GetCenterPosition().y -_dollPosition.y - _dollTexture.GetHeight() * _scale;

	if (_nextPosition.x > 0)
	{
		_inversion = true;
		_inversionRenderRect = _renderRect;
		_inversionRenderRect.Right = _renderRect.Left;
		_inversionRenderRect.Left = _renderRect.Right;
	}
	else _inversion = false;
}

void Doll::Update()
{
	if (_move) 
	{
		Move();
	}
}

void Doll::Move()
{
	_dollPosition.x += _nextPosition.x / _moveSpeed;
	_dollPosition.y += _nextPosition.y / _moveSpeed;
	_moveCount++;

	if (_moveCount >= _moveSpeed)
	{
		_moveCount = 0;
		ArrivalBlock();
	}
}

void Doll::ArrivalBlock()
{
	ActionAccessories();
	_currentUnderBlockNumber++;

	if (_currentUnderBlockNumber < _routeBlockArray.size()) 
	{
		SetNextPosition();
		return;
	}

	_field->EndMoveDoll();
	_move = false;
	_currentUnderBlockNumber = 0;
	_routeBlockArray.clear();
}

void Doll::ActionAccessories()
{
	if (_routeBlockArray[_currentUnderBlockNumber]->GetBlockOnObject()->GetAccessories() == nullptr) return;

	if (_routeBlockArray[_currentUnderBlockNumber]->GetBlockOnObject()->GetAccessories()->GetType() == ACCESSORIES_TYPE::DUMP)
	{
		CleanDump();
	}
	else if (_routeBlockArray[_currentUnderBlockNumber]->GetBlockOnObject()->GetAccessories()->GetType() == ACCESSORIES_TYPE::MOP)
	{
		SwitchToMop();
	}
}

void Doll::CleanDump()
{
	if ((!_heldMop && dynamic_cast<Dump*> (_routeBlockArray[_currentUnderBlockNumber]->GetBlockOnObject()->GetAccessories())->GetDumpType() == DUMP_TYPE::WATER) ||
		(_heldMop && dynamic_cast<Dump*> (_routeBlockArray[_currentUnderBlockNumber]->GetBlockOnObject()->GetAccessories())->GetDumpType() == DUMP_TYPE::DUST))return;

	_routeBlockArray[_currentUnderBlockNumber]->GetBlockOnObject()->HiddenAccessoriesFlg(true);
	if (_heldMop) {
		_waterDumpValue--;
		_field->CleanWater();
	}
	else {
		_dustDumpValue--;
		_field->CleanDust();
	}
}

void Doll::SwitchToMop()
{
	_heldMop = true;
	_routeBlockArray[_currentUnderBlockNumber]->GetBlockOnObject()->HiddenAccessoriesFlg(true);

	if (_dustDumpValue > 0)
	{
		//ゲームオーバー
		_field->GameOver();
		_move = false;
	}
}

void Doll::Render()
{
	_inversion ? _dollTexture.RenderScale(_dollPosition.x, _dollPosition.y, _scale, _inversionRenderRect) :
		_dollTexture.RenderScale(_dollPosition.x, _dollPosition.y, _scale, _renderRect);

	//CGraphicsUtilities::RenderRect(_dollPosition.x, _dollPosition.y, _dollPosition.x + _dollTexture.GetWidth() * _scale, _dollPosition.y + _dollTexture.GetHeight() * _scale, MOF_COLOR_RED);
}

void Doll::Release()
{
	_dollTexture.Release();
	_routeBlockArray.clear();
}