#pragma once
#include"DMap.h"
class Hero {
public:
	void InitHero(int nx, int ny);	//初始化英雄的坐标
	void loadHero();				//加载图片
	void HMove(char k, DMap a);				//控制横向移动
	void HMove();
	void VMove(char k, DMap a);				//控制纵向移动
	void Flash_back(char k);		//使用回溯技能
	int Event(DMap a);					//提示有事件可以触发，并作为触发器触发事件
	void hurt(DMap a);					//受伤事件
	void idle(char k);					//判断是否静止
	void show_100();					//展示如今剩下的点数
	void die();
	void sit();
	int num_100;			//记录剩下的100点数
	int mark_skill = 1;				//记录技能
	int tool[3] = { 0,0,0 };				//记录道具
	int sx, sy;					//记录起点坐标
	bool come(int tx);
private:
	int x, y;					//记录坐标
	int fx, fy, fn;					//记录回溯坐标与值
	int Vspeed = 0;					//记录纵坐标速度
	int HPspeed = 10, VPspeed = 10;		//记录横纵坐标加速度
	int been_hurt = 0;					// 0记为可受伤，1~20数字下不受伤
	int num_pic=0;				//记录应加载的图片
	IMAGE pic_hero;				//记录主角原图片
	IMAGE pic_herox;			//记录主角掩码图
	IMAGE pic_plant;			//记录假人图片
	IMAGE pic_plantx;			//记录假人掩码图
};
class Mei {
public:
	void loadMei(int x, int y);
private:
	IMAGE pic, picx;
};