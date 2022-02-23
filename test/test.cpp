#include <iostream>
using namespace std;

/*
 * 상속 : 클래스는 서로간에 부모의 자식관계를 형성할 수 있다.
 * 자식 클래스는 부모클래스의 멤버들을 사용할 수 있다.
 * 부모 클래스에서 public이나 protected로 되어있는 멤버들은 사용 가능하지만 private으로 되어있는 멤버는 자식에서도 사용이 불가능하다.
 *상속의 형태 : pullic, private 상속 

 다형성 : 상속관계에 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.
*/
class CParent
{
	public:
		CParent()
		{
			cout << "CParent 소멸자" << '\n';
		}
		~CParent()
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
		void output()
		{
			cout << "A : " << m_i_a << '\n';
			cout << "B : " << m_i_b << '\n';
			cout << "C : " << m_i_c << '\n';
		}
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
		~CChild()
		{
			cout << "CChild 소멸자" << '\n';
		}
	protected:
		int	m_i_d;
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

	/*
	 * 아래 두 클래스는 모드 CParent를 상속받고 있다.
	 * 그러므로 p_parent를 두 타입 모두 다운캐스팅 가능하다.
	 * 그런데 p_parent는 CChild로 할당한 객체이다.
	 * 이 객체를 CChild1 타입으로 다운캐스팅 하여 넣어주게 되면 문제가 발생할 수 있다.
	 */ 
	CChild 	*p_child = (CChild *)p_parent;
	CChild1	*p_child1 = (CChild1 *)p_parent;
	delete p_child;
	return (0);
}
