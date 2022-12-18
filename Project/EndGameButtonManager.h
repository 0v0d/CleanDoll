#pragma once
#include	"Mof.h"
#include	"functional"
#include	"map"
#include	"Button.h"
#include	"EndGameButtonAnimation.h"

class EndGameButtonManager
{
	std::vector<std::pair<Button*, std::function<void()>>*> _buttonArray;
	std::vector<EndGameButtonAnimation*> _animationArray;
public:

	void Initialize();
	void ReLoad();
	void CreateButton(CTexture*, float sizeX, float sizeY, Vector2 centerPos,std::function<void()>);
	
	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	
	void Render();
	void Release();

	bool IsEndAnimation();
};