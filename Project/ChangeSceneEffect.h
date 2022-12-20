#pragma once
#include	"functional"
#include	"FadeIn.h"
#include	"FadeOut.h"

class ChangeSceneEffect
{
	FadeIn _fadeIn;
	FadeOut _fadeOut;
	std::function<void()> _changeSceneMethod;
public:
	void Initialize();
	void SetChangeSceneMethod(std::function<void()> method) { _changeSceneMethod = method; }
	void Update();
	void StartEffect();

	void Render();
	void Release();

	bool CheckEndEffect() { return _fadeOut.IsEnd()&&_fadeIn.IsEnd(); }
	bool CheckChangeScene() { return _fadeOut.IsEnd(); }
};