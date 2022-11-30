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
		false,{{wait,0,0},{wait,1,0},{wait,2,0},{wait,3,0},{wait,4,0},{wait,5,0},{wait,6,0},{wait,7,0},
		{wait,8,0},{wait,9,0} ,{wait,10,0},{wait,11,0},{wait,12,0},{wait,13,0},{wait,14,0},{wait,15,0},{wait,16,0},
		{wait,17,0},{wait,18,0},{wait,19,0},}
	},
	{
		"Wait",
		0,320,
		320,320,
		false,{{wait,0,0},{wait,1,0},{wait,2,0},{wait,3,0},{wait,4,0},{wait,5,0},{wait,6,0},{wait,7,0},
		{wait,8,0},{wait,9,0} ,{wait,10,0},{wait,11,0},{wait,12,0},{wait,13,0},{wait,14,0},{wait,15,0},{wait,16,0},
		{wait,17,0},{wait,18,0},{wait,19,0},}
	},
	{
		"Walk",
		0,640,
		320,320,
		true,{{wait,0,0},{wait,1,0},{wait,2,0},{wait,3,0},{wait,4,0},{wait,5,0},{wait,6,0},{wait,7,0},
		{wait,8,0},{wait,9,0} ,{wait,10,0},{wait,11,0},{wait,12,0},{wait,13,0},{wait,14,0},{wait,15,0},{wait,16,0},
		{wait,17,0},{wait,18,0},{wait,19,0},{wait,20,0},{wait,21,0},{wait,22,0},{wait,23,0},{wait,24,0},{wait,25,0},
		{wait,26,0},{wait,27,0},{wait,28,0},{wait,29,0}}
	}

	};
	_motionController.Create(_dollAnimation, MOTION_COUNT);
}

void Doll::ReLoad()
{
	_move = false;
	_moveCount = 0;
	_inversion = false;
	_heldMop = false;
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


void Doll::SetNextBlock(Block* blcok) {

	_nextBlock = blcok;
	_field->SetDollOnBlockNumber(_nextBlock);
	SetNextPosition();
	_move = true;
}

void Doll::SetNextPosition()
{
	_nextPosition.x = _nextBlock->GetCenterPosition().x -_dollPosition.x - _dollTextureSize.x * _scale / 2;
	_nextPosition.y = _nextBlock->GetCenterPosition().y -_dollPosition.y - _dollTextureSize.y * _scale;

	_inversion = _nextPosition.x > 0;
}

void Doll::Update()
{
	if (_move){
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
		ActionAccessories();
		_move = false;
		_endMoveMethod();
	}
}

void Doll::ActionAccessories()
{
	IBaseAccessories* blockOnAccessories = _nextBlock->GetBlockOnObject()->GetAccessories();
	if (blockOnAccessories == nullptr) return;

	if (blockOnAccessories->GetType() == ACCESSORIES_TYPE::DUMP)
	{
		CleanDump();
	}
	else if (blockOnAccessories->GetType() == ACCESSORIES_TYPE::MOP)
	{
		SwitchToMop();
		_nextBlock->GetBlockOnObject()->HiddenAccessoriesFlg(true);
	}
}

void Doll::CleanDump()
{
	Dump* blockOnDump = dynamic_cast<Dump*>(_nextBlock->GetBlockOnObject()->GetAccessories());
	if ((!_heldMop && blockOnDump->GetDumpType() == DUMP_TYPE::WATER) ||
		(_heldMop && blockOnDump->GetDumpType() == DUMP_TYPE::DUST))return;

	_nextBlock->GetBlockOnObject()->HiddenAccessoriesFlg(true);
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

	//ゲームオーバー
	if (_dustDumpValue > 0)
	{
		_field->GameOver();
		_move = false;
	}
}

void Doll::EndMove() {
	_field->EndMoveDoll();
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

int Doll::AnimationRoop()
{
	return _motionCount = (_motionCount + 1) % 2;
}

void Doll::Render()
{
	_inversion ? _dollTexture.RenderScale(_dollPosition.x, _dollPosition.y, _scale, _inversionRenderRect) :
		_dollTexture.RenderScale(_dollPosition.x, _dollPosition.y, _scale, _renderRect);
}

void Doll::Release()
{
	_dollTexture.Release();
}

