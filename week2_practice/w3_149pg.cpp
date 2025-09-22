// 3장 실습 문제 3번(p.149)
#include <iostream>
using namespace std;
class Account {
private:
	string name;
	int number;
	int balance;
	int money;
public:
	Account(string name);
	void deposit(int money);
	string getOwner();
	int inquiry();
	int withdraw(int money);
};

Account::Account(string name) {
	this->name = name;
	this->balance = 0;
}
void Account :: deposit(int money) {
	this-> balance += money;
}
string Account::getOwner() {
	return this->name;
}
int Account::inquiry() {
	return balance;
}
int Account::withdraw(int money) {
	if (money <= balance) {
		balance -= money;
		return money;
	}
	money = balance;
	balance = 0;
	return money;
}

int main() {

	Account a("황수희"); 
	a.deposit(20000);
	cout << a.getOwner() << "의 잔액은 "<< a.inquiry() << endl;
	int money = a.withdraw(15000);
	cout << money << "원 출금, ";
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	money = a.withdraw(8000);
	cout << money << "원 출금, ";
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}
/*
황수희의 잔액은 20000
15000원 출금, 황수희의 잔액은 5000
5000원 출금, 황수희의 잔액은 0 */