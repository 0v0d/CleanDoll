#include "SideOut.h"

SideOut::SideOut() :
	_end(true),
	_time(1)
{
	_renderBlock = new bool* [_diffLine];
	for (int i = 0;i < _diffLine;i++) _renderBlock[i] = new bool[_blockValueY];
}

SideOut::~SideOut() {
	for (int i = 0;i < _diffLine;i++) delete[] _renderBlock[i];
	delete[] _renderBlock;
}

void SideOut::Start() {
	_end = false;
	_lineX = 0;
	_count = 0;

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _diffLine;x++) {
			_renderBlock[x][y] = false;
		}
	}
}

void SideOut::Update() {
	if (_end) return;

	_count++;
	if (_count < _time) return;

	for (int i = 0;i < _speed;i++) {
		SetBlock();
	}

	if (Check()) {
		_lineX++;
		Sort();

		if (_lineX > _blockValueX) {
			_end = true;
		}
	}
}

void SideOut::SetBlock() {
	for(int i=0;i<_blockValueY;i++){
		int rmdY = _random.Random(_blockValueY);

		for (int x = 0;x < _diffLine;x++) {
			if (!_renderBlock[x][rmdY]) {
				_renderBlock[x][rmdY] = true;
				_count = 0;
				return;
			}
		}
	}
}

bool SideOut::Check() {
	for (int i = 0;i < _blockValueY;i++) {
		if (!_renderBlock[0][i]) return false;
	}
	return true;
}

void SideOut::Sort() {
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 1;x < _diffLine;x++) {
			_renderBlock[x - 1][y] = _renderBlock[x][y];
		}
	}

	for (int y = 0;y < _blockValueY;y++) {
		_renderBlock[_diffLine - 1][y] = false;
	}
}

void SideOut::Render() {
	if (_end) return;
	Vector2 w = Vector2(g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _diffLine;x++) {
			if (!_renderBlock[x][y])break;
			CRectangle rect = CRectangle(w.x / _blockValueX * (_lineX + x), w.y / _blockValueY * y, w.x / _blockValueX * (_lineX + x + 1), w.y / _blockValueY * (y + 1));
			CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);
		}
	}

	CRectangle rect = CRectangle(0, 0, _lineX * w.x / _blockValueX, g_pGraphics->GetTargetHeight());
	CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);
}