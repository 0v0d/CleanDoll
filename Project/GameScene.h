#pragma once
#include    "IBaseScene.h"
#include    "Field.h"
#include    "InputInGame.h"
#include    "ContactFile.h"
#include    "Menu.h"
#include "BackGround.h"

class GameScene :public IBaseScene
{
private:
    Field _field;
    BackGround _backGround;
    InputInGame _inputInGame;
    ContactFile* _contactFile;
    Menu* _menu;
    CTexture _gameBackTexture;
public:
    void SetContactFile(ContactFile* contactFile) { _contactFile = contactFile; }
    void SetMenu(Menu* menu) { _menu = menu; }
    void Initialize();
    void ReLoad();
    void Update();
    void Render();
    void Release();

};