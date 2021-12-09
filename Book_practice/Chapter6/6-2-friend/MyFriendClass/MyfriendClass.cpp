#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Girl;	// Girl�̶�� �̸��� Ŭ������ �̸����� �˸�

class Boy {
private:
	int height;
	friend class Girl;	// Girl Ŭ������ ���� friend ����
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
	friend class Boy;	// Boy Ŭ������ ���� friend ����
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