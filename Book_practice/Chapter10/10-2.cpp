#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this;
	}
	
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}

	friend Point operator~(const Point& pos);
};

Point operator~(const Point& pos) {
	Point p(pos.ypos, pos.xpos);
	return p;
}