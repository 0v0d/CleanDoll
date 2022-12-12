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
    void SetStatu(Vector2 buttonAnimPos, CTexture* buttonAnimTexutre);
    void Update();
    void Render();

    bool IsEndAnimation(){ return _endAnimation; }

private:
    void UpdateAnimation();
};