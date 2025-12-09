//시험 추제 정리 및 기존 코드 복습

// 오버라이딩은 다형성의 한사례이다 --- 시험 출제 포인트 287

// static 사용의 이유 --- 시험 출제 포인트 324
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;

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

#include <iostream>
#include <cstring>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class ColorPoint : public Point{
	string color;
public:
	ColorPoint(int x, int y, string color) :Point(x, y) {
		this->color = color;
	}
	void setPoint(int x, int y) {
		move(x, y);
	}
	void setColor(string color) {
		this->color = color;
	}
	void show() {
		cout << color << "색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다.";
	}
};

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(30, 40);
	cp.setColor("BLUE");
	cp.show();
}