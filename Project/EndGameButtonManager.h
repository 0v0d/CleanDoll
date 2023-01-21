#pragma once
#include	"Mof.h"
#include	"functional"
#include	"Button.h"
#include	"EndGameButtonAnimation.h"

class EndGameButtonManager
{
	std::vector<Button*> _buttonArray;
	std::vector<EndGameButtonAnimation*> _animationArray;
	CSoundBuffer _buttonSe;
public:

	void Initialize();
	void LoadSound();
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