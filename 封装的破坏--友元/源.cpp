//实验七第一题
#include<iostream>
#include<cmath>
using namespace std;
class Point
{
public:
	Point(float = 0, float = 0);
	void set();
	void show();
	friend void dis(Point, Point);
private:
	float x, y;
};

Point::Point(float x, float y)
{
	this->x = x; this->y = y;
}

void Point::set()
{
	cout << "Please enter the coordinate of a point:";
	cin >> x >> y;
}
void Point::show() { cout << "(x,y)=" << "(" << x << "," << y << ")" << endl; }
void dis(Point p1, Point p2)
{
	float d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	cout << "The distance id:" << d << endl;
}

int main()
{
	Point p1(1, 2), p2(3, 4);
	p1.show();
	p2.show();
	dis(p1, p2);
	return 0;
}

//实验七第二题
#include<iostream>
using namespace std;
class Score
{
public:
	Score(int x)
	{
		score = x;
		sum += x;
	}
	int getScore() { return score; }
	static int getSum() { return sum; }
private:
	int score;
	static int sum;
};
int Score::sum = 0;

int main()
{
	Score* p = NULL;
	int s, count = 1;
	cout << "输入一个班的学生成绩直到输入-1为止！" << endl;
	while (1)
	{
		cout << "请输入第" << count << "个学生的分数" << ":";
		cin >> s;
		if (s == -1) { delete p; break; }
		p = new Score(s);
		count++;
	}
	count--;
	cout << "总分" << Score::getSum() << endl;
	cout << "平均分" << Score::getSum() / count << endl;

	return 0;
}

#include<iostream>
using namespace std;
class Date
{
public:
	Date() {
		month = 1;
		day = 1;
		year = 2020;
		cout << "无参构造函数运行成功" << endl;
	}
	Date(int M, int D, int Y) {
		month = M;
		day = D;
		year = Y;
		cout << "有参构造函数运行成功" << endl;
	}
	void setDate(int M, int D, int Y) {
		month = M;
		day = D;
		year = Y;
	}
	friend void Print(Date&);
private:
	int month;
	int day;
	int year;
};
void Print(Date& dd) {
	cout << "日期：" << dd.year << "年" << dd.month << "月" << dd.day << "日" << endl;
}
int main()
{
	Date d1, d2(4, 14, 2022);
	Print(d1); Print(d2);
	return 0;

#include<iostream>
using namespace std;
class Book
{
public:
	Book(string N, int P) {
		name = N;
		price = P;
		num++;
		totalPrice += P;
		cout << "构造函数运行成功" << endl;
	}
	Book(int P) {
		price = P;
		num++;
		totalPrice += P;
		cout << "构造函数运行成功" << endl;
	}
	static int num;
	static int totalPrice;
	void showInfo() {
		//给动态创建的对象写一个show函数
 	}
private:
	string name;
	int price;
};
int Book::num = 0;
int Book::totalPrice = 0;
int main()
{
	Book* p = nullptr;
	int price, count = 1;
	string name;
	cout << "输入一批书的书名和价格直到输入-1为止" << endl;
	while (1) {
		cout << "请输入第" << count << "本书的书名和价格" << "：";
		cin >> name >> price;
		if (name  == "-1" && price == -1) {
			delete p;
			break;
		}
		p = new Book(name, price);
		cout << p << endl;
		count++;
	}
	count--;
	cout << "图书总册数：" << Book::num << endl;
	cout << "图书总价：" << Book::totalPrice << endl;
	return 0;
}
