#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <strsafe.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
void Tri_Sound(const char* szCommand);
bool Tes_Sound(const char* szCommand);
/*
 Tri_Sound("open y784.wav alias C", NULL);			在mci设备中打开某一文件，并命名为C
Tri_Sound("seek C to start", NULL);					将C设置播放进度到开头
Tri_Sound("play C", NULL);							播放C
Tri_Sound("status C mode", szTimeBuffer);			检查C的播放进度，返回值为字符串stopped和playing
*/