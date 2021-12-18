#include <iostream>
#include <vector>
#include <string>
using namespace std;
// �ڿ����� �����ϴ� ���� Ʈ�� ����

class Node {
	int num;
	Node* less, * more;
public:
	Node(int n);
	int getNum();
	void insert(int n);
	int depth();
	int max();
	int min();
	void sumAndCount(int& sum, int& count);
	string ordered();
};

Node::Node(int n) :num(n), less(nullptr), more(nullptr) {};

int Node::getNum() {
	return num;
}
void Node::insert(int n) {
	if (n < num) {
		if (less == NULL)
			less = new Node(n);
		else
			less->insert(n);
	}
	else {
		if (more == NULL)
			more = new Node(n);
		else
			more->insert(n);
	}
}
int Node::depth() {
	int l, m;
	if (less != NULL)
		l = less->depth();
	else
		l = 0;

	if (more != NULL)
		m = more->depth();
	else
		m = 0;

	if (l > m)
		return l + 1;
	else
		return m + 1;
}
int Node::max() {
	if (more == NULL)
		return num;
	else
		return more->max();
}
int Node::min() {
	if (less == NULL)
		return num;
	else
		return less->min();
}
void Node::sumAndCount(int& sum, int& count) {
	sum += num;
	count++;
	if (less != NULL)
		less->sumAndCount(sum, count);
	if (more != NULL)
		more->sumAndCount(sum, count);
}
string Node::ordered() {
	string temp = "";
	if (less != NULL)
		temp = less->ordered(); // ���� ���� �� ���� �ֱ�
	temp += to_string(num);
	temp += ":";
	if (more != NULL)
		temp += more->ordered();
	return temp;
}

class Tree { // less ���� �湮
	Node* root;
public:
	Tree();
	void insert(int n);
	int depth();
	int max();
	int min();
	int mean();
	string ordered();
};

Tree::Tree() { root = NULL; }


void Tree::insert(int n) {
	if (root == NULL)
		root = new Node(n);
	else
		root->insert(n);
}

int Tree::depth() {
	if (root == NULL)
		return 0;
	else
		return root->depth();
}

int Tree::max() {
	if (root == NULL)
		return -1;
	else
		return root->max();
	
}
int Tree::min() {
	if (root == NULL)
		return -1;
	else
		return root->min();
}

int Tree::mean() {
	int sum = 0, count = 0;
	if (root == NULL)
		return -1;
	else {
		root->sumAndCount(sum, count);
		return (sum / count);
	}
}

string Tree::ordered() {
	if (root == NULL)
		return "";
	else
		return root->ordered();
}

int main() {
	Tree mytree;
	mytree.insert(4); //root node�� ��.
	mytree.insert(1);
	mytree.insert(2);
	mytree.insert(9);

	cout << "����: " << mytree.depth() << endl;
	cout << "�ִ�: " << mytree.max() << " �ּڰ�: " << mytree.min() << endl;
	cout << "���: " << mytree.mean() << endl;
	cout<< "�������� ����: " << mytree.ordered() << endl;
}