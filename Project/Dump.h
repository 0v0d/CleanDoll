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
	uint8_t _alpha;
	const uint8_t _maxAlphaValue = 255; 
	float _cleanTime;
	bool _clean;
public:
	Dump(CTexture* texture, DUMP_TYPE dumpType);
	void Initialize();
	void ReLoad();
	void CalcuScale(float blockSizeX) { _scale = blockSizeX / _dumpTexture->GetWidth(); }
	void Update();
	void Render();
	void Release();
	
	void SetPosotion(Vector2 pos);
	void CalucAlphaValue(float cleanTime) { _cleanTime = cleanTime /_maxAlphaValue; }
	void StartCleanflg(bool flg) { _clean = flg; }
	void SetDumpType(DUMP_TYPE dumpType) { _dumpType = dumpType; }
	ACCESSORIES_TYPE GetType() { return _accessoriesType; }
	DUMP_TYPE GetDumpType() { return _dumpType; }
};