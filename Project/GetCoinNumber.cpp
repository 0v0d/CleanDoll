#include "GetCoinNumber.h"

void GetCoinNumber::Initialize() {
	renderSizeX = coinnumberTexture.GetWidth() / 16;
	SetCoinNumberValue(0);
	
}

void GetCoinNumber::LoadTextrue() {
	coinnumberTexture.Load("GetCoinNumber.png");
}

void GetCoinNumber::SetPosition() {
	const int space = 20;

	//numberPos.x = g_pGraphics->GetTargetWidth() - coinnumberTexture.GetWidth() * _scale / 2;
	//numberPos.y = g_pGraphics->GetTargetHeight() - coinnumberTexture.GetHeight() * _scale / 2 + space;

	numberPos.x = 500;
	numberPos.y = 100;
}

void GetCoinNumber::SetCoinNumberValue(int value) {
	CoinNumberValue = value;


	ChangeCoinNumber(value);
}

void GetCoinNumber::ChangeCoinNumber(int coinnumbre) {
	renderRect = CRectangle(renderSizeX * coinnumbre, 0, renderSizeX * (coinnumbre + 1), coinnumberTexture.GetHeight());
}

void GetCoinNumber::Render() {
	coinnumberTexture.RenderScale(numberPos.x, numberPos.y, _scale, renderRect);
	CGraphicsUtilities::RenderString(0, 0, "%d", CoinNumberValue);
}

void GetCoinNumber::Release() {
	coinnumberTexture.Release();
}