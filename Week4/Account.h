#pragma once
using namespace std;
#include <string>//���� ���� �͸� include����! (iostream��ü�� �������⺸��...)
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