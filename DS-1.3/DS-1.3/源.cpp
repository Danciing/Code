#include<iostream>
using namespace std;
void CreateList(int* &L, int n) {		//����˳���
	L = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}
}
void ReverseList(int* &L, int n) {		//ת��˳���
	for (int i = 0; i < n / 2; i++) {
		swap(L[i], L[n - i - 1]);
	}
}
void ShowList(int* L, int n) {			//��ӡ˳���
	for (int i = 0; i < n; i++) {
		cout << L[i] << " ";
	}
}
int main() {
	int n;								//˳���Ԫ������
	cin >> n;
	int* tab;
	CreateList(tab, n);
	ReverseList(tab, n);
	ShowList(tab, n);
}