#include<iostream>
using namespace std;
int myadd(int n) {
	if (n == 1)return 1;
	else return n + myadd(n - 1);
}
int main() {
	int n;
	cout << "Please input int n: ";
	cin >> n;
	cout << myadd(n);
	return 0;
}