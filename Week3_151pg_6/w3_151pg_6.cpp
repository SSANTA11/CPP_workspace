// 개정판 3장 실습문제 6번(p.151)

#include <iostream>
using namespace std;

class Memo {
private:
	string date;
	string content;
public:
	Memo(string date, string content);
	void show();
	bool isSameDate(Memo b);
	string getDate();
	string getContent();
};
Memo::Memo(string date, string content) {
	this->date = date;
	this->content = content;
}
void Memo::show() {
	cout <<this-> date << " " << this-> content << endl;
}
bool Memo::isSameDate(Memo b) {
	return this->date == b.date;
}
string Memo::getDate() {
	return this->date;
}
string Memo::getContent() {
	return this->content;
}

int main() {
	Memo a("1:20", "캠프"), b("2:20", "송별회");
	a.show();
	if (a.isSameDate(b)) cout << "같은 날" << endl;
	else cout << "다른 날" << endl;
	cout << b.getDate() << "에 " << b.getContent() << endl;
}