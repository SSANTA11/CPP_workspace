#include<iostream>
#include<string>

using namespace std;

class Company {
	string name;
	int asset;
public:
	Company(string name = "", int asset = 0) {
		this->name = name;
		this->asset = asset;
	}
	string getName() {
		return name;
	}
	Company &operator+(Company company) {
		if (this->asset < company.asset) {
			this->name = company.getName();
		}
		this->asset += company.asset;
		return *this;
	}
	Company& operator*(int num) {
		this->asset *= num;
		return *this;
	}
	bool operator <(Company company) {
		if (this->asset < company.asset) {
			return true;
		}
		return false;
	}
	friend Company operator *(int op1, Company op2);
	friend ostream& operator<<(ostream& os, const Company& op);
};

Company operator *(int op1, Company op2) {
	op2.asset *= op1;
	return op2;
}
ostream& operator <<(ostream& os, const Company& op){
	os << "회사명 = " << op.name << ", 자본금 = " << op.asset;
	return os;
}

int main() {
	Company a("ABCsoft", 300), b("Orange", 200), c("BMI", 400);
	
	cout << a << endl << b << endl << c << endl;

	a = a + b;
	cout << a << endl;

	a = a * 2;
	cout << a << endl;

	c = 2 * c;
	cout << c << endl;

	if (a < c)
		cout << a.getName() << " < " << c.getName() << endl;
	else if (c < a)
		cout << a.getName() << " > " << c.getName() << endl;
	else
		cout << a.getName() << " == " << c.getName() << endl;
}