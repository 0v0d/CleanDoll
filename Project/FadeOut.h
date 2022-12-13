#pragma once
class FadeOut
{
private:
	int		Alpha;
	bool	fadeOut;
	bool Change;

public:
	void Initialize();
	void Update();
	void Render();
	void GetOut() { fadeOut = true; }
	bool IsChange() { return Change; }
	bool ISEnd() { return fadeOut; }
};