#pragma once
#include<graphics.h>
#include"DMap.h"
class Hero {
public:
	void InitHero(int nx, int ny);	//初始化英雄的坐标
	void loadHero();				//加载图片
	void HMove(char k, DMap a);				//控制横向移动
	void VMove(char k, DMap a);				//控制纵向移动
	void Flash_back(char k);		//使用回溯技能
	void Use_skill(char k);			//使用技能
	void Use_tool(char k);			//使用道具
	void Event();					//提示有事件可以触发，并作为触发器触发事件
	void hurt();					//受伤事件
	void idle();					//判断是否静止
	//int get_mapnum(Map a);			//获取Map上的二维数组值
private:
	int num_100 = 100;			//记录剩下的100点数
	int x, y;					//记录坐标
	int fx, fy;					//记录回溯坐标
	int Vspeed = 0;					//记录纵坐标速度
	int HPspeed = 5, VPspeed = 10;		//记录横纵坐标加速度
	int mark_skill = 0;				//记录技能
	int tool[3] = { 0,0,0 };				//记录道具
	int been_hurt = 0;					// 0记为可受伤，1~10数字下不受伤
	int num_pic;				//记录应加载的图片
	IMAGE pic_hero;				//记录主角原图片
	IMAGE pic_herox;			//记录主角掩码图
};