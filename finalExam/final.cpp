
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

//class Random {
//	static bool initialized;
//	Random() {};
//public:
//	static int nextInt(int min = 0, int max = RAND_MAX) {
//		if (!initialized) {
//			srand(time(0));
//			initialized = true;
//		}
//		return rand() % (max - min + 1) + min;
//	}
//};
//bool Random::initialized = false;
//int main() {
//	for (int i = 0;i < 10;i++) {
//		cout << Random::nextInt(20000) << endl;
//	}
//}
// static과 랜덤의 관계에서 랜덤을 private으로 선언한 이유와 static bool initialized을 static으로 선언한 이유
	// 객체를 생성할 필요가 없음을 명시적으로 들어내고 강제하기 위해 private으로 선언함
	// 현재 initialized변수를 이용하는게 static이므로 정적메서드는 정적 자원만 컨트롤 가능하기에 변수도 정적으로 설정했으며, 플래그의 역할을 하는 initialized의 단일성을 보장함

//========================================================================================================================================================================================================
//class Rect {
//	int w, h;
//public:
//	Rect(int w, int h) {
//		this->w = w;
//		this->h = h;
//	}
//	friend bool equals(Rect r, Rect s);
//};
//bool equals(Rect r, Rect s) {
//	if (r.w == s.w&& r.h == s.h) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//int main() {
//	Rect a(3, 4), b(1, 3);
//	if (equals(a, b)) {
//		cout << "=";
//	}
//	else {
//		cout << "!=";
//	}
//	
//}
//class Rect;
//
//class RectManager {
//public:
//	static bool equals(Rect a, Rect b);
//	static bool copy(Rect& dst, const Rect& src);
//};
//
//class Rect {
//	int w, h;
//public:
//	Rect(int w, int h) {
//		this->w = w;
//		this->h = h;
//	}
//	friend RectManager;
//};
//bool RectManager::equals(Rect r, Rect s) {
//	if (r.w == s.w&& r.h == s.h) {
//		return true;
//	}
//	else {
//		return false;
//	}
//};
//bool RectManager::copy(Rect& dst, const Rect& src) {
//	dst.w = src.w;
//	dst.h = src.h;
//	return true;
//}
//int main() {
//	Rect a(3, 4), b(1, 3);
//	RectManager::copy(a, b);
//	if (RectManager::equals(a, b)) {
//		cout << "=";
//	}
//	else {
//		cout << "!=";
//	}
//	
//}
// 프렌드 함수: 특정 클래스의 private, protected 맴버에 접근할 수 있는 특권을 부여받은 함수
// 프렌드 클래스*: 특정 클래스의 private, protected 맴버에 접근할 수 있는 특권을 부여받은 클래스
//========================================================================================================================================================================================================
//========================================================================================================================================================================================================


//class Power {
//	int k;
//	int p;
//public:
//	Power(int k = 0, int p = 0) {
//		this->k = k;
//		this->p = p;
//	}
//	void show() {
//		cout << "k=" << k << "    p=" << p << endl;
//	}
//	Power operator+(const Power& p2) {
//		Power tmp;
//		tmp.k = this->k + p2.k;
//		tmp.p = this->p + p2.p;
//		return tmp;
//	}
//	bool operator==(const Power& p2) {
//		if (this->k == p2.k && this->p == p2.p) {
//			return true;
//		}
//		return false;
//	}
//	Power& operator+=(const Power& p2) {
//		this->k += p2.k;
//		this->p += p2.p;
//		return *this;
//	}
//
//	Power operator + (const int& n) {
//		Power tmp;
//		tmp.k = this->k + n;
//		tmp.p = this->p + n;
//		return tmp;
//	}
//
//	bool operator < (const Power& op2) {
//		int thisPower = this->k * this->k + this->p * this->p;
//		int op2Power = op2.k * op2.k + op2.p * op2.p;
//
//		if (thisPower < op2Power)
//			return true;
//		return false;
//	}
//	bool operator > (const Power& op2) {
//		int thisPower = this->k * this->k + this->p * this->p;
//		int op2Power = op2.k * op2.k + op2.p * op2.p;
//
//		if (thisPower > op2Power)
//			return true;
//		return false;
//	}
//
//	friend Power operator+(const int& n, const Power& p1);
//	friend ostream& operator << (ostream& os, const Power& p);
//};
//ostream& operator << (ostream& os, const Power& p) {
//	os << "k=" << p.k << "        p=" << p.p;
//	return os;
//}
//Power operator +(const int& n, const Power& p1) {
//	Power tmp;
//	tmp.k = n + p1.k;
//	tmp.p = n + p1.p;
//	return tmp;
//}
//int main() {
//	Power a(1, 2), b(2, 3);
//	Power c;
//	c.operator=(a.operator+(b));
//	a.show();
//	b.show();
//	c.show();
//	if (a == b) {
//		cout << "="<<endl;
//	}
//	else {
//		cout << "!="<<endl;
//	}
//	a.operator+=(b);
//	a.show();
//	b = a + 2;
//	b.show();
//	if (b < a) {
//		cout << "a>b\n";
//	}
//	else if (b > a) {
//		cout << "a<b\n";
//	}
//	cout << a << b << endl;
//}


//class Point {
//	int x, y;
//public:
//	Point(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	int getX() {
//		return x;
//	}
//	int getY() {
//		return y;
//	}
//protected:
//	void move(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//};
//class ColorPoint : public Point {
//	string color;
//public:
//	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) {
//		this->color = color;
//	}
//	void setPoint(int x, int y) {
//		move(x, y);
//	}
//	void setColor(string color) {
//		this->color = color;
//	}
//	void show() {
//		cout << color << "색으로 " << getX() << ", " << getY() << endl;
//	}
//};
//int main() {
//	ColorPoint cp(5, 5, "RED");
//	cp.setPoint(30, 40);
//	cp.setColor("BLUE");
//	cp.show();
//}

//class Base {
//public:
//	void f() {
//		cout << "Base::f()\n";
//	}
//};
//class Derived :public Base {
//public:
//	void f() {
//		cout << "Derived::f()\n";
//	}
//};
//int main() {
//	Derived d;
//	Derived* dp = &d;
//	Base* bp = &d;
//	dp->f();
//	bp->f();
//}
//class Base {
//public:
//	virtual void f() {
//		cout << "Base::f()\n";
//	}
//};
//class Derived :public Base {
//public:
//	void f() {
//		cout << "Derived::f()\n";
//	}
//};
//int main() {
//	Derived d;
//	Base b;
//	int n;
//	cin >> n;
//	Base* pBase;
//	if (n == 1) {
//		pBase = &b;
//	}
//	else {
//		pBase = &d;
//	}
//	pBase->f();
//}

//정적 바인딩을 통한 함수 재정의는 다형성과 무관하다.
// ->왜냐하면 다형성은 하나의 인터페이스가 여러 상황에 따라 다양한 형태를 가지는 것을 의미하지만 함수 재정의는 매번 값이 부모의 것으로 고정되기 때문이다.


//class Base {
//public:
//	virtual void f() {
//		cout << "Base::f()\n";
//	}
//};
//class Derived :public Base {
//public:
//	void f() {
//		cout << "Derived::f()\n";
//	}
//};
//class GrandDerived :public Derived{
//public:
//	void f() {
//		cout << "GrandDerived::f()\n";
//	}
//};
//int main() {
//	GrandDerived g;
//	Base* bp;
//	Derived* dp;
//	GrandDerived* gp;
//	bp = dp = gp = &g;
//	bp->f();
//	dp->f();
//	gp->f();
//}

//class Shape {
//public:
//	virtual void draw() {
//		cout << "shape";
//	}
//};
//class Circle : public Shape {
//	void draw() {
//		Shape::draw();
//		cout << "Circle" << endl;
//	}
//};
//int main() {
//	Circle circle;
//	Shape* pShape = &circle;
//	pShape->draw();
//	pShape->Shape::draw();
//}

//class Animal {
//private:
//	int w;
//public:
//	Animal(int w = 0) {
//		this->w = w;
//	}
//	virtual ~Animal() {
//		cout << "Animal::~Animal\n";
//	}
//	int getWeight() {
//		return w;
//	}
//	virtual void sound() = 0;
//};
//class Dog : public Animal {
//	int fangSize;
//public:
//	Dog(int w, int f) :Animal(w) {
//		this->fangSize = f;
//	}
//	virtual ~Dog() {
//		cout << "Dog::~Dog()\n";
//	}
//	int getFangSize() {
//		return fangSize;
//	}
//	virtual void sound() {
//		cout << "woof\n";
//	}
//};
//class Cat :public Animal {
//	double clawSharpness;
//public:
//	Cat(int w, double clawSharpness) :Animal(w) {
//		this->clawSharpness = clawSharpness;
//	}
//	virtual ~Cat() {
//		cout << "Cat::~Cat()\n";
//	}
//	int getClawsharpness() {
//		return clawSharpness;
//	}
//	virtual void sound() {
//		cout << "Meow\n";
//	}
//};
//int main() {
//	Animal* a[3];
//	a[0] = new Dog(10, 15);
//	a[1] = new Cat(23, 1.3);
//	a[2] = new Dog(2, 3424);
//	for (int i = 0; i < 3; i++) {
//		a[i]->sound();
//	}
//	for (int i = 0; i < 3; i++) {
//		delete a[i];
//	}
//}

//template<class T>
//void mySwap(T& a, T& b) {
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//	int a = 4, b = 5;
//	mySwap(a, b);
//	cout << "a=" << a << ", " << "b= " << b << endl;
//	double c = 0.3, d = 12.5;
//	mySwap(c, d);
//	cout << "c=" << c << ", " << "d= " << d << endl;
//}

//template <class T>
//T bigger(const T& a, const T& b) {
//	if (a < b) {
//		return b;
//	}
//	return a;
//}
//int main() {
//	int a = 4, b = 5;
//	char c = 'a', d = 'b';
//	cout << bigger(a, b) << endl;
//	cout << bigger(c, d) << endl;
//}


//template <class T>
//T add(const T data[], const int n) {
//	T sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += data[i];
//	}
//	return sum;
//}
//int main() {
//	int n[] = { 1,2,3,4,5 };
//	double d[] = { 1.1,2.2,3.3,4.4,5.5 };
//	cout << add(n,1)<<endl;
//	cout << add(d,1);
//}

//template <class T>
//double average(T data[], int n) {
//	T sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += data[i];
//	}
//	return (double)sum / n;
//};
//
//int main() {
//	int x[] = { 1,2,3,4,5,6 };
//	double y[] = { 1.1,2.2,3.3,4.4,5.5,6.6 };
//	cout << average(x, 5)<< endl;
//	cout << average(y, 6);
//}

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
//			exit(0);
//		}
//		data[++tos] = element;
//	}
//	T pop() {
//		if (tos < 0) {
//			return 1;
//		}
//		return data[tos--];
//	}
//};
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
//}

//#include<vector>
//
//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	vector<int>::iterator it;
//	// 배열 사용
//	for (int i = 0; i < 3; i++) {
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	// 메서드 사용
//	for (int i = 0; i < 3; i++) {
//		cout << v.at(i) << " ";
//	}
//	cout << endl;
//	// 배열과 메서드는 참조를 리턴하여 원본을 반환하지만 이터레이터는 포인터 자체를 반환함으로 역참조가 필요하다
//
//	// 이터레이터 사용
//	for (it = v.begin(); it != v.end(); it++) {
//		cout << (*it) << " ";
//	}
//	cout << endl;
//}
//#include <vector>
//template <class T>
//void print_vector(const vector<T>& v) {
//	//vector<T>::iterator it;
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << " ";
//	}
//	//for (it = v.begin(); it != v.end(); it++) {
//	//	cout << (*it) << endl;
//	//}
//};
//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(4);
//	v.push_back(1);
//	v.push_back(4);
//	v.push_back(1);
//	v.push_back(4);
//	v.push_back(1);
//	v.push_back(4);
//	v.push_back(1);
//	v.push_back(4);
//	print_vector(v);
//
//	cout << "삭제하려는 값";
//	int a;
//	cin >> a;
//	vector<int>::iterator it=v.begin();
//	while (it != v.end()) {
//		if ((*it) != a) {
//			it++;
//			continue;
//		}
//		it = v.erase(it);
//	}
//	print_vector(v);
//	cout << "삭제 범위 시작";
//	int i;
//	cin >> i;
//	cout << "삭제 범위 끝";
//	int j;
//	cin >> j;
//	v.erase(v.begin() + i, v.begin() + j);
//	print_vector(v);
//}
//#include<map>
//#include<cstring>
//
//int main() {
//	map<string, int> dic;
//	dic["체리"] = 1111111;
//	dic["체리"] = 1111111;
//	dic["체리"] = 1111111;
//	dic["체리"] = 1111111;
//	cout << dic.size();
//	string name;
//	while (true) {
//		cout << "성적을 찾고 싶은 인물 이름>>";
//		cin >> name;
//		if (name == "exit") {
//			break;
//		}
//		if (dic.find(name) == dic.end()) {
//			cout << "없음" << endl;
//		}
//		else
//			cout << dic[name] << endl;
//		map<string, int>::iterator it;
//		for (it = dic.begin(); it != dic.end(); it++) {
//			cout << (*it).first << ": " << (*it).second << endl;
//		}
//	}
//}

#include <map>
#include <iostream>
#include <string>

//class MyID {
//	char code;
//	int number;
//public:
//	MyID(char code, int number) {
//		this->code = code;
//		this->number = number;
//	}
//	friend ostream& operator <<(ostream& op1, const MyID& op2);
//	bool operator < (const MyID& op2) const {
//		if (this->code < op2.code) {
//			return true;
//		}
//		else if (code == op2.code) {
//			return number < op2.number;
//		}
//		else
//			return false;
//	}
//};
//
//ostream& operator<< (ostream& op1, const MyID& op2) {
//	op1 << op2.code << op2.code;
//	return op1;
//}
//int main() {
//	map<MyID, string> dic;
//	map<MyID, string>::iterator it;
//	MyID a('a', 111), b('b', 222);
//	dic[a] = "노현수";
//	dic[b] = "노윤수";
//	dic[b] = "1111111";
//	for (it = dic.begin(); it != dic.end(); it++) {
//		cout << (*it).first << "   " << (*it).second << endl;
//	}
//}

//class MyStack {
//	int tos = -1;
//	int data[100];
//public:
//	void push(int n) throw (const char*) {
//		if (tos == 99) {
//			throw "stackFull";
//		}
//		data[++tos]=n;
//	}
//	int pop() throw (const char*) {
//		if (tos == -1) {
//			throw "stackEmpty";
//		}
//		int rData = data[tos--];
//		return rData;
//	}
//};
//
//int main() {
//	MyStack s;
//	try {
//		s.push(10);
//		s.push(11);
//		s.push(12);
//		s.push(13);
//		s.push(14);
//
//		cout << s.pop() << endl; 
//		cout << s.pop() << endl; 
//		cout << s.pop() << endl; 
//		cout << s.pop() << endl; 
//		cout << s.pop() << endl; 
//		cout << s.pop() << endl; // ★여기서 터짐
//	}
//	catch (const char* s) {
//		cout << "예외: " << s;
//	}
//}

#include <iostream>
#include <fstream>
//int main() {
//
//	const char* srcFile = "c:\\temp\\bullet.jpg";
//	const char* copyFile = "c:\\temp\\bulletCopy.jpg";
//
//	ifstream fin(srcFile, ios::in | ios::binary);
//	if (!fin) {
//		throw "error1";
//		exit(0);
//	}
//	ofstream fout(copyFile, ios::out|ios::binary);
//	if (!fout) {
//		throw "error2";
//		exit(0);
//	}
//	int c;
//	while ((c = fin.get()) != EOF) {
//		fout.put(c);
//	}
//	fin.close();
//	fout.close();
//}


int main() {
	const char* file = "c:\\temp\\data.txt";
	ofstream fout(file, ios::out | ios::binary);
	if (!fout) {
		throw "error";
		exit(0);
	}
	int n[] = { 1,2,3,4,5,6,7,8,9,0 };
	double d = 3.15;
	fout.write((char*)n, sizeof(n));
	fout.write((char*)&d, sizeof(d));
	fout.close();
	for (int i = 0; i < 10; i++) {
		n[i] = 0;
	}
	d = 8.15; //배열 n과 d 값을 변경
	ifstream fin(file, ios::in | ios::binary);
	if (!fin) {
		throw "error";
	}
	fin.read((char*)n, sizeof(n));
	fin.read((char*)&d, sizeof(d));
	for (int i = 0; i < 10; i++) {
		cout << n[i] << ' ';
	}


}