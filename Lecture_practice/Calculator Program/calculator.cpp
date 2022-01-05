#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BadToken {
public:
	string token;
	BadToken(string str) { token = str; }
};

double calculate(string& expression);
void tokenize(string& expression, vector<string>& tokens);
double getExpression(vector<string>& tokens);
double getTerm(vector<string>& tokens);
double getPrimary(vector<string>& tokens);
double getNumber(vector<string>& tokens);

int main() {
	string expression;

	while (true) {
		cin >> expression;

		if (expression == "q")
			break;
		else
			cout << calculate(expression) << endl;
	}

}

double calculate(string& expression) {
	vector<string> tokens;
	tokenize(expression, tokens);
	return getExpression(tokens);
}

void tokenize(string& expression, vector<string>& tokens) {
	string const delims{ "+-*/%()" };

	size_t pos1 = 0, pos2 = 0;

	while (pos2 != string::npos) {
		pos1 = expression.find_first_of(delims, pos2);

		if (pos1 != 0 && pos2 == 0) {						// 맨 앞에 숫자 넣기
			tokens.push_back(expression.substr(0, pos1));
		}
		pos2 = expression.find_first_of(delims, pos1 + 1);
		tokens.push_back(expression.substr(pos1, 1));		// 연산자 넣기
		
		if (pos2 != string::npos && (pos2 - pos1) != 1) {
			tokens.push_back(expression.substr(pos1 + 1, pos2 - pos1 - 1));	// 피연산자 넣기
		}
		if (pos1 != expression.size() - 1 && pos2 == string::npos) {		//맨 뒤에 숫자 넣기
			tokens.push_back(expression.substr(pos1 + 1, expression.size() - pos1 - 1));
		}
	}


	/*size_t beg, pos = 0;
	while ((beg = expression.find_first_not_of(delims, pos)) != string::npos) //delims에 해당하지 않는 첫번째 자리 찾기, 찾는 문자열이 없는 경우에는 string::npos를 반환
	{
		pos = expression.find_first_of(delims, beg + 1);
		tokens.push_back(expression.substr(beg, pos - beg));
		if (pos != string::npos)
			tokens.push_back(expression.substr(pos, 1));
	}*/
}

double getExpression(vector<string>& tokens) {
	double right = getTerm(tokens);

	if (tokens.size() > 0) {
		string token = tokens[tokens.size() - 1];
		tokens.pop_back(); //제일 마지막거는 뺀다.

		if (token == "+")
			return getExpression(tokens) + right;
		else if (token == "-")
			return getExpression(tokens) - right;
		else 
			tokens.push_back(token);
	}
	
	return right;
}

double getTerm(vector<string>& tokens) {
	double right = getPrimary(tokens);

	if (tokens.size() > 0) {
		string token = tokens[tokens.size() - 1];
		tokens.pop_back(); //제일 마지막거는 뺀다.

		if (token == "*")
			return getTerm(tokens) * right;
		else if (token == "/")
			return getTerm(tokens) / right;
		else
			tokens.push_back(token);
	}
	return right;
}

double getPrimary(vector<string>& tokens) {
	string token = tokens[tokens.size() - 1];

	if (token == ")") {
		tokens.pop_back();
		double d = getExpression(tokens);
		tokens.pop_back();
		return d;
	}

	double right = getNumber(tokens);
	return right;

	/*if (tokens.size() > 0) {
		string token = tokens[tokens.size() - 1];

		if (token == ")") {
			tokens.pop_back();
			right = getExpression(tokens);
		}
		else throw BadToken(token);

	}*/

}

double getNumber(vector<string>& tokens) {
	string token = tokens[tokens.size() - 1];
	tokens.pop_back();

	return atoi(token.c_str());
}
