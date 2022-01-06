#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

class Maze {
protected:
	int row, col;
	int crow, ccol;
	char direction;
	vector<vector<char>> map;
	void readMap(const char* name);
	bool isDone();
	void mark(int r, int c);
	void getNextPositions(int& f1_r, int& f1_c, int& f2_r, int& f2_c);
	void turn(bool clockwise);
	void move();
public:
	void play(const char* name);
	friend ostream& operator<<(ostream& output, const Maze& m);
};

void Maze::readMap(const char* name) {
	ifstream ifs(name);
	ifs >> row;
	ifs >> col;
	for (int i = 0; i < row; i++) {
		vector<char> arow;
		for (int j = 0; j < col; j++) {
			char c;
			ifs >> c;
			arow.push_back(c);
			if (c == 's') {
				crow = i; ccol = j;
				if (i == 0)
					direction = 's';
				else if (j == 0)
					direction = 'e';
				else if (i == (row - 1))
					direction = 'n';
				else
					direction = 'w';
			}
		}
		map.push_back(arow);
	}
}

bool Maze::isDone() {
	if (map[crow][ccol] == 'x')
		return true;
	else
		return false;
}

void Maze::mark(int r, int c) {
	if (map[r][c] == '.') map[r][c] = '*';
	else if (map[r][c] == '*')
		map[crow][ccol] = '.';
}

void Maze::getNextPositions(int& f1_r, int& f1_c, int& f2_r, int& f2_c) {
	switch (direction) {
	case 'n':
		f1_r = crow - 1; f1_c = ccol;
		f2_r = crow - 2; f2_c = ccol + 1;
		break;
	case 's':
		f1_r = crow + 1; f1_c = ccol;
		f2_r = crow - 2; f2_c = ccol - 1;
		break;
	case 'e':
		f1_r = crow; f1_c = ccol;
		f2_r = crow - 2; f2_c = ccol + 1;
		break;
	case 'w':
		f1_r = crow; f1_c = ccol;
		f2_r = crow; f2_c = ccol - 1;
		break;
	}
}

void Maze::turn(bool clockwise) {
	switch (direction) {
	case 'n':
		if (clockwise) direction = 'e';
		else direction = 'w';
		break;
	case 's':
		if (clockwise) direction = 'w';
		else direction = 'e';
		break;
	case 'e':
		if (clockwise) direction = 's';
		else direction = 'n';
		break;
	case 'w':
		if (clockwise) direction = 'n';
		else direction = 's';
		break;
	}
}

void Maze::move() {
	int f1_r, f1_c, f2_r, f2_c;
	getNextPositions(f1_r, f1_c, f2_r, f2_c);
	if (map[f1_r][f1_c] != '#' && map[f2_r][f2_c] == '#') {
		mark(f1_r, f1_c);
		crow = f1_r;
		ccol = f1_c;
	}
	else if (map[f1_r][f1_c] != '#' && map[f2_r][f2_c] == '#') {
		turn(false);
	}
	else {
		mark(f1_r, f1_c);
		crow = f2_r;
		ccol = f2_c;

		mark(f2_r, f2_c);
		turn(true);
		crow = f2_r;
		ccol = f2_c;
	}
}

void Maze::play(const char* name) {
	readMap(name);
	while (!isDone())
		move();
}

ostream& operator<<(ostream& output, const Maze& m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			output << m.map[i][j];
		}
		output << endl;
	}
	return output;
}

class Position {
	int row, col;
	Position* prev;
public:
	Position(int r, int c, Position* p);
	void getRC(int& r, int& c); // row와 col 가져오는 함수
	Position* getPrev();
};

Position::Position(int r, int c, Position* p) {
	row = r;
	col = c;
	prev = p;
}
void Position::getRC(int& r, int& c) {
	r = row; c = col;
}

Position* Position::getPrev() { return prev; }

class BFSMaze : public Maze {
	list<Position*> q;
	list<Position*> o;
	Position* find();
	void trace(Position* p);
	void open(Position* p);
	bool addable(int nr, int nc);
public:
	~BFSMaze();
	void play(const char* name);
	friend ostream& operator<<(ostream& output, const BFSMaze& m);
};

BFSMaze::~BFSMaze() {
	list<Position*>::iterator it, itt;
	for (it = q.begin(); it != q.end();) {
		itt = it;
		++it;
		delete (*itt);
	}
	for (it = o.begin(); it != o.end();) {
		itt = it;
		++it;
		delete (*itt);
	}
}

Position* BFSMaze::find() {
	Position* p;
	Position* t;
	int r, c;
	p = new Position(crow, ccol, NULL);
	q.push_back(p);
	while (!q.empty()) {
		t = q.front();
		q.pop_front();
		o.push_back(t); // open에 맨 앞에꺼 넣기
		t->getRC(r, c);
		if (map[r][c] == 'x')
			return t;
		else
			open(t);
	}
	return NULL;
}

void BFSMaze::open(Position* p) { //내가 그 다음번에 이동할 수 있는 자리
	int r, c;
	int nr, nc;
	p->getRC(r, c);

	nr = r + 1; nc = c;
	if (addable(nr, nc))
		q.push_back(new Position(nr, nc, p));

	nr = r - 1; nc = c;
	if (addable(nr, nc))
		q.push_back(new Position(nr, nc, p));

	nr = r; nc = c - 1;
	if (addable(nr, nc))
		q.push_back(new Position(nr, nc, p));

	nr = r; nc = c + 1;
	if (addable(nr, nc))
		q.push_back(new Position(nr, nc, p));
}

bool BFSMaze::addable(int r, int c) {
	// 1. 경계를 벗어나는가?
	// 2. 벽인가?
	// 3. 이미 방문한 위치인가?
	if (r < 0 || r >= row || c < 0 || c >= col)
		return false;
	if (map[r][c] == '#')
		return false;

	list<Position*>::iterator it;
	int tr, tc;
	for (it = q.begin(); it != q.end(); ++it) {
		(*it)->getRC(tr, tc);
		if (tr == r && tc == c)
			return false;
	}
	for (it = o.begin(); it != o.end(); ++it) {
		(*it)->getRC(tr, tc);
		if (tr == r && tc == c)
			return false;
	}

	return true;
}

void BFSMaze::trace(Position* p) {
	int r, c;
	do {
		p->getRC(r, c);
		mark(r, c);
		p = p->getPrev();
	} while (p != NULL);
}

void BFSMaze::play(const char* name) {
	readMap(name);
	Position* final;
	final = find();
	trace(final);
}

ostream& operator<<(ostream& output, const BFSMaze& m) {
	return output << (Maze&)m;
}

int main() {
	Maze mymaze;
	mymaze.play("12BY12.txt");
	cout << mymaze << endl;

	BFSMaze mymaze2;
	mymaze2.play("12BY12.txt");
	cout << mymaze2 << endl;
}
