#define CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

//class Circle {
//private:
//    int radius;
//
//public:
//    Circle() : Circle(1) {}
//
//    Circle(int r) {
//        radius = r;
//        cout << "반지름 " << radius << "원 생성\n";
//    }
//
//    ~Circle() {
//        cout << "반지름 " << radius << "원 소멸\n";
//    }
//
//    void setRadius(int r) {
//        radius = r;
//    }
//
//    double getArea() {
//        return 3.14 * radius * radius;
//    }
//    int getRadius() {
//        return radius;
//    }
//  // 시험에서 const를 쓸 수 있는 곳에 최대한 쓰라고 하는 문제가 나올 수 있다.
//    Circle(const Circle& c) { // 복사 생성자!! (만약 참조에 의한 호출을 한다면 복사생성자가 복사생성자를 찾는 무한 루프를 타게 될 수도....!)
//        this->radius = c.radius;
//        cout << "복사 생성자 실행 radius = " << radius << endl;
//    }
//};

//void increase(Circle *p) {
//    int r = p->getRadius();
//    p->setRadius(r + 1);
//}
//int main() {
//    Circle waffle(30);
//    increase(&waffle);
//    cout << waffle.getRadius() << endl;
//}

//참조와 함수 (233pg)

// 참조는 곧 원본 변수의 별명이다.******************************중요*******************************
    // 그러므로 당연히 원본변수가 존재해야지 참조변수가 가능하다.

// C++에서 참조변수란 별명이다. 자바처럼 주소는 아니다
    // 요약: C++ 참조는 메모리 주소처럼 동작하는 것이 아니라, 원본 변수와 동일하게 취급되는 이름(별명)입니다.✅

// 객체에 대한 참조 (main함수만, 예제 5-4)
//int main() {
//    Circle circle;
//    Circle& refc = circle;
//    Circle& aaaaaaaaaaaaaaaaaaaaaaaa = refc;
//    refc.setRadius(10);
//    cout << refc.getArea() << " " << circle.getRadius()<<endl;
//    cout << aaaaaaaaaaaaaaaaaaaaaaaa.getArea()<<endl;
//    cout << refc.getArea();
//}

// 참조(별명!!!)에 의한 호출 
    // C는 값에 의한 호출만 존재
    // C++은 값에 의한 호출이 기본이나, 참조에 의한 호출도 존재
//void increase(Circle &c) {
//    int r = c.getRadius();
//    c.setRadius(r + 1);
//}
//
//int main() {
//    Circle waffle(30);
//    increase(waffle);
//    cout << waffle.getRadius() << endl;
//}
// 별명을 매개변수로 사용하면, 원본에 대한 별명이기 때문에 원본의 값이 편집된다.
// 기존 포인터와 메모리 주소 활용과 달리 원본 자체가 넘어간다.

// 참조 매개변수로 평균 리턴하기 예제(237pg)
//bool average(int a[], int size, int& avg) {
//    if (size <= 0) {
//        return false;
//    }
//    int sum = 0;
//    for (int i = 0; i < size; i++) {
//        sum += a[i];
//    }
//    avg = sum / size;
//    return true;
//}
//
//int main() {
//    int x[] = { 0,1,2,3,4,5 };
//    int avg;
//    if (average(x, 6, avg)) {
//        cout << "평균은 " << avg << endl;
//    }
//    else
//        cout << "매개변수 오류" << endl;
//
//    if (average(x, -2, avg)) {
//        cout << "평균은 " << avg << endl;
//    }
//    else
//        cout << "매개변수 오류" << endl;
//}

// 실습문제 pg.274
// 1번
//void twice(int& ss) {
//    ss *= 2;
// 
//}
//
//int main() {
//    int n = 12;
//    twice(n);
//    cout << n << endl;
//}


//2번
//bool compare(int a, int b,int &min, int &max) {
//    if (a == b) {
//        return true;
//    }
//    else if (a < b) {
//        max = b;
//        min = a;
//    }
//    else if (a > b) {
//        max = a;
//        min = b;
//    }
//    return false;
//}
//
//int main() {
//    int a, b, min, max;
//    cout << "두 수 입력: ";
//    cin >> a >> b;
//    bool res = compare(a, b, min, max);
//    if (res)
//        cout << "같음\n";
//    else
//        cout << "min = " << min << ", max = " << max << endl;
//}

//_______________________________________________________ 중요: 만약 시험 문제 중 예를 들어라 하는 경우, 간략한 생략 많이된 소스코드를 예시로 들면된다._______________________________________________________________________________________

// 복사 생성자
    // 얕은 복사와 깊은 복사
        // 얕은 복사는 생성자 복사 시 내부의 포이터 또한 복사되어 별개의 공간을 가지지 못하는 상황을 꼬집는 워딩이다 <-> 잘되면 깊은 복사

// 251pg  Circle의 클래스와 복사 생성자와 객체 복사 (예제 5-10)
//void increase(Circle c) {
//    int r = c.getRadius();
//    c.setRadius(r + 1);
//}
//int main() {
//    Circle sss(30); // 값에 의한 호출
//    cout << "---------------------------------▲값에 의한 호출-----------------------------------"<<endl;
//    Circle src;
//    increase(src);// 값에 의한 호출로 인수를 넘겨줄 떄 복사 생성자가 호출됨
//    cout << "-------------▲값에 의한 호출로 인수를 넘겨줄 떄 복사 생성자가 호출됨---------------"<<endl;
//    Circle dest(src); // 복사 생성자 호출
//
//    cout << "원본의 면적 = " << src.getArea() << endl;
//    cout << "사본의 면적 = " << dest.getArea() << endl;
//    cout << "------------------------------▲복사 생성자 호출------------------------------------"<<endl;
//}
//복사 생성자에 대한 참고 사항
//주석에 언급하셨던 중요한 개념은 다음과 같습니다.
//
//참조 매개변수 const Circle& c의 중요성 : 복사 생성자는 매개변수로** 반드시 참조(&)** 를 사용해야 합니다.만약 값(Circle c)을 사용한다면, 함수 호출 시 인수를 전달하기 위해 다시 복사 생성자를 호출하게 되어** 무한 재귀 호출(Infinite Recursion)** 에 빠지게 됩니다.
//
//const의 사용 : 매개변수에 const를 사용함으로써 원본 객체 c를 복사 과정에서 수정하지 않겠다는 것을 명시하여 안전성을 높입니다.
//
//얕은 / 깊은 복사 : 이 예제는 멤버 변수가 int(기본 타입) 하나뿐이므로, 얕은 복사를 수행해도 잠재적인 문제(메모리 공유)는 발생하지 않습니다.하지만 포인터 멤버 변수가 있다면, 작성된 복사 생성자는 얕은 복사가 되어 문제가 될 수 있습니다.


 //얕은 복사 생성자를 사용하여 프로그램이 비정상 종료되는 경우 (254pg)
class Person { // Person 클래스 선언
private:
    char* name;
    int id;

public:
    // 복사 생성자 (컴파일러 디폴트 복사 생성자 대체)
    // 깊은 복사가 구현되지 않았음을 보여주기 위한 예제이므로, 
    // 여기서는 기본 타입만 복사하는 얕은 복사 형태로 구현된 것으로 가정합니다.


    // 생성자
    Person(int id, const char* name) {
        this->id = id;
        int len = strlen(name); // name의 문자열 길이 계산
        this->name = new char[len + 1]; // name 문자열 공간 할당
        strcpy(this->name, name); // name에 문자열 복사
    }

    // 소멸자
    ~Person() {
        if (name) // 만약 name에 동적 할당된 배열이 있으면
            delete[] name; // 할당된 메모리 소멸
    }

    // 이름 변경
    void changeName(const char* name) {
        if (strlen(name) > strlen(this->name)) // 현재 name에 할당된 메모리보다 새 이름이 더 길 경우 (변경 불가로 가정)
            return;
        strcpy(this->name, name); // name에 문자열 복사
    }

    // 출력
    void show() {
        cout << this->id << ", " << this->name << endl;
    }
};

int main() {
    Person father(1, "KiTae"); // (1) father 객체 생성
    Person daughter(father);   // (2) daughter 객체 복사 생성. 복사 생성자 호출.

    cout << "daughter 객체 생성 직후 ----" << endl;

    father.show(); // (3) father 객체 출력
    daughter.show(); // (3) daughter 객체 출력

    daughter.changeName("Grace"); // (4) daughter의 이름을 "Grace"로 변경
    cout << "daughter 이름 Grace로 변경한 후 ----" << endl;

    father.show(); // (5) father 객체 출력
    daughter.show(); // (5) daughter 객체 출력

    return 0; // (6), (7) daughter, father 소멸

}
