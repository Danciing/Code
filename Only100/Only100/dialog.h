#pragma once
#include <iostream>
#include <graphics.h>
#include<cstring>
#include"msound.h"
using namespace std;
class Dialog {
public:
	void InitDialog(int nn,int nx, int ny, string nt[10]); //Ԥ�ضԻ���
	void loadDialog(int t, char k);				//���ضԻ�
private:
	int x, y;						//��¼�Ի�����ֵ�����
	int n;							//��¼�Ի�˳��
	int t;							//��¼��ʾ��ʱ��
	IMAGE pic_Dialog, pic_Dialogx;
	int num;						//��¼�Ի����е��˵ڼ���
	string txt_Dialog[10];			//��¼10��Ի�
};