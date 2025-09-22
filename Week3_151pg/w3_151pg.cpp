// 개정판 3장 실습문제 5번(p.151)
#include <iostream>
using namespace std;
#include <cstdlib> 
#include <ctime>
//Random 클래스는 기본생성자, 난수를 반환하는 next(), 주어진 범위의
//난수를 반환하는 nextInRange(int low, int high) 멤버 함수를 가지
//며 멤버 변수는 없다.다음 페이지의 실행결과를 보고 클래스를 작성하라.
class Random {
public:
	Random();
	int next();
	int nextInRange(int low, int high);
};
Random::Random() {
	srand((unsigned int)time(0));
}
int Random::next() {
	return rand();
}
int Random::nextInRange(int low, int high) {
	int num = rand();
	while (1) {
		num = rand();
		if (low <= num && num <= high) {
			return num;
		}
	}

}
int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 난수 10 개--" << endl;
	for (int i = 0; i < 10; i++)
	 // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
	cout << r.next() << ' ';
	cout << endl << "-- 2에서 " << "4 까지의 난수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}

//실행 결과(아래는 2번 실행한 결과이며 실행 시마다 값이 달라짐)
//-- 0에서 32767까지의 난수 10 개--
//5339 23033 31816 5968 31625 15708 16667 23592 21078 11068
//-- 2에서 4 까지의 난수 10개--
//34 2 2 2 2 3 3 2 2...
//--에서 32767까지의 난수 10 개--
//5744 12348 18750 7931 32680 11103 9395 21058 4131 2371
//-- 2에서 4 까지의 난수 10개--
//2 344 2 224 24