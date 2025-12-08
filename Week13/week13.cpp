// 시험 포인트 
// 백터나 배열이나 전체를 흝는거는 이터레이터를 사용한다. 
// 이터레이터는 포인터임으로 it->꼴로 사용 가능
// 또한 이터레이터는 흝으면서 값을 변경하지 않기에 const_iterator로 사용 가능하다.
#include <map>
#include <iostream>
#include <string>
using namespace std;

// map 예제	
//class MyID {
//	char code;
//	int number;
//public:
//	MyID(char code, int number) {
//		this->code = code;
//		this->number = number;
//	}
//	friend ostream& operator<<(ostream& op1, const MyID& op2);
//	bool operator<(const MyID& op2)const { // 여기서 뒤에 const는 반드시 있어야 한다.!!!!!!?? Why???? 첫번째 const와 &는 없어도 됨! -->why??
//		if (code < op2.code)
//			return true;
//		else if (code == op2.code) {
//			return number < op2.number;
//		}
//		else
//			return false;
//	}
//};
//ostream& operator<<(ostream& op1, const MyID& op2) {
//	op1 << op2.code << op2.number;
//	return op1;
//}
//int main() {
//	map<MyID, string> students;
//	map<MyID, string> ::iterator it; // 이 부분은 반복문의 int 처럼 사용 가능하다.
//	MyID a('s', 123), b('p', 456);
//	students[a] = "노현수";
//	students[b] = "노윤수";
//	students[b] = "111111111111111111111111111111111111";
//	for (it = students.begin(); it != students.end(); it++) {
//		cout << it->first << ": " << it->second << endl;
//	}
//
//}

// 맵에서 key와 value에는 클래스가 들어간느 경우가 있는데, key에 들어갈 때는 비교가 가능해야 한다.

// 	bool operator<(const MyID& op2)const {
//에서 중괄호 뒤에 const는 해당 객체 내부의 값을 변경함을 금지를 보장하는 역할을 한다.------------------------------> 시험 범위!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//1. 각 const의 의미를 알아한다
//2. const 가 들어가도 되는 경우와 아닌 경우를 구분해라! 예시 setter getter 함수의 경우, getter는 가능하나, setter는 const를 사용하면 안됨.

// 곧바로 예외처리로 이동!!


//예외처리에서의 throw , 640pg
// 다수의 함수가 순차적으로 연달아 실행 중 예외가 생겨 throw 를 하면 
// 역순으로 반환값을 순차적으로 받지 않고 곧바로 던진다(throw) 직빵.

//try-throw-catch

//int main() {
//	int n, sum, average;
//	while (true) {
//		cout << " 합 , 인원 수 입력>>";
//		cin >> sum >> n;
//		try {
//			if (n <= 0) {
//				throw n;
//			}
//			else {
//				average = sum / n;
//			}
//		}
//		catch (int x) {
//			cout << "예외 : " << x << "으로 나눌 수 없음" << endl;
//			average = 0;
//			continue;
//		}
//		cout << "평균 = " << average << endl << endl;
//	}
//}

//
//int stringToInt(const char x[]) {
//	int sum = 0, i = 0;
//	while (x[i]) {
//		if (x[i] >= '0' && x[i] == '9') {
//			sum = sum * 10 + x[i] - '0';
//		}
//		else {
//			throw x;
//		}
//		i++;
//	}
//	return sum;
//}
//int main() {
//	try {
//		int n = stringToInt("123");
//		cout << " \"123\" 정수" << n << endl;
//		n = stringToInt("1A3");
//		cout << " \"1A3\" 정수" << n << endl;
//	}
//	catch (const char* s) {
//		cout << s << "정수 변환 불가\n";
//	}
//}

//652pg*** 던지는 놈이 누군지 표시!!
//class MyStack {
//	int data[100];
//	int tos;
//public:
//	MyStack() {
//		tos = -1;
//		void push(int n) throw (char*) {
//			if (tos == 99) throw "stackfull";
//			tos++;
//			data[tos] = n;
//		}
//		int pop() throw(char*) {
//			int rData = data[tos--];
//			return rData;
//		}
//	};
//	int main() {
//		MyStack s;
//		try {
//			s.push(100);
//			s.push(200);
//			cout << s.pop() << endl;
//			cout << s.pop() << endl;
//			cout << s.pop() << endl;
//		}
//		catch (cont char* s) {
//			cout << "예외 발생 : " << s << endl;
//		}
//	}
//653pg↑ 예제 13-7

//자바는 아무거나 던질 수 없다. throwable이라는 거를 상속받은 거만 던질 수 있다.
//C++에서는 아무거나 던질수 있다.

// 예외 클래스 만들기

class MyException {
	int lineNo;
	string func, msg;
public:
	MyException(int n, string f, string m) {
		lineNo = n;
		func = f;
		msg = m;
	}
	void print() {
		cout << func << ":" << lineNo << ", " << msg << endl;
	}
};
class DivideByZeroException : public MyException {
public:
	DivideByZeroException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {}
};
class InvalidInputException : public MyException {
public:
	InvalidInputException(int lineNo, string func, string msg) : MyException(lineNo, func, msg) {}
};
int main() {
	int x, y;
	try {
		cout << "양의 정수 두 개 입력";
		cin >> x >> y;
		if (x < 0 || y < 0) {
			throw InvalidInputException(__LINE__, __FUNCTION__, "라인에서 음수 입력 예외 발생");
		}
		if (y == 0) {
			throw DivideByZeroException(__LINE__, __FUNCTION__, "라인에서 0으로 나눔 예외 발생");
		}
		cout << "나누기 결과 : " << (double)x / (double)y;
	}
	catch (DivideByZeroException& e) {
		e.print();
	}
	catch (InvalidInputException& e) {
		e.print();
	}
}