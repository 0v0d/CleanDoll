#pragma once
#include    "IBaseScene.h"
#include    "Field.h"
#include    "FieldUI.h"
#include    "BackGround.h"
#include    "BGM.h"
#include    "Button.h"

class GameScene :public IBaseScene
{
    Field _field;
    FieldUI _fieldUI;
    BackGround _backGround;
    CTexture _gameBackTexture;
    BGM _bgm;
    CSoundBuffer _music,_buttonSe;

    Button _resetStageButton;
    CTexture _resetButtonTexture;
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
