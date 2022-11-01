#include "Bar.h"

void Bar::Initialize()
{
	_screenPos = Vector2(g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
	_movePos.x = g_pGraphics->GetTargetWidth() * 0.25 - g_pGraphics->GetTargetWidth() * 0.2;
	_movePos.y = 0;

	_initializePosY = (_barSize.y + _space) * _stageNumber;
	_barHitBox = CRectangle
	(_movePos.x, _initializePosY - _movePos.y,
		_movePos.x + _barSize.x, _initializePosY - _movePos.y + _barSize.y);

	_maxPos = (_barSize.y + _space) * _stageValue;
	_screenEdge = CRectangle(0, 0, _screenPos.x, _screenPos.y);

}

void Bar::SetStatu(int stageNumber, std::string previewTextureName, std::string stageName, int difficulty, std::string stageDataTextName)
{
	_stageNumber = stageNumber;
	_previewTexture.Load(previewTextureName.c_str());
	_stageName = stageName;
	_difficulty = difficulty;
	_stageDataTextName = stageDataTextName;
}

void Bar::Move(float moveValue)
{
	_movePos.y = (_maxPos - g_pGraphics->GetTargetHeight()) / _maxValue* moveValue;

	_barHitBox = CRectangle
	(_movePos.x, _initializePosY - _movePos.y,
		_movePos.x + _barSize.x, _initializePosY - _movePos.y + _barSize.y);
}


void Bar::Render()
{
	if (IsRenderRange())
	{
		CGraphicsUtilities::RenderRect(_barHitBox, MOF_COLOR_YELLOW);
		_barTexture.Render(_barHitBox);
		CGraphicsUtilities::RenderString(_barHitBox.Left, _barHitBox.Top, "%d", _stageNumber + 1);
	}
}

void Bar::Release()
{
	_previewTexture.Release();
}