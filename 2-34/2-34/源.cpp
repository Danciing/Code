#include<iostream>
using namespace std;
int main() {
	int num = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j < i; j++) {
			if(i!=j)
			for (int k = 1; k < j; k++) {
				if (i != k && k != j) {
					num++;
				}
			}
		}
	}
	cout << num;
	return 0;
}