#pragma once
#include "Mof.h"
class EndGameButtonAnimation
{
    CTexture* _buttonAnimTexture;
    Vector2 _buttonAnimPos;
    CRectangle _buttonAnimRect;

    float _scale, _targetScale;
    float _animationSpeed;
    bool _endAnimation;
public:
    void Initialize();
    void SetTexture(CTexture* buttonAnimTexutre);
    void CalcuTargetScale(float targetSizeY);
    void CalcuCenterPos(Vector2 buttonAnimCenterPos);
    void CalcuAnimationSpeed(int animationTime);
    void ReLoad();

    void Update();
    void Render();

    bool IsEndAnimation() { return _endAnimation; }

private:
    void UpdateAnimation();
    void CalcuButtonRect();
};