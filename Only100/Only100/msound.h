#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <strsafe.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
void Tri_Sound(const char* szCommand);
bool Tes_Sound(const char* szCommand);
/*
 Tri_Sound("open y784.wav alias C", NULL);			��mci�豸�д�ĳһ�ļ���������ΪC
Tri_Sound("seek C to start", NULL);					��C���ò��Ž��ȵ���ͷ
Tri_Sound("play C", NULL);							����C
Tri_Sound("status C mode", szTimeBuffer);			���C�Ĳ��Ž��ȣ�����ֵΪ�ַ���stopped��playing
*/