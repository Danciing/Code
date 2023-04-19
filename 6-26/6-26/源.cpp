#include<iostream>
#include<vector>
using namespace std;
void transpose(vector<vector<int>>&t, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			swap(t[i][j], t[j][i]);
		}
	}
}
int main() {
	int n, m;
	cout << "Please import the row and column of a matrix:";
	cin >> n >> m;
	vector<vector<int>>a(n,vector<int>(m));
	cout << "Please import a matrix:";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	transpose(a, n, m);
	cout << "This is the transposed matrix:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}