#include<iostream>
using namespace std;
void transpose(int t[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= i; j++) {
			swap(t[i][j], t[j][i]);
		}
	}
}
int main() {
	int a[3][3];
	cout << "Please import a matrix:";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	transpose(a);
	cout << "This is the transposed matrix:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}