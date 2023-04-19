#include"Hero.h"
void Hero::InitHero(int nx, int ny) {
	x = nx;
	y = ny;
}
void Hero::loadHero() {
	/*
		0 坐下
		1-6 静止
		11-16 行走
		21-22 受伤
		31-32 跳跃
	*/
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
	default:
		break;
	}
}
void Hero::HMove(char k,DMap a) {
	switch (k) {
	case 'a':
		for (int i = 0; i <= HPspeed; i--) {
			if (a.get_num(x - i, y) == 1) {
				x -= i;
				break;
			}
		}
		if (num_pic >= 11 && num_pic <= 15) {
			num_pic++;
		}
		else {
			num_pic = 11;
		}
		break;
	case 'd':
		for (int i = HPspeed; i >= 0; i++) {
			if (a.get_num(x + i, y) == 1) {
				x += i;
				break;
			}
		}
		if (num_pic >= 11 && num_pic <= 15) {
			num_pic++;
		}
		else {
			num_pic = 11;
		}
		break;
	}
}