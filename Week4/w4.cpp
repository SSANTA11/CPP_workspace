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
        cout << "������ "<<radius<<"�� ����\n";
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
//
//// �Ʒ� ����� �� �߻��� �Ҹ� ���� ����ϱ�(�ڵ��ϰ� �������� ���� ��°� ���� �߿�)
//Circle gDonut(1000);// ����(global)==�ܺκ���
//Circle gPizza(2000);
//
//void f() {
//    Circle fDonut(100);
//    Circle fPizza(200);
//}
//
//int main() {
//    Circle donut; // ����(local)--> �Ҽ� block ������ ����
//    Circle pizza(30); 
//    f();  
//}


//-----------------------------------------------------------------------------------------------------------------------------------

// �����ڸ� private���� ������ �ξ� ���к��� ��ü ������ ������ �ִ� ��찡 �����Ѵ�. ---> ��>>??? �˻��ϱ�
//#include <iostream>
//using namespace std;
//
//class Circle {
//private:
//    int radius;
//
//    Circle(): Circle(1) {}
//
//    Circle(int r) {
//        radius = r;
//        cout << "������ "<<radius<<"�� ����\n";
//    }
//
//public:
//    ~Circle() {
//        cout << "������ "<<radius<<"�� �Ҹ�\n";
//    }
//
//    void setRadius(int r) {
//        radius = r;
//    }
//
//    double getArea() {
//        return 3.14 * radius * radius;
//    }
//};

//-----------------------------------------------------------------------------------------------------------------------------------
// �ڹ��� �⺻ Ÿ�� ������ int double flaot char boolean ...
// C++������ �⺻Ÿ�� ��ü �迭�� ���� �⺻�� ����Ʈ�� ����???�ϴ� �̴� �ڹٿ� ū���� ---> ����##################################################


//int main() {
//    Circle donut;
//    Circle pizza(30);
//
//    cout << donut.getArea()<<endl;
//
//    Circle* p;
//    //p->getArea(); ���ٿ� �̾ �������� �ʱ�ȭ ���� ��ó�� ���ٸ�, ���� �߻�
//
//    p = &donut;
//    cout << p->getArea()<<endl;
//    cout << (*p).getArea() << endl;
//    p = &pizza;
//    cout << p->getArea()<<endl;
//    cout << (*p).getArea() << endl;
//
//}

// �ڹٿ����� ������ �� �޸� ������ ������, C++�� �����Ѵ�.


// ������ ������ ���� �Ҵ� �� ��ȯ

int main() {
    int* p;

    p = new int;
    if (!p) {
        cout << "�޸𸮸� �Ҵ��� �� �����ϴ�." << endl;
        return 0;
    }
    *p = 5; //�Ҵ���� ���� ������ 5 ����
    int n = *p;
    cout << "*p= "<<*p << endl;
    cout << "n= "<<n << endl;
    delete p;
}