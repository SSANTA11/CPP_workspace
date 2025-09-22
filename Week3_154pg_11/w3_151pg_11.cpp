//실습 문제 11번(p.154)
#include <iostream>
using namespace std;
//타원을 나타내는 Oval 클래스
//- 멤버변수: 너비, 높이를 나타내는 정수형 width, height
//- 너비, 높이 값을 매개 변수로 받는 생성자
//- 너비와 높이를 1로 초기화하는 기본 생성자(매개 변수 없는 생성자)
//멤버함수 : 너비를 반환하는 getWidth(), 높이를 반환하는 getHeight(),
//너비와 높이를 변경하는 set(int w, int h), 너비와 높이를 출력하는 show()


class Oval {
private:
	int width, height;
public:
	Oval();
	Oval(int width, int height);
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};
Oval::Oval() : Oval(1, 1) {}
Oval::Oval(int width, int height){
	this->width= width;
	this->height= height;
}
int Oval::getWidth(){
	return width;
}
int Oval::getHeight(){
	return height;
}
void Oval::set(int w, int h){
	this->width = w;
	this->height = h;
}
void Oval::show(){
	cout << "Oval: width = " << this->width << ", height = " << this->height<<endl;
}

int main() {
	Oval a, b(10, 15);
	a.set(3, 4);
	a.show();
	cout << b.getWidth() << 'x' << b.getHeight() << endl;
}