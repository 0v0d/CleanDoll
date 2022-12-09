#pragma once
#include "Mof.h"
class EndGameButtonAnimation
{
    CTexture* _buttonAnimTexture;
    Vector2 _buttonAnimPos;
    CRectangle _buttonAnimRect;

    float _scaleValeu;
    bool _endAnimation;
public:
    void Initialize();
    void ReLoad();
    void Update();
    void Render();
    void Release();

    void SetStatu(Vector2 buttonAnimPos, CTexture* buttonAnimTexutre)
    {
        _buttonAnimTexture = buttonAnimTexutre;
        _buttonAnimPos = buttonAnimPos;
    }

    bool IsEndAnimation(){ return _endAnimation; }

};