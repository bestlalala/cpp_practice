#include <iostream>
using namespace std;

class SoSimple {
private:
	static int simObjCnt; // 멤버변수X. 멤버변수인 것처럼 접근 가능
public:
	SoSimple();
};

SoSimple::SoSimple() {
	simObjCnt++;
	cout << simObjCnt << "번째 SoSimple 객체" << endl;
}

int SoSimple::simObjCnt = 0; // static 변수는 생성자가 아닌 클래스 외부에서 초기화해야 함.

class SoComplex {
private:
	static int cmxObjCnt;
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

int SoComplex::cmxObjCnt = 0;

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();

	return 0;
}