#include"UI.h"
#include <fstream>
int main() {
	int n;
	//读取存档
	ifstream save("Save.txt", ios::in); 
	save >> n;
	save.close();
	int t = 1;
	Hero a;
	DMap m;
	a.InitHero(0, 0);

	//提前将声音文件发送给mci设备
	{
		Tri_Sound("open jump.mp3 alias jump");
		Tri_Sound("open walk_1.mp3 alias walk_1");
		Tri_Sound("open walk_2.mp3 alias walk_2");
		Tri_Sound("open flash.wav alias flash");
		Tri_Sound("open plant.wav alias plant");
		Tri_Sound("open hurt.wav alias hurt");
		Tri_Sound("open heart.wav alias heart");
		Tri_Sound("open turn.wav alias turn");
		Tri_Sound("open ding.mp3 alias ding");
		Tri_Sound("open button.mp3 alias button");
	}
	initgraph(1280, 720);
	//批量绘图解决图片闪烁
	BeginBatchDraw();
	//主菜单
	while (t) {
		//重开关卡
		if (t == 4) {
			t = Episode(n, a, m);
			bturning();
			continue;
		}
		//通关后继续下一关卡
		if (t == 3) {
			m.InitMap(n);
			turning();
			t = Episode(n, a, m);
			bturning();
			continue;
		}
		t = initGame();

		if (t == 1) {
			//从头太开始
			turning();
			First_show();
			n = 1;
			m.InitMap(n);
			turning();
			t = Episode(n, a, m);
			bturning();
			continue;
		}
		else if (t == 2) {
			//继续游戏
			m.InitMap(n);
			turning();
			t = Episode(n, a, m);
			bturning();
			continue;
		}
	}
	EndBatchDraw();
	closegraph();
	//写入存档
	ofstream dsave("Save.txt", ios::out);
	dsave << n;
	dsave.close();
	return 0;
}