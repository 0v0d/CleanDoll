#pragma once
#include    "IBaseScene.h"
#include    "Field.h"
#include    "InputInGame.h"
#include    "ContactFile.h"
#include "BackGround.h"
#include  "GameSceneBGM.h"
class GameScene :public IBaseScene
{
private:
    Field _field;
    BackGround _backGround;
    InputInGame _inputInGame;
    ContactFile* _contactFile;
    CTexture _gameBackTexture;
    GameSceneBGM _gameSceneBGM;
public:
    void SetContactFile(ContactFile* contactFile) { _contactFile = contactFile; }
    void Initialize();
    void ReLoad();
    void Update();
    void Render();
    void Release();
    void StopBGM();
};