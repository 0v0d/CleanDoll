#include "OpenSetting.h"

void OpenSetting::Initialize()
{
	_openSettingPosition = Vector2(1920-100, 50);
	_size = Vector2(50, 50);

	_openSettingButton =
		CRectangle(_openSettingPosition.x, _openSettingPosition.y, _openSettingPosition.x + _size.x, _openSettingPosition.y + _size.y);
}

void OpenSetting::Render()
{
	CGraphicsUtilities::RenderFillRect(_openSettingButton, MOF_COLOR_HGREEN);
}

void OpenSetting::Release()
{

}