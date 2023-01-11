#include "Doll.h"
#include "Field.h"
#include "Dump.h"

void Doll::Initialize()
{
	_dollTexture.Load("doll.png");
	_field->SetDollMove(&_move);
	_broomAnimation.Initialize();
	_mopAnimation.Initialize();
	_dollTextureSize = Vector2(_dollTexture.GetWidth() / _textureValue, _dollTexture.GetHeight() /( _broomAnimation.GetMotionValue()+_mopAnimation.GetMotionValue()));
}

void Doll::ReLoad()
{
	_move = false;
	_moveCount = 0;
	_inversion = false;
	_holdMop = false;
	_animationflg = false;
	_getCoin = false;

	_mopAnimation.ReLoad();
	_broomAnimation.ReLoad();
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
	_inversion = _nextPosition.x > 0;

	_move = true;
	if (!_animationflg) {
		SetMoveAnimation();
	}
}

void Doll::SetNextPosition()
{
	_nextPosition.x = _nextBlock->GetCenterPosition().x - _dollPosition.x - _dollTextureSize.x * _scale / 2;
	_nextPosition.y = _nextBlock->GetCenterPosition().y - _dollPosition.y - _dollTextureSize.y * _scale;
}

void Doll::Update()
{
	if (_move) {
		Move();
	}

	DollAnimationUpdate();
	_holdMop ? _mopAnimation.WaitAnimation(): _broomAnimation.WaitAnimation();
}

void Doll::Move()
{
	if (_animationflg) return;

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
	if (!_animationflg) {
		_broomAnimation.SetMoveAnimationFlg(false);
		_mopAnimation.SetMoveAnimationFlg(false);
	}
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

	case ACCESSORIES_TYPE::ITEM:
		CollectCandy();
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
	if ((!_holdMop && blockOnDump->GetDumpType() == DUMP_TYPE::WATER) ||
		(_holdMop && blockOnDump->GetDumpType() == DUMP_TYPE::DUST))return;

	blockOnDump->CalucAlphaValue(_holdMop ? _mopAnimation.GetCleanTime() :_broomAnimation.GetCleanTime());
	blockOnDump->StartCleanflg(true);
	if (_holdMop) {
		_mopAnimation.StartCleanAnimation();
		_animationflg = true;
		_waterDumpValue--;
		_field->CleanWater();
	}
	else {
		_broomAnimation.StartCleanAnimation();
		_animationflg = true;
		_dustDumpValue--;
		_field->CleanDust();
	}
}

void Doll::CollectCandy()
{
	_holdMop? _mopAnimation.StartGetCandyAnimation():_broomAnimation.StartGetCandyAnimation();
	_animationflg = true;
}

void Doll::SwitchToMop()
{
	_holdMop = true;
	_mopAnimation.StartSwitchToMopAnimation();
	_animationflg = true;

	//ゲームオーバー
	if (_dustDumpValue > 0){
		_field->GameOver();
		_move = false;
	}
}

void Doll::DollAnimationUpdate()
{
	if (_animationflg && _broomAnimation.IsEndCurrentAnimation() || _animationflg && _mopAnimation.IsEndCurrentAnimation()) {
		_animationflg = false;
		SetMoveAnimation();
	}

	if(_holdMop){
		
		_mopAnimation.Update();
		_renderRect = _mopAnimation.GetRenderRect();
	}
	else{
		_broomAnimation.Update();
		_renderRect = _broomAnimation.GetRenderRect();
	}

	if (_inversion) {
		Inversion();
	}
}

void Doll::Inversion() {
	_inversionRenderRect = _renderRect;
	_inversionRenderRect.Right = _renderRect.Left;
	_inversionRenderRect.Left = _renderRect.Right;
}

void Doll::SetMoveAnimation() {
	_mopAnimation.SetMoveAnimationFlg(_move);
	_broomAnimation.SetMoveAnimationFlg(_move);
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