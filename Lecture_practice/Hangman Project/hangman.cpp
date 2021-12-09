#include <iostream>
#include <vector>
using namespace std;

/*
* 3����¥�� �ܾ� ���߱�
* ������ ���߸� 10�� �ο�
* 1�ܾ�� ���� �� �ִ� ��ȸ�� 7��
* �� ������ ���ڼ��� �����
* 3����. ������ 3������ ���� ����
*/

class Hangman {
private:
	int total = 0;
	vector<char> empty;
	vector<char> answer;
	int chance;
	char graphic[8] = "|O/|\\/\\";
	void initchance();
	void initempty();
	void game(char* word);
public:
	void showchance();
	void showempty();
	void check(char& input);
	void q1();
	void q2();
	void q3();
	void printAnswer();
	void play();
};


void Hangman::initchance() {
	chance = 7;
}


void Hangman::showchance() {
	for (int i = 0; i < (7 - chance);i++) {
		switch (i) {
		case 0:
		case 1:
			cout << " " << graphic[i] << " " << endl; break;
		case 4:
			cout << graphic[i] << endl; break;
		case 6:
			cout << " " << graphic[i] << endl;  break;
		default:
			cout << graphic[i]; break;
		}
	}
}

void Hangman::initempty() {
	empty.clear();
	for (int i = 0; i < answer.size(); i++) {
		empty.push_back('_');
	}
}
void Hangman::showempty() {
	for (int i = 0; i < answer.size(); i++) {
		cout << empty[i] << " ";
	}
	cout << endl;
}
void Hangman::check(char &input) {	// �Է��� ���� �´��� Ȯ���ϴ� �Լ�
	bool flag = false;
	for (int i = 0; i < answer.size(); i++) {
		if (input == answer[i]) {
			empty[i] = input;
			flag = true;
			total += 10;	//������ ����+10
		}
	}
	if (!flag) {
		chance--;	//Ʋ���� ���� ����.
	}
	
}
void Hangman::printAnswer(){
	cout << "--- ���� ���� ---" <<  "����: ";
	for (int i = 0; i < answer.size(); i++) 
		cout << answer[i];
	cout << endl << endl;
}
void Hangman::game(char *word) {
	answer.clear();
	for (int i = 0; i < strlen(word); i++) {
		answer.push_back(word[i]);
	}
	initempty();
	initchance();

	while (1){
		showempty();
		showchance();
		char input;
		cout << endl << "���� �Է��ϼ���: ";
		cin >> input;
		check(input);
		cout << "���� ����: " << total << endl;
		if (answer == empty || chance == 0) {
			printAnswer();
			break;
		}
	}
}

void Hangman::q1() {
	char word[] = "bug";
	game(word);
}
void Hangman::q2() {
	char word[] = "pencil";
	game(word);
}
void Hangman::q3() {
	char word[] = "code";
	game(word);
}
void Hangman::play() {
	cout << "Q1. ";
	q1();
	cout << "Q2. ";
	q2();
	cout << "Q3. ";
	q3();
}


int main() {
	Hangman hman;
	hman.play();
}