// C++에서는 직접 만든 헤더파일이 아니라면 호출하지 않는다.--> ?why??
// 코드를 팔아먹을 때(?) CPP파일은 제공하지 않고 헤더와 기계어만 제공한다. 고로 보안성 보장

// 3주차 자료 보강 질문사항: 필연 중복 호출 케이스가 존재하는가?
	// 예시
//#include <iostream>
//
//# include "Account.h" // 여기서 만약 #include <iostream>이 사용된 헤더 파일이라면 중복 호출 케이스가 발생한다...!
//Account::Account(string name) {
//	this->name = name;
//	this->balance = 0;
//}
//void Account::deposit(int money) {
//	this->balance += money;
//}
//string Account::getOwner() {
//	return this->name;
//}
//int Account::inquiry() {
//	return balance;
//}
//int Account::withdraw(int money) {
//	if (money <= balance) {
//		balance -= money;
//		return money;
//	}
//	money = balance;
//	balance = 0;
//	return money;
//}
//
//int main() {
//
//	Account a("황수희");
//	a.deposit(20000);
//	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
//	int money = a.withdraw(15000);
//	cout << money << "원 출금, ";
//	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
//	money = a.withdraw(8000);
//	cout << money << "원 출금, ";
//	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
//}

// 객체의 생성과 호출

// 소멸자: 객체의 소멸
	// 형태예시 : ~Circle();
#include <iostream>
using namespace std;

class Circle {
private:
    int radius;

public:
    Circle(): Circle(1) {}

    Circle(int r) {
        radius = r;
        cout << "반지름 "<<radius<<"원 소멸\n";
    }

    ~Circle() {
        cout << "반지름 "<<radius<<"원 소멸\n";
    }

    void setRadius(int r) {
        radius = r;
    }

    double getArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Circle donut;
    Circle pizza(30);
}