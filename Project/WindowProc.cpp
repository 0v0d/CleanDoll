#include "WindowProc.h"


CWindowProc::CWindowProc() :
	CDefWindowProc() {
}

CWindowProc::~CWindowProc() {
}

MofProcResult CWindowProc::WindowProc(MofWindowHandle hWnd, MofUInt msg, MofProcParamW wpar, MofProcParamL lpar) {
	switch (msg)
	{
	case WM_CLOSE:
		_exitGame->OpenExitDialog();
		return TRUE;
	default:
		return  CDefWindowProc::WindowProc(hWnd, msg, wpar, lpar);
	}
	return  DefWindowProc(hWnd, msg, wpar, lpar);
}