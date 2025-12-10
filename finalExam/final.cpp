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

#include<vector>
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

void print_vector(const vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";
}

int main() {
	vector<int> v;
	vector<int>::iterator it;
	for (int i = 1;i <= 20;i++) {
		v.push_back(i / 2);
	}
	print_vector(v);
	cout << "삭제할 값: ";
	int n;
	cin >> n;

	it = v.begin();
	while (it != v.end()) {
		if (*it == n) {
			it = v.erase(it);
		}
		else {
			it++;
		}

	}
	print_vector(v);
}