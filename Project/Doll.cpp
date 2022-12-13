#include "Doll.h"
#include "Field.h"
#include "Dump.h"

void Doll::Initialize()
{
	_dollTexture.Load("doll.png");
	_field->SetDollMove(&_move);
	_animation.Initialize();
	_dollTextureSize = Vector2(_dollTexture.GetWidth() / _textureValue, _dollTexture.GetHeight() / _animation.GetMotionValue());
}

void Doll::ReLoad()
{
	_move = false;
	_moveCount = 0;
	_inversion = false;
	_heldMop = false;
	_cleanAnimation = false;
	_getCoin = false;

	_animation.ReLoad();
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
	if (!_cleanAnimation)_animation.SetMoveAnimationFlg(_move);
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
	if (_cleanAnimation) return;

	_dollPosition.x += _nextPosition.x / _moveSpeed;
	_dollPosition.y += _nextPosition.y / _moveSpeed;
	_moveCount++;

	//目的のマスに移動した
	if (_moveCount >= _moveSpeed)
	{
		_moveCount = 0;
		ActionAccessories();
		_endMoveMethod();
	}
}

//残りの移動マスが無い時に呼ばれる関数
void Doll::EndMove() {
	_field->EndMoveDoll();
	_move = false;
	if (!_cleanAnimation)_animation.SetMoveAnimationFlg(false);
}

void Doll::ActionAccessories()
{
	IBaseAccessories* blockOnAccessories = _nextBlock->GetBlockOnObject()->GetAccessories();
	if (blockOnAccessories == nullptr) return;

	switch (blockOnAccessories->GetType())
	{
	case ACCESSORIES_TYPE::DUMP:
		CleanDump();
		break;

	case ACCESSORIES_TYPE::MOP:
		SwitchToMop();
		_nextBlock->GetBlockOnObject()->HiddenAccessoriesFlg(true);
		break;

	case ACCESSORIES_TYPE::COIN:
		_getCoin = true;
		_field->GetCoin();
		_nextBlock->GetBlockOnObject()->HiddenAccessoriesFlg(true);
		break;
	}
}

void Doll::CleanDump()
{
	Dump* blockOnDump = dynamic_cast<Dump*>(_nextBlock->GetBlockOnObject()->GetAccessories());
	if ((!_heldMop && blockOnDump->GetDumpType() == DUMP_TYPE::WATER) ||
		(_heldMop && blockOnDump->GetDumpType() == DUMP_TYPE::DUST))return;
	
	blockOnDump->CalucAlphaValue(_animation.GetCleanTime());
	blockOnDump->StartCleanflg(true);
	if (_heldMop) {
		_waterDumpValue--;
		_field->CleanWater();
	}
	else {
		_dustDumpValue--;
		_field->CleanDust();
	}
	_animation.StartCleanAnimation();
	_cleanAnimation = true;
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

void Doll::DollAnimationUpdate()
{
	if (_cleanAnimation && _animation.IsEndCurrentAnimation()) {
		_cleanAnimation = false;
		_animation.SetMoveAnimationFlg(_move);
	}

	_animation.Update();
	_renderRect = _animation.GetRenderRect();

	if (_inversion)
	{
		_inversionRenderRect = _renderRect;
		_inversionRenderRect.Right = _renderRect.Left;
		_inversionRenderRect.Left = _renderRect.Right;
	}
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

