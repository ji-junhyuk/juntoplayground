#include <iostream>
using namespace std;

/*
 * 템플릿 : 컴파일 단계에서 타입을 결정짓는 기능이다.
 * 타입이 다양하게 바뀔 수 있다.
 * template <typename 원하는 이름>의 형태로 사용 가능하다.
 * template <class 원하는 이름> 의 형태로 사용 가능하다.
 *
 * ex) template <typename T>
 * void output()
 * {
 * 		cout << typeid(T).name() << '\n';
 * }
 *
 * 위처럼 함수를 만들고 호출시
 * output<int>();
 * output<float>());
 * 이렇게 해주면 int, float을 타입이 정해진다. 상황에 따라 넣어주는 타입으로 타입이 가변적으로 바뀌는 것이다.
 *
 * 가변타입은 여러개를 지정해 줄 수 있다.
 * template <typename T, typename T1>
 * void output()
 * {
 * }
 * 위처럼 여러개 지정도 가능하다.
 *
 */
template <typename T>
void output_type()
{
	cout << "==== output_type ====" << '\n';
	cout << typeid(T).name() << '\n';
}

template <typename T>
void output_data(T data)
{
	cout << "==== output_data ====" << '\n';
	cout << typeid(T).name() << '\n';
	cout << data << '\n';
}

typedef struct _tag_student
{
}STUDENT, *PSTUDENT;

class CCar
{
	public:
		CCar()
		{
		}
		~CCar()
		{
		}
};

enum TEST
{
};

class CTemplate
{
	public:
		CTemplate()
		{
		}
		~CTemplate()
		{
		}
	public:
		template <class T, class T1>
			void output(T a, T1 b)
			{
				cout << a << '\n';
				cout << b << '\n';
			}
};

template <typename T>

class CTemplate1
{
	public:
		CTemplate1()
		{
			cout << "Template1 class Type : " << typeid(T).name() << '\n';
		}
		~CTemplate1()
		{
		}
	private:
		T	m_data;
	public:
		void output()
		{
			cout << typeid(T).name() << '\n';
			cout << m_data << '\n';
		}
};

int main(void)
{
	output_type<int>();
	output_type<float>();
	output_type<STUDENT>();
	output_type<CCar>();
	output_type<TEST>();

	output_data(10);
	output_data(3.1);
	output_data(323.1123f);
	output_data('a');
	output_data("ㅋ ㅋ ㅋ ㅋ");

	CTemplate tem;

	tem.output(10, 3.14f);

	CTemplate1<int> tem1;
	tem1.output();

	CTemplate1<CTemplate> tem2;
	return (0);
}
