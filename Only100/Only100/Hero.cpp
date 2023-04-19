#include"Hero.h"
void Hero::InitHero(int nx, int ny) {
	sx= x = nx;
	sy= y = ny;
	fx = 0;
	fy = 0;
	num_pic = 0;
	fn = num_100 = 100;
	been_hurt = 0;
}
void Hero::loadHero() {
	/*
		0 坐下
		1-6 静止
		11-16 行走
		21-22 受伤
		31-32 跳跃
		负数向左，正数向右
	*/
	if (been_hurt != 0 && been_hurt % 2 == 0) {
		return;
	}
	switch (num_pic) {
	case 0:
		loadimage(&pic_hero, _T("Knight_crouch_0.png"));
		loadimage(&pic_herox, _T("Knight_crouch_0x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 1:
		loadimage(&pic_hero, _T("Knight_idle_01.png"));
		loadimage(&pic_herox, _T("Knight_idle_01x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 2:
		loadimage(&pic_hero, _T("Knight_idle_02.png"));
		loadimage(&pic_herox, _T("Knight_idle_02x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 3:
		loadimage(&pic_hero, _T("Knight_idle_03.png"));
		loadimage(&pic_herox, _T("Knight_idle_03x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 4:
		loadimage(&pic_hero, _T("Knight_idle_04.png"));
		loadimage(&pic_herox, _T("Knight_idle_04x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 5:
		loadimage(&pic_hero, _T("Knight_idle_05.png"));
		loadimage(&pic_herox, _T("Knight_idle_05x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 6:
		loadimage(&pic_hero, _T("Knight_idle_06.png"));
		loadimage(&pic_herox, _T("Knight_idle_06x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 11:
		loadimage(&pic_hero, _T("Knight_walk_01.png"));
		loadimage(&pic_herox, _T("Knight_walk_01x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 12:
		loadimage(&pic_hero, _T("Knight_walk_02.png"));
		loadimage(&pic_herox, _T("Knight_walk_02x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 13:
		loadimage(&pic_hero, _T("Knight_walk_03.png"));
		loadimage(&pic_herox, _T("Knight_walk_03x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 14:
		loadimage(&pic_hero, _T("Knight_walk_04.png"));
		loadimage(&pic_herox, _T("Knight_walk_04x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 15:
		loadimage(&pic_hero, _T("Knight_walk_05.png"));
		loadimage(&pic_herox, _T("Knight_walk_05x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 16:
		loadimage(&pic_hero, _T("Knight_walk_06.png"));
		loadimage(&pic_herox, _T("Knight_walk_06x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 21:
		loadimage(&pic_hero, _T("Knight_hurt_01.png"));
		loadimage(&pic_herox, _T("Knight_hurt_01x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 22:
		loadimage(&pic_hero, _T("Knight_hurt_02.png"));
		loadimage(&pic_herox, _T("Knight_hurt_02x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 31:
		loadimage(&pic_hero, _T("Knight_jump_01.png"));
		loadimage(&pic_herox, _T("Knight_jump_01x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case 32:
		loadimage(&pic_hero, _T("Knight_jump_02.png"));
		loadimage(&pic_herox, _T("Knight_jump_02x.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -1:
		loadimage(&pic_hero, _T("Knight_idle_01l.png"));
		loadimage(&pic_herox, _T("Knight_idle_01lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -2:
		loadimage(&pic_hero, _T("Knight_idle_02l.png"));
		loadimage(&pic_herox, _T("Knight_idle_02lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -3:
		loadimage(&pic_hero, _T("Knight_idle_03l.png"));
		loadimage(&pic_herox, _T("Knight_idle_03lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -4:
		loadimage(&pic_hero, _T("Knight_idle_04l.png"));
		loadimage(&pic_herox, _T("Knight_idle_04lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -5:
		loadimage(&pic_hero, _T("Knight_idle_05l.png"));
		loadimage(&pic_herox, _T("Knight_idle_05lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -6:
		loadimage(&pic_hero, _T("Knight_idle_06l.png"));
		loadimage(&pic_herox, _T("Knight_idle_06lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -11:
		loadimage(&pic_hero, _T("Knight_walk_01l.png"));
		loadimage(&pic_herox, _T("Knight_walk_01lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -12:
		loadimage(&pic_hero, _T("Knight_walk_02l.png"));
		loadimage(&pic_herox, _T("Knight_walk_02lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -13:
		loadimage(&pic_hero, _T("Knight_walk_03l.png"));
		loadimage(&pic_herox, _T("Knight_walk_03lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -14:
		loadimage(&pic_hero, _T("Knight_walk_04l.png"));
		loadimage(&pic_herox, _T("Knight_walk_04lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -15:
		loadimage(&pic_hero, _T("Knight_walk_05l.png"));
		loadimage(&pic_herox, _T("Knight_walk_05lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -16:
		loadimage(&pic_hero, _T("Knight_walk_06l.png"));
		loadimage(&pic_herox, _T("Knight_walk_06lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -21:
		loadimage(&pic_hero, _T("Knight_hurt_01l.png"));
		loadimage(&pic_herox, _T("Knight_hurt_01lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -22:
		loadimage(&pic_hero, _T("Knight_hurt_02l.png"));
		loadimage(&pic_herox, _T("Knight_hurt_02lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -31:
		loadimage(&pic_hero, _T("Knight_jump_01l.png"));
		loadimage(&pic_herox, _T("Knight_jump_01lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	case -32:
		loadimage(&pic_hero, _T("Knight_jump_02l.png"));
		loadimage(&pic_herox, _T("Knight_jump_02lx.png"));
		SetWorkingImage(&pic_hero);
		putimage(0, 0, &pic_herox, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(x, y, &pic_herox, SRCAND);
		putimage(x, y, &pic_hero, SRCPAINT);
		break;
	default:
		break;
	}
}
void Hero::HMove(char k,DMap a) {
	switch (k) {
	case 'a':
		//向左移动
		for (int i = HPspeed; i >= 0 && x - i >= 0; i--) {
			if (a.get_num(x - i, y+50) != 1) {
				x -= i;
				break;
			}
		}
		//控制输出图片
		if (num_pic > 0) {
			num_pic *= -1;
		}
		if (num_pic <= -11 && num_pic >= -15) {
			num_pic--;
		}
		else {
			num_pic = -11;
		}
		//对100值的操纵和声音输出
		if (a.get_num(x + 50, y + 100) == 1) {
			num_100--;
			if (Tes_Sound("status walk_1 mode")) {
				Tri_Sound("seek walk_1 to start");
				Tri_Sound("play walk_1");
			}
			else if (Tes_Sound("status walk_2 mode")) {
				Tri_Sound("seek walk_2 to start");
				Tri_Sound("play walk_2");
			}
		}
		break;
	case 'd':
		//向右移动
		for (int i = HPspeed; i >= 0 && x+i<=1180; i--) {
			if (a.get_num(x + i, y+50) != 1) {
				x += i;
				break;
			}
		}
		//控制输出图片
		if (num_pic < 0) {
			num_pic *= -1;
		}
		if (num_pic >= 11 && num_pic <= 15) {
			num_pic++;
		}
		else {
			num_pic = 11;
		}
		//对100值的操纵和声音输出
		if (a.get_num(x + 50, y + 100) == 1) {
			num_100--;
			if (Tes_Sound("status walk_1 mode")) {
				Tri_Sound("seek walk_1 to start");
				Tri_Sound("play walk_1");
			}
			else if (Tes_Sound("status walk_2 mode")) {
				Tri_Sound("seek walk_2 to start");
				Tri_Sound("play walk_2");
			}
		}
		break;
	}
}
void Hero::HMove() {
	x = 590;
	y = 525;
	if (num_pic >= 11 && num_pic <= 15) {
		num_pic++;
	}
	else {
		num_pic = 11;
	}
}
void Hero::idle(char k) {
	if (k != 'a' && k != 'd' && k != 'k') {
		if (num_pic >= 0) {
			if (num_pic >= 1 && num_pic <= 5) {
				num_pic++;
			}
			else {
				num_pic = 1;
			}
		}
		else {
			if (num_pic >= -5 && num_pic <= -1) {
				num_pic--;
			}
			else {
				num_pic = -1;
			}
		}
		
	}
}
void Hero::VMove(char k,DMap a) {
	//首先判断是否在空中
	if (a.get_num(x + 50, y + 100) != 1) {
		//模拟重力加速度
		Vspeed -= VPspeed;
		//优化横坐标变化
		if (num_pic < 0) {
			for (int i = 15; i >= 0 && x - i >= 0; i--) {
				if (a.get_num(x-i,y) != 1) {
					x -= i;
					break;
				}
			}
		}
		if (num_pic > 0) {
			for (int i = 15; i >= 0 && x + i <= 1180; i--) {
				if (a.get_num(x + i, y) != 1) {
					x += i;
					break;
				}
			}
		}
		//二段跳
		if (k == 'k' && mark_skill == 1) {
			num_100 -= 5;
			Tri_Sound("seek jump to start");
			Tri_Sound("play jump");
			Vspeed = 40;
			mark_skill = -1;
		}
	}
	else {
	//碰到地面纵坐标速度清零，刷新二段跳
		Vspeed = 0;
		if (mark_skill == -1) {
			mark_skill = 1;
		}
	//实现跳跃的速度变化和声音输出
		if (k == 'k') {
			num_100 -= 5;
			Tri_Sound("seek jump to start");
			Tri_Sound("play jump");
			Vspeed = 50;
		}
	}
	//控制输出图片
	if (Vspeed > 0) {
		if (num_pic >= 0) {
			num_pic = 31;
		}
		else {
			num_pic = -31;
		}
	}
	if (Vspeed < 0) {
		if (num_pic > 0) {
			num_pic = 32;
		}
		else {
			num_pic = -32;
		}
	}
	//防止向上飞出屏幕
	if (y - Vspeed < 0) {
		y = 0;
		return ;
	}
	//防止下落时穿过地面
	if (Vspeed < 0) {
		for (int i = 0; i >= Vspeed; i--) {
			if (a.get_num(x + 50, y + 100 - i) == 1) {
				y -= i - 1;
				return;
			}
		}
	}
	y -= Vspeed;
}
int Hero::Event(DMap a) {
	int t = a.get_num(x+50, y+50);
	if (t >= 21) {
		RECT  r = { x + 30,y - 40,x + 70,y };
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
		settextcolor(RGB(255, 255, 255));
		drawtext("F", &r, DT_CENTER | DT_WORDBREAK);
	}
	else t = 0;
	return t;
}
void Hero::Flash_back(char k) {
	if (fx != 0) {
		loadimage(&pic_plant, _T("plant.png"));
		loadimage(&pic_plantx, _T("plantx.png"));
		SetWorkingImage(&pic_plant);
		putimage(0, 0, &pic_plantx, SRCINVERT);
		SetWorkingImage(NULL);
		putimage(fx, fy, &pic_plantx, SRCAND);
		putimage(fx, fy, &pic_plant, SRCPAINT);
		if (k == 'r') {
			num_100 -= 10;
			Tri_Sound("seek flash to start");
			loadimage(&pic_hero, _T("Knight_crouch_0.png"));
			loadimage(&pic_herox, _T("Knight_crouch_0x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			FlushBatchDraw();
			Tri_Sound("play flash");
			Sleep(200);
			x = fx;
			y = fy;
			num_100 = fn;
			fx = 0;
			fy = 0;

		}
	}
	else {
		if (k == 'r') {
			Tri_Sound("seek plant to start");
			Tri_Sound("play plant");
			fx = x;
			fy = y;
			fn = num_100;
		}
	}
}
void Hero::hurt(DMap a) {
	if (been_hurt != 0){
		been_hurt++;
		been_hurt%=20;
		if (num_pic < 0) {
			if (been_hurt <= 5) {
				num_pic = -21;
			}
			if (been_hurt > 5 && been_hurt <= 10) {
				num_pic = -22;
			}
		}
		else {
			if (been_hurt <= 5) {
				num_pic = 21;
			}
			if (been_hurt > 5 && been_hurt <= 10) {
				num_pic = 22;
			}
		}
	}
	else  {
		for (int i = x +20 ; i <= x + 80; i++) {
			for (int j = y + 20; j < + y + 100; j++) {
				if (a.get_num(i, j) == 11) {
					num_100 -= 20;
					Tri_Sound("seek hurt to start");
					Tri_Sound("play hurt");
					if (y - 50 < 0) {
						y = 0;
					}
					else {
						y -= 50;
					}
					been_hurt = 1;
					return;
				}
			}
		}
	}
}
void Hero::show_100() {
	char txt[4]="000";
	int t=num_100, k=2;
	while (t > 0) {
		txt[k] = '0' + t % 10;
		k--;
		t /= 10;
	}
	RECT  r = { 1200, 0, 1280, 80};
	setbkmode(TRANSPARENT);
	settextstyle(60, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	settextcolor(RGB(255, 255, 255));
	drawtext(txt, &r, DT_CENTER | DT_WORDBREAK);
}
void Hero::die() {
	cleardevice();
	Tri_Sound("seek hurt to start");
	Tri_Sound("play hurt");
	Sleep(50);
	for (int i = 1; i <= 8; i++) {
		switch (i) {
		case 1:
			loadimage(&pic_hero, _T("Knight_die_01.png"));
			loadimage(&pic_herox, _T("Knight_die_01x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		case 2:
			loadimage(&pic_hero, _T("Knight_die_02.png"));
			loadimage(&pic_herox, _T("Knight_die_02x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		case 3:
			loadimage(&pic_hero, _T("Knight_die_03.png"));
			loadimage(&pic_herox, _T("Knight_die_03x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		case 4:
			loadimage(&pic_hero, _T("Knight_die_04.png"));
			loadimage(&pic_herox, _T("Knight_die_04x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		case 5:
			loadimage(&pic_hero, _T("Knight_die_05.png"));
			loadimage(&pic_herox, _T("Knight_die_05x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		case 6:
			loadimage(&pic_hero, _T("Knight_die_06.png"));
			loadimage(&pic_herox, _T("Knight_die_06x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		case 7:
			loadimage(&pic_hero, _T("Knight_die_07.png"));
			loadimage(&pic_herox, _T("Knight_die_07x.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		case 8:
			loadimage(&pic_hero, _T("Knight_die_08.png"));
			loadimage(&pic_herox, _T("Knight_die_08.png"));
			SetWorkingImage(&pic_hero);
			putimage(0, 0, &pic_herox, SRCINVERT);
			SetWorkingImage(NULL);
			putimage(x, y, &pic_herox, SRCAND);
			putimage(x, y, &pic_hero, SRCPAINT);
			break;
		}
		FlushBatchDraw();
		Sleep(50);
	}
	cleardevice();
	string txt = "You failed again.";
	RECT  r = { 300, 250, 980, 400 };
	setbkmode(TRANSPARENT);
	settextstyle(100, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	settextcolor(RGB(255, 0, 0));
	drawtext(txt.c_str(), &r, DT_CENTER | DT_WORDBREAK);
	FlushBatchDraw();
	Sleep(1000);
	r = { 520, 600, 760, 700 };
	txt = "R or Esc";
	settextcolor(RGB(255, 255, 255));
	settextstyle(60, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
	drawtext(txt.c_str(), &r, DT_CENTER | DT_WORDBREAK);
	FlushBatchDraw();
}
void Hero::sit() {
	loadimage(&pic_hero, _T("Knight_crouch_0.png"));
	loadimage(&pic_herox, _T("Knight_crouch_0x.png"));
	SetWorkingImage(&pic_hero);
	putimage(0, 0, &pic_herox, SRCINVERT);
	SetWorkingImage(NULL);
	putimage(x, y, &pic_herox, SRCAND);
	putimage(x, y, &pic_hero, SRCPAINT);
	num_100 = 100;
}
void Mei::loadMei(int x, int y) {
	loadimage(&pic, _T("Mei.png"));
	loadimage(&picx, _T("Meix.png"));
	SetWorkingImage(&pic);
	putimage(0, 0, &picx, SRCINVERT);
	SetWorkingImage(NULL);
	putimage(x, y, &picx, SRCAND);
	putimage(x, y, &pic, SRCPAINT);
}
bool Hero::come(int tx) {
	if (tx - x >= -100 && tx - x <= 100) {
		return 1;
	}
	return 0;
}