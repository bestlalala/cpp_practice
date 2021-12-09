#include <iostream>
#include <vector>
using namespace std;

/*
* 3글자짜리 단어 맞추기
* 문제를 맞추면 10점 부여
* 1단어당 맞출 수 있는 기회는 7번
* 한 문제당 글자수는 맘대로
* 3문제. 점수는 3문제의 누적 점수
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
void Hangman::check(char &input) {	// 입력한 답이 맞는지 확인하는 함수
	bool flag = false;
	for (int i = 0; i < answer.size(); i++) {
		if (input == answer[i]) {
			empty[i] = input;
			flag = true;
			total += 10;	//맞으면 점수+10
		}
	}
	if (!flag) {
		chance--;	//틀리면 찬스 깎임.
	}
	
}
void Hangman::printAnswer(){
	cout << "--- 문제 종료 ---" <<  "정답: ";
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
		cout << endl << "답을 입력하세요: ";
		cin >> input;
		check(input);
		cout << "현재 점수: " << total << endl;
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