#include "Doll.h"
#include "Field.h"
#include "Dump.h"

void Doll::Initialize()
{
	_dollTexture.Load("doll.png");
	_field->SetDollMove(&_move);
	_motionCount = 0;
	_dollTextureSize = Vector2(_dollTexture.GetWidth() / _textureValue, _dollTexture.GetHeight() / MOTION_COUNT);
	DollAnimationInit();
}

void Doll::DollAnimationInit() 
{
	SpriteAnimationCreate _dollAnimation[] = {
	{
		"Wait",
		0,0,
		320,320,
		false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
		{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
		{_wait,17,0},{_wait,18,0},{_wait,19,0},}
	},
	{
		"Wait",
		0,320,
		320,320,
		false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
		{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
		{_wait,17,0},{_wait,18,0},{_wait,19,0},}
	},
	{
		"Walk",
		0,640,
		320,320,
		true,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
		{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
		{_wait,17,0},{_wait,18,0},{_wait,19,0},{_wait,20,0},{_wait,21,0},{_wait,22,0},{_wait,23,0},{_wait,24,0},{_wait,25,0},
		{_wait,26,0},{_wait,27,0},{_wait,28,0},{_wait,29,0}}
	}

	};
	_motionController.Create(_dollAnimation, MOTION_COUNT);
}

int Doll::AnimationRoop()
{
	return _motionCount = (_motionCount + 1) % 2;
}

void Doll::DollAnimationUpdate() 
{
	_motionController.AddTimer(CUtilities::GetFrameSecond());
	_renderRect = _motionController.GetSrcRect();

	if (_inversion)
	{
		_inversionRenderRect = _renderRect;
		_inversionRenderRect.Right = _renderRect.Left;
		_inversionRenderRect.Left = _renderRect.Right;
	}

	if (_motionController.IsEndMotion())
	{
		_motionController.ChangeMotion(AnimationRoop());
	}
	if (_move)
	{
		if (_motionController.GetMotionNo() == WAIT_1 || _motionController.GetMotionNo() == WAIT_2)
		{
			_motionController.ChangeMotion(WALK);

		}
	}
	else
	{
		if (_motionController.GetMotionNo() == WALK)
		{
			_motionController.ChangeMotion(AnimationRoop());
		}
	}
	
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
	_scale = boxSizeY * blockPercentDoll * scale / _dollTextureSize.y;
}

void Doll::SetDumpValue(int dustDumpValue, int waterDumpValue)
{
	_dustDumpValue = dustDumpValue;
	_waterDumpValue = waterDumpValue;
}

void Doll::SetPosition(Vector2 blockCenterPosition)
{
	_dollPosition.x = blockCenterPosition.x - _dollTextureSize.x * _scale / 2;
	_dollPosition.y = blockCenterPosition.y - _dollTextureSize.y * _scale;
}

void Doll::SetRouteBlockArray(std::vector<Block*> blockArray)
{
	_routeBlockArray = blockArray; 
	_move = true;

	SetNextPosition();
}

void Doll::SetNextPosition()
{

	_nextPosition.x =  _routeBlockArray[_currentUnderBlockNumber]->GetCenterPosition().x -_dollPosition.x - _dollTextureSize.x * _scale / 2;
	_nextPosition.y =  _routeBlockArray[_currentUnderBlockNumber]->GetCenterPosition().y -_dollPosition.y - _dollTextureSize.y * _scale;

	if (_nextPosition.x > 0)
	{
		_inversion = true;

	}
	else _inversion = false;
}

void Doll::Update()
{
	if (_move) 
	{
		Move();
	}

	DollAnimationUpdate();
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
	if (_routeBlockArray[_currentUnderBlockNumber]->GetAccessories() == nullptr) return;

	if (_routeBlockArray[_currentUnderBlockNumber]->GetAccessories()->GetType() == ACCESSORIES_TYPE::DUMP)
	{
		CleanDump();
	}
	else if (_routeBlockArray[_currentUnderBlockNumber]->GetAccessories()->GetType() == ACCESSORIES_TYPE::MOP) 
	{
		SwitchToMop();
	}
}

void Doll::CleanDump()
{
	if ((!_heldMop && dynamic_cast<Dump*> (_routeBlockArray[_currentUnderBlockNumber]->GetAccessories())->GetDumpType() == DUMP_TYPE::WATER) ||
		(_heldMop && dynamic_cast<Dump*> (_routeBlockArray[_currentUnderBlockNumber]->GetAccessories())->GetDumpType() == DUMP_TYPE::DUST))return;

	_routeBlockArray[_currentUnderBlockNumber]->HiddenAccessoriesFlg(true);
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
	_routeBlockArray[_currentUnderBlockNumber]->HiddenAccessoriesFlg(true);

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

