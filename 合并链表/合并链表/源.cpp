#include<iostream>
#include<string>
using namespace std;
struct Node {
    int num = 0;
    Node* next = NULL;
};
void addList(Node* L, int num) {
    Node* s = L;
    while (s->next != NULL)
        s = s->next;
    Node* k = (Node*)malloc(sizeof(Node));
    k->next = NULL;
    k->num = num;
    s->next = k;
}
void CreateList(Node*& L) {
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
    L->num = -111;
    int num = 0;
    while (cin >> num) {
        addList(L, num);
        char t = getchar();
        if (t == '\n') {
            break;
        }
    }
}
int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;
    Node* all = NULL;
    CreateList(l1);
    CreateList(l2);
    all = (Node*)malloc(sizeof(Node));
    all->next = NULL;
    all->num = -111;
    int last = -2222222;
    while (l1->next != NULL && l2->next != NULL) {
        if (l1->next->num <= l2->next->num) {
            if (last == l1->next->num) {
                l1 = l1->next;
                continue;
            }
            cout << l1->next->num << " ";
            addList(all, l1->next->num);
            last = l1->next->num;
            l1 = l1->next;
        }
        else {
            if (last == l2->next->num) {
                l2 = l2->next;
                continue;
            }
            cout << l2->next->num << " ";
            addList(all, l2->next->num);
            last = l2->next->num;
            l2 = l2->next;
        }
    }
    while (l2->next != NULL) {
        if (last == l2->next->num) {
            l2 = l2->next;
            continue;
        }
        cout << l2->next->num << " ";
        addList(all, l2->next->num);
        last = l2->next->num;
        l2 = l2->next;
        continue;
    }
    while (l1->next != NULL) {
        if (last == l1->next->num) {
            l1 = l1->next;
            continue;
        }
        cout << l1->next->num << " ";
        addList(all, l1->next->num);
        last = l1->next->num;
        l1 = l1->next;
    }
    return 0;
}