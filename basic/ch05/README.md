### 5.1 연산자 함수
- 절대로 논리 연산자들을 다중 정의해서는 안된다.
]()
### 5.2 산술 연산자
- operator int () // 형변환 연산자
- CMyData operator+(const CMyData &rhs) // 덧셈연산자, CMyData형식을 반환하므로 이동 생성자가 호출된다!
- CMyData &operator=(const CMyData &rhs) // 단순대입연산자
- 연산자 함수도 다중 정의할 수 있다.
- cout 객체는 ostream 클래스의 인스턴스이다. 전역 변수 형태로 존재하고 네임 스페이스 std 소속이다. 이 ostream 클래스는 c++의 다양한 기본 자료형에 <<, >> 라는 연산자 함수를 제공한다.
### 5.3 대입 연산자
```c++
CMyData &operator=(const CMyData &rhs)
{
	if (this == &rhs)
		return *this;
	delete m_p_i_data;
	m_p_i_data = new int(*rhs.m_p_i_data);
	return *this;
}
```
#### 복합 대입 연산자
```c++
CMyData &operator++(const CMyData &rhs)
{
	int *p_i_new_data = new int(*m_p_i_data);
	*p_i_new_data += *rhs.m_p_i_data;
	delete m_p_i_data;
	m_p_i_data = p_i_new_data;
	return *this;
}
```
#### 이동 대입 연산자
- 임시 객체로 인해 이동 생성자가 생겨났듯이 임시 객체 로 인해 이동대입연산자도 생겨났다.
- a = b + c; CMyData클래스 인스턴스인 b와 c를 더하면 당연히 CMyData::operator+() 함수가 호출되고, 부산물로 임시객체가 탄생한다. 이 임시객체를 l-value삼아 곧바로 단순 대입 연산을 실행한다면 이때는 이동 대입 연산자가 호출된다.
### 5.4 배열 연산자
```c++
int &operator[] (int i_index);
int operator[] (int i_index) const;
```

### 5.5 관계 연산자
```c++
int 클래스이름::operator==(const 클래스이름 &);
int 클래스이름::operator!=(const 클래스이름 &);
```

### 5.6 단항 증감 연산자
```c++
int operator++() // 전위식
int operator++(int) // 후위식
