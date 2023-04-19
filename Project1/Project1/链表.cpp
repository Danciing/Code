#include<iostream>
using namespace std;
int main() {
	cout << "Menu: A(dd) D(elete) S(ort) Q(uit), Select one:"<<endl;
	char t;
	while (1) {
		cin >> t;
		
		switch (t) {
			case 'A':cout << "数据已经增加。"<<endl;
					break;
			case 'D':cout << "数据已经删除。"<<endl;
					break;
			case 'S':cout << "数据已经排序。"<<endl;
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