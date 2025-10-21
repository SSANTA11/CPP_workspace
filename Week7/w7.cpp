// ���� �غ� 
// ������ ���� ȣ��� ���� ���� ȣ���� ����
// C++������ ����
// const�� ������ �ǵ��� �ʰڴٴ� ����̴�.
// ����&�� ���� �Ű������� �ٷ�� ��� �������� ������ �ޱ� ������ const�� �ٿ� ������ ���� ��ȣ�����ϴ�.


// ��� return���� ��ȯ�� �ÿ� ���� ���� ��ȯ, �� ���簡 �Ͼ�� �ȴ�.
// ������ ���� ��ȯ �ÿ� �Լ� ���� �ÿ� �������� �׾������ ������ ��ȯ�� �������ϸ� �ȵȴ�.(<- �̰� ���迣 �ȳ��´�(������ȯ ��Ʈ�� �н�))


// �ǽ� pg.278 9��
#include<iostream>
using namespace std;
//
//class MyStack {
//	int p[10], tos;
//public:
//	MyStack() {
//		this->tos = 0;
//	}
//	bool push(int n) {
//		if (tos == 10) {
//			return false;
//		}
//		p[tos++] = n;
//		return true;
//	}
//	bool pop(int &n) {
//		if (tos == 0) {
//			return false;
//		}
//		n=p[--tos];
//		return true;
//	}
//	
//};
//int main() {
//	MyStack st;
//
//	for (int i = 0; i < 11; i++) { // 11���� ���� Ǫ��
//		if (st.push(i))
//			cout << i << ' '; // Ǫ�õ� �� ȭ�� ���
//		else
//			cout << endl << i + 1 << "��° Ǫ�� ����! ���� �� �� ����" << endl;
//	}
//
//	int n;
//
//	for (int i = 0; i < 11; i++) { // 11���� ���� ��
//		if (st.pop(n))
//			cout << n << ' '; // ������ �޾ƿ� �� ���
//		else
//			cout << endl << i + 1 << "��° �� ����! ������ ��� ����" << endl;
//	}
//}
// ���� 11��
//#include<iostream>
//using namespace std;
//
//class MyStack {
//	int *p, tos, size;
//public:
//	MyStack() : MyStack(10) {};
//	MyStack(int size) {
//		p=new int[size];
//		this->size = size;
//		this->tos = 0;
//	}
//	MyStack(const MyStack& src) {
//		this->size = src.size;
//		p = new int[src.size];
//		for (int i = 0; i < src.size; i++) {
//			p[i] = src.p[i];
//		}
//		tos = src.tos;
//
//	}
//	~MyStack() {
//		if (p)
//			delete[] p;
//	}
//	bool push(int n) {
//		if (tos == 10) {
//			return false;
//		}
//		p[tos++] = n;
//		return true;
//	}
//	bool pop(int &n) {
//		if (tos == 0) {
//			return false;
//		}
//		n=p[--tos];
//		return true;
//	}
//	
//};
//int main() {
//	MyStack a(10); // 10���� ���� ������ ���� ��ü ����
//	a.push(10);
//	a.push(20); // ���� a���� 10, 20�� ������ ���� ����
//
//	MyStack b = a; // ���� ����(��ü a�� �����Ͽ� ��ü b ����)
//	// ���� ��, ���� b�� a�� ���� 10, 20�� ������ ���� ����
//	b.push(30); // ���� b���� 10, 20, 30�� ������ ���� ����
//
//	int n;
//
//	a.pop(n); // ���� a�� �ֻ�ܿ� ����� ���� ��. n�� 20
//	cout << "���� a���� ���� �� " << n << endl;
//
//	b.pop(n); // ���� b�� �ֻ�ܿ� ����� ���� ��. n�� 30
//	cout << "���� b���� ���� �� " << n << endl;
//}

// ������ �������� ����

//class Dept {
//	int size;
//	double* scores;
//public:
//	Dept(int size, double scores[]) {
//		this->size = size;
//		this->scores = new double[size];
//		for (int i = 0; i < size; i++)
//			this->scores[i] = scores[i];
//	}
//	Dept(const Dept & dept) {
//		this->size = dept.size;
//		this->scores = new double[size];
//		for (int i = 0; i < size; i++)
//			this->scores[i] = dept.scores[i];
//	};
//	~Dept() {
//		if (this->scores)
//			delete[] scores;
//	};
//	int getSize() {
//		return size;
//	}
//	void show() {
//		for (int i = 0; i < size; i++)
//			cout << scores[i] << " ";
//	};
//};
//
//int main() {
//	double scores[] = { 10,20,30,40,50 };
//	Dept cs(5, scores);
//	Dept aa(cs);
//	cout << cs.getSize() << endl;
//	cs.show();
//	cout << endl;
//	cout << aa.getSize() << endl;
//	aa.show();
//}



// ������ �������� �߰� ���迡 static�ɹ� ��Ʈ�� �Լ� �ߺ� ��Ʈ���� ���ϰ� �����ϼż� ���迡 �ְ�;��ϽŴ�.(6.4 304pg)

// ��� �Լ� �ߺ� ��Ʈ�� �н�!!

//����Ʈ: ����ƽ�� Ŭ���� �Ҽ����� ��ü�Ҽ��� �ƴϴ�.

// 312pg ������ static �ɹ��� ������ �������� ����ϴ� ���� �ּ�ó���ϰ� �������� �õ�->�׷��� ������ ���� ���ȼ��� �������� ������ �߻�
// static�� Ư¡�� �巯������ �̿��̸� ��ü��::����ƽ�ɹ��� �ƴ� Ŭ������::������ �������� �ۼ�����!


//#include <iostream>
//using namespace std;

//class Circle {
//private:
//    static int numOfCircles; // ������ ���� ���� ���
//    int radius;
//public:
//    Circle() :Circle(1) {};
//    Circle(int r) {
//        radius = r;
//        numOfCircles++; // ������ ���� ���� ����
//    }
//    // ���� �����ڵ� �߰�
//    Circle(const int& c) {
//        this->radius = c.radius;
//    }
//    ~Circle() {
//        numOfCircles--; // ������ ���� ���� ����
//    }
//    double getArea() {
//        return 3.14 * radius * radius;
//    }
//    static int getNumOfCircles() {
//        return numOfCircles;
//    }
//};

int numOfCircles=0;
int getNumOfCircles() {
    return numOfCircles;
};
class Circle {
private:
    //static int numOfCircles;
    int radius;
public:
    Circle() : Circle(1) {}

    Circle(int r) {
        radius = r;
        cout << "������ " << radius << "�� ����\n";
        numOfCircles++; // ������ ���� ���� ����
    }

    ~Circle() {
        cout << "������ " << radius << "�� �Ҹ�\n";
        numOfCircles--;
    }

    void setRadius(int r) {
        radius = r;
    }

    double getArea() {
        return 3.14 * radius * radius;
    }
    int getRadius() {
        return radius;
    }
  // ���迡�� const�� �� �� �ִ� ���� �ִ��� ����� �ϴ� ������ ���� �� �ִ�. ���� �����ڴ� ����� ��� const�� �ݵ�� �ʿ���Ѵ�.
    Circle(const Circle& c) { // ���� ������!! (���� ������ ���� ȣ���� �Ѵٸ� ��������ڰ� ��������ڸ� ã�� ���� ������ Ÿ�� �� ����....!)
        this->radius = c.radius;
        cout << "���� ������ ���� radius = " << radius << endl;
    }
    /*static int getNumOfCircles() {
        return numOfCircles;
    }*/
};

//int Circle::numOfCircles = 0; // 0���� �ʱ�ȭ


int main() {
    Circle* p = new Circle[10]; // 10���� ������ ����
    //cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;
    cout << "�����ϰ� �ִ� ���� ���� = " << getNumOfCircles() << endl;

    delete[] p; // 10���� �Ҹ��� ����
    //cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;
    cout << "�����ϰ� �ִ� ���� ���� = " << getNumOfCircles() << endl;

    Circle a; // ������ ����
    //cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;
    cout << "�����ϰ� �ִ� ���� ���� = " << getNumOfCircles() << endl;

    Circle b; // ������ ����
    //cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;
    cout << "�����ϰ� �ִ� ���� ���� = " << getNumOfCircles() << endl;
}

// ����ƽ �ɹ��� �ν��Ͻ� �ɹ��� �����ϱ⿡�� �ʹ��� ���� ��ü�� ����� �ϱ� ������ �Ž��� �ö󰡼� ����ϱ�� ��������� ����ƽ�Լ��� ����ƽ ������ ����Ѵ�.(313pg ����!!)

//static �ɹ� �Լ��� this ���Ұ�
// non-static�� static�� ���� ����
// static������ ���� ����

// ������ this�� �Ҽ� Ŭ������ ����Ű�� ���� �ƴ϶� ��ü�� ����Ų��.

//30%�� ���� ����
// ���� �������Ѵٸ� �ִ��� ������ ���ڵ� �Ͻð� ���� ������ ���� ���ñ�
//70%�� �ι��� ���� ���ڵ�