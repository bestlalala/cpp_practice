#include <iostream>
using namespace std;

class Fraction {
protected:
	int numerator, denominator;
	
public:
	Fraction();
	Fraction(int n, int d);
	int getnum();
	int getdenom();
	friend void yakbun(Fraction& a);
	friend Fraction operator+(const Fraction& a, Fraction& b);
	friend Fraction operator-(const Fraction& a, Fraction& b);
	friend Fraction operator*(const Fraction& a, Fraction& b);
	friend Fraction operator/(const Fraction& a, Fraction& b);
	friend ostream& operator<<(ostream&, const Fraction&);
};
Fraction::Fraction() {};
Fraction::Fraction(int n, int d) :numerator(n), denominator(d) {}
int Fraction::getnum() { return numerator; }
int Fraction::getdenom() { return denominator; }

void yakbun(Fraction& a) {
	int max;
	if (a.numerator > a.denominator) max = a.numerator;
	else max = a.denominator;
	for (int i = 2; i < max; i++) {
		if (a.numerator % i == 0 && a.denominator % i == 0) {
			a.numerator /= i;
			a.denominator /= i;
		}
	}
}
Fraction operator+(const Fraction& a, Fraction& b) {
	Fraction c;
	if (a.denominator == b.denominator) {
		c.denominator = a.denominator;
		c.numerator = a.numerator + b.numerator;
	}
	else {
		c.denominator = a.denominator * b.denominator;
		c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	}
	return c;
}
Fraction operator-(const Fraction& a, Fraction& b) {
	Fraction c;
	if (a.denominator == b.denominator) {
		c.denominator = a.denominator;
		c.numerator = a.numerator - b.numerator;
	}
	else {
		c.denominator = a.denominator * b.denominator;
		c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	}
	return c;
}
Fraction operator*(const Fraction& a, Fraction& b) {
	Fraction c(a.numerator * b.numerator, a.denominator * b.denominator);
	yakbun(c);
	return c;
}
Fraction operator/(const Fraction& a, Fraction& b) {
	Fraction c(a.numerator * b.denominator, a.denominator * b.numerator);
	yakbun(c);
	return c;
}
ostream& operator<<(ostream& os, const Fraction& f) {
	os << f.numerator << "/" << f.denominator;
	return os;
}

class Mixed : public Fraction {
private:
	int whole;
public:
	Mixed();
	Mixed(int w, int n, int d);
	friend Fraction gabunsu(Mixed& m);
	friend Mixed daebunsu(Fraction& f);
	friend Mixed operator+(Mixed& a, Mixed& b);
	friend Mixed operator-(Mixed& a, Mixed& b);
	friend Mixed operator*(Mixed& a, Mixed& b);
	friend Mixed operator/(Mixed& a, Mixed& b);
	friend ostream& operator<<(ostream&, const Mixed&);
};

Fraction gabunsu(Mixed& m) {
	Fraction a(m.whole * m.denominator + m.numerator, m.denominator);
	return a;
}

Mixed daebunsu(Fraction& f) {
	Mixed m(f.getnum() / f.getdenom(), f.getnum(), f.getdenom());
	m.numerator %= m.denominator;
	int max;
	if (m.numerator > m.denominator) max = m.numerator;
	else max = m.denominator;
	for (int i = 2; i < max; i++) {
		if (m.numerator % i == 0 && m.denominator % i == 0) {
			m.numerator /= i;
			m.denominator /= i;
		}
	}
	return m;
}

Mixed::Mixed() {}
Mixed::Mixed(int w, int n, int d) :Fraction(n, d) {
	whole = w;
}

Mixed operator+(Mixed& a, Mixed& b) {
	Fraction a2 = gabunsu(a);
	Fraction b2 = gabunsu(b);
	Fraction c2 = a2 + b2;
	Mixed c = daebunsu(c2);
	return c;
}

Mixed operator-(Mixed& a, Mixed& b) {
	Fraction a2 = gabunsu(a);
	Fraction b2 = gabunsu(b);
	Fraction c2 = a2 - b2;
	Mixed c = daebunsu(c2);
	return c;
}
Mixed operator*(Mixed& a, Mixed& b) {
	Fraction a2 = gabunsu(a);
	Fraction b2 = gabunsu(b);
	Fraction c2 = a2 * b2;
	Mixed c = daebunsu(c2);
	return c;
}
Mixed operator/(Mixed& a, Mixed& b) {
	Fraction a2 = gabunsu(a);
	Fraction b2 = gabunsu(b);
	Fraction c2 = a2 / b2;
	Mixed c = daebunsu(c2);
	return c;
}

ostream& operator<<(ostream& os, const Mixed& m) {
	os << m.whole << " " << m.numerator << "/" << m.denominator;
	return os;
}

int main() {
	Mixed a(2, 4, 3);
	Mixed b(1, 3, 5);
	cout << (a + b) << ":" << (a - b) << endl;
	cout << (a * b) << ":" << (a / b) << endl;
}