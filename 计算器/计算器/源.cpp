#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct Node {
	int num;
	char op='#';
	Node* l = NULL;
	Node* r = NULL;
};
void getTree(Node* p,stack<Node*>& aft) {
	if (p->op == '#') {
		aft.push(p);
	}
	else {
		p->r = aft.top();
		aft.pop();
		p->l = aft.top();
		aft.pop();
		switch (p->op) {
			case '+':
				p->num = p->l->num + p->r->num;
				break;
			case '-':
				p->num = p->l->num - p->r->num;
				break;
			case '*':
				p->num = p->l->num * p->r->num;
				break;
			case '/':
				p->num = p->l->num / p->r->num;
				break;
		}
		aft.push(p);
	}
}
int main() {
	stack<Node*>ori, aft;
	string t;
	int num;
	getline(cin, t);
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == ' ')continue;
		Node* p = (Node*)malloc(sizeof(Node));
		if (t[i] == '=')break;
		if (t[i] >= '0' && t[i] <= '9') {
			p->op = '#';
			num = 0;
			while (t[i] >= '0' && t[i] <= '9') {
				num = num * 10 + t[i] - '0';
				i++;
			}
			i--;
			p->num = num;
			aft.push(p);
		}
		else {
			p->op = t[i];
			if (p->op == '(') {
				p->num = 0;
				ori.push(p);
			}
			else if (p->op == ')') {
				while (ori.top()->op != '(') {
					getTree(ori.top(), aft);
					ori.pop();
				}
				ori.pop();
			}
			else if (p->op == '+') {
				p->num = 1;
				while (!ori.empty()) {
					if (ori.top()->num == 2) {
						getTree(ori.top(), aft);
						ori.pop();
					}
					else break;
				}
				ori.push(p);
			}
			else if (p->op == '-') {
				p->num = 1;
				while (!ori.empty()) {
					if (ori.top()->num >= 1) {
						getTree(ori.top(), aft);
						ori.pop();
					}
					else break;
				}
				ori.push(p);
			}
			else if (p->op == '*') {
				p->num = 2;
				while (!ori.empty()) {
					if (ori.top()->num >= 2) {
						getTree(ori.top(), aft);
						ori.pop();
					}
					else break;
				}
				ori.push(p);
			}
			else if (p->op == '/') {
				p->num = 2;
				while (!ori.empty()) {
					if (ori.top()->num >= 2) {
						getTree(ori.top(), aft);
						ori.pop();
					}
					else break;
				}
				ori.push(p);
			}
		}
	}
	while (!ori.empty()) {
		getTree(ori.top(), aft);
		ori.pop();
	}
	cout << aft.top()->op << " ";
	if (aft.top()->l->op == '#') {
		cout << aft.top()->l->num<<" ";
	}
	else {
		cout << aft.top()->l->op << " ";
	}
	if (aft.top()->r->op == '#') {
		cout << aft.top()->r->num << " " << endl;
	}
	else {
		cout << aft.top()->r->op << endl;
	}
	cout << aft.top()->num;
	return 0;
}