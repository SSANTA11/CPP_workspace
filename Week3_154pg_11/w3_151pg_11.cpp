//�ǽ� ���� 11��(p.154)
#include <iostream>
using namespace std;
//Ÿ���� ��Ÿ���� Oval Ŭ����
//- �������: �ʺ�, ���̸� ��Ÿ���� ������ width, height
//- �ʺ�, ���� ���� �Ű� ������ �޴� ������
//- �ʺ�� ���̸� 1�� �ʱ�ȭ�ϴ� �⺻ ������(�Ű� ���� ���� ������)
//����Լ� : �ʺ� ��ȯ�ϴ� getWidth(), ���̸� ��ȯ�ϴ� getHeight(),
//�ʺ�� ���̸� �����ϴ� set(int w, int h), �ʺ�� ���̸� ����ϴ� show()


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