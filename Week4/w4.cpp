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
        cout << "반지름 "<<radius<<"원 생성\n";
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
//
//// 아래 디버깅 시 발생과 소멸 순서 기억하기(코드블록과 스택으로 인한 출력값 예측 중요)
//Circle gDonut(1000);// 전역(global)==외부변수
//Circle gPizza(2000);
//
//void f() {
//    Circle fDonut(100);
//    Circle fPizza(200);
//}
//
//int main() {
//    Circle donut; // 지역(local)--> 소속 block 내에서 선언
//    Circle pizza(30); 
//    f();  
//}


//-----------------------------------------------------------------------------------------------------------------------------------

// 생성자를 private으로 제한을 두어 무분별한 객체 생성을 제약을 주는 경우가 존재한다. ---> 왜>>??? 검색하기
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
//        cout << "반지름 "<<radius<<"원 생성\n";
//    }
//
//public:
//    ~Circle() {
//        cout << "반지름 "<<radius<<"원 소멸\n";
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
// 자바의 기본 타입 변수들 int double flaot char boolean ...
// C++에서는 기본타입 객체 배열을 참조 기본값 포인트로 가능???하다 이는 자바와 큰차이 ---> 시험##################################################


//int main() {
//    Circle donut;
//    Circle pizza(30);
//
//    cout << donut.getArea()<<endl;
//
//    Circle* p;
//    //p->getArea(); 윗줄에 이어서 포인터의 초기화 없이 이처럼 쓴다면, 문제 발생
//
//    p = &donut;
//    cout << p->getArea()<<endl;
//    cout << (*p).getArea() << endl;
//    p = &pizza;
//    cout << p->getArea()<<endl;
//    cout << (*p).getArea() << endl;
//
//}

// 자바에서는 문제를 언어가 메모리 관리를 하지만, C++은 직접한다.


// 정수형 공간의 동적 할당 및 반환

int main() {
    int* p;

    p = new int;
    if (!p) {
        cout << "메모리를 할당할 수 없습니다." << endl;
        return 0;
    }
    *p = 5; //할당받은 정수 공간에 5 대입
    int n = *p;
    cout << "*p= "<<*p << endl;
    cout << "n= "<<n << endl;
    delete p;
}