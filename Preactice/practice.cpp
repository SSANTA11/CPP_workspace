#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Student {
private:
    char* name; // 이름
    char* addr; // 주소
public:
    Student(const char* name, const char* addr); // name과 addr 공간 둘 다 할당받음.
    ~Student(); // name과 addr 공간 둘 다 반납.
    void setAddr(const char* addr); // 주소 변경, 기존 주소공간을 반납한 후 새로 할당받아야 함, Book 클래스의 set 함수 참고. 
    Student(const Student& orig); // 복사생성자
    void show(); // "이름 : 김길동, 주소 : 서울시 성북구"과 같은 형식으로 출력
};
Student::Student(const char* name, const char* addr) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->addr = new char[strlen(addr) + 1];
    strcpy(this->addr, addr);
};
Student::~Student() {
    if (this->name)
        delete[] this->name;
};
Student::Student(const Student& orig) {
    this->name = new char[strlen(orig.name) + 1];
    strcpy(this->name, orig.name);
    this->addr = new char[strlen(orig.addr) + 1];
    strcpy(this->addr, orig.addr);
};

void Student::setAddr(const char* addr) {
    if (this->name)
        delete[] this->name;
    this->addr = new char[strlen(addr) + 1];
    strcpy(this->addr, addr);

};
void Student::show() {
    cout << "이름: " << name << ", 주소: " << addr << endl;
};






int main() {
    Student kim("김길동", "서울시 성북구");
    Student copy(kim);
    kim.show();
    copy.show();
    copy.setAddr("경기도 양주시");
    kim.show();
    copy.show();
}