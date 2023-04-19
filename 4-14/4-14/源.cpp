#include<iostream>
using namespace std;
class Tree {
	public:
		Tree(int age_now);
		void grow(int years);
		int age();
	private:
		int ages;
};
Tree::Tree(int age_now):ages(age_now) {}
void Tree::grow(int years) {
	ages += years;
}
int Tree::age() {
	return ages;
}
int main() {
	Tree a(8);
	a.grow(10);
	cout << a.age();
	return 0;
}