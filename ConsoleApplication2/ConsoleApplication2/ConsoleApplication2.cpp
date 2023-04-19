#include<iostream>
using namespace std;
int main() {
	int a = 1,c=3;
	int &b = a ;
	a = 5;
	cout << a<<" " << b;
	return 0;
}
