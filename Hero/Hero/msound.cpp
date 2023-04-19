#include"msound.h"
void Tri_Sound(const char* szCommand, char* szbuffer)
{
	if (NULL == szbuffer)
	{
		mciSendString(szCommand, NULL, 0, NULL);				//如若报错，请在项目->属性中，配置属性->高级中，字符集选择多字节字符集
	}
	else
	{
		mciSendString(szCommand, szbuffer, 1024, NULL);
	}
}