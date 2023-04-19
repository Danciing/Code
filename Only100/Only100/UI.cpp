#include"UI.h"
void BGM() {//播放音乐
	mciSendString("open music.wma", 0, 0, 0);
	mciSendString("play music.wma repeat", 0, 0, 0);//关闭音乐用flag
}
int initGame() {
	//BGM();
	IMAGE back, button, buttonx, t1, t2, t1x, t2x,t,tx;
	loadimage(&back, "Tietle_back.png");//背景图片
	int p = 1;
	char k=0;
	for (int i = 0; i <= 257;i++)//不断处理事务
	{
		cleardevice();
		if (_kbhit()) {
			k = _getch();
			if (k == 'w') {
				if (p >= 2) {
					Tri_Sound("seek button to start");
					Tri_Sound("play button");
					p--;
				}
			}
			if (k == 's') {
				if (p <= 2) {
					Tri_Sound("seek button to start");
					Tri_Sound("play button");
					p++;
				}
			}
			if (k == 'k') {
				return p%3;
			}
		}

		loadimage(&t, _T("Tangle.png"));
		loadimage(&tx, _T("Tanglex.png"));
		SetWorkingImage(&t);
		putimage(0, 0, &tx, SRCINVERT);
		

		loadimage(&button, _T("Tietle_button.png"));
		loadimage(&buttonx, _T("Tietle_buttonx.png"));
		SetWorkingImage(&button);
		putimage(0, 0, &buttonx, SRCINVERT);
		loadimage(&t1, _T("Tietle1.png"));
		loadimage(&t1x, _T("Tietle1x.png"));
		SetWorkingImage(&t1);
		putimage(0, 0, &t1x, SRCINVERT);
		loadimage(&t2, _T("Tietle2.png"));
		loadimage(&t2x, _T("Tietle2x.png"));
		SetWorkingImage(&t2);
		putimage(0, 0, &t2x, SRCINVERT);

		SetWorkingImage(NULL);
		putimage(0, 0, &back);
		putimage(1280 - i * 10, 0, &t2x, SRCAND);
		putimage(1280 - i * 10, 0, &t2, SRCPAINT);
		if (1280 - i * 10 >= 0) {
			putimage(0 - i * 10, 0, &t1x, SRCAND);
			putimage(0 - i * 10, 0, &t1, SRCPAINT);
		}
		else {
			putimage(2560 - i * 10, 0, &t1x, SRCAND);
			putimage(2560 - i * 10, 0, &t1, SRCPAINT);
		}
		
		if (i == 110 || i == 112 || i ==117) {
			putimage(-60, 0, &button, SRCPAINT);
			switch (p) {
			case 1:
				putimage(420, 332, &t, SRCPAINT);
				break;
			case 2:
				putimage(420, 415, &t, SRCPAINT);
				break;
			case 3:
				putimage(420, 500, &t, SRCPAINT);
				break;
			}
		}
		else if(i == 113 || i == 115) {
			putimage(60, 0, &button, SRCPAINT);

			switch (p) {
			case 1:
				putimage(540, 332, &t, SRCPAINT);
				break;
			case 2:
				putimage(540, 415, &t, SRCPAINT);
				break;
			case 3:
				putimage(540, 500, &t, SRCPAINT);
				break;
			}
		}
		else if(i != 112 && i!= 114 && i != 116) {
			putimage(0, 0, &buttonx, SRCAND);
			putimage(0, 0, &button, SRCPAINT);

			switch (p) {
			case 1:
				putimage(480, 332, &tx, SRCAND);
				putimage(480, 332, &t, SRCPAINT);
				break;
			case 2:
				putimage(480, 415, &tx, SRCAND);
				putimage(480, 415, &t, SRCPAINT);
				break;
			case 3:
				putimage(480, 500, &tx, SRCAND);
				putimage(480, 500, &t, SRCPAINT);
				break;
			}
		}
		FlushBatchDraw();
		Sleep(50);
		i %= 256;
	}
	return 1;
}
bool pauseGame() {
	IMAGE pause, t, tx;
	char k = 0;
	int p = 1;
	loadimage(&pause, _T("Pause.jpg"));
	Tri_Sound("seek button to start");
	Tri_Sound("play button");
	while (1) {
		if (_kbhit()) {
			k = _getch();
			if (k == 'w') {
				if (p == 2) {
					Tri_Sound("seek button to start");
					Tri_Sound("play button");
					p--;
				}
			}
			if (k == 's') {
				if (p == 1) {
					Tri_Sound("seek button to start");
					Tri_Sound("play button");
					p++;
				}
			}
			if (k == 'k') {
				return p % 2;
			}
			if (k == 27) {
				return 1;
			}
		}
		putimage(359, 148, &pause);
		loadimage(&t, _T("Tangle.png"));
		loadimage(&tx, _T("Tanglex.png"));
		SetWorkingImage(&t);
		putimage(0, 0, &tx, SRCINVERT);
		SetWorkingImage(NULL);
		switch (p) {
		case 1:
			putimage(489, 350, &tx, SRCAND);
			putimage(489, 350, &t, SRCPAINT);
			break;
		case 2:
			putimage(489, 432, &tx, SRCAND);
			putimage(489, 432, &t, SRCPAINT);
			break;
		}
		FlushBatchDraw();
	}
}
void turning() {
	IMAGE wb1, wb2, wbx, wb3, back;
	loadimage(&back, "Tietle_back.png");
	Tri_Sound("seek turn to start");
	Tri_Sound("play turn");
	for (int i = 1; i <= 9; i++) {
		cleardevice();		
		if (i <= 2) {
			putimage(0, 0, &back);
			loadimage(&wb1, _T("WB1.png"));
			loadimage(&wbx, _T("WBx.png"));
			SetWorkingImage(&wb1);
			putimage(0, 0, &wbx, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(0, 0, &wb1, SRCPAINT);
		}
		else if (i <= 4) {
			putimage(0, 0, &back);
			loadimage(&wb2, _T("WB2.png"));
			loadimage(&wbx, _T("WBx.png"));
			SetWorkingImage(&wb2);
			putimage(0, 0, &wbx, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(0, 0, &wb2, SRCPAINT);
		}
		else {
			putimage(0, 0, &back);
			loadimage(&wb3, _T("WB3.png"));
			loadimage(&wbx, _T("WBx.png"));
			SetWorkingImage(&wb3);
			putimage(0, 0, &wbx, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(0, 0, &wb3, SRCPAINT);
			
		}
		FlushBatchDraw();
		Sleep(50);
	}
}
void bturning() {
	IMAGE wb1, wb2, wbx, wb3, back;
	loadimage(&back, "Tietle_back.png");
	Tri_Sound("seek turn to start");
	Tri_Sound("play turn");
	for (int i = 9; i >= 1; i--) {
		cleardevice();
		if (i <= 2) {
			putimage(0, 0, &back);
			loadimage(&wb1, _T("WB1.png"));
			loadimage(&wbx, _T("WBx.png"));
			SetWorkingImage(&wb1);
			putimage(0, 0, &wbx, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(0, 0, &wb1, SRCPAINT);
		}
		else if (i <= 7) {
			putimage(0, 0, &back);
			loadimage(&wb2, _T("WB2.png"));
			loadimage(&wbx, _T("WBx.png"));
			SetWorkingImage(&wb2);
			putimage(0, 0, &wbx, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(0, 0, &wb2, SRCPAINT);
		}
		else {
			putimage(0, 0, &back);
			loadimage(&wb3, _T("WB3.png"));
			loadimage(&wbx, _T("WBx.png"));
			SetWorkingImage(&wb3);
			putimage(0, 0, &wbx, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(0, 0, &wb3, SRCPAINT);

		}
		FlushBatchDraw();
		Sleep(50);
	}
}
void First_show() {
	cleardevice();
	string txt = "Where is your limitation, wiht only 100?";
	setbkmode(TRANSPARENT);
	settextstyle(72, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	settextcolor(RGB(255, 255, 255));
	outtextxy(110, 110, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "Dare you challenge yourself?";
	outtextxy(270, 510, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	settextcolor(RGB(96, 96, 96));
	txt = "Why not?";
	outtextxy(160, 310, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "I am born for challenge.";
	outtextxy(180, 450, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	settextstyle(100, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	txt = "I will aim at the idol.";
	outtextxy(400, 310, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "This is my choice.";
	outtextxy(550, 610, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "I will aim at the idol.";
	outtextxy(50, 200, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "This is my choice.";
	outtextxy(70, 360, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "I will aim at the idol.";
	outtextxy(120, 0, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "This is my choice.";
	outtextxy(40, 600, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding");
	Sleep(1500);
	txt = "I will aim at the idol.";
	outtextxy(810, 99, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding");
	Sleep(1500);
	txt = "This is my choice.";
	outtextxy(630, 350, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding");
	Sleep(1000);
	txt = "I will aim at the idol.";
	outtextxy(280, 190, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding");
	Sleep(1000);
	txt = "This is my choice.";
	outtextxy(735, 429, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding");
	Sleep(800);
	cleardevice();
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	while(_kbhit())
		_getch();
}
void EndGame() {
	Hero a;
	IMAGE back, t1, t2, t1x, t2x;
	loadimage(&back, "Tietle_back.png");//背景图片
	char k = 0;
	for (int i = 0; i <= 257; i++)//不断处理事务
	{
		cleardevice();
		loadimage(&t1, _T("Tietle1.png"));
		loadimage(&t1x, _T("Tietle1x.png"));
		SetWorkingImage(&t1);
		putimage(0, 0, &t1x, SRCINVERT);
		loadimage(&t2, _T("Tietle2.png"));
		loadimage(&t2x, _T("Tietle2x.png"));
		SetWorkingImage(&t2);
		putimage(0, 0, &t2x, SRCINVERT);

		SetWorkingImage(NULL);
		putimage(0, 0, &back);
		putimage(1280 - i * 10, 0, &t2x, SRCAND);
		putimage(1280 - i * 10, 0, &t2, SRCPAINT);
		if (1280 - i * 10 >= 0) {
			putimage(0 - i * 10, 0, &t1x, SRCAND);
			putimage(0 - i * 10, 0, &t1, SRCPAINT);
		}
		else {
			putimage(2560 - i * 10, 0, &t1x, SRCAND);
			putimage(2560 - i * 10, 0, &t1, SRCPAINT);
		}
		a.HMove();
		a.loadHero();
		FlushBatchDraw();
		Sleep(50);
		i %= 256;
		if (_kbhit()) {
			_getch();
			return;
		}
	}
}
void myEnd() {
	cleardevice();
	string txt = "Aiming at the idol was his choice.";
	setbkmode(TRANSPARENT);
	settextstyle(72, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	settextcolor(RGB(255, 255, 255));
	outtextxy(205, 110, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "Rather than that,";
	outtextxy(400, 310, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	txt = "Staying here with you is my choice.";
	outtextxy(180, 510, txt.c_str());
	FlushBatchDraw();
	Tri_Sound("seek ding to start");
	Tri_Sound("play ding wait");
	while (1) {
		if (_kbhit()) {
			_getch();
			return;
		}
	}
}
ball::ball(int nx, int ny, int nhy, int nly) :x(nx), y(ny), hy(nhy), ly(nly) {

}
void ball::loadball(DMap& m) {
	loadimage(&pic, _T("ball.png"));
	loadimage(&picx, _T("ballx.png"));
	SetWorkingImage(&pic);
	putimage(0, 0, &picx, SRCINVERT);
	SetWorkingImage(NULL);
	putimage(x, y, &picx, SRCAND);
	putimage(x, y, &pic, SRCPAINT);
	if (k) {
		
		for (int i = x + 10; i <= x + 20; i++) {
			for (int j = y; j <= y + 30; j++) {
				m.num[i][j] = 0;
			}
		}
		for (int i = x + 10; i <= x + 20; i++) {
			for (int j = y + 10; j <= y + 40; j++) {
				m.num[i][j] = 11;
			}
		}
		y += 10;
	}
	else {
		for (int i = x + 10; i <= x + 20; i++) {
			for (int j = y; j <= y + 30; j++) {
				m.num[i][j] = 0;
			}
		}
		for (int i = x + 10; i <= x + 20; i++) {
			for (int j = y - 10; j <= y + 20; j++) {
				m.num[i][j] = 11;
			}
		}
		y -= 10;
	}
	if (y >= ly || y <= hy) {
		k = !k;
	}
}
sword::sword(int nx, int ny) :x(nx), y(ny) {

}
void sword::loadsword(DMap& m, Hero& a) {
	loadimage(&pic, _T("sword.png"));
	loadimage(&picx, _T("swordx.png"));
	SetWorkingImage(&pic);
	putimage(0, 0, &picx, SRCINVERT);
	SetWorkingImage(NULL);
	putimage(x, y, &picx, SRCAND);
	putimage(x, y, &pic, SRCPAINT);
	int t = 20;
	if (k == 2) {
		return;
	}
	if (k == 0 &&a.come(x)) {
		k = 1;
	}
	if (k == 1) {
		for (int i = 20; i >= 0; i--) {
			if (m.num[x][y + 41 + i] == 1) {
				t= i - 1;
				k = 2;
			}
		}
		y += t;
		for (int i = x + 3; i <= x + 7; i++) {
			for (int j = y + 20; j <= y + 40; j++) {
				m.num[i][j] = 0;
			}
		}
		for (int i = x + 3; i <= x + 7; i++) {
			for (int j = y + 20 + t; j <= y + 40 + t; j++) {
				m.num[i][j] = 11;
			}
		}
	}
	
}