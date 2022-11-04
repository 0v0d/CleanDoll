#include "SliderBar.h"


void SliderBar::SetBarStatu(Vector2 barSize, Vector2 barPos)
{
	_barSize = barSize;
	_barPos = barPos;
	_barRect = CRectangle(_barPos.x, _barPos.y,
		_barPos.x + _barSize.x, _barPos.y + _barSize.y);
}

void SliderBar::Render()
{
	
	CGraphicsUtilities::RenderRect(_barRect, MOF_COLOR_GREEN);
}