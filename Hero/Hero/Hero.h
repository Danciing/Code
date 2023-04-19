#pragma once
#include<graphics.h>
#include"DMap.h"
class Hero {
public:
	void InitHero(int nx, int ny);	//��ʼ��Ӣ�۵�����
	void loadHero();				//����ͼƬ
	void HMove(char k, DMap a);				//���ƺ����ƶ�
	void VMove(char k, DMap a);				//���������ƶ�
	void Flash_back(char k);		//ʹ�û��ݼ���
	void Use_skill(char k);			//ʹ�ü���
	void Use_tool(char k);			//ʹ�õ���
	void Event();					//��ʾ���¼����Դ���������Ϊ�����������¼�
	void hurt();					//�����¼�
	void idle();					//�ж��Ƿ�ֹ
	//int get_mapnum(Map a);			//��ȡMap�ϵĶ�ά����ֵ
private:
	int num_100 = 100;			//��¼ʣ�µ�100����
	int x, y;					//��¼����
	int fx, fy;					//��¼��������
	int Vspeed = 0;					//��¼�������ٶ�
	int HPspeed = 5, VPspeed = 10;		//��¼����������ٶ�
	int mark_skill = 0;				//��¼����
	int tool[3] = { 0,0,0 };				//��¼����
	int been_hurt = 0;					// 0��Ϊ�����ˣ�1~10�����²�����
	int num_pic;				//��¼Ӧ���ص�ͼƬ
	IMAGE pic_hero;				//��¼����ԭͼƬ
	IMAGE pic_herox;			//��¼��������ͼ
};