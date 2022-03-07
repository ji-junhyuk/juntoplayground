#include <iostream>
using namespace std;

/*
   객체(object) : 모든 사물 (C++에서 객체를 의미하는 것은 각 변수들도 객체로 취급할 수 있다. 하지만 객체지향 프로그래밍을 지원하기 위해 제공 되는 수단은 class이다. class는 객체가 아니다. class는 객체를 만들기 위한 틀이다.
 
   객체지향 프로그래밍(OOP) : 객체들의 관계를 설정해주어서 부품을 조립하듯이 객체들을 조립하여 완성된 프로그램을 만들어나가는 방식이다.

   클래스 선언방법 : class 클래스명 {}; 의 형태로 선언한다.
   코드블럭안에 멤버변수를 넣어줄 수 있다. 단, 함수도 멤버로 만들 수 있다.

   클래스의 4가지 속성
   1. 캡슐화 : 클래스 안에 속하는 여러 변수 혹은 함수를 하나의 클래스로 묶어주는 기능
   2. 은닉화 : 클래스 안에 속하는 변수 혹은 함수를 내가 원하는 부분만 외부에 공개하고 외부에 공개하지 않을 수 있다.
public : 클래스 내부와 외부에서 모두 접근 가능
protected : 클래스 외부에서는 접근이 불가능하고 자기자신 내부나 자식 클래스 내부에서는 접근이 가능한 키워드이다.
privated : 자기자신 내부에서만 접근이 가능하고 외부나 자식 내부에서는 접근이 불가능한 방법이다.
   3. 상속성 : 클래스는 클래스와 클래스간에 부모, 자식 관계를 형성할 수 있다. 자식 클래스는 부모 클래스의 멤버를 물려받아 자신의 것처럼 사용할 수 있다. 단, private으로 되어 있는 멤버에는 접근이 불가능하다.
   4. 다형성 : 부모 자식관계로 상속관계가 형성되어 있는 클래스간에 서로 형변환이 가능한 성질을 말한다. 

   생성자와 소멸자
   생성자 : 어떤 클래스를 이용해서 객체를 생성할 때 자동으로 호출되는 함수이다. 객체 생성시 호출되는 함수이기 때문에 객체의 멤버변수를 초기화할때 유용하게 사용할 수 있다.

   생성자를 만들어주지 않을 경우 내부적으로 기본 생성자가 제공이 되어서 자동으로 기본 생성자를 호출해주게 된다.

   클래스명()
   {
   }
   의 형태로 선언된다.

   소멸자 : 어떤 클래스를 이용해서 생성한 객체가 메모리에서 해제될 때 자동으로 호출되는 함수이다. 객체를 사용하고 난 뒤 마무리 작업을 해줄 때 유용하게 사용할 수 있다.

   ~클래스명()
   {
   }
*/
class CTracer
{
	public:
	// 생성자
	CTracer()
	{
		cout << "Tracer 생성자" << '\n';
		strcpy_s(m_str_name, "트레이서");
	}
	CTracer(char *p_name)
	{
		strcpy_s(m_str_name, p_name);
		cout << "Name 생성자" << '\n';
	}
	// 소멸자
	~CTracer()
	{
		cout << "Tracer 소멸자" << '\n';
	}
	CTracer(char *p_name, int i_flash, int i_back) :
		m_i_back(i_back),
		m_i_flash(i_flash)
	{
		strcpy_s(m_str_name, p_name);
		cout << "Name, Flash, Back 생성자" << '\n';
		//m_i_flash = i_flash;
		// int a;
		// a = 10
		// int b = 10;
	}
	

	//클래스 멤버변수를 선언할때는 m_를 붙여준다.
	char	m_str_name[32];

	public:
	int m_i_attack;
	int m_i_hp;

	private:
	int m_i_flash;

	private:
	int m_i_back;

	public:
	void output()
	{
		cout << "Tracer Output" << '\n';
		cout << "Name : " << m_str_name << '\n';
	}
};

int main()
{
	// main함수 안은 클래스 외부이기 때문에 public으로 설정되어 있는 멤버에만 접근이 가능하다.
	CTracer tr1("junto", 3, 1);

	tr1.output();

	return (0);
}
