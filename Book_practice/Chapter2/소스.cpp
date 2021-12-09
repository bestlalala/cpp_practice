#include <iostream>	
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct __Point
{
	int xpos, ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main(void) {
	Point* a = new Point;
	Point* b = new Point;

	a->xpos = 10;
	a->ypos = 20;
	b->xpos = 35;
	b->ypos = 12;

	Point &c = PntAdder(*a, *b);

	cout << "result: " << "("<< c.xpos << ", " << c.ypos << ")" << endl;

	delete(a);
	delete(b);

	return 0;
}

Point& PntAdder(const Point& p1, const Point& p2) {
	Point *result = new Point;
	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;
	return *result;
}