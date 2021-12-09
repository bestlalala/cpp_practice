#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y) :xpos(x), ypos(y) 
	{ }

	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int rad;
public:

	Circle(int a, int b, int r) : center(a, b) 
	{
		rad = r;
	}

	void ShowCircleInfo() const {
		cout << "radius: " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inCircle, outCircle;
public:
	Ring(int a1, int b1, int r1, int a2, int b2, int r2) 
		: inCircle(a1, b1, r1), outCircle(a2, b2, r2) 
	{    }
	
	void ShowRingInfo() const {		
		cout << "Inner Circle Info..." << endl;
		inCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outCircle.ShowCircleInfo();
		
	}
};

int main() {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}