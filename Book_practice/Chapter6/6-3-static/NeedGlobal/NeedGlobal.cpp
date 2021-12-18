#include <iostream>
using namespace std;

// 전역변수로 선언
int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple {
public:
	SoSimple();
};

SoSimple::SoSimple() {
	simObjCnt++;
	cout << simObjCnt << "번째 SoSimple 객체" << endl;
}

class SoComplex {
public:
	SoComplex();
	SoComplex(SoComplex& copy);
};

SoComplex::SoComplex() {
	cmxObjCnt++;
	cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
}
SoComplex::SoComplex(SoComplex& copy) {
	cmxObjCnt++;
	cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
}

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}