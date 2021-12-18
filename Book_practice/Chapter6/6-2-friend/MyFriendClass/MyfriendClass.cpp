#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Girl;	// Girl이라는 이름이 클래스의 이름임을 알림

class Boy {
private:
	int height;
	friend class Girl;	// Girl 클래스에 대한 friend 선언
public:
	Boy(int len);
	void ShowYourFriendInfo(Girl& frn);
};


class Girl {
private:
	char phNum[20];
public:
	Girl(const char* num);
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;	// Boy 클래스에 대한 friend 선언
};

Boy::Boy(int len) : height(len) {};

void Boy::ShowYourFriendInfo(Girl& frn) {
	cout << "Her phone number: " << frn.phNum << endl;
}


Girl::Girl(const char *num) {
	strcpy(phNum, num);
}

void Girl::ShowYourFriendInfo(Boy& frn) {
	cout << "His height: " << frn.height << endl;
}

int main() {
	Boy boy(180);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}