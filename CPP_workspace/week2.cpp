#include <iostream>
using namespace std;
// Circle Ŭ���� �����
class Circle {
private:
	int radius;
public: //����Լ��� ���ԵǴ� �⺻ �����ڿ� �����ڿ� getArea�Լ�
	Circle();
	Circle(int r);
	double getArea();
};
// Circle Ŭ���� ������
	//����ο� �����θ� �����ϴ� ������ �����ΰ� ������ ���� ����� ��ȯ�Ǳ� ������ ����θ� �����ϰ� ���ȼ��� ���̱� ���ؼ�
//Circle::Circle() {
//	radius = 1;
//	cout << "������" << radius << "������" << endl;
//} 
Circle::Circle() :Circle(1) {} // '���� ������'��� ��� --> ���� �⺻ �����ڿ� ������ ����, ������ ������ ��� �ڵ差�� ���̱� ���� ���
// �� ������ "�⺻�����ڷ� �٤��� �Լ��� ȣ���Ͻÿ�" ���� �������� ������ �� ����
Circle::Circle(int r) {
	radius = r;
	cout << "������" << radius << "�� ����" << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}
int main() {
	Circle donut; //�⺻ ������ ȣ��
	cout << "donut�� ������ " << donut.getArea() << endl;
	Circle pizza(30); //�Ű������� �ִ� ������ ȣ��
	cout << "pizza�� ������ " << pizza.getArea() << endl;
	return 0;
}