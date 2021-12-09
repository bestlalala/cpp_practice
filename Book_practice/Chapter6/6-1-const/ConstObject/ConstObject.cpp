#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n);
	SoSimple& AddNum(int n);
	void ShowData() const;
};

SoSimple::SoSimple(int n) :num(n) {}
SoSimple& SoSimple::AddNum(int n) {
	num += n; 
	return *this;
}
void SoSimple::ShowData() const {
	cout << "num: " << num << endl;
}

int main(void) {
	const SoSimple obj(7);
	// obj.AddNum(20); AddNum�� const �Լ��� �ƴϱ� ������ ȣ�� �Ұ���
	obj.ShowData(); //const �Լ��̱� ������ const ��ü�� ������� ȣ�� ����
	return 0;
}