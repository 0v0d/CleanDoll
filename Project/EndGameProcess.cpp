#include "EndGameProcess.h"

EndGameProcess::EndGameProcess() {
	_gameClear.SetGameClearAnimation(&_gameClearAnimation);
	_endTutorial.SetGameClearAnimation(&_gameClearAnimation);
}

void EndGameProcess::Initialize(){
	CreateProcessArray();
	_gameClearAnimation.Initialize();
	_gameClear.Initialize();
	_gameOver.Initialize();
	_endTutorial.Initialize();
}

void EndGameProcess::CreateProcessArray() {
	_processArray[ProcessType::GameClear] = &_gameClear;
	_processArray[ProcessType::GameOver] = &_gameOver;
	_processArray[ProcessType::EndTutorial] = &_endTutorial;
}

void EndGameProcess::ReLoad(){
	_gameClear.ReLoad();
	_gameOver.ReLoad();
	_endTutorial.ReLoad();
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
	_endTutorial.Release();
	_gameClearAnimation.Release();
}