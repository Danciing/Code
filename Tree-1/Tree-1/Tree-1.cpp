#include<iostream>
#include<cmath>
using namespace std;
int run() {
	char tree[10][10000];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < pow(2, (i + 1)); j++) {
			tree[i][j] = 0;
		}
	}
	tree[7][50]='i';
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < pow(2,(i+1)); j++) {
			if (tree[i][j] == 'i') {
				cout << i;
			}
		}
	}
	return 0;
}