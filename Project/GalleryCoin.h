#pragma once
#include    "IBaseAccessories.h"
class GalleryCoin :public IBaseAccessories
{
    CTexture _coinTexture;
    Vector2 _coinPos;
    float _coinScale;

    CTexture _coinShadowTexture;
    Vector2 _coinShadowPos;
    float _coinShadowScale;
    uint8_t  _alpha;

    float _time;
    float _incPosY;

    ACCESSORIES_TYPE _accessoriesType;
public:
    GalleryCoin(ACCESSORIES_TYPE accessoriesType);
    void Initialize();
    void LoadTexture();
    void ReLoad();
    void Update();
    void Render();
    void Release();
    void SetPosotion(Vector2 pos);
    void CalcuScale(float blockSizeX);
    ACCESSORIES_TYPE GetType() { return _accessoriesType; }
private:
    void CalcPosY();
    void CalcAlpha();
};