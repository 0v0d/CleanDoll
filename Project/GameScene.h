#pragma once
#include    "IBaseScene.h"
#include    "Field.h"
#include    "FieldUI.h"
#include    "BackGround.h"
#include "BGM.h"

class GameScene :public IBaseScene
{
private:
    Field _field;
    FieldUI _fieldUI;
    BackGround _backGround;
    CTexture _gameBackTexture;
    BGM _bgm;
    CSoundBuffer _music;
public:
    void Initialize();
    void ReLoad();

    void Update();
    void SetMousePos(Vector2);
    void Push();
    void Pull();

    void Render();
    void Release();
    void StopBGM();
    Field* GetField() { return &_field; }
};
