#include"msound.h"
void Tri_Sound(const char* szCommand)
{
		mciSendString(szCommand, NULL, 0, NULL);				//��������������Ŀ->�����У���������->�߼��У��ַ���ѡ����ֽ��ַ���
}
bool Tes_Sound(const char* szCommand) {
	char tab[10];
	mciSendString(szCommand, tab, 1024, NULL);
	if (tab[0] == 's') {
		return 1;
	}
	else {
		return 0;
	}
}