#pragma once
#include"DMap.h"
class Hero {
public:
	void InitHero(int nx, int ny);	//��ʼ��Ӣ�۵�����
	void loadHero();				//����ͼƬ
	void HMove(char k, DMap a);				//���ƺ����ƶ�
	void HMove();
	void VMove(char k, DMap a);				//���������ƶ�
	void Flash_back(char k);		//ʹ�û��ݼ���
	int Event(DMap a);					//��ʾ���¼����Դ���������Ϊ�����������¼�
	void hurt(DMap a);					//�����¼�
	void idle(char k);					//�ж��Ƿ�ֹ
	void show_100();					//չʾ���ʣ�µĵ���
	void die();
	void sit();
	int num_100;			//��¼ʣ�µ�100����
	int mark_skill = 1;				//��¼����
	int tool[3] = { 0,0,0 };				//��¼����
	int sx, sy;					//��¼�������
	bool come(int tx);
private:
	int x, y;					//��¼����
	int fx, fy, fn;					//��¼����������ֵ
	int Vspeed = 0;					//��¼�������ٶ�
	int HPspeed = 10, VPspeed = 10;		//��¼����������ٶ�
	int been_hurt = 0;					// 0��Ϊ�����ˣ�1~20�����²�����
	int num_pic=0;				//��¼Ӧ���ص�ͼƬ
	IMAGE pic_hero;				//��¼����ԭͼƬ
	IMAGE pic_herox;			//��¼��������ͼ
	IMAGE pic_plant;			//��¼����ͼƬ
	IMAGE pic_plantx;			//��¼��������ͼ
};
class Mei {
public:
	void loadMei(int x, int y);
private:
	IMAGE pic, picx;
};