#include <iostream>
using namespace std;
// Circle 클래스 선언부
class Circle {
private:
	int radius;
public: //멤버함수에 포함되는 기본 생성자와 생성자와 getArea함수
	Circle();
	Circle(int r);
	double getArea();
};
// Circle 클래스 구현부
	//선언부와 구현부를 구분하는 이유는 구현부가 컴파일 이후 기계어로 변환되기 때문에 선언부만 공개하고 보안성을 높이기 위해서
//Circle::Circle() {
//	radius = 1;
//	cout << "반지름" << radius << "원생성" << endl;
//} 
Circle::Circle() :Circle(1) {} // '위임 생성자'라는 기능 --> 위의 기본 생성자와 동일한 역할, 동일한 구조일 경우 코드량을 줄이기 위해 사용
// 위 내용을 "기본생성자로 다ㄹ른 함수를 호출하시오" 등의 워딩으로 출제될 수 있음
Circle::Circle(int r) {
	radius = r;
	cout << "반지름" << radius << "원 생성" << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}
int main() {
	Circle donut; //기본 생성자 호출
	cout << "donut의 면적은 " << donut.getArea() << endl;
	Circle pizza(30); //매개변수가 있는 생성자 호출
	cout << "pizza의 면적은 " << pizza.getArea() << endl;
	return 0;
}