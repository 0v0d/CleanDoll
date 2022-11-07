#include "SliderBar.h"


void SliderBar::SetBarStatu(CTexture* barTexture, Vector2 barPos)
{
	_barTexture = barTexture;
	_barSize = Vector2(barTexture->GetWidth(),barTexture->GetHeight());
	_barPos = barPos;
	_barRect = CRectangle(_barPos.x, _barPos.y,
		_barPos.x + _barSize.x, _barPos.y + _barSize.y);
}

void SliderBar::Render()
{
	_barTexture->Render(_barRect);
	CGraphicsUtilities::RenderRect(_barRect, MOF_COLOR_GREEN);
}