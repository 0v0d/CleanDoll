#include "SliderBar.h"


void SliderBar::SetBarStatu(CTexture* barTexture, Vector2 barPos)
{
	const int calcSize = 20;
	_barTexture = barTexture;
	_barSize = Vector2(barTexture->GetWidth(),barTexture->GetHeight());
	_barPos = Vector2(barPos.x - _barSize.x / 2, barPos.y - _barSize.y / 2);
	_renderRect = CRectangle(_barPos.x, _barPos.y,
		_barPos.x + _barSize.x, _barPos.y + _barSize.y);
	_barRect = CRectangle(_barPos.x - calcSize, _barPos.y - calcSize,
		_barPos.x + _barSize.x + calcSize, _barPos.y + _barSize.y + calcSize);
}

void SliderBar::Render()
{
	_barTexture->Render(_renderRect);
	//CGraphicsUtilities::RenderRect(_barRect, MOF_COLOR_GREEN);
}