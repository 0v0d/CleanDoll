#pragma once
class IBaseScene
{
public:
	virtual void Initialize() = 0;
	virtual void ReLoad() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
	virtual void StopBGM() = 0;
};