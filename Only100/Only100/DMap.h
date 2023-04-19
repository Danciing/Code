#pragma once
#include"dialog.h"
#include<vector>
using namespace std;
class DMap {
	friend class ball;
	friend class sword;
public:
	DMap();
	int get_num(int x, int y);
	void InitMap(int n);
private:
	vector<vector<int>>num;
};
