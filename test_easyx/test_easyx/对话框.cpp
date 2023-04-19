#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include<cstring>
#include"msound.h"
using namespace std;
class Dialog {
public:
	Dialog(int nx, int ny, string nt[10]);
	void loadDialog(char k);				//加载对话
private:
	int x, y;						//记录对话框出现的坐标
	int t;							//记录显示的时间
	IMAGE pic_Dialog, pic_Dialogx;
	int num;						//记录对话进行到了第几局
	string txt_Dialog[10];			//记录10句对话
};
Dialog::Dialog(int nx, int ny, string nt[10]) {
	num = -1;
	t = 0;
	x = nx;
	y = ny;
	for (int i = 0; i < 10; i++) {
		txt_Dialog[i] = nt[i];
	}
}
void Dialog::loadDialog(char k) 
{
	if (k != 'f' && t == 0)return;
	if (k == 'f') {
		if(num<9)num++;
		t = 0;
		Tri_Sound("seek C to start", NULL);
		Tri_Sound("play C", NULL);
	}
	t++;
	t %= 100;
	//掩码法加载图片
	loadimage(&pic_Dialog, _T("dialog.png"));
	loadimage(&pic_Dialogx, _T("dialogx.png"));
	SetWorkingImage(&pic_Dialog);
	putimage(0, 0, &pic_Dialogx, SRCINVERT);
	SetWorkingImage(NULL);
	putimage(x, y, &pic_Dialogx, SRCAND);
	putimage(x, y, &pic_Dialog, SRCPAINT);
	//利用draw在矩形内加载文字
	RECT  r = { x+35,y+60,x+160,y+140 };
	setbkmode(TRANSPARENT);
	settextstyle(16, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	settextcolor(RGB(80, 63, 62));
	drawtext(txt_Dialog[num].c_str(), &r, DT_CENTER | DT_WORDBREAK);
}
int c3main() {
	initgraph(1280, 720);
	IMAGE D;
	loadimage(&D, _T("1.jpg"));
	string b[10];
	for (int i = 0; i < 10; i++) {
		b[i] = "It's 23:47 now. I can't believe I have been studying for hours. You know what? No more than 4 hours before!";
	}
	Dialog a(0, 0, b);
	char fk[100];
	char k=0;
	Tri_Sound("open 15029.wav alias B", NULL);
	Tri_Sound("play B", NULL);
	Tri_Sound("open dialog.wav alias C", NULL);
	BeginBatchDraw();
	while (1) {
		cleardevice();
		k = 0;
		putimage(0, 0, &D, SRCPAINT);
		if (_kbhit())
			k = _getch();
		a.loadDialog(k);
		FlushBatchDraw();
		Tri_Sound("status B mode", fk);
		if (fk[0] == 's') {
			Tri_Sound("seek B to start", NULL);
			Tri_Sound("play B", NULL);
		}
		Sleep(100);
	}
	EndBatchDraw();
	getchar();
	closegraph();
	return 0;
}