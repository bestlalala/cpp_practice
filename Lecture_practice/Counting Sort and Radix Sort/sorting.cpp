#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Sorting {
public:
	virtual void sort(vector<int>& nums) = 0;
	static void print(vector<int>& nums);
};

void Sorting::print(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";

	cout << endl;
}

class Counting : public Sorting {
private:
	void countFrequency(int* count, vector<int>& nums);
	void calFirstPos(int* count, int* pos);
	void countsort(int* pos, vector<int>& nums);
protected:
	virtual int getValue(int v);
public:
	void sort(vector<int>& nums);
};

int Counting::getValue(int v) {
	return v;
}

void Counting::countFrequency(int* count, vector<int>& nums) {
	for (int i = 0; i < 10; i++)
		count[i] = 0;
	for (int i = 0; i < nums.size(); i++)
		count[getValue(nums[i])]++;
}
void Counting::calFirstPos(int* count, int* pos) {
	for (int i = 0; i < 10; i++)
		pos[i] = 0;
	for (int i = 1; i < 10; i++)
		pos[i] = pos[i - 1] + count[i - 1];
}
void Counting::countsort(int* pos, vector<int>& nums) {
	vector<int> temp;
	for (int i = 0; i < nums.size(); i++)
		temp.push_back(0);
	for (int i = 0; i < nums.size(); i++) {
		temp[pos[getValue(nums[i])]] = nums[i];
		pos[getValue(nums[i])]++;
	}
	for (int i = 0; i < nums.size(); i++) {
		nums[i] = temp[i];
	}
}

void Counting::sort(vector<int>& nums) {
	int count[10];
	int pos[10];
	// 1. 빈도수 세기
	countFrequency(count, nums);
	// 2. 각 숫자의 첫 번째 위치 계산
	calFirstPos(count, pos);
	// 3. 위치값에 해당 숫자를 기록하면서 위치 값을 업데이트
	countsort(pos, nums);
}

class Radix : public Counting {
private:
	int bit;
protected:
	virtual int getValue(int v);
public:
	void sort(vector<int>& nums);
};

int Radix::getValue(int v) {	
	int mask = 1;
	mask = mask << bit;
	return (v & mask);
}

void Radix::sort(vector<int>& nums) {
	for (bit = 0; bit < 4; bit++) {
		Counting::sort(nums);
		Sorting::print(nums);
	}
}

int main() {
	int type;
	vector<int> nums;
	string infilename, outfilename;
	Sorting* sort;

	cout << "Give an input file name:" << endl;
	cin >> infilename;
	cout << "Give an output file name:" << endl;
	cin >> outfilename;
	cout << "Select you algorithm: 1. Counting Sort, 2. Radix Sort" << endl;
	cin >> type;

	// read values from a file
	ifstream ist(infilename);
	int temp;
	while (ist >> temp)
		nums.push_back(temp);

	if (type == 1) 
		sort = new Counting();
	else 
		sort = new Radix();

	cout << "Initial Values" << endl;
	Sorting::print(nums);
	sort->sort(nums);
	cout << "Sorted Values" << endl;
	Sorting::print(nums);

	// write the sorted values into the file
	ofstream ost(outfilename);
	for (int i = 0; i < nums.size(); i++) {
		ost << nums[i] << ' ';
	}

	return 0;
}