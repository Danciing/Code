#include<iostream>
using namespace std;
class Circle {
	public:
		Circle(int x);
		double getArea();
	private:
		int radius;
};
Circle::Circle(int x) :radius(x) {}
double Circle::getArea() {
	return radius * radius * 3.14;
}
int main() {
	Circle a(3);
	cout << a.getArea();
	return 0;
}