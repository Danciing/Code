#include<iostream>
using namespace std;
struct Node {
	int num = 0;
	Node* next = NULL;

};
void CreateList(Node* &L) {				//头插法建立单链表
	Node* s;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	L->num = -1;
	for (int i = 0; i < 10; i++) {		//输入十个值作为数据
		s = (Node*)malloc(sizeof(Node));
		cin >> s->num;
		s->next = L->next;
		L->next = s;
	}
}
int SearchMax(Node* L) {				//查找链表内第一个最大值
	L = L->next;
	int now = L->num;
	while (L != NULL) {
		if (now < L->num) {
			now = L->num;
		}
		L = L->next;
	}
	return now;
}
int main() {
	Node* st = NULL;
	CreateList(st);
	cout << SearchMax(st);
	return 0;
}