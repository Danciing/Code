#include<iostream>
using namespace std;
int p(int x,int n) {
	if (n == 0)return 1;
	if (n == 1)return x;
	return ((2 * n - 1) * x * p(x, n - 1) - (n - 1) * p(x, n - 2)) / n;
}
int main() {
	int x, n;
	cin >> x >> n;
	cout << p(x, n);
	return 0;
}