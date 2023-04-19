#pragma once
#include <iostream>
#include <graphics.h>
#include<cstring>
#include"msound.h"
using namespace std;
class Dialog {
public:
	void InitDialog(int nn,int nx, int ny, string nt[10]); //预载对话框
	void loadDialog(int t, char k);				//加载对话
private:
	int x, y;						//记录对话框出现的坐标
	int n;							//记录对话顺序
	int t;							//记录显示的时间
	IMAGE pic_Dialog, pic_Dialogx;
	int num;						//记录对话进行到了第几局
	string txt_Dialog[10];			//记录10句对话
};