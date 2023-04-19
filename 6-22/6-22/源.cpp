#include<iostream>
#include<cstring>
using namespace std;
void reverse(string& s) {
	if (s[1] != 0) {
		string t;
		t = s.substr(1, s.length() - 1);
		reverse(t);
	}
	cout << s[0];
}
int main() {
	string a;
	cin >> a;
	reverse(a);
	return 0;
}