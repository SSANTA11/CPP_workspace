// 10주차 과제 有
	// 객체지향의 가장 큰 특징 --> '시키는 행위'

//8단원 상속
	//상속의 비유 : 기존의 건축물의 층고를 올리는것
		// 기본(부모)클래스=1층=슈퍼클래스
		// 파생(자식)클래스=2층=서브클래스
	// 사실 확장이라는 표현 또한 상속의 특징을 잘나타내는 워딩
	// 물론 상속의 특징에는 상속에 따른 포함관계에 대해서도 유의해야한다.
	// 여튼 기존 기능에 +a이면 자식 클래스!!

	// 별개로 다중상속은 안나온다

// 8.2 클래스 상속과 객체 391pg
	//예제 8-1 pg391
#include <iostream>
#include <string>
using namespace std;
//
//class Point {
//	int x, y;
//public:
//	void set(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	void showPoint() {
//		cout << "(" << x << "," << ")" << endl;
//	}
//};
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
//	Point p;
//	ColorPoint cp;
//	cp.set(3, 4);
//	cp.setColor("red");
//	cp.showColorPoint();
//	cp.showPoint();
//
//}
// 당연히 자식이라도 부모의 요소 중 private은 당연이 접근이 불가하다.
// 다만 protected는 이를 유하게 해주어서 자식이 부모에 protected엔 접근 가능토록한다.
// 부모의 private은 자식에서 접근 불가하나 자식에 포함된다

//420pg 실습문제1

//class Circle {
//protected:
//	int radius;
//
//public:
//	Circle(int r = 1) {
//		radius = r;
//#ifdef _DEBUG
//		cout << "반지름 " << radius << "원 생성\n";
//#endif
//	}
//
//	~Circle() {
//
//#ifdef _DEBUG
//		cout << "반지름 " << radius << "원 소멸\n";
//#endif
//	}
//
//	void setRadius(int r) {
//		radius = r;
//	}
//
//
//	int getRadius() {
//		return radius;
//	}
//
//	double getArea() {
//		return 3.14 * radius * radius;
//	}
//};
//class NamedCircle : public Circle {
//	int r;
//	string name;
//public:
//	NamedCircle(int r, string name) {
//		//setRadius(r);
//		this->radius = r;
//		this->name = name;
//	}
//	void show() {
//		cout << "r = " << getRadius() << ", name = " << name;
//	}
//
//};
//int main() {
//	NamedCircle waffle(3, "waffle");
//	waffle.show();
//}
// 8.3 상속과 객체 포인터 395pg 
// 업캐스팅****************************** 업캐스팅이 뭔가?? - 시험출제-********************************
	//기본클래스 포인터로(혹은 참조변수)로 자식클래스르 가르킴!
// ★★★★★★★★★★★★★★★★★★★★★★ 시험 출제 다형성 : 함수중복 다형성과 상속 다형성 ★★★★★★★★★★★★★★★★★★★★★★★★★

//class Point {
//	int x, y;
//public:
//	void set(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	void showPoint() {
//		cout << "(" << x << "," << ")" << endl;
//	}
//};
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
//	Point p;
//	ColorPoint cp;
//	ColorPoint* pDer = &cp; //개를 가르키는 손가락을 개를 가르킴
//	Point* pBase = &cp; // up-casting: 포유류 손가락을 개를 가르킴
//
//	pDer->set(3, 4);
//	pBase->showPoint();
//	pDer->setColor("Red");
//	pDer->showColorPoint();
//	//pBase->showColorPoint();
//
//	cp.set(3, 4);
//	cp.setColor("red");
//	cp.showColorPoint();
//	cp.showPoint();
//
//}

//다운캐스팅*********************************시험 출제*********************************************
	// 이전에 했던 것처럼 당연히 업캐스팅된 것만 다운캐스팅이 가능하다.
	// 책에 기본 클래스 객체를 파생 클래스로 형 변환하여 파생 클래스 포인터로 가르키는 것이라는 표현에서 
	// 기본 클래스라는 워딩은 다소 옳지 않다.

// 8.4 protected 점근지정 pg398

// 예제 8-2 400pg
//class Point {
//protected:
//	int x, y;
//public:
//	void set(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	void showPoint() {
//		cout << "(" << x << "," << ")" << endl;
//	}
//};
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
//	bool equals(ColorPoint p) {
//		if (x == p.x && y == p.y && color == p.color) {
//			return true;
//		}return false;
//	}
//};
//int main() {
//	Point p;
//	ColorPoint cp;
//	ColorPoint cp2;
//	ColorPoint* pDer = &cp; //개를 가르키는 손가락을 개를 가르킴
//	Point* pBase = &cp; // up-casting: 포유류 손가락을 개를 가르킴
//
//	pDer->set(3, 4);
//	pBase->showPoint();
//	pDer->setColor("Red");
//	pDer->showColorPoint();
//	//pBase->showColorPoint();
//
//	cp.set(3, 4);
//	cp.setColor("red");
//	cp.showColorPoint();
//	cp.showPoint();
//
//}

// 8.5 상속과 생성자, 소멸자 401pg
	// 1층: 부모
	// 2층: 자식
		// 1층부터 만들고, 2층을 올리고(생성자 실행)
		// 2층부터 부시고, 1층을 부시고(소멸자 실행)
	//이를테면 A를 상속받은 B 객체를 만들때 B의 생성자의 동작 중 A의 생성자가 실행 및 완료되고, B의 생성자가 완료된다.
	//만약 부모의 기본 생성자가 묵시적이라면, 위의 과정에선 당연히 컴파일 오류
		// 이때는 명시적인 부모클래스의 생성자로 호출한다. 406pg
			// 앞서 언급한 A,B 생성자 관계에서 생성자 B 옆에 B(int x): A(x+3) rkxdl Tjwnsek


// 예제 8-3

//class TV {
//	int size;
//public:
//	TV(int size=20) {
//		this->size = size;
//	}
//	int getSize() {
//		return size;
//	}
//};
//class WideTV :public TV {
//	bool videoIn;
//public:
//	WideTV(int size, bool videoIn):TV(size) {
//		this->videoIn = videoIn;
//	}
//	bool getVideoIn() {
//		return videoIn;
//
//	}
//
//};
//class SmartTV :public WideTV {
//	string ipAddr;
//public:
//	SmartTV(string ipAddr, int size): WideTV(size, true){
//		this->ipAddr = ipAddr;
//	}
//	string getIpAddr() {
//		return ipAddr;
//
//	}
//
//};
//
//int main() {
//	SmartTV htv("192.0.0.1", 32);
//	cout << "size=" << htv.getSize() << endl;
//	cout << "videoIn=" << boolalpha <<htv.getVideoIn()<< endl;
//	cout << "IP=" << htv.getIpAddr() << endl;
//}


// 연습 풀이 교수님 오리지널 생성자 매개변수로 private 침공(?)
//class Circle {
//private:
//	int radius;
//
//public:
//	Circle(int r = 1) {
//		radius = r;
//#ifdef _DEBUG
//		cout << "반지름 " << radius << "원 생성\n";
//#endif
//	}
//
//	~Circle() {
//
//#ifdef _DEBUG
//		cout << "반지름 " << radius << "원 소멸\n";
//#endif
//	}
//
//	void setRadius(int r) {
//		radius = r;
//	}
//
//
//	int getRadius() {
//		return radius;
//	}
//
//	double getArea() {
//		return 3.14 * radius * radius;
//	}
//};
//class NamedCircle : public Circle {
//	int r;
//	string name;
//public:
//	NamedCircle(int r, string name): Circle(r) {
//		this->name = name;
//	}
//	void show() {
//		cout << "r = " << getRadius() << ", name = " << name;
//	}
//
//};
//int main() {
//	NamedCircle waffle(3, "waffle");
//	waffle.show();
//}

//개정판 실습문제2 418pg
class Circle {
private:
	int radius;

public:
	Circle(int r = 1) {
		radius = r;
		cout << "반지름 " << radius << "원 생성\n";
	}

	~Circle() {

		cout << "반지름 " << radius << "원 소멸\n";
	}

	void setRadius(int r) {
		radius = r;
	}


	int getRadius() {
		return radius;
	}

	double getArea() {
		return 3.14 * radius * radius;
	}
};
class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int r = 0, string name = "") : Circle(r) {
		this->name = name;
	}
	void show() {
		cout << "r = " << getRadius() << ", name = " << name;
	}
	void setName(string name) {
		this->name = name;
	}
};
int main() {
	NamedCircle pizza[5];
}