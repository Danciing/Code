#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
void Tri_Sound(const char* szCommand, char* szbuffer)
{
	if (NULL == szbuffer)
	{
		mciSendString(szCommand, NULL, 0, NULL);
	}
	else
	{
		mciSendString(szCommand, szbuffer, 1024, NULL);
	}
}

int xx2main(void)
{
	char szTimeBuffer[1024];
	Tri_Sound("open 15029.wav alias B", NULL);
	Tri_Sound("open dialog.wav alias C", NULL);
	//Tri_Sound("play C", NULL);
	while (1) {												//repeat
		Tri_Sound("status B mode", szTimeBuffer);
		if (szTimeBuffer[0] == 's') {
			Tri_Sound("seek B to start", NULL);
			Tri_Sound("play B", NULL);
		}
	}
}
