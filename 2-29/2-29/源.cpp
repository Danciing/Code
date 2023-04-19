#include<iostream>
using namespace std;
int main() {
	bool k;
	for (int i = 2; i <= 100; i++) {
		k = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				k = 0;
				break;
			}
		}
		if (k) {
			cout << i<<" ";
		}
	}
	cout << endl;
	int t = 2, a;
	while (t <= 100) {
		k = 1;
		a = 2;
		while (a < t) {
			if (t % a == 0) {
				k = 0;
				break;
			}
			a++;
		}
		if (k) {
			cout << t << " ";
		}
		t++;
	}
	cout << endl;
	t = 2;
	do {
		k = 1;
		a = 2;
		do {
			if (t == 2)break;
			if (t % a == 0) {
				k = 0;
				break;
			}
			a++;
		} while (a < t);
		if (k) {
			cout << t << " ";
		}
		t++;
	} while (t <= 100);
	cout << endl;
	return 0;
}