#include<iostream>
#include<cmath>
using namespace std;
struct node {
	char data;
	node* l;
	node* r;
};
void initTree(node* now, int num) {
	now->data = 'a' + num;
	if (num == 8)
	{
		now->l = NULL;
		now->r = NULL;
		return;
	}
	now->l = (node*)malloc(sizeof(node));
	now->r = (node*)malloc(sizeof(node));
	initTree(now->l, num + 1);
	initTree(now->r, num + 1);
}
bool compTree(node* nl, node* nr) {
	if (nl->l == NULL && nr->l != NULL) {
		return 0;
	}
	if (nl->r == NULL && nr->r != NULL) {
		return 0;
	}
	if (nl->l != NULL && nr->l == NULL) {
		return 0;
	}
	if (nl->r != NULL && nr->r == NULL) {
		return 0;
	}
	if (nl->l != NULL)compTree(nl->l, nr->l);
	if (nl->r != NULL)compTree(nl->r, nr->r);
	return 1;
}
int main() {
	node* tree = (node*)malloc(sizeof(node));
	initTree(tree, 0);
	if (compTree(tree->l,tree->r)) {
		cout << "Yes!";
	}
	else {
		cout << "No!";
	}
	return 0;
}