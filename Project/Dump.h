#pragma once
#include	"Mof.h"
#include	"IBaseAccessories.h"

enum class DUMP_TYPE
{
	DUST,
	WATER
};

class Dump :public IBaseAccessories
{
private:
	CTexture* _dumpTexture;
	Vector2 _position;
	float _scale;

	ACCESSORIES_TYPE _accessoriesType = ACCESSORIES_TYPE::DUMP;
	DUMP_TYPE _dumpType;
public:
	Dump(CTexture* texture, DUMP_TYPE dumpType);
	void Initialize();
	void SetScale(float scale) { _scale = scale; }
	void Update();
	void Render();
	void Release();

	void SetPosotion(Vector2 pos);
	void SetDumpType(DUMP_TYPE dumpType) { _dumpType = dumpType; }
	ACCESSORIES_TYPE GetType() { return _accessoriesType; }
	DUMP_TYPE GetDumpType() { return _dumpType; }
};