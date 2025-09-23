#pragma once
using namespace std;
#include <string>//내가 쓰는 것만 include하자! (iostream전체를 가져오기보단...)
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