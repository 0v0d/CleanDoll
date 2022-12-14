#pragma once
#include    "IBaseScene.h"
#include    "Field.h"
#include    "FieldUI.h"
#include    "BackGround.h"
#include    "BGM.h"
#include "TutorialScene.h"

class GameScene :public IBaseScene
{
    Field _field;
    FieldUI _fieldUI;
    BackGround _backGround;
    CTexture _gameBackTexture;
    BGM _bgm;
    CSoundBuffer _music;
    TutorialScene _tutorial;
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
 
private:
    void LoadTexture();
};
