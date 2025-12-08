//421pg 실습 문제 3
#include <iostream>
#include <string>
using namespace std;

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
//class ColorPoint : public Point {
//	string color;
//public:
//	ColorPoint(int x = 0, int y = 0, string color = "BLACK") :Point(x, y) {
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
//	//cp.move(10,20);로 조지면 protected로 인해 컴파일 오류
//	cp.setPoint(30, 40);
//	cp.setColor("BLUE");
//	cp.show();
//}


// ---------------------------------시험 출제 가능성▼----------------------------
//옛날 책에만 있는 "상속의 종류" (갤러리 참고 사진 개정판 p.397)------신출간 책에는 없다-----
// 자바에는 없지만 c++에는 존재
// public 상속
// protected 상속
// private 상속
	// 나한테 일단 상속하고 private해!
	// 한번만 상속 가능한가????
// ---------------------------------시험 출제 가능성▲----------------------------

// 다중 상속은 시험에 나오지 않는다.409pg --- +다중 상속은 쓰지마!!!!!

// 9장 가상 함수와 추상 클래스

// 예제 9-1 파생 클래스에서 함수를 재정의하는 사례432pg

//class Base {
//public:
//	void f() {
//		cout << "Base::f()\n";
//	}
//};
//class Derived : public Base {
//public:
//	void f() {
//		cout << "Derived::f()\n";
//	}
//};
//int main() {
//	Derived d;
//	Derived* pDer = &d;
//	pDer->f();
//	Base* pBase = &d;
//	pBase->f();
//}

// 99.9999999999% 동적 바인딩과 정적 바인딩 출제 434pg
//가상 함수
	// 동적 바인딩 --> 실행 시간에 함수 코드가 결정
	//cf. 정적 바인딩 --> 컴파일 시간에 함수 코드가 결정
//class Base {
//public:
//	virtual void f() {
//		cout << "Base::f()\n";
//	}
//};
//class Derived : public Base {
//public:
//	virtual void f() {// 함수 오버라이딩(virtual)/ 없으면 재정의
//		cout << "Derived::f()\n";
//	}
//};
//int main() {
//	Derived d;
//	Base b;
//	int n;
//	cin >> n;
//	Base* pBase = 0;
//	if (n == 1) {
//		pBase = &b;
//	}
//	else {
//		pBase = &d;
//	}
//	/*Derived* pDer = &d;
//	pDer->f();
//	Base* pBase = &d;*/
//	// 런타임에선 base가 어떤 클래스를 가르키는지 안다.
//	// --> virtual이 붙어야 동적 바인딩이 일으켜 오버라이딩이 성립
//	// 만약 virtual로 함수를 다시 쓴다면 함수오버라이딩
//	// 만약 정적 바인딩으로 함수를 다시 쓴다면 함수재정의
//	// 물론 virtual이 붙어도 재정의 가능
//		// 이를테면 virtual이 붙어도 자식 클래스를 가르키는 포인터로 자식을 다르키면 정적으로 바인딩
//// 정적바인딩과 동적 바인딩의 전공서적의 정의와 구분은 시험 출제 100% 달달 외워
//	/*pBase->f();*/
//}

//442~443pg는 시험 범위 제외! 한번은 읽어봐라



// 예제 9-3 상속이 반복되는 경우 가상 함수 호출
//class Base {
//public:
//	virtual void f() {
//		cout << "Base::f()\n";
//	}
//};
//class Derived : public Base {
//public:
//	virtual void f() {// 함수 오버라이딩(virtual)/ 없으면 재정의
//		cout << "Derived::f()\n";
//	}
//};
//class GrandDerived : public Derived {
//public:
//	virtual void f() {// 함수 오버라이딩(virtual)/ 없으면 재정의
//		cout << "GrandDerived::f()\n";
//	}
//};
//int main() {
//	GrandDerived g;
//	Base* bp;
//	Derived* dp;
//	GrandDerived* gp;
//	bp = dp = gp = &g;
//	bp->f();
//	dp->f();
//	gp->f();
//}




//오버라이딩과 범위 지정 연산자(::)446pg
	//예제 9-4 범위 지정 연간자(::)를 이용한 기본 클래스의 가상 함수 호출

//class Shape {
//public:
//	virtual void draw() {
//		cout << "--shape--";
//	}
//};
//class Circle :public Shape {
//public:
//	int x;
//	virtual void draw() {
//		Shape::draw();// 기본 클래스의 draw() 호출
//		cout << "Cirlce" << endl;
//	}
//};
//int main() {
//	Circle circle;
//	Shape* pShape = &circle;
//
//	pShape->draw();// 동적 바인딩 발생. draw()가 virtual이므로
//	pShape->Shape::draw();// 정적 바인딩. 발생 범위 지정 연산자(::)로 인해 virtual이라도 정적바인딩
//}

//449pg 가상 소멸자
	// 이제부터는 반드시 소멸자 앞에는 virtual을 붙인다.
	// 가상=동적바인딩(?) 애매하게 들어서 다시확인

//class Base {
//public:
//	virtual void f() {
//		cout << "Base::f()\n";
//	}
//	virtual ~Base() {
//		cout << "~Base() 소멸" << endl;
//	}
//};
//class Derived : public Base {
//public:
//	virtual void f() {// 함수 오버라이딩(virtual)/ 없으면 재정의
//		cout << "Derived::f()\n";
//	}
//	~Derived() {
//		cout << "~Derived() 소멸" << endl;
//	}
//};
//
//int main() {
//	Base* bp = new Derived();
//	Derived* dp = new Derived();
//	delete dp;
//	delete bp;
//}


// 452pg <표 9-1> 오버로딩, 함수 재정의 오버라이딩 비교 읽어보기

// 9.3 가상함수와 오버라이딩의 사례 453pg
	// 모든 interface부와 implementation부가 존재한다.

// 9.4 추상 클래스(=C++에선 abstract를 pure virtual이라고 한다------------------------------이 부분 시험!!!!---------------------------------
	// 순수 가상 함수(추상이라고 하기) 456pg
	// 추상클래스 (457pg) 100% 시험 출제*************
		//추상클래스란?
			// 순수 가상함수를 적어도 하나 이상 가진 클래스
		//추상클래스 포인터는 선언 가능하다.

class Animal {
private:
	int weight;
public:
	Animal(int w = 0) {
		weight = w;
	}
	virtual ~Animal() {
		cout << "Animal::~Animal()\n";
	}
	int getWeight() {
		return weight;
	}
	virtual void sound() = 0;
};
class Dog :public Animal {
	int fangSize;
public:
	Dog(int w, int f) : Animal(w) {
		fangSize = f;
	}
	virtual ~Dog() {// 소멸자는 특히 동적 바인딩을 해야한다.
		cout << "Dog::~Dog()\n";
	}
	int getFangSize() {
		return fangSize;
	}
	virtual void sound() {
		cout << "woof\n";
	}
};
class Cat :public Animal {
	double clawSharpness;
public:
	Cat(int w, double s) : Animal(w) {
		clawSharpness = s;
	}
	virtual ~Cat() {
		cout << "Cat::~Cat()\n";
	}
	int getClawSharpness() {
		return clawSharpness;
	}
	virtual void sound() {
		cout << "Meow\n";
	}
};

int main() {
	Animal* a[3];
	a[0] = new Dog(10, 15);
	a[1] = new Cat(5, 0.9);
	a[2] = new Dog(3, 150);
	for (int i = 0; i < 3; i++)
		a[i]->sound();
	for (int i = 0; i < 3; i++)
		delete a[i];
}
