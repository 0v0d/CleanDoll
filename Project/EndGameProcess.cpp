#include "EndGameProcess.h"

void EndGameProcess::Initialize(){
	CreateProcessArray();

	_gameClear.Initialize();
	_gameOver.Initialize();
}

void EndGameProcess::CreateProcessArray() {
	_processArray[ProcessType::GameClear] = &_gameClear;
	_processArray[ProcessType::GameOver] = &_gameOver;
}

void EndGameProcess::ReLoad(){
	_gameClear.ReLoad();
	_gameOver.ReLoad();

	_process = false;
}

void EndGameProcess::Update(){
	if (!_process) return;
	_currentProcess->Update();
}

void EndGameProcess::SetMousePos(Vector2 mousePos){
	if (!_process) return;
	_currentProcess->SetMousePos(mousePos);
}

void EndGameProcess::Push(){
	if (!_process) return;
	_currentProcess->Push();
}

void EndGameProcess::Pull(){
	if (!_process) return;
	_currentProcess->Pull();
}

void EndGameProcess::SetCurrentProcess(ProcessType type) {
	_currentProcess = _processArray[type];
	_process = true;
}


void EndGameProcess::Render(){
	if (!_process) return;
	_currentProcess->Render();
}

void EndGameProcess::Release(){
	_gameClear.Release();
	_gameOver.Release();
}