#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n);
	SoSimple& AddNum(int n);
	void SimpleFunc();
	void SimpleFunc() const;
};

SoSimple::SoSimple(int n) :num(n) {}
SoSimple& SoSimple::AddNum(int n) {
	num += n;
	return *this;
}
void SoSimple::SimpleFunc() {
	cout << "SimpleFunc: " << num << endl;
}
void SoSimple::SimpleFunc() const {
	cout << "const SimpleFunc: " << num << endl;
}

void YourFunc(const SoSimple& obj) {
	obj.SimpleFunc();
}

int main(void) {
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YourFunc(obj1);
	YourFunc(obj2);

	return 0;
}