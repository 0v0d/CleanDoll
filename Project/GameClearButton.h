#pragma once
#include "Button.h"

class GameClearButton
{
	Button _button;
	CTexture _clearButtonTexture;
	CSoundBuffer _buttonSe;
	bool _pull;
	bool _show;
	int _waterValue;
	int _dustValue;
public:
	void Initialize();
	void ReLoad();
	void Pull();
	void Push();
	void Update();
	void Render();
	void Release();
	void SetMousePos(Vector2 mousePos);
	void SetDustValue(int dumpValue) { _dustValue = dumpValue; }
	void SetWaterValue(int dumpValue) { _waterValue = dumpValue; }
	void CleanDust() { _dustValue--; }
	void CleanWater() { _waterValue--; }
	bool IsPull() const{ return _pull; }
private:
	void Load();
	void CreateButton();
};
