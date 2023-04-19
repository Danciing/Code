#pragma once
#include"Episode.h"
int initGame();
int menu();
void BGM();
bool pauseGame();
void turning();
void bturning();
void First_show();
void EndGame();
void myEnd();
class ball {
public:
	ball(int nx, int ny, int nhy, int nly);
	void loadball(DMap& m);
private:
	IMAGE pic, picx;
	int x, y;
	int hy, ly;
	bool k = 1;
};
class sword {
public:
	sword(int nx, int ny);
	void loadsword(DMap& m, Hero& a);
private:
	IMAGE pic, picx;
	int x, y;
	int k = 0;
};
