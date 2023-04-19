#include<iostream>
using namespace std;
int getPower(int x, int y) {
	if (y == 0)return 1;
	if (y < 0)return 1 / getPower(x, -y);
	return x * getPower(x, y - 1);
}
double getPower(double x, int y) {
	if (y == 0)return 1;
	if (y < 0)return 1.0 / getPower(x, -y);
	return x * getPower(x, y - 1);
}
int main() {
	int a, m;
	double b;
	cin >> a >> b >> m;
	cout << (double)getPower(a, m) << " " << getPower(b, m);
	return 0;
}