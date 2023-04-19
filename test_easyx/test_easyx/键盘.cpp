#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <time.h>

using namespace std;
class bb {
public:void ad() {
		  loadimage(&a, _T("Knight_jump_01.png"));
		  putimage(0, 0, &a);
	  }
private:IMAGE a;

};
void geta(char a) {
		if (a == 'a')
			cout << a;
}
void getb(char b) {
		if (b == 'b')
			cout << b;
}
void geta() {
	char a=0;
	if (_kbhit())
		a = _getch();
	if (a == 'a')
		cout << a;
}
void getb() {
	char b=0;
	if (_kbhit())
		b = _getch();
	if (b == 'b')
		cout << b;
}
int c1main() {
	bb c;
	
	
	char k=0;
	/*while (1) {
		geta();
		getb();
	}*/

	while (1) {
		if (_kbhit())
			k = _getch();
		geta(k);
		getb(k);
		k = 0;
	}

	//closegraph();
	return 0;
}