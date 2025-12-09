// 12장 학습 12.1 위주

// 네트워크에 전송하든 파일에 전송하든 연속된 바이트(바이트 스트림)를 보내는 것
// 이때 해석하는 방식을 프로토콜이라고 한다.

// 590pg 중요!!!!!!!!---시험에 나오지는 않음
	// 윈도우의 줄바꿈과 유닉스의 줄바꿈은 분명히 다른 로직이다.
	// 윈도우: 줄바꿈시 앞으로 가서 한칸내리시오 \r,\n
	// 유닉스: 오직 줄바꿈 \n

//593pg iostream에 외에 파일 입출력을 위해선 ifstream, ofstream --이부분 중요

//602pg 표 대략 보기 암기는 말고...! --이부분 중요

//613pg 바이너리 IO 중요 녹음본 듣고 보완
#include <iostream>
#include <fstream>
using namespace std;
//int main() {
//	const char* srcFile = "c:\\temp\\bullet.jpg";
//	const char* destFile = "c:\\temp\\copybullet.jpg";
//	ifstream fsrc(srcFile, ios::in | ios::binary);
//	if (!fsrc) {
//		cout << "fail to open" << endl;
//		return 0;
//	}
//	ofstream fdest(destFile, ios::out | ios::binary);
//	if (!fdest) {
//		cout << "fail to write" << endl;
//		return 0;
//	}
//	int c;
//	while ((c = fsrc.get()) != EOF) {
//		fdest.put(c);
//	}
//
//	fsrc.close();
//	fdest.close();
//}

//int main() {
//	const char* file = "c:\\temp\\data.txt";
//	ofstream fout;
//	fout.open(file, ios::out | ios::binary);// 쓰기모드로 파일 열기
//	if (!fout) {
//		cout << "파일 열기 오류" << endl;
//		return 0;
//	}
//	int n[] = { 0,1,2,3,4,5,6,7,8,9 };
//	double d = 3.15;
//	fout.write((char*)n, sizeof(n)); //write(주소,크기)
//	fout.write((char*)(&d), sizeof(d));
//	fout.close();
//	for (int i = 0; i < 10; i++) {
//		n[i] = 99;
//	}
//	d = 8.15; //배열 n과 d 값을 변경
//	ifstream fin(file, ios::in);
//	if (!fin) {
//		cout << "파일열기 오류";
//		return 0;
//	}
//
//	fin.read((char*)n, sizeof(n));
//	fin.read((char*)(&d), sizeof(d)); // read(주소, 크기)
//
//	for (int i = 0; i < 10; i++) {
//		cout << n[i] << ' ';
//	}
//	cout << endl << d << endl;
//	fin.close();
//}

// 제일 중요한거 추상클래스 상속

class Person {
	int id;
	char* name;
public:
	Person(int i, const char* n) {
		id = i;
		int len = strlen(n) + 1;
		name = new char[len];
		strcpy_s(name, len, n);
	}
	virtual ~Person() {
		cout << "~Person()" << name << endl;
		if (name)
			delete name;
	}
	int getID() const {
		return id;
	}
	const char* getName() {
		return name;
	}
	virtual int strength() = 0;
	virtual void show() {
		Person::show();
		cout << "ID=" << id << ", 이름=" << name << ", 체력" << strength();
	}
};
class Student :public Person {
	double gpa;
public:
	Student(int i, const char* n, double g) : Person(i, n) {
		gpa = g;
	}
	~Student() {
		cout << "~Student\n";
	}
	virtual int strength() {
		return gpa / 4.5 * 100;
	}
	virtual void show() {
		Person::show();
		cout << " ,평점=" << gpa;
	}
};
class Staff :public Person {
	int salary;
public:
	Staff(int i, const char* n, int s) : Person(i, n) {
		salary = s;
	}
	~Staff() {
		cout << "~Staff\n";
	}
	virtual int strength() {
		return salary / 5;
	}
	virtual void show() {
		Person::show();
		cout << " ,월급=" << salary;
	}
};
const int NUM = 5;
const int LEN = 20;
int main() {
	Person* p[NUM];
	int i, id, kind, salary;
	char name[LEN];
	double gpa;
	for (i = 0; i < NUM; i++) {
		cout << endl << i + 1 << " 번째 사람 정보 입력" << endl;
		cout << "ID: ";
		cin >> id;
		cin.get();
		cout << "이름: ";
		cin.getline(name, LEN);
		cout << "학생 1, 지원 2: ";
		while (cin >> kind && (kind != 1 && kind != 2))
			cout << "학생 1, 지원 2: ";

		if (kind == 1) {
			cout << "평점: ";
			cin >> gpa;
			p[i] = new Student(id, name, gpa); // 업캐스팅 
		}
		else {
			cout << "월급: ";
			cin >> salary;
			p[i] = new Staff(id, name, salary); // 업캐스팅
		}
	}
	// 상속 관계의 동적바인딩  --> polymorphism 다형성
	for (i = 0; i < NUM; i++) {
		cout << "ID= " << p[i]->getID() << " 이름= " << p[i]->getName() << endl;
	}
	for (i = 0; i < NUM; i++) {
		p[i]->show();
		cout << endl;
	}
	for (i = 0; i < NUM; i++) {
		delete p[i];
	}

}

// 기말고사에서 가장 주요한 것은 추상클래스와 상속 동적 바인딩
