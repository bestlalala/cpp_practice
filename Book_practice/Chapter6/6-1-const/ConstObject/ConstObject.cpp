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
	// obj.AddNum(20); AddNum은 const 함수가 아니기 때문에 호출 불가능
	obj.ShowData(); //const 함수이기 때문에 const 객체를 대상으로 호출 가능
	return 0;
}