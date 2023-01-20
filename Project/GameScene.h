#pragma once
#include    "IBaseScene.h"
#include    "Field.h"
#include    "FieldUI.h"
#include    "BackGround.h"
#include    "BGM.h"
#include    "Button.h"
#include    "GameStartAnimation.h"
#include    "SlideInUI.h"

class GameScene :public IBaseScene
{
    Field _field;
    FieldUI _fieldUI;
    BackGround _backGround;
    CTexture _gameBackTexture;
    CSoundBuffer _music,_buttonSe;
    Vector2 _resetButtonPos;
    float _slideInPos;
    GameStartAnimation _startAnimation;
    Button _resetStageButton;
    CTexture _resetButtonTexture;
    SlideInUI _slideInUI;
    bool _slideUI;

public:
    void Initialize();
    void ReLoad();

    void Update();
    void SetMousePos(Vector2);
    void Push();
    void Pull();

    void Render();
    void Release();

    Field* GetField() { return &_field; }
    CSoundBuffer* GetBGM() { return &_music; }
private:
    void LoadTexture();
    void LoadSound();
};
