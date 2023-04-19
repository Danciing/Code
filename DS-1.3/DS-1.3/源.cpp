#include<iostream>
using namespace std;
void CreateList(int* &L, int n) {		//创建顺序表
	L = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}
}
void ReverseList(int* &L, int n) {		//转置顺序表
	for (int i = 0; i < n / 2; i++) {
		swap(L[i], L[n - i - 1]);
	}
}
void ShowList(int* L, int n) {			//打印顺序表
	for (int i = 0; i < n; i++) {
		cout << L[i] << " ";
	}
}
int main() {
	int n;								//顺序表元素总数
	cin >> n;
	int* tab;
	CreateList(tab, n);
	ReverseList(tab, n);
	ShowList(tab, n);
}