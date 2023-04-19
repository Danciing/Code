#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <time.h>

using namespace std;
class bb {
public:
	void loadI();
	void putI();
private:
	IMAGE pic;
	int num=0;
};
void bb::loadI() {
	switch (num) {
		case 0:
			loadimage(&pic, _T("Knight_walk_01.png"));
			break;
		case 1:
			loadimage(&pic, _T("Knight_walk_02.png"));
			break;
		case 2:
			loadimage(&pic, _T("Knight_walk_03.png"));
			break;
		case 3:
			loadimage(&pic, _T("Knight_walk_04.png"));
			break;
		case 4:
			loadimage(&pic, _T("Knight_walk_05.png"));
			break;
		case 5:
			loadimage(&pic, _T("Knight_walk_06.png"));
			break;
	}
	putimage(-200, 400, &pic);
	num++;
	num %= 6;
}
void bb::putI() {
	putimage(0, 0, &pic);
	num++;
	num %= 3;
}
int main() {
	initgraph(1280, 720);
	bb a;
	char c;
	IMAGE back;
	loadimage(&back, _T("Map.01.png"));
	putimage(0, 0, &back);
	a.loadI();
	while (1) {
		if (_kbhit()) {
			c = _getch();       //∆Ê›‚£ø£ø£ø
			a.loadI();
		}
		Sleep(100);
	}
	closegraph();
	return 0;
}