// ������ 3�� �ǽ����� 5��(p.151)
#include <iostream>
using namespace std;
#include <cstdlib> 
#include <ctime>
//Random Ŭ������ �⺻������, ������ ��ȯ�ϴ� next(), �־��� ������
//������ ��ȯ�ϴ� nextInRange(int low, int high) ��� �Լ��� ����
//�� ��� ������ ����.���� �������� �������� ���� Ŭ������ �ۼ��϶�.
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
	cout << "-- 0���� " << RAND_MAX << "������ ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++)
	 // 0���� RAND_MAX(32767) ������ ������ ����
	cout << r.next() << ' ';
	cout << endl << "-- 2���� " << "4 ������ ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}

//���� ���(�Ʒ��� 2�� ������ ����̸� ���� �ø��� ���� �޶���)
//-- 0���� 32767������ ���� 10 ��--
//5339 23033 31816 5968 31625 15708 16667 23592 21078 11068
//-- 2���� 4 ������ ���� 10��--
//34 2 2 2 2 3 3 2 2...
//--���� 32767������ ���� 10 ��--
//5744 12348 18750 7931 32680 11103 9395 21058 4131 2371
//-- 2���� 4 ������ ���� 10��--
//2 344 2 224 24