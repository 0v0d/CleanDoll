#pragma once
#include	"Mof.h"

class SideIn
{
	const int _maxAlpha = 255;
	const int _blockValueX = 26;
	const int _blockValueY = 13;

	bool** _renderBlock;

	int _lineX, _backLine;
	const int _diffLine = 3;
	int _time, _count;
	const int _speed = 4;

	bool _end;

	CRandom _random;
public:

	SideIn();
	~SideIn();
	void Start();
	void Update();
	void Render();

	bool IsEnd() { return _end; }
	bool Check();

private:
	void SetBlock();
	void Sort();
};