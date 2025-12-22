
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

//class Random {
//	static bool initialized;
//	Random() {};
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
//	for (int i = 0;i < 10;i++) {
//		cout << Random::nextInt(20000) << endl;
//	}
//}
// static과 랜덤의 관계에서 랜덤을 private으로 선언한 이유와 static bool initialized을 static으로 선언한 이유
	// 객체를 생성할 필요가 없음을 명시적으로 들어내고 강제하기 위해 private으로 선언함
	// 현재 initialized변수를 이용하는게 static이므로 정적메서드는 정적 자원만 컨트롤 가능하기에 변수도 정적으로 설정했으며, 플래그의 역할을 하는 initialized의 단일성을 보장함

//========================================================================================================================================================================================================
//class Rect {
//	int w, h;
//public:
//	Rect(int w, int h) {
//		this->w = w;
//		this->h = h;
//	}
//	friend bool equals(Rect r, Rect s);
//};
//bool equals(Rect r, Rect s) {
//	if (r.w == s.w&& r.h == s.h) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//int main() {
//	Rect a(3, 4), b(1, 3);
//	if (equals(a, b)) {
//		cout << "=";
//	}
//	else {
//		cout << "!=";
//	}
//	
//}
//class Rect;
//
//class RectManager {
//public:
//	static bool equals(Rect a, Rect b);
//	static bool copy(Rect& dst, const Rect& src);
//};
//
//class Rect {
//	int w, h;
//public:
//	Rect(int w, int h) {
//		this->w = w;
//		this->h = h;
//	}
//	friend RectManager;
//};
//bool RectManager::equals(Rect r, Rect s) {
//	if (r.w == s.w&& r.h == s.h) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//bool RectManager::copy(Rect& dst, const Rect& src) {
//	dst.w = src.w;
//	dst.h = src.h;
//	return true;
//}
//int main() {
//	Rect a(3, 4), b(1, 3);
//	RectManager::copy(a, b);
//	if (RectManager::equals(a, b)) {
//		cout << "=";
//	}
//	else {
//		cout << "!=";
//	}
//	
//}
// 프렌드 함수: 특정 클래스의 private, protected 맴버에 접근할 수 있는 특권을 부여받은 함수
// 프렌드 클래스*: 특정 클래스의 private, protected 맴버에 접근할 수 있는 특권을 부여받은 클래스
//========================================================================================================================================================================================================
//========================================================================================================================================================================================================


class Power {
	int k;
	int p;
public:
	Power(int k = 0, int p = 0) {
		this->k = k;
		this->p = p;
	}
	void show() {
		cout << "k=" << k << "    p=" << p << endl;
	}
	Power operator+(const Power& p2) {
		Power tmp;
		tmp.k = this->k + p2.k;
		tmp.p = this->p + p2.p;
		return tmp;
	}
	bool operator==(const Power& p2) {
		if (this->k == p2.k && this->p == p2.p) {
			return true;
		}
		return false;
	}
	Power& operator+=(const Power& p2) {
		this->k += p2.k;
		this->p += p2.p;
		return *this;
	}

	Power operator + (const int& n) {
		Power tmp;
		tmp.k = this->k + n;
		tmp.p = this->p + n;
		return tmp;
	}

	bool operator < (const Power& op2) {
		int thisPower = this->k * this->k + this->p * this->p;
		int op2Power = op2.k * op2.k + op2.p * op2.p;

		if (thisPower < op2Power)
			return true;
		return false;
	}
	bool operator > (const Power& op2) {
		int thisPower = this->k * this->k + this->p * this->p;
		int op2Power = op2.k * op2.k + op2.p * op2.p;

		if (thisPower > op2Power)
			return true;
		return false;
	}

	friend Power operator+(const int& n, const Power& p1);
	friend ostream& operator << (ostream& os, const Power& p);
};
ostream& operator << (ostream& os, const Power& p) {
	os << "k=" << p.k << "        p=" << p.p;
	return os;
}
Power operator +(const int& n, const Power& p1) {
	Power tmp;
	tmp.k = n + p1.k;
	tmp.p = n + p1.p;
	return tmp;
}
int main() {
	Power a(1, 2), b(2, 3);
	Power c;
	c.operator=(a.operator+(b));
	a.show();
	b.show();
	c.show();
	if (a == b) {
		cout << "="<<endl;
	}
	else {
		cout << "!="<<endl;
	}
	a.operator+=(b);
	a.show();
	b = a + 2;
	b.show();
	if (b < a) {
		cout << "a>b\n";
	}
	else if (b > a) {
		cout << "a<b\n";
	}
	cout << a << b << endl;
}
