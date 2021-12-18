#include <iostream>
using namespace std;

class SoSimple {
private:
	static int simObjCnt; // �������X. ��������� ��ó�� ���� ����
public:
	SoSimple();
};

SoSimple::SoSimple() {
	simObjCnt++;
	cout << simObjCnt << "��° SoSimple ��ü" << endl;
}

int SoSimple::simObjCnt = 0; // static ������ �����ڰ� �ƴ� Ŭ���� �ܺο��� �ʱ�ȭ�ؾ� ��.

class SoComplex {
private:
	static int cmxObjCnt;
public:
	SoComplex();
	SoComplex(SoComplex& copy);
};

SoComplex::SoComplex() {
	cmxObjCnt++;
	cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
}
SoComplex::SoComplex(SoComplex& copy) {
	cmxObjCnt++;
	cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
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