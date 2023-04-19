#include<iostream>
using  namespace std;
int Fibonacci(int x) {
	if (x == 1 || x == 2)return 1;
	return Fibonacci(x - 1) + Fibonacci(x - 2);
}
int main() {
	int n;
	cin >> n;
	cout << Fibonacci(n);
	return 0;
}