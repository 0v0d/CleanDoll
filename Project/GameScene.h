#pragma once
#include	"IBaseScene.h"
#include	"Field.h"
#include	"InputInGame.h"
#include	"ContactFile.h"
#include	"Menu.h"

class GameScene :public IBaseScene
{
private:
	Field _field;
	InputInGame _inputInGaame;
	ContactFile* _contactFile;
	Menu* _menu;

public:
	void SetContactFile(ContactFile* contactFile) { _contactFile = contactFile; }
	void SetMenu(Menu* menu) { _menu = menu; }
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
};