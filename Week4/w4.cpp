// C++������ ���� ���� ��������� �ƴ϶�� ȣ������ �ʴ´�.--> ?why??
// �ڵ带 �ȾƸ��� ��(?) CPP������ �������� �ʰ� ����� ��� �����Ѵ�. ��� ���ȼ� ����

// 3���� �ڷ� ���� ��������: �ʿ� �ߺ� ȣ�� ���̽��� �����ϴ°�?
	// ����
//#include <iostream>
//
//# include "Account.h" // ���⼭ ���� #include <iostream>�� ���� ��� �����̶�� �ߺ� ȣ�� ���̽��� �߻��Ѵ�...!
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
//	Account a("Ȳ����");
//	a.deposit(20000);
//	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
//	int money = a.withdraw(15000);
//	cout << money << "�� ���, ";
//	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
//	money = a.withdraw(8000);
//	cout << money << "�� ���, ";
//	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
//}

// ��ü�� ������ ȣ��

// �Ҹ���: ��ü�� �Ҹ�
	// ���¿��� : ~Circle();
#include <iostream>
using namespace std;

class Circle {
private:
    int radius;

public:
    Circle(): Circle(1) {}

    Circle(int r) {
        radius = r;
        cout << "������ "<<radius<<"�� �Ҹ�\n";
    }

    ~Circle() {
        cout << "������ "<<radius<<"�� �Ҹ�\n";
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