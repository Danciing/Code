#include<iostream>
#include<algorithm>
using namespace std;
struct Line {
	int id;
	int l, r ;
	int cost = 0;
};
int fa[1005];
int ff(int n) {
	while (n != fa[n]) {
		n = fa[n];
	}
	return n;
}
bool cmp(Line x, Line y) {
	return x.cost < y.cost;
}
int main() {
	int n, m, a, b, ans = 0, cnt = 0;
	Line tab[10005];
	int ians[1005];
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tab[i].id >> tab[i].l >> tab[i].r >> tab[i].cost;
	}
	for (int i = 0; i < n; i++)
		fa[i] = i;
	sort(tab, tab + m, cmp);
	for (int i = 0; i < m; i++) {
		if (cnt == n - 1)break;
		int l = tab[i].l, r = tab[i].r;
		if (ff(l)!=ff(r)) {
			fa[ff(l)] = fa[ff(r)];
			ians[cnt] = tab[i].id;
			cnt++;
			ans += tab[i].cost;
		}
	}
	cout << ans << endl;
	sort(ians, ians + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << ians[i] << " ";
	}
	return 0;
}