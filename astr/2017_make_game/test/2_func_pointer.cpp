#include <iostream>
#include <functional>
using namespace std;

/*
   함수포인터 : 함수의 메모리 주소를 저장하기 위한 포인터 변수를 선언할 수 있다.
   전역함수의 경우 함수명이 곧 함수의 메모리 주소이다.
   함수포인터 선언방법 : 반환타입 (*포인터변수명)(인자타입); 의 형태로 구성이 된다.
*/
int sum(int a, int b)
{
	return (a + b);
}

int out_sum(int a, int b)
{
	cout << a - b << '\n';
	return (a - b);
}

void out_put()
{
	cout << "output function" << '\n';
}

float test_func(float a)
{
	cout << a << '\n';
	return a;
}

class CHanzo
{
	public:
		CHanzo()
		{
			m_i_test = 10;
		}

		~CHanzo()
		{
		}
	public:
		int	m_i_test;
	public:
		void output()
		{
			cout << "Hanzo" << '\n';
			// this-> 는 생략할 수 있다.
			cout << "Test : " << this->m_i_test << '\n';
		}
};

typedef struct _tag_point
{
	int x;
	int y;

	_tag_point() :
		x(0),
		y(0)
	{
	}

	_tag_point(int _x, int _y) :
		x(_x),
		y(_y)
	{
	}
	_tag_point(const _tag_point& pt)
	{
		// 얕은 복사를 한다. 이렇게 해줄 경우 this는 자기 자신의 포인터이고 *을 붙여서 자기 자신을 역참조하여 모든 데이터를 복사하게 한다.
		*this = pt;
	}

	_tag_point operator +(const _tag_point& pt)
	{
		_tag_point result;
		result.x = x + pt.x;
		result.y = y + pt.y;
		return result;
	}

	_tag_point operator +(int a)
	{
		_tag_point pt;
		pt.x = x + a;
		pt.y = y + a;
		return pt;
	}

	void operator +=(int a)
	{
		x += a;
		y += a;
	}
	
	void operator ++()
	{
		x++;
		y++;
	}

	void operator << (const _tag_point& pt)
	{
		x = pt.x;
		y = pt.y;
	}
}POINT, *PPOINT;

int main(void)
{
	int (*p_func)(int, int) = sum;

	cout << p_func(10, 20) << '\n';
	p_func = out_sum;
	p_func(10, 20);
	void (*p_func1)() = out_put;
	p_func1();

	CHanzo hanzo1, hanzo2;

	hanzo1.m_i_test = 100;
	hanzo2.m_i_test = 200;

	// this 포인터 : 클래스 안에서 this를 사용할 경우 해당 객체의 메모리 주소가 된다. 즉 자기자신의 포인터이다. 멤버 함수를 호출할 때 this를 호출자로 셋팅한다.
	hanzo1.output();
	hanzo2.output();
	// 멤버함수포인터 선언시 포인터변수 이름 앞에 클래스명 ::을 붙여준다.
	// :: 범위지정연산자
	void (CHanzo::*p_func2)() = &CHanzo::output;
//	(*p_func2)();
//	hanzo1.(*p_func2)();
	(hanzo1.*p_func2)();

	/*
	   function 기능은 c++11 부터 지원해주는 기능이다. 이 기능은 함수포인터를 전역, 멤버 가리지 않고 쉽게 주소를 저장해서 호출해줄 수 있도록 만들어주는 기능이다.
	   선언방법 : function<반환타입(인자타입)> 변수명; 의 형태로 선언한다.
	*/
	function<void()>	func;
	function<void()>	func1;

	// bind를 이용해서 함수를 묶어준다.
	func = bind(out_put);
	func1 = bind(&CHanzo::output, &hanzo1);

	func();
	func1();

	function<int(int, int)> func3;
	function<float(float)> func4;
	//함수에 인자가 있을 경우 placeholders 를 이용해서 인자의 순서를 정의할 수 있다. 2, 1로 넣어줄 경우 서로 바뀌게된다.
	func3 = bind(out_sum, placeholders::_1, placeholders::_2);
	func3(10, 20);
	func4 = bind(test_func, placeholders::_1);
	func4(3.14f);

	cout << "=================== Point ================" << '\n';
	POINT pt1(10, 20), pt2(30, 40), pt3;

	// POINT 구조체는 +연산자가 operator로 재정의 되어 있다. 그래서 + 연산이 가능하게 되고 pt1의 + 연산자 함수를 호출해주는 개념이다.
	pt3 = pt1 + pt2;
	pt3 << pt1;
	pt3 << pt2;
	pt3 = pt1 + 1000;
	++pt3;
	pt3 += 2000;
	cout << "x : " << pt3.x << "\ty : " << pt3.y << '\n';
	return (0);
}
