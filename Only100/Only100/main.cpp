#include"UI.h"
#include <fstream>
int main() {
	int n;
	//��ȡ�浵
	ifstream save("Save.txt", ios::in); 
	save >> n;
	save.close();
	int t = 1;
	Hero a;
	DMap m;
	a.InitHero(0, 0);

	//��ǰ�������ļ����͸�mci�豸
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
	//������ͼ���ͼƬ��˸
	BeginBatchDraw();
	//���˵�
	while (t) {
		//�ؿ��ؿ�
		if (t == 4) {
			t = Episode(n, a, m);
			bturning();
			continue;
		}
		//ͨ�غ������һ�ؿ�
		if (t == 3) {
			m.InitMap(n);
			turning();
			t = Episode(n, a, m);
			bturning();
			continue;
		}
		t = initGame();

		if (t == 1) {
			//��ͷ̫��ʼ
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
			//������Ϸ
			m.InitMap(n);
			turning();
			t = Episode(n, a, m);
			bturning();
			continue;
		}
	}
	EndBatchDraw();
	closegraph();
	//д��浵
	ofstream dsave("Save.txt", ios::out);
	dsave << n;
	dsave.close();
	return 0;
}