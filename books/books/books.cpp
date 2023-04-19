#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
using namespace std;
struct book {
	string name, writer, place, date;
}tab[505];
int n;
bool cmp(book a, book b) {
	return a.name<b.name;
}
void addb() {
	cin >> tab[n].name >> tab[n].writer >> tab[n].place >> tab[n].date;
	n++;
	sort(tab, tab + n, cmp);
}
void delb(int x) {
	for (int i = x; i < n; i++) {
		tab[i] = tab[i + 1];
	}
	n--;
}
int main() {
	ifstream file;
	file.open("books.txt");
	while (file >> tab[n].name) {
		file >> tab[n].writer >> tab[n].place >> tab[n].date;
		n++;
	}
	file.close();
	sort(tab, tab + n, cmp);
	int op;
	while (cin >> op) {
		if (op == 0) {
			break;
		}
		if (op == 1) {
			addb();
			continue;
		}
		if (op == 2) {
			string s;
			cin >> s;
			for (int i = 0; i < n; i++) {
				if (tab[i].name.find(s) != string::npos) {
					cout << setw(50) << setiosflags(ios::left) << tab[i].name;
					cout << setw(20) << setiosflags(ios::left) << tab[i].writer;
					cout << setw(30) << setiosflags(ios::left) << tab[i].place;
					cout << setw(10) << setiosflags(ios::left) << tab[i].date;
					cout << endl;
				}
			}
			continue;
		}
		if (op == 3) {
			string s;
			cin >> s;
			for (int i = 0; i < n; i++) {
				while (tab[i].name.find(s) != string::npos) {
					delb(i);
				}
			}
			continue;
		}
	}
	ofstream ofile;
	ofile.open("ordered.txt");
	for (int i = 0; i < n; i++) {
		ofile << setw(50) << setiosflags(ios::left) << tab[i].name;
		ofile << setw(20) << setiosflags(ios::left) << tab[i].writer;
		ofile << setw(30) << setiosflags(ios::left) << tab[i].place;
		ofile << setw(10) << setiosflags(ios::left) << tab[i].date;
		ofile << endl;
	}
	ofile.close();
	return 0;
}