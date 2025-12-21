//시험 추제 정리 및 기존 코드 복습

// 오버라이딩은 다형성의 한사례이다 --- 시험 출제 포인트 287

// static 사용의 이유 --- 시험 출제 포인트 324
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//class Random {
//private:
//	Random() {};
//	static bool initialized;
//public:
//	static int nextInt(int min = 0, int max = RAND_MAX) {
//		if (!initialized) {
//			srand(time(0));
//			initialized = true;
//		}
//		return rand() % (max - min + 1) + min;
//	}
//};
//bool Random::initialized = false;
//int main() {
//	srand(time(0));
//	for (int i = 0; i < 10; i++) {
//		cout << Random::nextInt(20000) << endl;
//	}
//}
// 위 예제 기말 포인트 :  static과 랜덤의 관계에서 랜덤을 private으로 선언한 이유와 static bool initialized을 static으로 선언한 이유
	// 불필요한 객체 생성을 방지 한다는 점에서 싱글턴과 유사해 보이나, 객체 생성을 아예 방지 한다는 점에서 차이가 있다. 
	// 해당 로직에서는 굳이 객체를 생성할 필요가 없음으로 생성자를 private으로 돌리고 나머지 필드와 메서드를 static으로 만들었고
	// 내부의 조건문을 통해 해당 클래스의 초기화는 단 한번만 일어남을 보장하고 클래스명::메서드 형태로 원하는 결과를 얻을 수 있다. 

// 프렌드 함수 --- 332 예제
//class Rect {
//	int width, height;
//public:
//	Rect(int width, int height) {
//		this->width = width;
//		this->height = height;
//	}
//	friend bool equals(Rect r1, Rect r2);
//};
//bool equals(Rect r1, Rect r2) {
//	if (r1.width == r2.width && r1.height == r2.height) {
//		return true;
//	} else {
//		return false;
//	}
//}
//int main() {
//	Rect a(3, 4), b(4, 5);
//	if (equals(a, b)) {
//		cout << "equal" << endl;
//	} else {
//		cout << "not equal" << endl;
//	}
//}

// 프렌드 함수의 전방 참조 --- 334 예제
//#include <iostream>
//using namespace std;
//
//class Power {
//private:
//	int kick, punch;
//public:
//	Power(int kick = 0, int punch = 0) {
//		this->kick = kick;
//		this->punch = punch;
//	}
//	void show() const {
//		cout <<"Kick: " << kick << "\nPunch: " << punch << endl;
//	}
//
//	Power operator+(const Power& p) {
//		Power tmp;
//		tmp.kick = this->kick + p.kick;
//		tmp.punch = this->punch + p.punch;
//		return tmp;
//	}
	//Power operator+(const Power& p) const {
	//	Power tmp;
	//	tmp.kick = this->kick + p.kick;
	//	tmp.punch = this->punch + p.punch;
	//	return tmp;
	//}

	//bool operator==(const Power& p) const {
	//	if (this->kick == p.kick && this->punch == p.punch) {
	//		return true;
	//	}
	//	return false;
	//}

	//Power& operator+=(const Power& p) {
	//	this->kick += p.kick;
	//	this->punch += p.punch;
	//	return *this;
	//}
//};
//int main() {
//	Power p0, p1(10, 10), p2(1, 2);
//	p0 = p1 + p2;
//	p0.show();
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Point {
//	int x, y;
//public:
//	void set(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	void showPoint() {
//		cout << "(" << x << "," << y << ")" << endl;
//	}
//};
//
//class ColorPoint : public Point {
//	string color;
//public:
//	void setColor(string color) {
//		this->color = color;
//	}
//	void showColorPoint() {
//		cout << color << ":";
//		showPoint();
//	}
//};
//int main() {
//	ColorPoint cp;
//	ColorPoint* pDer = &cp;
//	Point* pBase = pDer;
//	pDer->set(1,2);
//	pBase->showPoint();
//	pDer->setColor("red");
//	pDer->showColorPoint();
//	pDer = (ColorPoint*)pBase;
//
//}
//int main() {
//	ColorPoint* pDer;
//	Point* pBase, po;
//	pBase = &po;
//	pDer = (ColorPoint*)pBase;
//}

//class Circle {
//	int radius;
//public:
//	Circle(int radius = 0) {
//		this->radius = radius;
//	}
//	~Circle() {
//
//		cout << "\n반지름 " << radius << "원 소멸\n";
//	}
//	int getRadius() {
//		return radius;
//	}
//	void setRadius(int radius) {
//		this->radius = radius;
//	}
//	double getArea() {
//		return 3.14 * radius * radius;
//	}
//};
//class NamedCircle : public Circle {
//	string name;
//public:
//	NamedCircle(int r, string name) : Circle(r) {
//		this->name = name;
//	}
//	void show() {
//		cout << "반지름이 " << getRadius() << "인 " << name;
//	}
//};
//int main() {
//	NamedCircle waffle(3, "waffle");
//	waffle.show();
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Point {
//	int x, y;
//public:
//	Point(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	int getX() {
//		return x;
//	}
//	int getY() {
//		return y;
//	}
//protected:
//	void move(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//};
//
//class ColorPoint : public Point{
//	string color;
//public:
//	ColorPoint(int x, int y, string color) :Point(x, y) {
//		this->color = color;
//	}
//	void setPoint(int x, int y) {
//		move(x, y);
//	}
//	void setColor(string color) {
//		this->color = color;
//	}
//	void show() {
//		cout << color << "색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다.";
//	}
//};
//
//int main() {
//	ColorPoint cp(5, 5, "RED");
//	cp.setPoint(30, 40);
//	cp.setColor("BLUE");
//	cp.show();
//}





//클래스 계층 구조 및 멤버 :
//Animal 클래스는 추상 클래스여야 합니다. (sound() 메서드의 = 0을 유지).
//Animal 클래스는 weight 필드와 getWeight() 메서드를 가져야 합니다.
//Dog와 Cat은 Animal을 공개 상속(:public Animal)해야 하며, 각자의 고유 필드(fangSize, clawSharpness)를 가져야 합니다.

//생성자 및 초기화 :
//모든 클래스는 원본 코드에 명시된 형태의 생성자 초기화 리스트를 사용해야 합니다. (예 : Dog(...) : Animal(...)).

//다형성 강제 :
//배열을 사용하지 않고 다형성을 구현해야 합니다. (함수 또는 컨테이너 활용).
//sound() 메서드를 호출할 때는 반드시 Animal* 포인터 또는 Animal& 참조를 통해 호출해야 합니다.
//메모리 해제 및 가상 소멸자 :
//모든 객체는** 힙(Heap)** 에 new로 할당되어야 합니다.
//Animal 클래스의 소멸자는 반드시 virtual로 선언되어야 하며, delete를 통해 올바르게 소멸(Dog / Cat 소멸자->Animal 소멸자 순)되어야 합니다.

//📜 요구 사항
//main 함수 내에서 다음을 순서대로 수행하는 코드를 작성하십시오.
//Animal 포인터 변수 3개를 선언하고, 각각 Dog, Cat, Dog 객체를 원본 코드와 동일한 인자 값으로 동적 할당합니다.
//할당된 객체 3개를 Animal * 포인터 또는 Animal & 참조를 인수로 받는 * *함수(또는 컨테이너 순회) * *를 통해 순서대로 sound()를 호출하게 합니다.
//할당된 3개의 객체를 순서대로 delete를 통해 해제합니다.

//class Animal {
//private:
//	int weight;
//public:
//	Animal(int weight = 0) {
//		this->weight = weight;// 자식으로부터의 호출때문에 생성자가 존재
//	}
//	~Animal() {
//		cout << "Animal::~Animal()\n";
//	}
//	void virtual sound() = 0;
//
//	int getWeight() {
//		return this->weight;
//	}
//};
//
//class Dog :public Animal {
//	int fangSize;
//public:
//	Dog(int fangSize, int weight) :Animal(weight) {
//		this->fangSize = fangSize;
//	}
//	~Dog() {
//		cout << "Dog::~Dog()\n";
//	}
//	int getFangSize() {
//		return fangSize;
//	}
//	void virtual sound() {
//		cout << "woof" << endl;
//	}
//
//};
//
//class Cat :public Animal {
//	int clawSharpness;
//public:
//	Cat(int clawSharpness, int weight) :Animal(weight) {
//		this->clawSharpness = clawSharpness;
//	}
//	~Cat() {
//		cout << "Cat::~Cat()\n";
//	}
//	int getClawSharpness() {
//		return clawSharpness;
//	}
//	void virtual sound() {
//		cout << "meow" << endl;
//	}
//
//};
//int main() {
//	Animal* a[3];
//	a[0] = new Dog(10, 15);
//	a[1] = new Cat(5, 1);
//	a[2] = new Dog(3, 150);
//	for (int i = 0; i < 3; i++)
//		a[i]->sound();
//	for (int i = 0; i < 3; i++)
//		delete a[i];
//}
//template <typename T>
//
//T bigger(T a, T b) {
//	if (a < b) {
//		return b;
//	}
//	else if (a == b) {
//		cout << "동일합니다.";
//		return 111111;
//	}
//	return a;
//}
//int main() {
//	int a = 1, b = 2;
//	cout<<bigger(a, b);
//}
//template <class T>
//class Stack {
//	int tos = -1;
//	T data[100];
//public:
//	void push(T element) {
//		if (tos == 99) {
//			return;
//		}
//		data[++tos] = element;
//	}
//	T pop() {
//		if (tos == 1) {
//			return 0;
//		}
//		return data[tos--];
//	}
//};
//int main() {
//	Stack<int> myStack;
//	myStack.push(1);
//	myStack.push(1);
//	myStack.push(1);
//	myStack.push(1);
//	myStack.push(1);
//	cout << myStack.pop();
//	cout << myStack.pop();
//	cout << myStack.pop();
//	cout << myStack.pop();
//	cout << myStack.pop();
//}

//#include<vector>
//int main() {
//	vector<int> v;
//	vector<int>::iterator it;
//	v.push_back(1);
//	v.push_back(10);
//	v.push_back(100);
//	for (int i: v) {
//		cout << i << " ";
//	}
//	cout << "\n";
//}

//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(10);
//	v.push_back(100);
//	for (int i = 0;i < v.size();i++) {
//		cout << v.at(i) << " ";
//	}
//	cout << "\n";
//	for (int i = 0;i < v.size();i++) {
//		cout << v[i] << " ";
//	}
//	cout << "\n";
//	for (int i : v) {
//		cout << i << " ";
//	}
//	cout << "\n";
//	vector<int>::iterator it;
//	for (it = v.begin();it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << "\n";
//}

//void print_vector(const vector<int>& v) {
//	for (int i : v) {
//		cout << i << " ";
//	}
//	cout << "\n";
//}
//
//int main() {
//	vector<int> v;
//	vector<int>::iterator it;
//	for (int i = 1;i <= 20;i++) {
//		v.push_back(i / 2);
//	}
//	print_vector(v);
//	cout << "삭제할 값: ";
//	int n;
//	cin >> n;
//
//	it = v.begin();
//	while (it != v.end()) {
//		if (*it == n) {
//			it = v.erase(it);
//		}
//		else {
//			it++;
//		}
//
//	}
//	print_vector(v);
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class OutOfBoundsException {
//	string msg;
//public:
//	OutOfBoundsException(string msg) { this->msg = msg; }
//	void print() { cout << msg << endl; }
//};
//
//template <typename T>
//class MyArray {
//	T* data;	// 동적배열 포인터
//	int size;	// 배열크기(원소 수)
//public:
//	MyArray(int size = 16) {
//		data = new T[size];
//		this->size = size;
//	}
//	~MyArray() {
//		if (data) {
//			delete[] data;
//			data = 0;
//		}
//	}
//	// [] 연산자는 배열원소의 값을 리턴하는 것이 아니고 배열원소 자체(참조)를 리턴해야 함.
//	// 이해가 되지 않으면 &를 삭제(T&를 T로)하고 컴파일 해볼 것.
//	T& operator[](int index) throw(OutOfBoundsException) {
//		if (index > -1 && index < size)
//			return data[index];
//
//		string func(__FUNCTION__);
//		throw OutOfBoundsException("Array Out of Bounds Exception in " + func
//			+ " LINE: " + to_string(__LINE__) + ", index = " + to_string(index)
//			+ ", size = " + to_string(size));
//	}
//};
//int main() {
//	MyArray<double> a(5);	// 원소 5개인 실수 배열
//	try {
//		for (int i = 0; i < 5; i++)
//			a[i] = (double)(i + 1) / 10;
//		for (int i = 0; i < 5; i++)
//			cout << a[i] << ' ';
//		cout << endl;
//		a[5] = 0.6;	// 인덱스 범위(0~4)를 벗어나서 예외 발생
//	}
//	catch (OutOfBoundsException e) { e.print(); }
//
//	MyArray<int> b;	// 원소 16개인 정수 배열
//	try {
//		for (int i = 0; i < 16; i++)
//			b[i] = i + 1;
//		for (int i = 0; i < 16; i++)
//			cout << b[i] << ' ';
//		cout << endl;
//		cout << b[16] << endl;	// 인덱스 범위(0~15)를 벗어나서 예외 발생
//	}
//	catch (OutOfBoundsException e) { e.print(); }
//}
//#include <iostream>
//#include <cstring>
//using namespace std;

//class MyStackDataException {
//	string msg;  // 예외에 대한 설명
//	int size;  // 스택 데이터를 저장하는 배열의 크기
//	int numOfData;  // 현재 스택에 들어있는 데이터 개수
//public:
//	MyStackDataException(string msg, int size, int numOfData) {
//		this->msg = msg;
//		this->size = size;
//		this->numOfData = numOfData;
//	}
//	void print() {
//		cout << msg << ", size = " << size << ", num of data = " << numOfData << endl;
//	}
//};
//
//template <typename T>
//class MyGenStack {
//	int tos = -1;
//	int size;
//	T* data;
//public:
//	MyGenStack(int size = 8) {
//		this->size = size;
//		data = new T[size];
//	}
//	~MyGenStack() {
//		delete[] data;
//	}
//	void push(T element) throw(MyStackDataException) {
//		cout << "push 시도\n";
//		if (tos == size - 1) {
//			throw MyStackDataException("Stack full", this->size, tos);
//		}
//		else {
//			tos++;
//			data[tos] = element;
//			cout << "성공:" << element << endl;
//		}
//	}
//	T pop() throw(MyStackDataException) {
//		cout << "pop 시도\n";
//		if (tos == -1) {
//			throw MyStackDataException("Stack empty", this->size, tos);
//		}
//		else {
//			cout << "성공:" << data[tos] << endl;
//			return data[tos--];
//		}
//	}
//	int length() {
//		return size;
//	}
//};


//int main() {
//	MyGenStack<int> a(5);
//	cout << "--------------------------------------------------\n정수 stack 크기 = " << a.length() << endl;
//	try {
//		for (int i = 0;i < 6;i++) {
//			a.push(i + 1);
//		}
//	}
//	catch (MyStackDataException e) {
//		e.print();
//	}
//	try {
//		for (int i = 0;i < 6;i++) {
//			a.pop();
//		}
//	}
//	catch (MyStackDataException e) {
//		e.print();
//	}
//	MyGenStack<double> b;
//	cout << "--------------------------------------------------\n정수 stack 크기 = " << b.length() << endl;
//	try {
//		for (int i = 0;i < 9;i++) {
//			b.push((double)(i + 1) / 10);
//		}
//	}
//	catch (MyStackDataException e) {
//		e.print();
//	}
//	try {
//		for (int i = 0;i < 9;i++) {
//			b.pop();
//		}
//	}
//	catch (MyStackDataException e) {
//		e.print();
//	}
//	cout << "--------------------------------------------------\n";
//}

//#include <map>
//#include <iostream>
//#include <string>
//using namespace std;
//
//class MyID {
//	char code;
//	int number;
//public:
//	MyID(char code, int number) {
//		this->code = code;
//		this->number = number;
//	}
//	friend ostream& operator<<(ostream& op1, const MyID& op2);
//	bool operator <(MyID& const op2)const {
//		if (code < op2.code)
//			return true;
//		else if (code == op2.code) {
//			return number < op2.number;
//		}
//		else {
//			return false;
//		}
//	}
//};
//ostream& operator<<(ostream& op1, const MyID& op2) {
//	op1 << op2.code << op2.number;
//	return op1;
//}
//int main() {
//	map<MyID, string> students;
//	map<MyID, string> ::iterator it;
//	MyID a('a', 123), b('b', 456), c('c', 400);
//	students[a] = "노현수";
//	students[b] = "노윤수";
//	students[c] = "바보들";
//	for (it = students.begin();it != students.end();it++) {
//		cout << it->first << ": " << it->second << endl;
//	}
//}

// 13주차 map<key, value> 포인트!!!
// int나 double 같은 기본 자료형은 컴파일러가 이미 크기 비교 방법을 알고 있습니다.
// 하지만 사용자가 직접 만든 클래스(예: MyID, Power)는 어떤 기준으로 '더 작다'고 판단할지 컴파일러가 알 수 없습니다.
// 따라서 키에 부등호가 적용되지 않는 타입을 키로 쓰려면 반드시 별도의 연산자 중복 구현이 필요합니다

// 참조 반환 시, 즉, class A = a.operator(~)라면 해당 a 객체의 주소지가 반환 대상이다.
//참조 반환은 다음 두 가지 약속이 필요할 때 사용한다고 기억하시면 정확합니다.
//1. "방금 건드린 놈을 그대로 돌려줄 테니, 뒤에 다른 작업을 더 해!" (연속 작업)
//2. "복사본이 아니라 실제 원본 주소를 줄 테니, 거기다가 바로 값을 써!" (수정 가능성)


#include<iostream>
#include<cstring>

using namespace std;

class Person {
	int id;
	char* name;
public:
	Person(int id, const char* name) {
		this->id = id;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	virtual ~Person() {
		delete[] name;
	}
	virtual double strength()=0;
	virtual void show() {
		cout << name << id;
	}
};
class Student :public Person {
	double gpa;
public:
	Student(int id, const char* name, double gpa) :Person(id, name) {
		this->gpa = gpa;
	}
	double strength() {
		return gpa / 4.5 * 100;
	}
	void show() {
		Person::show();
		cout << gpa;
	}
};
class Staff :public Person {
	int salary;
public:
	Staff(int id, const char* name, int salary) :Person(id, name) {
		this->salary = salary;
	}
	double strength() {
		return salary / 5;
	}
	void show() {
		Person::show();
		cout << salary;
	}
};
int main() {
	Person* p[2];
	p[0] = new Student(112, "police", 2.3);
	p[1] = new Staff(114, "po", 3);
	for (int i = 0;i < 2;i++) {
		p[i]->show();
	}
	for (int i = 0;i < 2;i++) {
		delete p[i];
	}
}