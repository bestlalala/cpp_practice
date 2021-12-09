#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void showMenu();
void makeAccount();
void depositMoney();
void withdrawMoney();
void printAllAccInfo();

class Account {

private:
	int accountID; //계좌번호
	char* cusName;
	int balance = 0; //고객의 잔액

public:
	
	Account(int id, int money, char* name) : accountID(id), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(const Account& copy) :accountID(copy.accountID), balance(copy.balance) {
		cusName = new char[strlen(copy.cusName) + 1];
		strcpy(cusName, copy.cusName);
	}

	int GetAccID() {
		return accountID;
	}
	
	void Deposit(int money) {
		balance += money;
	}

	int Withdraw(int money) {
		if (balance < money)
			return 0;
		
		balance -= money;
		return money;
	}

	void ShowInfo() {
		cout << "계좌ID: " << accountID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액: " << balance << endl;
	}

	~Account() {
		delete []cusName;
	}
};

Account* accArr[100]; //Account 저장을 위한 배열
int accNum = 0; //저장된 Account 수

int main()
{
	int choice;

	while (1) {
		showMenu();
		cout << "선택: "; cin >> choice;
		cout << endl;
		
		switch (choice)
		{
		case 1: makeAccount(); break;
		case 2: depositMoney(); break;
		case 3: withdrawMoney(); break;
		case 4: printAllAccInfo(); break;
		case 5: 
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}

void showMenu() {

	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void makeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;


	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}


void depositMoney() {
	int id, money;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "입금 완료\n";
			return;
		}
	}
	cout << "해당 계좌는 존재하지 않습니다." << endl;

}

void withdrawMoney() {
	int id, money;
	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금 완료\n";
			return;
		}
	}
	cout << "해당 계좌는 존재하지 않습니다." << endl;

}

void printAllAccInfo() {

	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowInfo();
		cout << endl << endl;
	}

}