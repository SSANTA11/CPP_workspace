// 시험 준비 
// 참조에 의한 호출과 값에 의한 호출의 차이
// C++에서의 참조
// const는 원본을 건들지 않겠다는 약속이다.
// 참조&를 통해 매개변수를 다루는 경우 원본값이 영향을 받기 때문에 const를 붙여 원본의 값을 보호가능하다.


// 통상 return으로 반환할 시에 값에 의한 반환, 즉 복사가 일어나게 된다.
// 참조에 의한 반환 시엔 함수 종료 시에 원본값이 죽어버리기 때문에 반환은 참조로하면 안된다.(<- 이건 시험엔 안나온다(참조반환 파트는 패스))


// 실습 pg.278 9번
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
//	for (int i = 0; i < 11; i++) { // 11개의 정수 푸시
//		if (st.push(i))
//			cout << i << ' '; // 푸시된 값 화면 출력
//		else
//			cout << endl << i + 1 << "번째 푸시 실패! 스택 꽉 차 있음" << endl;
//	}
//
//	int n;
//
//	for (int i = 0; i < 11; i++) { // 11번의 정수 팝
//		if (st.pop(n))
//			cout << n << ' '; // 팝으로 받아온 값 출력
//		else
//			cout << endl << i + 1 << "번째 팝 실패! 스택이 비어 있음" << endl;
//	}
//}
// 문제 11번
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
//	MyStack a(10); // 10개의 저장 공간을 가진 객체 생성
//	a.push(10);
//	a.push(20); // 스택 a에는 10, 20의 순서로 정수 저장
//
//	MyStack b = a; // 복사 생성(객체 a를 복사하여 객체 b 생성)
//	// 복사 후, 스택 b는 a와 같이 10, 20의 순서로 정수 저장
//	b.push(30); // 스택 b에는 10, 20, 30의 순서로 정수 저장
//
//	int n;
//
//	a.pop(n); // 스택 a의 최상단에 저장된 정수 팝. n은 20
//	cout << "스택 a에서 팝한 값 " << n << endl;
//
//	b.pop(n); // 스택 b의 최상단에 저장된 정수 팝. n은 30
//	cout << "스택 b에서 팝한 값 " << n << endl;
//}

// 교수님 오리지널 문제

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



// 노정규 교수님은 중간 시험에 static맴버 파트를 함수 중복 파트보다 중하게 생각하셔서 시험에 넣고싶어하신다.(6.4 304pg)

// 고로 함수 중복 파트는 패스!!

//포인트: 스태틱은 클래스 소속이지 객체소속이 아니다.

// 312pg 편집판 static 맴버를 공유의 목적으로 사용하는 예를 주석처리하고 전역으로 시도->그러나 전역의 경우는 보안성이 떨어지는 문제점 발생
// static의 특징을 드러내도록 이왕이면 객체명::스태틱맴버가 아닌 클래스명::스태택 형식으로 작성하자!


//#include <iostream>
//using namespace std;

//class Circle {
//private:
//    static int numOfCircles; // 생성된 원의 개수 기억
//    int radius;
//public:
//    Circle() :Circle(1) {};
//    Circle(int r) {
//        radius = r;
//        numOfCircles++; // 생성된 원의 개수 증가
//    }
//    // 복사 생성자도 추가
//    Circle(const int& c) {
//        this->radius = c.radius;
//    }
//    ~Circle() {
//        numOfCircles--; // 생성된 원의 개수 감소
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
        cout << "반지름 " << radius << "원 생성\n";
        numOfCircles++; // 생성된 원의 개수 증가
    }

    ~Circle() {
        cout << "반지름 " << radius << "원 소멸\n";
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
  // 시험에서 const를 쓸 수 있는 곳에 최대한 쓰라고 하는 문제가 나올 수 있다. 복사 생성자는 통상의 경우 const를 반드시 필요로한다.
    Circle(const Circle& c) { // 복사 생성자!! (만약 참조에 의한 호출을 한다면 복사생성자가 복사생성자를 찾는 무한 루프를 타게 될 수도....!)
        this->radius = c.radius;
        cout << "복사 생성자 실행 radius = " << radius << endl;
    }
    /*static int getNumOfCircles() {
        return numOfCircles;
    }*/
};

//int Circle::numOfCircles = 0; // 0으로 초기화


int main() {
    Circle* p = new Circle[10]; // 10개의 생성자 실행
    //cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
    cout << "생존하고 있는 원의 개수 = " << getNumOfCircles() << endl;

    delete[] p; // 10개의 소멸자 실행
    //cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
    cout << "생존하고 있는 원의 개수 = " << getNumOfCircles() << endl;

    Circle a; // 생성자 실행
    //cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
    cout << "생존하고 있는 원의 개수 = " << getNumOfCircles() << endl;

    Circle b; // 생성자 실행
    //cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
    cout << "생존하고 있는 원의 개수 = " << getNumOfCircles() << endl;
}

// 스태틱 맴버는 인스턴스 맴버에 접근하기에는 너무나 많은 객체가 사용을 하기 때문에 거슬러 올라가서 사용하기는 어려움으로 스태틱함수가 스태틱 변수를 사용한다.(313pg 참고!!)

//static 맴버 함수는 this 사용불가
// non-static은 static에 접근 가능
// static끼리는 접근 가능

// 별개로 this는 소속 클래스를 가르키는 것이 아니라 객체를 가르킨다.

//30%는 설명 문제
// 예를 들으라한다면 최대한 가볍게 손코딩 하시고 설명만 줄줄이 쓰지 마시길
//70%는 두문제 정도 손코딩