#include "Dump.h"

Dump::Dump(CTexture* texture, DUMP_TYPE dumpType) :
	_dumpTexture(texture),
	_dumpType(dumpType)
{
}

void Dump::Initialize(){

}

void Dump::SetPosotion(Vector2 pos) {
	_position.x = pos.x - _dumpTexture->GetWidth() * _scale / 2;
	_position.y = pos.y - _dumpTexture->GetHeight() * _scale / 2;
}

void Dump::Update(){

}

void Dump::Render(){
	_dumpType == DUMP_TYPE::DUST ? _dumpTexture->RenderScale(_position.x, _position.y, _scale) : _dumpTexture->RenderScale(_position.x, _position.y, _scale, MOF_COLOR_BLUE);
}

void Dump::Release(){

}