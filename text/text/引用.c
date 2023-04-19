#include<iostream>
#include<queue>
using namespace std;
int geta(int** a) {
	cout << a[2][2];
}
int main() {
	queue<int> q;
	int x;
	q.push(1);
	q.pop(x);
	cout << x;
}