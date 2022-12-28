#pragma once
#include	"functional"
#include	"SideIn.h"
#include	"SideOut.h"

class ChangeSceneEffect
{
	SideIn _sideIn;
	SideOut _sideOut;
	std::function<void()> _changeSceneMethod;
public:
	void Initialize();
	void SetChangeSceneMethod(std::function<void()> method) { _changeSceneMethod = method; }
	void Update();
	void StartEffect();

	void Render();
	void Release();

	bool CheckEndEffect() { return _sideOut.IsEnd()&& _sideIn.IsEnd(); }
	bool CheckChangeScene() { return _sideOut.IsEnd(); }
};