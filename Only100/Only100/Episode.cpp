#include"Ui.h"
int Episode(int &n, Hero &a, DMap m) {
	static IMAGE back;
	int t;
	char k = 0; 
	string t21[10], t22[10], t23[10];
	Dialog d21, d22, d23;
	Mei b;
	switch (n) {
		case -1:
		{
			//关闭开始界面BGM
			mciSendString("close music.wma", 0, 0, 0);
			a.InitHero(0, 0);
			//开始批量绘图解决闪烁问题，退出时需要退出批量绘图，且函数中若需要绘图记得Flush
			while (1) {
				cleardevice();
				//在此处监听键盘，提高效率
				string txt = "Does the end truly exist ?";
				setbkmode(TRANSPARENT);
				settextstyle(72, 0, "Comic Sans MS", 0, 0, 1000, 0, 0, 0);
				settextcolor(RGB(255, 255, 255));
				outtextxy(205, 110, txt.c_str());
				FlushBatchDraw();
				if (_kbhit())
					k = _getch();
				//主角相关，函数顺序对最终效果有影响
				a.show_100();
				a.Flash_back(k);
				a.idle(k);
				a.HMove(k, m);
				a.VMove(k, m);
				a.hurt(m);
				a.Event(m);
				a.loadHero();
				//进行一次批量绘制
				FlushBatchDraw();
				k = 0;
				//暂停，防止速度过快
				Sleep(50);
			}
			//结束批量绘制
			break;
		}
		case 1: 
		{
			//对话预载
			{
				t21[0] = "A tomb with a fresh flower.";
				t21[1] = "Here are the words on it.";
				t21[2] = "Facing the One Above All,";
				t21[3] = "he still maintained his dignity.";
				t21[4] = "Bathed in the God's scornful eyes,";
				t21[5] = "he chosed to fight as aways.";
				t21[6] = "He accepted the unfair bet.";
				t21[7] = "No one ever knew why he chosed that.";
				t21[8] = "But that was his choice.";
				t21[9] = "……";
				t22[0] = "A bonfire with afterheat.";
				t22[1] = "Someone had been here.";
				t22[2] = "A bonfire with afterheat.";
				t22[3] = "Someone had been here.";
				t22[4] = "……";
				t22[5] = "……";
				t22[6] = "……";
				t22[7] = "……";
				t22[8] = "……";
				t22[9] = "……";
				d21.InitDialog(21, 222, 521, t21);
				d22.InitDialog(22, 974, 219, t22);
			}
			//关闭开始界面BGM
			mciSendString("close music.wma", 0, 0, 0);
			a.InitHero(76, 560);
			loadimage(&back, _T("Map.01.png"));
			//开始批量绘图解决闪烁问题，退出时需要退出批量绘图，且函数中若需要绘图记得Flush
			
			while (1) {
				cleardevice();
				putimage(0, 0, &back);
				//在此处监听键盘，提高效率
				if (_kbhit())
					k = _getch();
				//主角相关，函数顺序对最终效果有影响
				t = a.Event(m);
				a.Flash_back(k);
				a.idle(k);
				a.HMove(k, m);
				a.VMove(k, m);
				a.hurt(m);
				d21.loadDialog(t, k);
				d22.loadDialog(t, k);
				a.show_100();
				if (t == 100 && k == 'f') {
					k = 0;
					a.sit();
					FlushBatchDraw();
					while (1) {
						if (_kbhit())
							k = _getch();
						if (k != 0) {
							break;
						}
					}
				}
				else {
					a.loadHero();
				}
				a.show_100();
				//按下Esc键暂停游戏
				if (k == 27 && !(pauseGame())) {
					return 1;
				}
				//进行一次批量绘制
				if (t == 522 && k == 'f') {
					n++;
					return 3;
				}
				FlushBatchDraw();
				k = 0;
				t = 0;
				if (a.num_100 <= 0) {
					a.die();
					while (1) {
						if (Tes_Sound("status heart mode")) {
							Tri_Sound("seek heart to start");
							Tri_Sound("play heart");
						}
						if (_kbhit()) {
							k = _getch();
							if (k == 'r') {
								k = 0;
								return 4;
							}
							if (k == 27) {
								return 1;
							}
						}
					}
					a.InitHero(a.sx, a.sy);
				}
				//暂停，防止速度过快
				Sleep(50);
			}
			//结束批量绘制
			break;
		}	
		case 2:
		{
			//对话预载
			{
				t21[0] = "You are back, it's been a long time.";
				t21[1] = "Maybe you have forgotten the reason why you are here.";
				t21[2] = "I will explain to you , again.";
				t21[3] = "You made a bet with the gods for some reasons.";
				t21[4] = "You need to touch as much idols as you can.";
				t21[5] = "The gods crafted elaborate traps.";
				t21[6] = "But they don't know you have the power to Flash Back.";
				t21[7] = "During the time and space travle, you might lose your memorise.";
				t21[8] = "So you chosed me to guide you to your destination.";
				t21[9] = "Now just go to the idol below and touch it.";
				d21.InitDialog(21, 176, 245, t21);
			}
			//关闭开始界面BGM
			mciSendString("close music.wma", 0, 0, 0);
			a.InitHero(10, 245);
			loadimage(&back, _T("Map.02.png"));
			ball trap_b1(457, 104, 104, 215), trap_b2(618, 92, 92, 203), trap_b3(717, 92, 92, 203), trap_b4(807, 92, 92, 203), trap_b5(954, 92, 92, 203), trap_b6(600, 450, 450, 600), trap_b7(800, 450, 450, 600), trap_b8(1000, 450, 450, 600);
			//开始批量绘图解决闪烁问题，退出时需要退出批量绘图，且函数中若需要绘图记得Flush

			while (1) {
				cleardevice();
				putimage(0, 0, &back);
				b.loadMei(156, 245);

				//在此处监听键盘，提高效率
				if (_kbhit())
					k = _getch();
				//主角相关，函数顺序对最终效果有影响
				t = a.Event(m);
				a.Flash_back(k);
				a.idle(k);
				a.HMove(k, m);
				a.VMove(k, m);
				a.hurt(m);
				d21.loadDialog(t, k);
				if (t == 100 && k == 'f') {
					k = 0;
					a.sit();
					a.show_100();
					FlushBatchDraw();
					while (1) {
						if (_kbhit())
							k = _getch();
						if (k != 0) {
							break;
						}
					}
				}
				else {
					a.loadHero();
				}
				a.show_100();
				//按下Esc键暂停游戏
				if (k == 27 && !(pauseGame())) {
					return 1;
				}
				//进行一次批量绘制
				if (t == 522 && k == 'f') {
					n++;
					return 3;
				}
				if (t == 523 && k == 'f') {
					n = -1;
					return 3;
				}
				trap_b1.loadball(m);
				trap_b2.loadball(m);
				trap_b3.loadball(m);
				trap_b4.loadball(m);
				trap_b5.loadball(m);
				trap_b6.loadball(m);
				trap_b7.loadball(m);
				trap_b8.loadball(m);
				FlushBatchDraw();
				k = 0;
				t = 0;
				if (a.num_100 <= 0) {
					a.die();
					while (1) {
						if (Tes_Sound("status heart mode")) {
							Tri_Sound("seek heart to start");
							Tri_Sound("play heart");
						}
						if (_kbhit()) {
							k = _getch();
							if (k == 'r') {
								k = 0;
								return 4;
							}
							if (k == 27) {
								return 1;
							}
						}
					}
					a.InitHero(a.sx, a.sy);
				}
				//暂停，防止速度过快
				Sleep(50);
			}
			//结束批量绘制
			break;
		}
		case 3:
		{
			//对话预载
			{
				t21[0] = "No need to surprise, I have my own way to travel.";
				t21[1] = "But I can't take you with me, that was your choice.";
				t21[2] = "I am sorry that nothing much I can do for you.";
				t21[3] = "You want to know more about the past?";
				t21[4] = "It has been a long time for me to assist you.";
				t21[5] = "Actually, I don't even remember how many years has passed.";
				t21[6] = "No, I'm not complaining about this mission.";
				t21[7] = "In fact,I kind of like this job, though it could be boring sometimes.";
				t21[8] = "And I even once thought about releasing you from tis loop.";
				t21[9] = "I am sorry, forget about that.";
				d21.InitDialog(21, 300, 550, t21);
			}
			//关闭开始界面BGM
			mciSendString("close music.wma", 0, 0, 0);
			a.InitHero(100, 535);
			loadimage(&back, _T("Map.03.png"));
			ball trap_b1(457, 104, 104, 215), trap_b3(717, 92, 92, 203), trap_b4(807, 92, 92, 203), trap_b5(954, 92, 92, 203), trap_b6(600, 450, 450, 600), trap_b7(800, 450, 450, 600), trap_b8(1000, 450, 450, 600);
			sword trap_s1(350, 80);
			//开始批量绘图解决闪烁问题，退出时需要退出批量绘图，且函数中若需要绘图记得Flush

			while (1) {
				cleardevice();
				putimage(0, 0, &back);
				b.loadMei(280, 550);

				//在此处监听键盘，提高效率
				if (_kbhit())
					k = _getch();
				//主角相关，函数顺序对最终效果有影响
				t = a.Event(m);
				a.Flash_back(k);
				a.idle(k);
				a.HMove(k, m);
				a.VMove(k, m);
				a.hurt(m);
				d21.loadDialog(t, k);
				if (t == 100 && k == 'f') {
					k = 0;
					a.sit();
					a.show_100();
					FlushBatchDraw();
					while (1) {
						if (_kbhit())
							k = _getch();
						if (k != 0) {
							break;
						}
					}
				}
				else {
					a.loadHero();
				}
				a.show_100();
				//按下Esc键暂停游戏
				if (k == 27 && !(pauseGame())) {
					return 1;
				}
				//进行一次批量绘制
				if (t == 522 && k == 'f') {
					n++;
					return 3;
				}
				trap_b1.loadball(m);
				trap_b3.loadball(m);
				trap_b5.loadball(m);
				trap_b6.loadball(m);
				trap_b7.loadball(m);
				trap_s1.loadsword(m, a);
				FlushBatchDraw();
				k = 0;
				t = 0;
				if (a.num_100 <= 0) {
					a.die();
					while (1) {
						if (Tes_Sound("status heart mode")) {
							Tri_Sound("seek heart to start");
							Tri_Sound("play heart");
						}
						if (_kbhit()) {
							k = _getch();
							if (k == 'r') {
								k = 0;
								return 4;
							}
							if (k == 27) {
								return 1;
							}
						}
					}
				}
				//暂停，防止速度过快
				Sleep(50);
			}
			//结束批量绘制
			break;
		}
		case 4:
		{
			//对话预载
			{
				t21[0] = "According to the contract made at the beginning,";
				t21[1] = "there is one more thing you need to do.";
				t21[2] = "Jump dowm to the well, and then collect holy water";
				t21[3] = "Take good use of your Flash Back,";
				t21[4] = "it is engraved in the soul.";
				t21[5] ="Press 'R' to use it." ;
				t21[6] = "What is the holly water used for?";
				t21[7] = "It was used to please those gods.";
				t21[8] = "Why? You will find out one day.";
				t21[9] = "Let's hope that one day will eventually come.";
				d21.InitDialog(21, 190, 95, t21);
			}
			//关闭开始界面BGM
			bool water = 0;
			mciSendString("close music.wma", 0, 0, 0);
			a.InitHero(10, 90);
			loadimage(&back, _T("Map.04.png"));
			ball trap_b1(457, 104, 104, 215), trap_b2(457, 215, 215, 326);
			sword trap_s1(630, 0), trap_s2(788, 0);
			//开始批量绘图解决闪烁问题，退出时需要退出批量绘图，且函数中若需要绘图记得Flush

			while (1) {
				cleardevice();
				putimage(0, 0, &back);
				b.loadMei(170, 95);
				
				//在此处监听键盘，提高效率
				if (_kbhit())
					k = _getch();
				//主角相关，函数顺序对最终效果有影响
				t = a.Event(m);
				a.Flash_back(k);
				a.idle(k);
				a.HMove(k, m);
				a.VMove(k, m);
				a.hurt(m);
				d21.loadDialog(t, k);
				if (t == 555 && k == 'f') {
					water = 1;
				}
				if (t == 100 && k == 'f') {
					k = 0;
					a.sit();
					a.show_100();
					FlushBatchDraw();
					while (1) {
						if (_kbhit())
							k = _getch();
						if (k != 0) {
							break;
						}
					}
				}
				else {
					a.loadHero();
				}
				a.show_100();
				//按下Esc键暂停游戏
				if (k == 27 && !(pauseGame())) {
					return 1;
				}
				//进行一次批量绘制
				if (t == 522 && k == 'f' && water) {
					n++;
					return 3;
				}
				trap_b1.loadball(m);
				trap_b2.loadball(m);
				trap_s1.loadsword(m, a);
				trap_s2.loadsword(m, a);
				FlushBatchDraw();
				k = 0;
				t = 0;
				if (a.num_100 <= 0) {
					a.die();
					while (1) {
						if (Tes_Sound("status heart mode")) {
							Tri_Sound("seek heart to start");
							Tri_Sound("play heart");
						}
						if (_kbhit()) {
							k = _getch();
							if (k == 'r') {
								k = 0;
								return 4;
							}
							if (k == 27) {
								return 1;
							}
						}
					}
					a.InitHero(a.sx, a.sy);
				}
				//暂停，防止速度过快
				Sleep(50);
			}
			//结束批量绘制
			break;
		}
		case 5:
		{
			//对话预载
			{
				t21[0] = "There are aways more than one way to the idol.";
				t21[1] = "The better way is always hidden.";
				t21[2] = "No. It's not my found. It was what you have told me.";
				t21[3] = "However, I can not tell you too much.";
				t21[4] = "Yes. That's one of the limitations from the contract.";
				t21[5] = "For me ,that contract is absolutely a conspiracy.";
				t21[6] = "Those gods never wanted you to reach the top.";
				t21[7] = "They blocked every possible way and other's assistance.";
				t21[8] = "No. I am not doubting your choice. It's just...";
				t21[9] = "I am sorry, forget about that.";
				t22[0] = "You are back again, challenger.";
				t22[1] = "Hey! Hey! Don't ignore me.";
				t22[2] = "It's here,the Scarecrow. Why you can't find me for every time.";
				t22[3] = "It's amazing, right? A talking Scarecrow.";
				t22[4] = "Hahhhh, that face again. Your reaction never changed.";
				t22[5] = "So do me a favor. Bring me some straw.";
				t22[6] = "Same as you, I am not immortal. I need straw to stay alive.";
				t22[7] = "The straw is just on the left. ";
				t22[8] = "It won't take you too much time.";
				t22[9] = "Go go go! Don't let me down";
				t23[0] = "Hahhhh, thank you. Then I can remain myself for longer time.";
				t23[1] = "Why are you still here?";
				t23[2] = "I have no prize for you.";
				t23[3] = "Hmmm, as for the prize, do you remember what they offered?";
				t23[4] = "Stuck in the loop, and don't even know what's chasing for.";
				t23[5] = "What a poor man. But that was your choice.";
				t23[6] = "By the way, are you still yourself after reincarnation?";
				t23[7] = "Why not change it? If it were me, I would choose different.";
				t23[8] = "I would choose to stay with my beloved ones.";
				t23[9] = "But I have no chance to change. Do you?";
				d23.InitDialog(23, 930, 570, t23);
				d21.InitDialog(21, 1170, 550, t21);
				d22.InitDialog(22, 930, 570, t22);
			}
			//关闭开始界面BGM
			mciSendString("close music.wma", 0, 0, 0);
			a.InitHero(1000, 550);
			loadimage(&back, _T("Map.05.png"));
			ball trap_b1(383, 500, 500, 600), trap_b3(496, 283, 283, 400), trap_b4(1000, 400, 400, 500), trap_b5(954, 92, 92, 203), trap_b6(600, 450, 450, 600), trap_b7(800, 450, 450, 600), trap_b8(1000, 450, 450, 600);
			//开始批量绘图解决闪烁问题，退出时需要退出批量绘图，且函数中若需要绘图记得Flush
			int cao = 0;
			while (1) {
				cleardevice();
				putimage(0, 0, &back);
				b.loadMei(1150, 550);

				//在此处监听键盘，提高效率
				if (_kbhit())
					k = _getch();
				//主角相关，函数顺序对最终效果有影响
				t = a.Event(m);
				a.Flash_back(k);
				a.idle(k);
				a.HMove(k, m);
				a.VMove(k, m);
				a.hurt(m);
				d21.loadDialog(t, k);
				d22.loadDialog(t + cao, k);
				d23.loadDialog(t + cao, k);
				if (t == 555 && k == 'f') {
					cao = 1;
				}
				if (t == 100 && k == 'f') {
					k = 0;
					a.sit();
					a.show_100();
					FlushBatchDraw();
					while (1) {
						if (_kbhit())
							k = _getch();
						if (k != 0) {
							break;
						}
					}
				}
				else {
					a.loadHero();
				}
				a.show_100();
				//按下Esc键暂停游戏
				if (k == 27 && !(pauseGame())) {
					return 1;
				}
				//进行一次批量绘制
				if (t == 522 && k == 'f') {
					n++;
					return 3;
				}
				trap_b1.loadball(m);
				trap_b3.loadball(m);
				trap_b4.loadball(m);
				FlushBatchDraw();
				k = 0;
				t = 0;
				if (a.num_100 <= 0) {
					a.die();
					while (1) {
						if (Tes_Sound("status heart mode")) {
							Tri_Sound("seek heart to start");
							Tri_Sound("play heart");
						}
						if (_kbhit()) {
							k = _getch();
							if (k == 'r') {
								k = 0;
								return 4;
							}
							if (k == 27) {
								return 1;
							}
						}
					}
				}
				//暂停，防止速度过快
				Sleep(50);
			}
			//结束批量绘制
			break;
		}
		case 6:
		{
			//对话预载
			{
				t21[0] = "This is the end of my journey. The rest is all yours.";
				t21[1] = "According to the contract, I can accompany you till here";
				t21[2] = "It was a nice tirp and it is time to say goodbye now.";
				t21[3] = "Hope next time we met, you have already won the bet.";
				t21[4] = "I hold my faith in you, you should belive in yourself.";
				t21[5] = "If you feel lost, just keep climbing up.";
				t21[6] = "It was your choice, and it will be your choice.";
				t21[7] = "Even if the road ahead is muddy, don't give up.";
				t21[8] = "One day you will see. One day……";
				t21[9] = "Best wishes to you.";
				t22[0] = "Aren't you going?";
				t22[1] = "No, I didn't mean to drive you away.";
				t22[2] = "I...I don't know what I should do.";
				t22[3] = "I have promised you. I promised to assist you.";
				t22[4] = "But I...";
				t22[5] = "Forgive me. I don't want you suffer any more.";
				t22[6] = "No. I just want you to stay with me.";
				t22[7] = "I……";
				t22[8] = "Thank you...";
				t22[9] = "THank you for your choice.";
				d21.InitDialog(21, 332, 529, t21);
				d22.InitDialog(22, 332, 529, t22);
			}
			//关闭开始界面BGM
			mciSendString("close music.wma", 0, 0, 0);
			a.InitHero(76, 529);
			loadimage(&back, _T("Map.06.png"));
			//开始批量绘图解决闪烁问题，退出时需要退出批量绘图，且函数中若需要绘图记得Flush

			while (1) {
				cleardevice();
				putimage(0, 0, &back);
				b.loadMei(312, 529);
				
				//在此处监听键盘，提高效率
				if (_kbhit())
					k = _getch();
				//主角相关，函数顺序对最终效果有影响
				t = a.Event(m);
				a.Flash_back(k);
				a.idle(k);
				a.HMove(k, m);
				a.VMove(k, m);
				a.hurt(m);
				d21.loadDialog(t, k);
				
				if (t == 100 && k == 'f') {
					k = 0;
					a.sit();
					a.show_100();
					FlushBatchDraw();
					for (int i = 1; i <= 1100; i++) {
						if (_kbhit())
							k = _getch();
						if (k != 0) {
							break;
						}
						Sleep(50);
						if (i % 100 == 0) {
							k = 'f';
						}
						d22.loadDialog(22, k);
						k = 0;
						FlushBatchDraw();
						if (i == 1100) {
							turning();
							myEnd();
							return 1;
						}
					}
				}
				else {
					a.loadHero();
				}
				a.show_100();
				//按下Esc键暂停游戏
				if (k == 27 && !(pauseGame())) {
					return 1;
				}
				//进行一次批量绘制
				if (t == 522 && k == 'f') {
					bturning();
					EndGame();
					return 1;
				}
				FlushBatchDraw();
				k = 0;
				t = 0;
				if (a.num_100 <= 0) {
					a.die();
					while (1) {
						if (Tes_Sound("status heart mode")) {
							Tri_Sound("seek heart to start");
							Tri_Sound("play heart");
						}
						if (_kbhit()) {
							k = _getch();
							if (k == 'r') {
								k = 0;
								return 4;
							}
							if (k == 27) {
								return 1;
							}
						}
					}
					a.InitHero(a.sx, a.sy);
				}
				//暂停，防止速度过快
				Sleep(50);
			}
			//结束批量绘制
			break;
		}
		default:
			break;
	}
	return 1;
}