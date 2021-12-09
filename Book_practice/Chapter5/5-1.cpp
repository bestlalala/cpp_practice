#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionName(int n) {

		switch (n) {
		case CLERK:
			cout << "사원";
			break;
		case SENIOR:
			cout << "주임";
			break;
		case ASSIST:
			cout << "대리";
			break;
		case MANAGER:
			cout << "과장";
			break;
		}
		cout << endl;
	}
}

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(char* name, char* company, char* phone, int pos) : position(pos) 
	{
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);
	}

	NameCard(const NameCard& copy) : position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		company = new char[strlen(copy.company) + 1];
		phone = new char[strlen(copy.phone) + 1];

		strcpy(name, copy.name);
		strcpy(company, copy.company);
		strcpy(phone, copy.phone);
	}

	void ShownameCardInfo();

	~NameCard() {
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

void NameCard::ShownameCardInfo() {
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << phone << endl;
	cout << "직급: "; COMP_POS::ShowPositionName(position);

}


int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010 - 3333 - 4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShownameCardInfo();
	copy2.ShownameCardInfo();
	return 0;
}