#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Student {
private:
	char* name;
	char * addr;
public:
	Student(const char* name,const char* addr) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->addr = new char[strlen(addr) + 1];
		strcpy(this->addr, addr);
	}
	~Student() {
		if (this->name)
			delete[] this->name;
	}
	void setAddr(const char* name) {
		if (this->name)
			delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	
	}
	Student(const Student& orgin) {
		this->name = new char[strlen(orgin.name) + 1];
		strcpy(this->name, orgin.name);
		this->addr = new char[strlen(orgin.addr) + 1];
		strcpy(this->addr, orgin.addr);
		
	}
	void show() {
		cout << "이름: " << name << " " << "주소: " << addr  << endl;
	}

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