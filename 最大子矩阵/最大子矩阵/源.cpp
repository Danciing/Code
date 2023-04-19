#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream file;
	file.open("in.txt");
	int m, n, x, y;
	file >> n >> m >> x >> y;
	int num[1005][1005];
	int dp[1005][1005];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			file >> num[i][j];
		}
	}
	for (int i = 1; i <= n - x + 1; i++) {
		for (int j = 1; j <= m - y + 1; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = 0;
				for (int o = i; o < i + x; o++) {
					for (int k = j; k < j + y; k++) {
						dp[i][j] += num[o][k];
					}
				}
			}
			else if (j == 1) {
				dp[i][j] = dp[i - 1][j];
				for (int k = j; k < j + y; k++) {
					dp[i][j] += num[i + x - 1][k] - num[i - 1][k];
				}				
			}
			else {
				dp[i][j] = dp[i][j - 1];
				for (int o = i; o < i + x; o++) {
					dp[i][j] += num[o][j + y - 1] - num[o][j - 1];
				}
			}
			if (ans < dp[i][j]) {
				ans = dp[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}