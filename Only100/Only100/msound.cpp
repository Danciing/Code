#include"msound.h"
void Tri_Sound(const char* szCommand)
{
		mciSendString(szCommand, NULL, 0, NULL);				//如若报错，请在项目->属性中，配置属性->高级中，字符集选择多字节字符集
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