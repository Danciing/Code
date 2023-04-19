#include<iostream>
#include<algorithm>
#include <fstream>
using namespace std;
char k;
ofstream Ans("Ans.txt", ios::out);
struct Point {
	double x, y, z;
}Ptab[10000];
struct Line {
	double dx, dy, dz;
	double x, y, z;
	double lmin, lmax;
}Ltab[100000];
bool cmp(Line a, Line b) {
	return a.lmin < b.lmin;
}
void genL(Point a, Point b, int n) {
	Line& t = Ltab[n];
	if (k == 'x') {
		if (a.x > b.x) {
			swap(a, b);
		}
		t.x = a.x;
		t.y = a.y;
		t.z = a.z;
		t.dx = b.x - a.x;
		t.dy = b.y - a.y;
		t.dz = b.z - a.z;
		t.lmin = a.x;
		t.lmax = b.x;
		return;
	}
	if (k == 'y') {
		if (a.y > b.y) {
			swap(a, b);
		}
		t.x = a.x;
		t.y = a.y;
		t.z = a.z;
		t.dx = b.x - a.x;
		t.dy = b.y - a.y;
		t.dz = b.z - a.z;
		t.lmin = a.y;
		t.lmax = b.y;
		return;
	}
	if (k == 'z') {
		if (a.z > b.z) {
			swap(a, b);
		}
		t.x = a.x;
		t.y = a.y;
		t.z = a.z;
		t.dx = b.x - a.x;
		t.dy = b.y - a.y;
		t.dz = b.z - a.z;
		t.lmin = a.z;
		t.lmax = b.z;
		return;
	}
}
void genP(double du, int i) {
	Line& now = Ltab[i];
	if (k == 'x') {
		Ans << du << " " << (du - now.x) * now.dy / now.dx + now.y << " " << (du - now.x) * now.dz / now.dx + now.z << '\n';
	}
	if (k == 'y') {
		Ans << (du - now.y) * now.dx / now.dy + now.x << " " << du << " " << (du - now.y) * now.dz / now.dy + now.z << '\n';
	}
	if (k == 'z') {
		Ans << (du - now.z) * now.dx / now.dz + now.x << " " << (du - now.z) * now.dy / now.dz + now.y << " " << du << '\n';
	}
	if (du >= Ltab[i+1].lmin) {
		genP(du, i + 1);
	}
}
int main() {
	ifstream Pfile("Res01.txt", ios::in);
	int n;
	double m;
	Pfile >> n;
	for (int i = 0; i < n; i++) {
		Pfile >> Ptab[i].x >> Ptab[i].y >> Ptab[i].z;
	}
	cout << "请输入选择的轴，按照x、y或z输入：";
	cin >> k;
	cout << "请输入选择的度：";
	cin >> m;
	Pfile >> n;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		Pfile >> a >> b >> c;
		genL(Ptab[a], Ptab[b], i * 3);
		genL(Ptab[a], Ptab[c], i * 3 + 1);
		genL(Ptab[b], Ptab[c], i * 3 + 2);
		
	}
	Pfile.close();
	sort(Ltab, Ltab+3*n, cmp);	
	int num = 1, i = 0;
	while (i < 3*n) {
		Line& now = Ltab[i];
		if (m * num > now.lmax) {
			i++;
			continue;
		}
		if (m * num >= now.lmin) {
			genP(m * num, i);
		}
		num++;
	}
	Ans.close();
	return 0;
}