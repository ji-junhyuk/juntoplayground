### 5.1 연산자 함수
- 절대로 논리 연산자들을 다중 정의해서는 안된다.
### 5.2 산술 연산자
- operator int () // 형변환 연산자
- CMyData operator+(const CMyData &rhs) // 덧셈연산자, CMyData형식을 반환하므로 이동 생성자가 호출된다!
- CMyData &operator=(const CMyData &rhs) // 단순대입연산자
- 연산자 함수도 다중 정의할 수 있다.
- cout 객체는 ostream 클래스의 인스턴스이다. 전역 변수 형태로 존재하고 네임 스페이스 std 소속이다. 이 ostream 클래스는 c++의 다양한 기본 자료형에 <<, >> 라는 연산자 함수를 제공한다.
```c++
a = b + c;
// b + c 는 이름 없는 임시 객체를 만들어내는데, 이 과정에서 이동 생성자가 호출된다. 결국 a에 단순 대입되는 것은 임시 객체이며, 이 임시객체는 대입 연산 직후 소멸한다.
// 함수의 매개변수가 클래스인 경우에는 무조건 참조로 받는 것이 맞다. 반환 형식은 대입 연산자 같은 몇몇을 제외하고는 임시 객체를 의도적으로 이용할 수 밖에 없다. 간단한 기본 형식이라면 연산의 중간 결과값을 CPU의 레지스터에 담겠지만 클래스 인스턴스는 그럴수가 없다.
```
### 5.3 대입 연산자
```c++
CMyData &operator=(const CMyData &rhs)
{
	if (this == &rhs)
		return *this; // rvalue가 자기 자신일 경우에 원본이 삭제될 것을 방지!
	delete m_p_i_data;  // 본래 가리키던 메모리를 삭제하고
	m_p_i_data = new int(*rhs.m_p_i_data); // 새로 할당된 메모리에 값을 저장한다.
	return *this; 
}
```
#### 복합 대입 연산자
```c++
CMyData &operator++(const CMyData &rhs)
{
	int *p_i_new_data = new int(*m_p_i_data); // 현재 값 처리
	*p_i_new_data += *rhs.m_p_i_data; // 누적 값 처리
	delete m_p_i_data;
	m_p_i_data = p_i_new_data;
	return *this;
}
```
#### 이동 대입 연산자
- 임시 객체로 인해 이동 생성자가 생겨났듯이 임시 객체 로 인해 이동대입연산자도 생겨났다.
- a = b + c; CMyData클래스 인스턴스인 b와 c를 더하면 당연히 CMyData::operator+() 함수가 호출되고, 부산물로 임시객체가 탄생한다. 이 임시객체를 l-value삼아 곧바로 단순 대입 연산을 실행한다면 이때는 이동 대입 연산자가 호출된다.
```c++
...
CMyData operator+(const CMyData &rhs)
{
	return CMyData(*m_piData + *rhs.m_piData);
}

CMyData operator=(const CMyData &rhs)
{
	cout << "operator=" << '\n';
	if (this == &rhs)
		return *this;
	delete m_piData;
	m_piData = new int (*rhs.m_piData);
	return *this;
}

CMyData opertor=(const CMyData &&rhs)
{
	cout << "operator=(Move)" << '\n';
	m_piData = rhs.m_piData;
	rhs.m_piData = NULL;
	return *this;
}
int main()
{
	a = b + c; // 이동 대입 연산자가 실행된다!
	a = b // operator = 가 실행된다!
}
```
### 5.4 배열 연산자
- int& operator[] (int i_index); // int& 으로 반환하는데 이는 l-value로 사용되는 경우를 고려한 것
- int operator[] (int i_index) const; // 상수형 참조를 통해서만 호출할 수 있고 오로지 r-value로만 사용된다
```c++
class CIntArray
{
public:
	CIntArray(int iSize)
	{
		m_piData = new int[iSize];
		memset(m_piData, 0, sizeof(int) * iSize);
	}
	~CIntArray() { delete m_piData };
	int operator[](int iIndex)const // 상수형 참조인 경우의 배열 연산자
	{
		cout << "operator[] const" << '\n';
		return m_piData[iIndex];
	}
	int& operator[](int iIndex) // 일반적인 배열 연산자
	{
		cout << "operator[]" << '\n';
		return m_piData[iIndex];
	}
}
void TestFunc(const CIntArray &arParam)
{
	cout << "TestFunc()" << '\n';
	cout << arParam[3] << '\n'; // 상수형 참조이므로 opertaor[](int iIndex) const를 호출한다.
}
int main()
{
	CIntArray arr(5);
	for (int idx = 0; idx < 5; ++idx)
		arr[idx] = idx * 10; // 여기선 int& operator[] (int iIndex) 연산자를 활용한다.반환 형식이 참조자이므로 l-value가 될 수 있다.
	TestFunc(arr);
	return (0);
}
```
### 5.5 관계 연산자
- int 클래스이름::operator==(const 클래스이름 &);
- int 클래스이름::operator!=(const 클래스이름 &);

### 5.6 단항 증감 연산자
- int operator++() // 전위식
- int operator++(int) // 후위식
