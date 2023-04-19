#include"dialog.h"
void Dialog::InitDialog(int nn, int nx, int ny, string nt[10]) {
	num = -1;
	n = nn;
	t = 0;
	x = nx;
	y = ny;
	for (int i = 0; i < 10; i++) {
		txt_Dialog[i] = nt[i];
	}
}
void Dialog::loadDialog(int p, char k)
{
	if (p != n && t == 0)return;
	if (k != 'f' && t == 0)return;
	//触发谈话
	if (p == n && k == 'f') {
		if (num < 9)num++;
		t = 0;
		Tri_Sound("seek C to start");
		Tri_Sound("play C");
	}
	//保持谈话10s
	t++;
	t %= 100;
	//掩码法加载背景对话框图片
	loadimage(&pic_Dialog, _T("dialog.png"));
	loadimage(&pic_Dialogx, _T("dialogx.png"));
	SetWorkingImage(&pic_Dialog);
	putimage(0, 0, &pic_Dialogx, SRCINVERT);
	SetWorkingImage(NULL);
	putimage(x-65, y-160, &pic_Dialogx, SRCAND);
	putimage(x-65, y-160, &pic_Dialog, SRCPAINT);
	//利用draw在矩形内加载文字
	RECT  r = { x -30 ,y -100,x + 95,y -20 };
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	settextcolor(RGB(80, 63, 62));
	drawtext(txt_Dialog[num].c_str(), &r, DT_CENTER | DT_WORDBREAK);
}