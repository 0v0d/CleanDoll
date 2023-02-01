#include	"GameApp.h"
#include "resource.h"
#include "WindowProc.h"

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Mof::LPFramework pFrame = new Mof::CDX11GameFramework();
	Mof::WINDOWSGAMEFRAMEWORKINITIALIZEINFO Info;

	Info.WindowCreateInfo.Width = 1920;
	Info.WindowCreateInfo.Height = 1080;
	CGameApp* app = new CGameApp();
	Info.pApplication = app;
	Info.WindowCreateInfo.hIcon = ::LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	CWindowProc* proc = new CWindowProc();
	proc->SetExitGame(app->GetExitGame());
	Info.WindowCreateInfo.pProc = proc;
	Info.WindowCreateInfo.Title = "Clean Doll";
	//Info.WindowCreateInfo.Style = WS_POPUP;
	if (pFrame->Initialize(&Info))
	{
		pFrame->Run();
	}
	MOF_SAFE_DELETE(pFrame);
	return 0;
}