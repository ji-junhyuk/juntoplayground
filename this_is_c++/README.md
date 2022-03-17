# C++ 프로그래밍과 STL
## ch01. 객체지향 프로그래밍의 개념
- 구조적 프로그래밍처럼 프로그래머가 순차적으로 구성한 시나리오에 의해 기능이 수행되는 것이 아니라,
실행 중에 사용자가 마음 가는 대로 기능을 선택하면, 그 기능을 수행하도록 하는 방식이다. 객체 지향프로그래밍은 이와 같은 구성 방식을 가지고 있다고 생각하면 쉽다.
- 은닉된 데이터는 외부로부터 숨기고, 외부로는 멤버함수만 공개하여 은닉된 데이터를 접근할 수 있는 방법은 오직 멤버함수로 제한하였다.
### 다형성(polymorphism)
1. 오버로딩(overloading) : 같은 이름, 다른 전달인자의 타입과 전달인자의 개수.
2. 오버라이딩(overriding) : 재정의

## ch02. C에서 C++로 확장
### 인라인 함수(inline function)
- 멤버함수의 정의가 아주 짧으면, 크래스 선언 내부에 직접 함수를 정의할 수 있다. 클래스 내부에 직접 함수를 정의하게 되면 inline 키워드를 굳이 붙이지 않아도 인라인 함수가 된다.
- 장점
1. 인라인 함수의 전달인자에 데이터 형을 체크할 수 있다.
2. 매크로가 갖는 부작용 없이 일반 함수처럼 사용이 가능하다.
3. 디버깅이 가능하다.
- 단점
1. 실행 코드가 커진다
2. 인라인 함수의 구현을 짧게 해야 한다. 길다면, 컴파일러는 이를 일반 함수로 취급하게 된다.

## ch03. 클래스의 기본
- 클래스란 사용자가 정의한 추상적인 데이터형(Abstract Data Type)이라고 할 수 있다.
- 클래스는 기본이 private, 구조체는 접근 지정자의 기본이 public. c++에서 데이터 멤버만을 사용할 때는 구조체를 사용하되, 멤버변수 및 멤버함수를 모두 사용하는 경우는 클래스를 사용하도록 하자.
#### 객체 생성
```c++
MousePoint point;
// 변수를 선언하듯이 MousePoint 클래스 명을 쓰고, 그 뒤에 point라는 객체 이름을 선언하였다.
// MousePoint 클래스가 바로 사용자가 정의한 자료형이고, point가 실질적인 프로그래밍을 하게 할 객체이다.
```
#### 멤버함수
- 클래스는 데이터인 멤버 변수를 은닉화시키고, 은닉화된 멤버변수를 컨트롤 할 수 있는 유일한 게이트로 멤버함수를 정의한다.

#### 생성자
- 객체 생성 시 자동으로 초기화를 해주는 특별한 초기화 전용 멤버함수를 제공하고 있는데, 이것이 바로 생성자(Constructor)이다.
- 특징
1. 생성자의 이름은 클래스의 이름과 동일하다
2. 생성자의 타입은 지정하지 않는다
3. 생성자의 호출은 객체 선언 시 자동으로 호출되다
4. 반환값을 지정하지 않는다
5. 디폴트 생성자가 존재한다.

#### 소멸자
- 특징
1. 클래스의 이름을 그대로 사용한다. ~틸드 기호를 붙인다.
2. 소멸자 타입은 지정하지 않는다
3. 객체 소멸 시 자동으로 호출된다. 인위적으로 호출할 수 있는 함수가 아니다
4. 반환값을 지정하지 않는다.
5. 전달인자를 지정하지 않는다.
6. 생성자처럼 오버로딩이 되지 않는다.
 
## ch04. 클래스의 특징과 객체 활용
#### 객체 배열
```c++
MousePoint pt[3];
// pt라는 객체가 3개 선언되어있따는 의미이다. 각 객체별로 별도의 메모리를 할당받는다. 즉(멤버변수도 객체별 메모리를 각각 할당받되, 멤버함수는 3개의 객체가 공유한다)
```
#### 객체 포인터
```c++
MousePoint *pObj;
// 객체 포인터는 객체의 주소값을 저장하기 위한 변수이며 객체를 간접 참조하기 위해 사용한다.

MousePoint pt(10, 20);
pObj = &pt;
cout << pObj->Getx() << '\n'; // 10을 출력.
```

#### this 포인터
- this 포인터가 필요한 이유
	- 각 객체함수가 멤버함수를 호출하면 당연히 자기 자신이 갖고 있는 데이터를 멤버함수가 사용할 것이라고 생각한다. 하지만, 멤버함수 입장에서 생각해보자. 어떤 객체가 자신을 호출했는가?
	- 이때 필요한 정보가 this 포인터이다.
- this 포인터는 호출한 객체를 가리키는 const포인터이다.
```c++
void MousePoint::SetXY(int x, int y)
{
	this->x = x;
	this->y = y;
	// 멤버 변수를 나타내는 x, y는 this 포인터를 붙여줌으로써 현재 호출한 객체의 멤버변수임을 명시할 수 있다.
}
```
### 객체에 대한 값 전달 방식 
```c++
class 
...
void MousePoint::SetXY(int nx, int ny) // nx, ny는 형식 매개변수
{
	this->x = nX;
	this->y = nY; 
}
pt1.SetXY(a, b);
// a, b 의 값이 nx, ny 변수의 메모리에 저장되는 것이다.

void CopyObject(MousePoint pt1, MousePoint pt2)
{
	pt1 = pt2;
}
CopyObject(mp1, mp2); // 이것 또한 mp1, mp2객체의 값이 mp1, mp2 변수의 메모리에 저장되는 것 뿐이다.
```
### 객체에 대한 레퍼런스 전달 방식
- 실 매개변수를 함수를 통해 변경하고 싶다면 레퍼런스 전달 방식(&)을 사용해야 한다!

### static 멤버
- 개요
```c++
은행 예금계좌에 대한 클래스를 작성한다고 생각해보자.
고객명과 고객의 예금 잔액을 저장할 멤버 변수가 있어야하고, 현재 이자율을 표시하는 이자율 멤버함수가 있어야 한다.
이 때 이자율은 모든 고객에 해당하는 공통 변수이다. 만약 이자율이 클래스의 멤버변수로 선언된다면 각각의 객체는 이자율 멤버 변수가
각각 포함되기 때문에 똑같은 정보를 여러 객체가 있다는 점에서 메모리 낭비이다. 또한 이자율 수정시 모든 객체의 이자율을 수정해야 한다는
부담감이 있다.
=====================================
전역 변수는 모든 클래스에서 접근 가능하므로 객체 지향의 기본 철학에 위배된다. 즉 우리가 원하는 것은
하나의 클래스 내에 속해 있는 객체들에서만 사용할 수 있는, 전역변수와 같은 성질의 멤버변수인데 이것이 바로 static 멤버 선언 방식이다.
```
```c++
static double dInterestRate;
```
- static 멤버변수
	- 클래스에 대한 객체가 생성된다 하더라도 단 하나의 변수만 메모리에 할당된다.
	- static멤버 변수는 클래스에 속해 있는 멤버이므로 private 속성을 갖는다면 같은 클래스의 멤버함수에서만 접근이 가능하다.
	- static변수는 전역변수처럼 프로그램이 시작되면서 멤버변수가 메모리에 할당된다. (즉, 클래스의 객체가 생성되지 않아도!)
	- static멤버변수는 생성자에 초기화가 불가능하다(해당 클래스를 통해 생성되는 각각의 객체마다 사용하는 값이 달라지므로!)
	- 클래스 외부에서 초기화가 가능하다. ex) double Deposit::dInterestRate = 0.05;
	- static 멤버변수의 접근 지정자가 public이라면 외부에서도 접근 가능하다. (Deposit::dInterestRate = 0.06; // 일반 멤버 변수가 변경되는 것이 아니라 클래스 내의 static 멤버 변수의 값이 변경되는 것이라고 명확하게 해주자!, 멤버 변수는 private으로 해주고 static 멤버함수를 public으로 선언하여 static 멤버 함수를 통해 static 멤버 변수에 접근하도록 해주자!)
	- static 멤버함수를 호출하는 방법은 2가지가 있다. 선언한 클래스를 통해 (.)연산자를 통해 호출하거나 클래스명 뒤에 영역 결정 연산자(::)를 붙여 호출하는 것이다. (후자를 사용하자. 특정 객체를 통해 변경하는 것으로 보이는 방식은 지양한다) ex) kim.SetInterestRate(0.03)이 아닌 Deposit::SetInterestRate(0.03);
	- static 멤버변수의 경우 static 멤버함수 내에서 사용하게 했지만, 일반 멤버함수에서도  static 멤버 변수에 접근할 수 있다. (static 멤버변수도 하나의 클래스 멤버변수이기 때문이다) 그렇다면 왜 static 멤버 함수를 사용할까?
	  - static 멤버함수는 객체가 생성되지 않아도 static 멤버함수는 호출할 수 있다. private 속성의 static 멤버변수 dInterestRate에 접근하기 위해 사용할 수 있기 때문이다.
	  - static 멤버함수는 클래스의 특정 객체에 영향을 미치지 않으므로 this포인터를 사용할 수 없다. (즉 멤버함수에서 this를 통해 static 멤버 변수에 접근할 수 없으며, static 멤버 함수 안에서 객체가 필요한 특정 멤버함수 호출도 불가능하다)
### friend

## ch05. 클래스와 동적 메모리 할당
- 동적 메모리는 실행 시간에 할당되어 사용되는 메모리 블록을 말한다. 정적 메모리의 할당은 컴파일 시점에 할당한다. 따라서 동적 메모리의 경우는 프로그램 작성 시에 얼마만큼의 메모리가 필요한지 알지 못하는 경우에 사용된다. 동적 메모리의 크기는 프로그램 실행 시간에 결정되며, 할당되는 동적 메모리 영역을 우리는 힙(Heap) 영역이라고 한다.
- 배열이 생성되는 시점은 컴파일 시점인데 배열의 변수 n_Length는 실행시점에 사용자에게 입력받도록 설정되어 있다. 따라서 프로그램 작성 시 배열의 크기를 결정할 수 없는 경우 동적 메모리 할당이 필요하게 된다.
### new / delete 연산자
- malloc()함수의 경우 전달인자로 크기만 넘겨주면 넘겨진 메모리의 크기만을 생성할 뿐 메모리의 타입이나 어떤 정보도 없이 void* 만 넘길 뿐이다. 그러나 new 연산자는 자신이 할당하는 객체의 데이터형을 알고 있을 뿐 아니라 그 데이터형의 포인터를 반환해준다.
### 객체의 동적 메모리 할당
#### 1. 힙 영역에 객체 생성
```c++
MousePoint *pt;
pt = new MousePoint(10, 20);
```
#### 2. 객체 포인터 배열
```c++
MousePoint *pArr[3];
pArr[0] = new MousePoint(10, 20);
pArr[1] = new MousePoint(20, 30);
pArr[2] = new MousePoint(30, 40);
```
## 3. 포인터 멤버변수를 갖는 클래스 <처음에 여기부분을 잘 이해못했음>
- 객체끼리의 대입 및 문제점
```c++
String str1('A', 3), str2('B', 5); // str1에는 "AAA\0'이 동적할당된다.
str2 = str1; // 여기가 문제된다
// str2 객체가 먼저 소멸되는데, 소멸 시 str2의 pbuffer 멤버 변수가 가리키고 있는 메모리 영역을 delete한다.
// 헌데, str1객체 또한 pbuffer가 가리키는 영역을 다시 delete 하려는 시도를 함으로써 치명적인 에러를 유발한다.
```

- 대입 연산자 오버로딩(Assignment Operator Overloading)
```c++
void operator=(const string& s);
str1 = str2;
// 단순히 st2가 str1이 가리키는 메모리의 주소를 공유하는 것이 아니라 기존에 가리키고 있던 메모리 주소 값을 delete하고,
힙 영역에 메모리를 새로 할당한 후, 문자열 값을 메모리에 대입하고 있다. 즉 각 객체는 같은 메모리를 참조하고 있기 않기 때문에
치명적인 에러가 생기지 않는다.
```

- 객체의 자기 자신에 대입 시에 대한 처리
```c++
str1 = str1;
// 자기 자신의 메모리를 복사하게 될 때 기존의 자신의 메모리를 삭제하므로 pbuffer 에는 쓰레기 값이 저장된다.
// 다음과 같이 수정해주도록 하자.
void String::operator=(const String& s)
{
	if (&s == this)
		return ;
	delete pBuffer;
	nLength = s.nLength;
	pBuffer = new char[nLength + 1]
	strcpy(pBuffer, s.pBuffer);
}
```

- 객체의 다중 대입 시에 대한 처리
```c++
str1 = (str2 = str3); // 즉 str2에 str3이 대입되고 그 객체가 다시 str1에 다시 대입되어야 한다. 결국, str2 = str3 문장 수행 후 멤버 간의 복사에 그치지 않고 str3 객체를 str2 객체로 반환해주어야 한다.
string& String::operator=(const String& s)
{
	if (&s == this)
		return *this;
	delete pBuffer;
	nLength = s.nLength;
	pBuffer = new char[nLength + 1];
	strcpy(pBuffer, s.pBuffer);
	return *this;
}
```

## 복사생성자 < 여기도 어려웠음, 정리해두자!>
- 우리는 생성자란 객체 생성 시 객체의 멤버롤 초기화하는 함수이며, 전달인자가 없는 디폴트 생성자와 전달인자가 있는 생성자가 있다는 것을 알고 있다. 그럼 '복사'라는 말이 붙은 복사 생성자는 무엇일까?
- 복사 생성자 또한 객체 생성 시 초기화를 하되, 생성되는 객체를 다른 객체로 초기화 시에 호출된다는 특징이 있다.
	- 바로 객체간의 대입. 앞에서 객체 간 대입시 문제가 되었던 부분은 포인터 멤버변수(두개의 멤버 변수가 같은 곳을 가리키므로 소멸 시 해제된 메모리 접근)이다. 복사 생성자 또한 객체 간의 복사이므로 이에 대한 처리를 해주어야 한다.
```c++
String str('A', 3); // 일반 생성자 호출
String str2 = str1; // 복사 생성자 호출, 이때 초기화된 str1객체를 str2객체에 대입함으로써 초기화시키고 있다. 이때 복사생성자 호출
String str2(str1);  // 복사 생성자 호출, 
```
- 복사 생성자 특징
	- 함수명이 클래스명과 동일하다
	- 반환형이 없다.
- 대입 연산자와의 차이점
	- 대입 연산자인 operator=() 멤버함수는 이미 생성된 객체에서만 호출되는 반면, 복사 생성자는 새로운 객체를 만들 때 호출된다. 즉, oprator=()멤버함수에서는 원래 할당했었던 메모리를 해제하고 새로 할당해야 하지만, 복사 생성자는 객체가 처음 생성되는 시점이기에 그럴 필요가 없다.
	- 대입 연산자인 operator=() 멤버함수는 자기 자신의 객체를 대입하였는지 검사해야 하지만, 복사 생성자는 자기 자신의 초기화가 불가능하기에 그럴 필요가 없다.
	- 대입연산자 operator=() 다중 대입문을 지원해야 하므로 *this를 반환해야 하지만, 복사 생성자는 생성자이기 때문에 반환값을 가질 수 없다.
```c++
class String
{
	String(const String& s);
};

String::String(const String& s) // cosnt 는 객체를 상수화시킴으로써 복사하고자하는 객체의 변경을 막기 위함.
{
	nLength = s.nLength; // 값에 의한 복사
	pBuffer = new char[nLength + 1]; // 메모리를 새로 할당하여 주소값을 가리킨다
	strcpy(pBuffer, s.pBuffer);
}

void main()
{
	String str('A', 3);
	String str2 = str1; 
}
```
## ch06. 연산자 오버로딩
```c++
class Point
{
	private:
		int m_x;
		int m_y;
	public:
	Point(int x, int y) : m_x(x), m_y(y){}
	Point operator+(const Point& p);
};

Point Point::operator+(const Point& p)
{
	return Point(m_x + p.m_x, m_y + p.m_y);
}

void main()
{
	Point p1(10, 10);
	Point p2(20, 20);
	Point a = p1 + p2; // 내부적으로 다음과 같은 연산을 한다. p1.operator+(p2);
}
```
- 연산자 오버로딩 시 주의할 점 
	- 기존에 존재하지 않는 연산자는 정의할 수 없다.
	- 연산자의 피연산자 수는 변경할 수 없다.
	- 연산자의 우선순위와 결합 방향은 변경할 수 없다.
	- 기본 데이터형에 대해서는 연산자를 오버로딩할 수 없다
	- :: . , * ? : sizeof 연산자는 오버로딩 할 수 없다.
	- = () [] -> 연산자를 오버로딩 시 연산자 함수는 멤버함수로 구현된다.
### 멤버 연산자 함수와 프렌드 함수
#### 1. 멤버 연산자 함수 사용
```c++
Point p(10, 10);
Point a = p + 100; // operator+를 멤버함수로 구현 가능
Point b = 100 + p; // operator+를 멤버함수로 구현 불가능
```
#### 2. 프렌드 연산자 함수 사용
- 앞서 살펴본 멤버함수로 구현하기 어려운 연산자 함수는 프렌드 함수로 구현할 수 있다.
```c++
class Point
{
	...
	friend Point operator+(int n, const Point& p);
	
	Point operator+(int n, const Point& p)
	{
		return Point(n + p.m_x, n + p.m_y);
	}
}
```

#### 3. 여러가지 연산자 오버로딩
##### 1) 관계연산자
```c++
class Point
{
public:
	bool operator==(const Point& p);
	bool operator>(const Point& p);
	bool operator<(const Point& p);
}

bool Point::operator==(const Point& p)
{
	if (m_x == p.m_x && m_y == p.m_y)
		return true;
	else
		return false;
}

bool Point::operator>(const Point& p)
{	
	if (m_x > p.m_x)
		return true;
	else if (m_y > p.m_y)
		return true;
	return false;
}

bool Point::operator<(const Point& p)
{
	if (m_x < p.m_x)
		return true;
	else if (m_y < p.m_y)
		return true;
	return false;
}
```
##### 2) 증가 및 감소 연산자
- 전위형 연산자 함수
	- operator++()
- 후위형 연산자 함수
	- operator++(int) // int형 전달 인자를 갖는다. 그 이유는 전위형 연산자 함수와 구분하기 위함이지, 실제로 int형 전달인자가 사용되는 것은 아니다.
```c++
Point operator++();
Point operator++(int);
Point operator--();
Point operator--(int);

Point Point::operator++()
{
	return Point(++m_x, ++m_y);
}
Point Point::operator++(int)
{
	return Point(m_x++, m_y++);
}
Point Point::operator--()
{
	return Point(--m_x, --m_y);
}
Point Point::operator--(int)
{
	return Point(m_x--, m_y--);
}
```
##### 3) <<, >> 연산자 
- << 연산자는 피연산자가 정수이든 실수이든 표준형이든 가리지 않고 출력할 수 있었다. 그 이유는 cout의 소속 클래스인 ostream 내부에 << 연산자가 각 타입별로 정의되어 있기 때문이다.
```c++
point p(10, 20)
cout << p;

// 기본형이 아니므로 << 연산자를 인식할 수 없다.
// cout << 연산식으로 만났을 때, ostream 클래스의 멤버 연산자 함수 <<를 검색해보고 Point형의 인수를 취하고 있는 연산자가 있는지 조사한 후, 없으면 프렌드 함수로 <<를 오버로딩할 연산자를 찾는다.
friend ostream& operator<<(ostream& os, const Point& p);
friend istream& operator>>(ostream& os, const Point& p);

ostream& operator<<(ostream& os, const Point& p)
{
	os << p.m_x << ", " << p.m_y;
	return os;
}

istream& operator>>(ostream& os, const Point& p);
{
	is >> p.m_x >> p.m_y;
	return is;
}
```

##### 4) ()연산자
- ()연산자 또한 일종의 연산자로써 함수를 호출하는 역할을 한다.
```c++
public:
	int operator()(int x, int y)
	{
		return x + y;
	}
	int operator()(int x, int y, int z)
	{	
		return x + y + z;
	}
```
## ch07. 상속성(inheritance)
## ch08. 다형성(polymorphiysm)
## ch09. 다중상속(multiple inheritance)
## ch10. 템플릿(Template)
## ch11. 예외처리(exception handling)
