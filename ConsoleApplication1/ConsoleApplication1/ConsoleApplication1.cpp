#include"iostream"
#include"stdio.h"
#include"math.h"
#include"iomanip"
using namespace std;

//定义一个学生姓名+成绩的结构体
struct student {
    char name[16];
    int score;
};

//定义一个结点结构体
struct node {
    int data;
    node* next;
};

//创建一个链表
node* newList(student a[], int n) {
    node* head = NULL;
    node* end = NULL, * p = NULL; //end指向链表末端，p指向新的结点
    head = (node*)malloc(sizeof(node));
    end = head;
    head->next = NULL;

    int i;
    for (i = 0; i < n; i++) {
        p = (node*)malloc(sizeof(node));
        cin >> a[i].score;
        p->data = a[i].score;
        if (p->data != NULL) {
            end->next = p; //把p接在end指针后面
            p->next = NULL; //p结点变为末尾元素
            end = p; //把end指针移动到链表末尾
        }
    }

    return head;
}

//统计链表长度
int length(node* head, int l) {
    return l;
}

//查找第i个元素
//int Findnode(node* head,int i) {
 //int end;

 //return end;
//}

//将数据x插入链表
node* insternode(node* head, int x, int i) {
    return head;
}

//删除链表中的数据y
node* deletenode(node* head, int y) {
    return head;
}

//打印链表
void printnode(node* head, int n) {
    node* p;
    p = head->next;
    while (p != NULL) {
        cout << p->data; 
        p = p->next;
    }
    
}

int main() {
    int n;
    int i;
    node* head = NULL;

    //创建一个单链表，输入数据并打印
    cout << "请输入单链表长度：" << endl;
    cin >> n;
    student* a = new student[n];
    head = newList(a, n);
    printnode(head, n);

    

}