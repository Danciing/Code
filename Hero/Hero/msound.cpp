#include"msound.h"
void Tri_Sound(const char* szCommand, char* szbuffer)
{
	if (NULL == szbuffer)
	{
		mciSendString(szCommand, NULL, 0, NULL);				//��������������Ŀ->�����У���������->�߼��У��ַ���ѡ����ֽ��ַ���
	}
	else
	{
		mciSendString(szCommand, szbuffer, 1024, NULL);
	}
}