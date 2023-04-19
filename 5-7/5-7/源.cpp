#include<iostream>
using namespace std;
class Cat {
public:
	Cat(int nage);
	static int getNumOfCats();
private:
	static int numOfCats;
	int age;
};
int Cat::numOfCats = 0;
Cat::Cat(int nage):age(nage){
	numOfCats++;
}
int Cat::getNumOfCats() {
	return numOfCats;
}
int main() {
	Cat a(1);
	cout << a.getNumOfCats() << endl;
	Cat b(3);
	cout << Cat::getNumOfCats();
	return 0;
}