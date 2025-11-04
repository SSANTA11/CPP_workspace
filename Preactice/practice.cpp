//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class Student {
//private:
//    char* name; // 이름
//    char* addr; // 주소
//public:
//    Student(const char* name, const char* addr); // name과 addr 공간 둘 다 할당받음.
//    ~Student(); // name과 addr 공간 둘 다 반납.
//    void setAddr(const char* addr); // 주소 변경, 기존 주소공간을 반납한 후 새로 할당받아야 함, Book 클래스의 set 함수 참고. 
//    Student(const Student& orig); // 복사생성자
//    void show(); // "이름 : 김길동, 주소 : 서울시 성북구"과 같은 형식으로 출력
//};
//Student::Student(const char* name, const char* addr) {
//    this->name = new char[strlen(name) + 1];
//    strcpy(this->name, name);
//    this->addr = new char[strlen(addr) + 1];
//    strcpy(this->addr, addr);
//};
//Student::~Student() {
//    if (this->name)
//        delete[] this->name;
//};
//Student::Student(const Student& orig) {
//    this->name = new char[strlen(orig.name) + 1];
//    strcpy(this->name, orig.name);
//    this->addr = new char[strlen(orig.addr) + 1];
//    strcpy(this->addr, orig.addr);
//};
//
//void Student::setAddr(const char* addr) {
//    if (this->name)
//        delete[] this->name;
//    this->addr = new char[strlen(addr) + 1];
//    strcpy(this->addr, addr);
//
//};
//void Student::show() {
//    cout << "이름: " << name << ", 주소: " << addr << endl;
//};
//
//
//
//
//
//
//int main() {
//    Student kim("김길동", "서울시 성북구");
//    Student copy(kim);
//    kim.show();
//    copy.show();
//    copy.setAddr("경기도 양주시");
//    kim.show();
//    copy.show();
//}
//278pg 9번
//#include <iostream>
//using namespace std;
//class MyStack {
//	int p[10];
//	int tos = 0;
//public:
//	MyStack();
//	bool push(int n) {
//		if (tos <= 9) {
//			p[tos++] = n;
//			return true;
//		}
//		return false;
//	};
//	bool pop(int& n) {
//		if (tos > 0)
//			n=p[--tos];
//			return true;
//		return false;
//	};
//};
//
//int main() {
//	MyStack st;
//	for (int i = 0; i < 11; i++) {
//		if (st.push(i))
//			cout << i << ' ';
//		else
//			cout << endl << i + 1 << "번쨰 푸시 실패! 스택 가득 차 있음";
//	}
//	int n;
//	for (int i = 0; i < 11; i++) {
//		if (st.pop(i))
//			cout << i << ' ';
//		else
//			cout << endl << i + 1 << "번쨰 팝 실패! 스택 비어 있음";
//	}
//
//}


 //문제 11번
#include<iostream>
using namespace std;

class MyStack {
	int *p, tos=0, size=0;

public:
	MyStack();
	MyStack(int size) {
		this->size = size; 
		p = new int[size];
	};
	MyStack(const MyStack& src) {
		this->size = src.size;
		this->tos = src.tos;
		this->p = new int[src.size];
		for (int i = 0; i < tos; i++)
			this->p[i] = src.p[i];
	};
	~MyStack(){
		delete[]p;
	};
	bool push(int n) {
		if (tos <= 9) {
			p[tos++] = n;
			return true;
		}
		return false;
	};
	bool pop(int& n) {
		if (tos > 0)
			n=p[--tos];
			return true;
		return false;
	};
};

int main() {
	MyStack a(10); // 10개의 저장 공간을 가진 객체 생성
	a.push(10);
	a.push(20); // 스택 a에는 10, 20의 순서로 정수 저장

	MyStack b = a; // 복사 생성(객체 a를 복사하여 객체 b 생성)
	// 복사 후, 스택 b는 a와 같이 10, 20의 순서로 정수 저장
	b.push(30); // 스택 b에는 10, 20, 30의 순서로 정수 저장

	int n;

	a.pop(n); // 스택 a의 최상단에 저장된 정수 팝. n은 20
	cout << "스택 a에서 팝한 값 " << n << endl;

	b.pop(n); // 스택 b의 최상단에 저장된 정수 팝. n은 30
	cout << "스택 b에서 팝한 값 " << n << endl;
}