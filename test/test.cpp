#include <iostream>
using namespace std;

/*
 * 상속 : 클래스는 서로간에 부모의 자식관계를 형성할 수 있다.
 * 자식 클래스는 부모클래스의 멤버들을 사용할 수 있다.
 * 부모 클래스에서 public이나 protected로 되어있는 멤버들은 사용 가능하지만 private으로 되어있는 멤버는 자식에서도 사용이 불가능하다.
 *상속의 형태 : pullic, private 상속 

 다형성 : 상속관계에 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.
 가상함수 : 함수 오버라이딩이라고도 부른다. 함수를 재정의하는 기능이다.
 멤버함수 앞에 virtual 키워드를 붙이면 해당 함수는 가상 함수가 된다.
 만약 CParent 클래스에 virtual void output() 함수가 있다면 자식 클래스에서는 이 가상함수를
 재정의 할 수 있다. 재정의는 함수이름과 인자가 완전히 똑같아야 한다.

 가상함수를 가지고 있는 클래스는 내부적으로 가상함수 테이블이라는 것을 생성한다.
 가상함수테이블은 가상함수들의 메모리 주소를 저장하는 테이블이다.

 만약 CParent의 output이 가상함수이고 CChild 클래스에 output을 재정의 한다면
 그런뒤 CChild 객체를 생성하면 가상함수 테이블에는 CChild 클래스의 output 주소에 올라가게 된다.
 그래서 output함수, 즉 가상함수를 호출하게 되면 먼저 가상함수 테이블을 참조해서 메모리 주소를 확인한다.
 가상함수 테이블에 CChild의 output 주소가 들어가 있다면 그 주소의 함수를 호출해주는 개념이다.

 소멸자도 가상함수로 만들 수 있다. 부모의 소멸자는 가상함수로 만들어두자.
*/
class CParent
{
	public:
		CParent()
		{
			cout << "CParent 생성자" << '\n';
		}
		virtual ~CParent()
		{
			cout << "CParent 소멸자" << '\n';
		}
	public:
		int	m_i_a;
	protected:
		int m_i_b;
	private:
		int m_i_c;
	public:
		virtual void output()
		{
			cout << "parent output function" << '\n';
		}
		virtual void output_pure() = 0;
};

class CChild : public CParent
{
	public:
		CChild()
		{
			m_i_b = 200;
		//	m_i_c = 300;
			cout << "CChild 생성자" << '\n';
		}
		virtual ~CChild()
		{
			cout << "CChild 소멸자" << '\n';
		}
	protected:
		int	m_i_d;
	public:
		void child_output()
		{
			cout << "child output function" << '\n';
		}
		virtual void output()
		{
			CParent::output();
			cout << "child output function" << '\n';
		}
		// 순수가상함수 : 가상함수 뒤에 = 0을 붙여주면 해당 가상함수는 순수가상함수가 된다. 순수가상함수는 구현부분이 존재하지 않는다. 순수가상함수를 가지고 있는 클래스를 추상클래스라고 부른다. 추상클래스는 인스턴스(객체) 생성이 불가능하다. 순수가상함수는 자식에서 반드시 재정의 해야 한다. 왜냐하면 순수가상함수 정의 부분이 없기 때문에 반드시 자식에서 재정의해서 사용할 목적으로 만들어주는 함수이기 때문이다.
		virtual void output_pure()
		{
		}
};

class CChild1 : private CParent
{
	public:
		CChild1()
		{
			m_i_a = 100;
			m_i_b = 200;
			cout << "CChild1 생성자" << '\n';
		}
		~CChild1()
		{
			cout << "CChild1 소멸자" << '\n';
		}
	private:
		int m_i_d;
	public:
		virtual void output_pure()
		{
		}
};

class CChildChild : public CChild
{
	public:
		CChildChild()
		{
			m_i_d = 500;
			cout << "CChildChild 생성자" << '\n';
		}
		~CChildChild()
		{
			cout << "CChildChild 소멸자" << '\n';
		}
	private:
		int m_i_e;
};

int main(void)
{
	//CParent		parent;
	//CChild		child;
	//CChild1		child1;
	//CChildChild	childchild;

	//parent.m_i_a = 100;
	//child.m_i_a = 200;
	//child1.m_i_a = 300;
	/*
	 * CChild 클래스는 CParent 클래스를 상속받고 있다. new CChild를 하게 되면 CChild 객체 하나를 생성해주고 그 메모리 주소를 반환한다. 그런데 아래에서는 CParent *타입 변수에 이 반환된 주소를 대입하고 있다. 부모 포인터 타입에 CChild 객체의 메모리 주소를 넣을 수 있는 이유는 상속 관계에 있기 때문이다. 자식 메모리 주소가 부모 포인터 타입으로 형변환 된 것이기 때문이다. 이런 형변환을 업캐스팅이라고 한다.
	 * 부모 -> 자식 타입 형변환 : 다운 캐스팅
	 */
	CParent *p_parent = new CChild;
	CChild1 child1;
	// CParent 클래스는 추상클래스이기 때문에 객체 생성이 불가능하다.
//	CParent parent;
//	CParent *p_parent1 = new CChild1;
//	CParent *p_parent2 = new CChildChild;

//	CParent *p_parent_arr[2] = {};
//	p_parent_arr[0] = new CChild;
//	p_parent_arr[1] = new CChildChild;

	/*
	 * 아래 두 클래스는 모드 CParent를 상속받고 있다.
	 * 그러므로 p_parent를 두 타입 모두 다운캐스팅 가능하다.
	 * 그런데 p_parent는 CChild로 할당한 객체이다.
	 * 이 객체를 CChild1 타입으로 다운캐스팅 하여 넣어주게 되면 문제가 발생할 수 있다.
	 */ 

	// 현재 delete를 하게 되면 CChild 소멸자 -> CParent 소멸자가 호출되어야 하는데 지금은 CParent 소멸자만 호출된다.
	// 왜냐하면 근본적으로 p_parent는 CParent 포인터 타입이다. CParent 포인터 타입이기 때문에 CChild 소멸자가 호출될 수 없다.
	CChild 	*p_child = (CChild *)p_parent;
	CChild1	*p_child1 = (CChild1 *)p_parent;

	//p_parent->CParent::output();
	p_parent->output();
	// CChild 클래스에 있는 child_output 함수에 접근할 수 없다. 왜냐하면 p_parent는 CParent 포인터 타입이기 때문에 자식 멤버에 접근이 불가능하다. 만약 접근하고 싶다면 형변환을 해야 한다.
	// ((CChild *)p_parent->child_output();
	delete p_parent;
//	delete p_parent2;
	for (int idx = 0; idx < 2; ++idx)
//		delete p_parent_arr[idx];
	return (0);
}
