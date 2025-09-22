// 3�� �ǽ� ���� 3��(p.149)
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

	Account a("Ȳ����"); 
	a.deposit(20000);
	cout << a.getOwner() << "�� �ܾ��� "<< a.inquiry() << endl;
	int money = a.withdraw(15000);
	cout << money << "�� ���, ";
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	money = a.withdraw(8000);
	cout << money << "�� ���, ";
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}
/*
Ȳ������ �ܾ��� 20000
15000�� ���, Ȳ������ �ܾ��� 5000
5000�� ���, Ȳ������ �ܾ��� 0 */