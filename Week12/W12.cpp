//11/25 12주차(저번 시간 추상클래스와 동적바인딩 정적바인딩 복습으로 시작)

#include <iostream>
#include <string>
using namespace std;


// virtual이 없으면 반드시 정적 바인딩
// 동적 바인딩의 소멸자 없으면 생기는 일 결과 예측 시험 준비

/*
동적 바인딩을 위해 부모 클래스 포인터로 자식 클래스 객체를 다룰 때, 부모 클래스의 소멸자에 virtual 키워드가 없으면 발생하는 문제는 다음과 같이 요약할 수 있습니다.

핵심 요약 부모 포인터를 통해 자식 객체를 삭제(delete)할 때, 자식 클래스의 소멸자가 호출되지 않아 자식 클래스에서 할당한 자원이 해제되지 않는 '메모리 누수(Memory Leak)' 및 **'미정의 동작(Undefined Behavior)'**이 발생합니다.
*/






//10장 켐플릿과 표준 템플릿 라이브러리(STL) pg483
//제너릭 또는 일반화(ctrl+f 처럼 찾아 바꾸기!!! 한다 라고 기억하자)
	// 일반화와 템플릿 483pg~484pg
//template <class T> 하나짜리(class는 typeName으로 바꿔도 된다)
//template <class T1,class T2,class T3 > 여러개 짜리












//예제10-1 제너릭 mySwap 변형 문제 487pg
//template <typename T>
//void mySwap(T& a, T& b) {
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//int main() {
//	int a = 4, b = 5;
//	mySwap(a, b);
//	cout << "a=" << a << ", " << "b=" << b << endl;
//	double c = 0.3, d = 12.5;
//	mySwap(c, d);
//	cout << "c=" << c << ", " << "d=" << d<< endl;
//}











//예제10-2 큰 값을  리턴하는 제너릭 bigger()함수 만들기 연습
//template <typename T>
//T bigger(T a, T b) {
//	if (a < b) {
//		return b;
//	}
//	return a;
//}
//int main() {
//	int a = 4, b = 5;
//	char c = 'a', d = 'b';
//	cout << "bigger(a, b)의 결과는 " << bigger(a, b) << endl;
//	cout << "bigger(c, d)의 결과는 " << bigger(c, d) << endl;
//}





//예제10-3 배열의 합을 구하여 리턴하는 제네릭 add()함수 만들기 연습
//template <class T >
//T add(T data[], int n) {
//	T sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += data[i];
//	}
//	return sum;
//}
//int main() {
//	int x[] = { 1,2,3,4,5 };
//	double d[] = { 1.2,2.3,3.4,4.5,5.6,6.7 };
//	cout << add(x, 5) << endl;
//	cout << add(d, 6) << endl;
//}




//연습문제: 배열의 평균을 실수값을 리턴하는 함수
//template <class T >
//double average(T data[], int n) {
//	T sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += data[i];
//	}
//	return (double)sum/n;
//}
//int main() {
//	int x[] = { 1,2,3,4,6 };
//	double y[] = { 1.2,2.3,3.4,4.5,5.6,6.7 };
//	cout << average(x, 5) << endl;
//	cout << average(y, 6) << endl;
//}
// 근데 왜 return을 정수로 해도 반환이 되지? 심지어 3.0이 아니라 3으로??



//10.3 제너릭 클래스 만들기 pg493

// 제너릭 클래스에서 제너릭은 클래스를 찍어내는 틀이다!! (클래스 아님 주의!!)

//예제 10-5 제너릭 클래스 만들기 496~497pg
//template <class T>
//class MyStack {
//	int tos;
//	T data[100];
//public:
//	MyStack() {
//		tos = -1;
//	}
//	void push(T element) {
//		if (tos == 99) {
//			return;
//		}
//		data[++tos] = element;
//	}
//	T pop() {
//		if (tos == 1) {
//			return 0;
//		}
//		return data[tos--];
//	}
//
//};
//
//int main() {
//	MyStack<int> iStack;
//	iStack.push(3);
//	iStack.push(2);
//	iStack.push(5);
//	iStack.push(7);
//	cout << iStack.pop() << endl;
//	MyStack<double> dStack;
//	dStack.push(3.5);
//	dStack.push(3.2);
//	dStack.push(3.1);
//	dStack.push(2.0);
//	cout << dStack.pop() << endl;
//
//}


/*

STL 컨테이너란?

C++에서 범용적인 자료 구조(컨테이너), 알고리즘, 그리고 이를 연결하는 반복자(이터레이터) 등을 템플릿 형태로 제공하는 표준 라이브러리입니다.
*/

// 예제 10-6 문자열을 저장하는 벡터 만들기 연습
//#include <vector>
//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	v[0]=10;
//	int m = v[2];
//	v.at(2) = 5;// at과 []는 참조를 리턴
//	for (int i = 0; i < v.size(); i++) {
//		cout << v.at(i)<< " " ;
//	}
//	cout << endl;
//}
// 예제10-7은 대충보고 넘어감
// 



// 506pg iterator 사용 ****
//iterator는 컨테이너의 원소를 순차적으로 가르키는 포인터이다.
	// 포인터 처럼 타입을 가져야한다.
// 이하 508pg 참고
	// v.end는 마지막 원소 바로 뒤를 가르킨다.
	//iterator는 원소 읽기, 쓰기, 삭제, 끝으로 옮기기 기능을 가진다
		// 이때 삭제를 위해선 iterator가 해당 원소를 가르켜야한다.


//509~506pg
//예제 10-8 수정
#include <vector>
//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	vector<int>::iterator it;
// // 배열 사용
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
// //함수 사용
//	v.at(2) = 5;// at과 []는 참조를 리턴
//	for (int i = 0; i < v.size(); i++) {
//		cout << v.at(i) << " ";
//	}
//	cout << endl;
//
// // iterator 사용
//	for (it = v.begin(); it != v.end(); it++)
//		cout << *it << ' ';
//	cout << endl;
//}


// 교수님 예제
//void print_vector(const vector<int>& v)
//{
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	vector<int>::iterator it;
//
//	for (int i = 1; i <= 20; i++)
//		v.push_back(i / 2);
//
//	print_vector(v);
//
//	cout << "삭제하려는 값: "; // 특정 값을 삭제
//	int n;
//	cin >> n;
//
//	it = v.begin();
//	while (it != v.end()) {
//		if (*it == n)
//			it = v.erase(it);
//		else
//			it++;
//	}
//
//	print_vector(v);
//
//	cout << "삽입 위치 (예: 0번째 원소 앞, " << v.size() << " 제일 뒤) : ";
//	int i;
//	cin >> i;
//
//	cout << "삽입하려는 값 : ";
//	cin >> n;
//
//	v.insert(v.begin() + i, n);
//
//	print_vector(v);
//
//
//
//	cout << "삭제 위치 (예: 0 번째 원소, " << v.size() - 1 << " 마지막 원소) : "; // 지정 위치 삭제
//	cin >> i;
//	v.erase(v.begin() + i);
//
//	print_vector(v);
//
//	cout << "삭제 범위 시작 (예: 0 번째 원소, " << v.size() - 1 << " 마지막 원소) : "; // 범위 삭제
//	cin >> i;
//
//	cout << "삭제 범위 끝 (예: " << i + 1 << " 시작 원소만 삭제, " << v.size() << " 마지막 원소까지) : ";
//	int j;
//	cin >> j;
//
//	v.erase(v.begin() + i, v.begin() + j);
//
//	print_vector(v);
//
//
//	return 0;
//}



// 예제 10-9 map영한사전511pg~512pg
// 시험에서도 그냥 insert(pair<>&element) 처럼 쓰기보다는 그냥 dic["cherry"]="체리"; 으로 쓰자!!

#include <map>
//int main() {
//	map <string, string> dic;
//	dic["love"] = "사랑";
//	dic["apple"] = "사과";
//	dic["cherry"] = "체리";
//	cout << "저장 단어 개수 " << dic.size() << endl;
//	string eng;
//	while (true) {
//		cout << "찾고 싶은 단어>> ";
//		cin >> eng;
//		if (eng == "exit") {
//			break;
//		}
//		if (dic.find(eng) == dic.end()) {
//			cout << "없음" << endl;
//		}
//		else
//			cout << dic[eng] << endl;
//	}
//}


// 위 예제 추가변형문제+모든 요소출력연습
int main() {
	map <string, int> dic;
	dic["이영주"] = 10;
	dic["노구한"] = 10;
	dic["노현수"] = 20;
	dic["노윤수"] = 30;
	cout << "저장된 인적 정보 개수" << dic.size() << endl;
	string eng;
	while (true) {
		cout << "성적을 찾고 싶은 인물의 이름>> ";
		cin >> eng;
		if (eng == "exit") {
			break;
		}
		if (dic.find(eng) == dic.end()) {
			cout << "없음" << endl;
		}
		else
			cout << dic[eng] << endl;
		map<string, int>::iterator it;
		for (it = dic.begin(); it != dic.end();it++) {
			cout << (*it).first << ": " << (*it).second << endl;
		}

	}
}


//다음시간 예고 : 시험 나올 것 多(예외처리 등)