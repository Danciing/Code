#include<iostream>
using namespace std;
int getg(int a);
int getg(int a = 10) {
	return a;
}
int main() {
	cout << getg();
	return 0;
}