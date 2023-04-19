#include<iostream>
#include<cmath>
using namespace std;
struct node {
	int data ;
	node* l;
	node* r;
};
node* getLCA(node* now, int x,int y) {
	if (now->data >= min(x, y) && now->data <= max(x, y)) {
		return now;
	}
	node* t;
	t = getLCA(now->l, x, y);
	if (t != NULL)return t;
	t = getLCA(now->r, x, y);
	if (t != NULL)return t;
	return NULL;
}