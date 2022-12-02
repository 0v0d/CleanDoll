#pragma once
#include	"Mof.h"
#include	"map"
#include	"IBaseEndGameProcess.h"
#include	"GameClear.h"
#include	"GameOver.h"

enum class ProcessType {
	GameClear,
	GameOver
};

class EndGameProcess
{
	std::map<ProcessType, IBaseEndGameProcess*> _processArray;
	IBaseEndGameProcess* _currentProcess;

	GameClear _gameClear;
	GameOver _gameOver;

	bool _process;
public:
	void Initialize();
	void ReLoad();

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	
	void Render();
	void Release();

	void SetCurrentProcess(ProcessType type);

private:
	void CreateProcessArray();
};