#include <iostream>
using namespace std;

class FruitSeller {
private:
	const int APPLE_PRICES;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
		: APPLE_PRICES(price), numOfApples(num), myMoney(money)
	{
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICES;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl;
	}
};

class FruitBuyer {
private:
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money) 
		: myMoney(money), numOfApples(0)
	{
	}
	void BuyApples(FruitSeller& seller, int money) {
		if (money < 0) {
			cout << "잘못된 정보가 전달되어 구매를 취소합니다." << endl;
			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void) {
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}