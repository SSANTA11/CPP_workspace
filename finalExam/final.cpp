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

