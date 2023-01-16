#include "Dump.h"

Dump::Dump(CTexture* texture, DUMP_TYPE dumpType) :
	_dumpTexture(texture),
	_dumpType(dumpType)
{
}

void Dump::Initialize()
{

}

void Dump::ReLoad()
{
	_clean = false;
	_alpha = 255;
}

void Dump::SetPosotion(Vector2 pos)
{
	_position.x = pos.x - _dumpTexture->GetWidth() * _scale / 2;
	_position.y = pos.y - _dumpTexture->GetHeight() * _scale;
}

void Dump::Update()
{
	if (_clean)
	{
		_alpha -= _cleanTime;
		if (_alpha <= 0+_cleanTime)
		{
			_alpha = 0;
			_clean = false;
		}
	}
}

void Dump::Render()
{
	_dumpTexture->RenderScale(_position.x, _position.y, _scale, MOF_ARGB(_alpha, 255, 255, 255));
}

void Dump::Release()
{

}