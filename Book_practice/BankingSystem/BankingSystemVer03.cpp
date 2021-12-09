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
	int accountID; //���¹�ȣ
	char* cusName;
	int balance = 0; //���� �ܾ�

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
		cout << "����ID: " << accountID << endl;
		cout << "�� ��: " << cusName << endl;
		cout << "�� ��: " << balance << endl;
	}

	~Account() {
		delete []cusName;
	}
};

Account* accArr[100]; //Account ������ ���� �迭
int accNum = 0; //����� Account ��

int main()
{
	int choice;

	while (1) {
		showMenu();
		cout << "����: "; cin >> choice;
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
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}

void showMenu() {

	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void makeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;


	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}


void depositMoney() {
	int id, money;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "�Ա� �Ϸ�\n";
			return;
		}
	}
	cout << "�ش� ���´� �������� �ʽ��ϴ�." << endl;

}

void withdrawMoney() {
	int id, money;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��� �Ϸ�\n";
			return;
		}
	}
	cout << "�ش� ���´� �������� �ʽ��ϴ�." << endl;

}

void printAllAccInfo() {

	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowInfo();
		cout << endl << endl;
	}

}