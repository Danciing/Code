#include<iostream>
using namespace std;
int main() {
	cout << "Menu: A(dd) D(elete) S(ort) Q(uit), Select one:"<<endl;
	char t;
	while (1) {
		cin >> t;
		
		switch (t) {
			case 'A':cout << "�����Ѿ����ӡ�"<<endl;
					break;
			case 'D':cout << "�����Ѿ�ɾ����"<<endl;
					break;
			case 'S':cout << "�����Ѿ�����"<<endl;
					break;
			default:break;
		}
		if (t == 'Q') {
			break;
		}
		else continue;
	}
	return 0;
}