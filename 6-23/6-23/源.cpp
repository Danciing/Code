#include<iostream>
using namespace std;
int main() {
	int N=8;
	double ans = 0, t;
	cout << "Please inport " << N << " students' grades:";
	for (int i = 0; i < N; i++) {
		cin >> t;
		ans += t;
	}
	ans /= N;
	cout << "Here is the average value of their grades: " << ans;
	return 0;
}