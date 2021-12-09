#include <iostream>
using namespace std;

class Calculator
{
private:
	int addcount, mincount, mulcount, divcount;
	double x, y, result;
public:
	void Init();
	double Add(double x, double y);
	double Min(double x, double y);
	double Mul(double x, double y);
	double Div(double x, double y);
	void ShowOpCount();
};

void Calculator::Init() {
	addcount = 0, mincount = 0, mulcount = 0, divcount = 0;
}

double Calculator::Add(double x, double y) {
	result = x + y;
	addcount++;
	return result;
}

double Calculator::Min(double x, double y) {
	result = x - y;
	mincount++;
	return result;
}
double Calculator::Mul(double x, double y) {
	result = x * y;
	mulcount++;
	return result;
}
double Calculator::Div(double x, double y) {
	result = x / y;
	divcount++;
	return result;
}
void Calculator::ShowOpCount() {
	cout << "µ¡¼À: " << addcount << "  ";
	cout << "»¬¼À: " << mincount << "  ";
	cout << "°ö¼À: " << mulcount << "  ";
	cout << "³ª´°¼À: " << divcount << "  ";
}

int main(){

	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}