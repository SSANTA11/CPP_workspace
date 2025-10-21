#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Student {
private:
    char* name; // �̸�
    char* addr; // �ּ�
public:
    Student(const char* name, const char* addr); // name�� addr ���� �� �� �Ҵ����.
    ~Student(); // name�� addr ���� �� �� �ݳ�.
    void setAddr(const char* addr); // �ּ� ����, ���� �ּҰ����� �ݳ��� �� ���� �Ҵ�޾ƾ� ��, Book Ŭ������ set �Լ� ����. 
    Student(const Student& orig); // ���������
    void show(); // "�̸� : ��浿, �ּ� : ����� ���ϱ�"�� ���� �������� ���
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
    cout << "�̸�: " << name << ", �ּ�: " << addr << endl;
};






int main() {
    Student kim("��浿", "����� ���ϱ�");
    Student copy(kim);
    kim.show();
    copy.show();
    copy.setAddr("��⵵ ���ֽ�");
    kim.show();
    copy.show();
}