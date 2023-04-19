#include<iostream>
using namespace std;
class Complex {
public:
	Complex(double nshi, double nxu=0);
	Complex(const Complex& a);
	void add(Complex a);
	void show();
private:
	double shi;
	double xu;
};
Complex::Complex(double nshi=0,double nxu):shi(nshi),xu(nxu){}
Complex::Complex(const Complex& a) {
	shi = a.shi;
	xu = a.xu;
}
void Complex::add(Complex a) {
	shi += a.shi;
	xu += a.xu;
}
void Complex::show() {
	cout << shi << "+" << xu << "i";
}
int main() {
	Complex c1(3, 5);
	Complex c2 = 4.5;
	c1.add(c2);
	c1.show();
	return 0;
}