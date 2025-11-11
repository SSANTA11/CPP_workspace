// 6.1 함수중복
	//함수중복 동일한 이름의 함수를 두개 이상 정의
	//다형성(polymorphism)의 한사례, ---------------------------------------------------------------------------------------------시험출제 가능성 농후 287pg

	// 생성자 함수 중복 290pg

// 6.2 디폴트 매개변수 291pg
	// 디폴트 매개변수에 관한 제약조건!
		// 기본형태 -> void msg(int a=5)
	
	// 지켜야할 규칙
		// 매개변수가 다수일 경우 디폴트 매개변수는 모두 끝에 몰려 선언되어야 한다.
	
	// 함수 중복의 간소화 296pg
		// (예를 들어 생성자에서 기본 생성자와 추가적인 생성자를 한번에 처리 가능) 

//324pg 7번 문제 수정판

#include <iostream>
#include <cstdlib>// stdlib.h : rand(), srand()
#include <ctime> // time.h : time()
using namespace std;
//
//
//class Random {
//	Random() {}
//	static bool initialized;
//public:
//	static int nextInt(int min = 0, int max = RAND_MAX) {
//	if (!initialized) {
//		srand(time(0));
//		initialized = true;
//	}
//	return rand()% (max - min + 1) + min;
//	}
//};
//bool Random::initialized = false;
//
//int main() {
//srand(time(0));
//	for (int i = 0; i < 10; i++) {
//		cout << Random::nextInt(20000) << endl;
//	}
//}
// 위 예제 기말 포인트 :  static과 랜덤의 관계에서 랜덤을 private으로 선언한 이유와 static bool initialized을 static으로 선언한 이유


//-------------------------------------------------------------------------------------------------------------------------------------------------------------
// 프렌드 개념 331pg
	// 클래스의 private, protected 맴버에 접근할 수 있는 특권을 부여받은 함수나 클래스
	// 프렌드 함수: 특정 클래스의 private, protected 맴버에 접근할 수 있는 특권을 부여받은 함수
	// 프렌드 클래스*: 특정 클래스의 private, protected 맴버에 접근할 수 있는 특권을 부여받은 클래스

// 332pg 예제
//class Rect {
//	int width, height;
//public:
//	Rect(int width, int height) {
//		this->width = width;
//		this->height = height;
//	}
//	friend bool equals(Rect r, Rect s); // 전역 함수 friend
//};
//
//bool equals(Rect r, Rect s) { // 전역 함수 friend
//	if (r.width == s.width && r.height == s.height)
//		return true;
//	else 
//		return false;
//}
//
//int main() {
//	Rect a(3, 4), b(3, 4);
//
//	if (equals(a, b))
//		cout << "equal\n";
//	else 
//		cout << "not equal\n";
//}

// 7-2 334pg 예제 그대로
//class Rect;// 전방 참조
//
//class RectManager {
//public:
//    static bool equals(Rect r, Rect s);
//	static bool copy(Rect& dst, const Rect& src);
//};
//
//class Rect {
//    int width, height;
//public:
//    Rect(int width, int height) {
//        this->width = width;
//        this->height = height;
//    }
//    //friend bool RectManager::equals(Rect r, Rect s);
//	friend RectManager;
//};
//
//bool RectManager::equals(Rect r, Rect s) {
//    if (r.width == s.width && r.height == s.height)
//        return true;
//    else 
//		return false;
//}
//bool RectManager::copy(Rect& dst, const Rect& src) {
//	dst.width = src.width;
//	dst.height = src.height;
//	return true;
//}
//
//int main() {
//    Rect a(3, 4), b(1, 1);
//    //RectManager man; // 객체 생성 없이 equals 호출하도록 수정
//	RectManager::copy(a, b);
//    if (RectManager::equals(a, b))
//        cout << "equal\n";
//    else cout << "not equal\n";
//}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// 7.2 연산자 중복

// 연산자 함수 구현340pg
	// 구현의 2가지 방법
		// 멤버 함수로 구현
		// 전역 함수로 구현
	// operator 키워드 사용
	// 연산자 함수의 형식
		// 멤버 함수: 반환형 operator 연산자기호(매개변수리스트)
		// 전역 함수: 반환형 operator 연산자기호(피연산자1, 피연산자2)

//두대의 power객체를 더하는 +연산자 작성 345pg 예제 7-4

class Power {
	int kick;
	int punch;
public:
	Power(int k = 0, int p = 0) {
		kick = k;
		punch = p;
	}
	void show() {
		cout << "kick: " << kick << ", punch: " << punch << endl;
	}
	
	Power operator + (const Power& op2) {
		Power tmp;
		tmp.kick = this->kick + op2.kick;
		tmp.punch = this->punch + op2.punch;
		return tmp;
	}
	
	bool operator == (const Power& op2) {
		if ((this->kick == op2.kick) && (this->punch == op2.punch))
			return true;
		else
			return false;
	}

	Power& operator += (const Power& op2) {
		cout << "operator += called" << endl;
		this->kick += op2.kick;
		this->punch += op2.punch;
		return *this;
	}

	Power operator +(const int& op2) {
		Power tmp;
		tmp.kick = kick + op2;
		tmp.punch = punch + op2;
		return tmp;
	}
	
	bool operator < (const Power & op2) {
		int thisPower = this->kick * this->kick + this->punch * this->punch;
		int op2Power = op2.kick * op2.kick + op2.punch * op2.punch;

		if (thisPower < op2Power)
			return true;
		return false;
	}
	bool operator > (const Power& op2) {
		int thisPower = this->kick * this->kick + this->punch * this->punch;
		int op2Power = op2.kick * op2.kick + op2.punch * op2.punch;

		if (thisPower > op2Power)
			return true;
		return false;
	}
	friend Power operator +(int op1, Power op2);
	// ▲ 2+a를 위한 + 연산자 함수를 프렌드로 작성 361pg
	friend ostream& operator<<(ostream& os, const Power& op);
};
ostream&operator<<(ostream& os, const Power& op) {
	os << "kick: " << op.kick << ", punch: " << op.punch << endl;
	return os;
}
Power operator +(int op1, Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}
int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b;
	// ▲ 내부적으로 c=a.operator+(b);로 동작함 345pg
	a.show();
	b.show();
	c.show();

	if (a==b) {
	// ▲ 내부적으로 a.operator==(b);로 동작함 347pg
		cout << "a와 b는 같다!" << endl;
	}
	else {
		cout << "a와 b는 다르다!" << endl;
	}
	//a += b;
	a.operator+=(b);
	a.show();
	// ▲ 내부적으로 a.operator+=(b);로 동작함 349pg
	b = a + 2;
	b.show();
	if (b < a) {
		cout << "a가 b보다 크다!" << endl;
	}
	else if(b > a) {
		cout << "b가 a보다 크다!" << endl;
	}
	// ▲ 내부적으로 b.operator<(a);, b.operator>(a);로 동작함
	cout << a << endl << b << endl;
}