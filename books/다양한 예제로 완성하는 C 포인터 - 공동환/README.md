### 다양한 예제로 완성하는 C포인터 (03-14-Sun ~ 00-00-000)
### Ch1. 변수와 메모리
- 변수는 데이터를 저장하기 위한 메모리 공간의 이름이다.
- 변수는 자료형(Data Type)으로 메모리 공간의 크기와 형태를 나타낸다.
- 크기가 4바이트인 메모리 주소는 총 4개의 주소를 사용한다.
- char형의 크기는 1바이트(8비트)이다.
- 하나의 주소는 1바이트의 저장 공간을 가지고 있다.
- int형 변수는 4바이트의 크기를 사용한다. 즉, 4개의 주소를 사용한다.
- 모든 변수는 메모리 공간의 주소를 가지고 있고 이때 그 변수를 대표하는 주소를 시작주소(대표주소)라 한다.
- c언어에서는 &연산자를 사용하여 변수의 시작 주소(대표 주소)를 구한다.
- char형 주소에 +1을 하면 주소 하나가 증가하고 int형 주소에 +1을 하면 주소 4개가 증가한다.
- 자동 형변환과 강제 형변환이 있다. 전자는 컴파일러에 의해 자동으로 변환되고 강제 형변환은 ()연산자를 사용하여 변환한다.
- & 연산자와 * 연산자는 상반된 개념을 가지고 있다. & 연산자는 변수(메모리 이름)앞에서만 사용하고, * 연산자는 주소 앞에서만 사용한다.
- (* N)과 같이 사용하면 N은 주소이고 & N과 같이 사용하면 N은 변수(메모리 이름)이여야 한다.
- 만약 N이 주소라면 * N과 같이 사용하면 메모리 이름이고, & * N 과 같이하면 주소가 되고, * & * N 과 같이하면 메모리가 된다.
- 즉, 어떤 주소에 * 연산자를 붙여 값(메모리)에 접근하므로 char형 주소에 * 를 붙이면 현재 주소부터 1바이트 크기의 정수라는 의미를 갖는다.
### Ch2. 포인터
- 포인터란 주소를 저장하기 위한 메모리 공간이다. 즉, 주소를 저장하는 변수를 포인터라 한다.
- 포인터 변수로 값에 접근할 때(메모리 공간)은 * 연산자를 사용한다.
- 2차원 포인터 변수는 1차원 포인터 변수의 주소를 저장하기 위한 메모리 공간(변수)이다.
- n차원 포인터 변수는 n-1차원 포인터 변수의 주소를 저장하기 위한 메모리 공간(변수)이다.
- n차원 포인터 변수는 * 연산자를 n개 붙여 값(메모리 공간)에 접근한다.
### Ch3. 배열
- 1차원 배열의 이름에는 * 연산자를 한 번 붙이면 값이 되고 2차원 배열의 이름에는 * 연산자를 두 번 붙여야 값이 된다 (n차원 주소, * 연산자를 n번 붙여야 값에 접근).
### Ch4. 포인터와 배열
- 각 자료형의 n차원 배열의 시작 주소를 저장하려면 n차원 배열의 시작 주소를 저장할 수 있는 배열 포인터를 선언하여 사용한다 (시작 주소를 포인터에 저장하면 포인터를 이용해 모든 배열의 항목에 접근할 수 있다).
### Ch5. 포인터와 문자열
- 헷갈리기 쉬운 것들 정리
	1. 1 : 정수를 의미하며 정수 1(10진수)이다. 일 숫자라 부른다.
	2. '1' : 한 문자를 의미하며 ASCII 코드 정수 49(10진수)이다. 일 문자라 부른다.
	3. "1" : 한 문자열을 의미하며 메모리에 두 문자 '1' 문자(49)와 '\0'(0) 문자가 저장되어 있다. 일 문자열이라 부른다.
- char *cp = "ABC"; char carr[10] = "ABC" 
	1. cp[0]은 문자열 상수가 저장된 상수이므로 변경할 수 없다 (carr[0]은 변경 가능).
	2. carr은 배열의 시작주소로 상수이므로 변경할 수 없다 (cp는 변경 가능).
### Ch6. 구조체와 공용체
- 구조체와 공용체는 사용자가 선언하는 자료형이다. 구조체는 각 멤버가 멤버만의 메로기 공간을 가지고 공용체는 각 멤버가 하나의 메모리를 공유한다.
- 구조체와 공용체의 변수로 멤버에 접근할 때는 . 연산자를 사용하고 구조체 변수의 주소로 멤버에 접근할 때는 ->연산자를 사용한다.
- 구조체와 공용체의 변수에 &연산자를 붙이면 그 변수의 시작 주소를 의미한다.
### Ch7. 포인터와 구조체
- struct _ point p1, * ps; (int x, int y)
	- p1 : 구조체형 메모리 변수를 의미한다.
	- ps : 구조체형 포인터 변수를 의미한다.
	- &p1 : 구조체 변수(p1)의 주소를 의미한다.
	- &ps : 구조체형 포인터 변수의 주소를 의미한다.
	- * p1 : p1이 주소가 아니므로 오류가 발생한다.
	- * ps : ps가 가리키는 구조체 메모리(값)을 의미한다.
	- p1.x : p1의 멤버인 x메모리 변수를 의미하며 4바이트(int 형)이다.
	- &p1.x : p1의 멤버인 x메모리의 주소를 의미한다. .이 &보다 우선순위가 높다.
	- ps-> x : ps가 가리키는 구조체 메모리의 멤버인 x 메모리(변수)를 의미한다.
	- &ps-> x : ps가 가리키는 구조체 메모리의 멤버인 x 메모리(변수)의 주소를 의미한다. ->이 &보다 우선순위가 높다.
	- * ps.x : .이 * 보다 우선순위가 높으므로 ps.x에 먼저 접근하고 ps가 구조체의 주소이므로 문법 오류가 발생한다.
	- ( * ps).x : 괄호 연산자가 우선순위가 가장 높으므로 ( * ps)는 ps가 가리키는 구조체의 메모리를 의미하며, ( * ps.x)는 구조체의 메모리의 멤버인 x메모리(변수)를 의미한다.

- struct _ point s1, * ps; (char * str1, char str2[8])
	- s1 : 구조체 메모리(변수)를 의미한다.
	- ps : 구조체형의 포인터 변수를 의미한다.
	- s1.str1 : 구조체(s1)의 멤버인 str1을 의미하며 char형 포인터 변수이다.
	- s1.str2 : 구조체(s1)의 멤버인 str2를 의미하며 char형 배열의 시작 주소(문자열의 시작 주소)이다.
	- s1.str1[1], * (s1.str1+1) : st.str1이 문자열의 시작 주소(포인터)이므로 이는 두 번째 문자를 의미한다.
	- s1.str2[1], * (s1.str2+1) : s1.str2가 문자열의 시작 주소(배열 이름)이므로 이는 두 번째 문자를 의미한다.
	- ps-> str1 : ps가 가리키는 구조체 메모리의 멤버인 str1을 의미하며 char형 포인터 변수(문자열의 시작 주소)이다. 
	- ps-> str2 : ps가 가리키는 구조체 메모리의 멤버인 str2를 의미하며 char형 배열의 시작 주소(문자열의 시작 주소)이다.
	- ps-> str[1], ps-> str[2] : 두 번째 문자를 의미한다.
	- * (ps-> str1+1), * (ps-> str2+1) : 두 번째 문자를 의미한다.
	- * ps.str1[1], * ps.str2[1] : . 연산자가 * 연산자보다 우선순위가 높으므로 문법 오류가 발생한다. ( * ps).str1[1]로 바꾼다면 ( * ps)는 ps가 가리키는 구조체 메모리이고, ( * ps).str1은 문자열의 시작주소이므로 ( * ps).str1은 두 번째 문자를 의미한다 (str2도 마찬가지).
	- &s1.str1 : char형 포인터 변수 s1.str1의 시작 주소이다.
	- &s1.str2 : char형 배열 이름의 주소를 의미한다. s1.str2와 같은 주소이다.
	- &s1.str1[1], &s1.str2[1] : 두 번째 문자의 주소를 의미한다.
	- &ps-> str1 : char형 포인터 변수 ps-> str1의 시작 주소이다.
	- &ps-> str2 : char형 배열 이름의 주소를 의미한다. ps-> str2와 같은 주소이다.
				       
	- &ps-> str1[1], &ps-> str2[1] : 두 번째 문자의 주소를 의미한다.
### Ch8. 포인터와 함수
- 함수의 원형과 함수의 원형이 필요한 이유
	- main() 함수에서 fun1(), func2(), func3()을 호출하려고 하면 세 함수는 모두 main() 함수 위쪽에 정의되어 있어야 한다 (아래쪽에 있을 경우 컴파일 에러).
	- 아래쪽에 있으려면 컴파일러가 세 함수를 인식할 수 있도록 함수에 정보를 알려줘야 한다. 함수의 반환형, 이름, 매개변수 개수와 자료형이 이때 필요한 정보다. 이와 같은 정보를 함수의 원형이라고 한다.
		- void func1(void);
		- int func2(int, int);
		- int* func3(int *, int *);
- 변수가 만들어지는 위치와 용도에 따라 자동 변수(auto), 정적 변수(static), 외부 변수(extern), 레지스터 변수(register), 동적변수 등으로 나눌 수 있다.
- 자동변수는 'auto' 키워드를 붙여 사용하고 정적 변수는 변수 자료형 앞에 'static'을 붙여 사용한다. 'auto' 키워드는 생략가능하다.
- 자동변수는 함수가 시작될 때 만들어지고 함수가 종료될 때 삭제된다는 것을 알 수 있다.
- 정적변수(satic)는 데이터 영역이란 곳에 만들어지며 프로그램이 시작될 때 만들어지고 프로그램이 종료될 때 삭제된다.
- **함수 내의 자동 변수는 함수가 호출될 때 마다 변수가 생성되므로 초기화가 함수를 호출할 때마다 일어날 수 있지만 정적 변수는 초기화가 단 한번 일어난다**.
- **정적 변수는 프로그램이 실행되는 동안 항상 메모리에 존재하므로 만약 함수가 종료하더라도 함수 내의 변수를 함수 외부에서 접근해야 하는 경우 등에 사용한다**.
- 문자열이나 배열은 많은 메모리를 차지하므로 함수를 전달하고자 할 때는 간단하게 시작 주소를 전달하여 값에 접근한다. 함수의 인자가 int형 주소라면 함수의 매개변수는 int형 포인터 변수로 만들어야 한다.
- **값에 의한 호출(Call-By-Value)와 참조에 의한 호출(Call-By-Reference)**
	- 값에 의한 호출은 함수에서 복사된 메모리(값)을 이용하지만, 참조에 의한 호출은 호출된 함수에서 주소를 이용하여 원본 메모리에 접근할 수 있다.
```c
// Call-By-Value
void func(int n)
{
	...
}

void main()
{
	int m;
	...
	func(m);
}

// Call-By-Reference
void func(int * n)
{
	...
}

void main()
{
	int m;
	...
	func(&m);
}
```
- 어떤 함수가 리턴값으로 주소를 반환할 때, 변수 n이 자동 변수라면 함수가 종료될 때 소멸하므로 컴파일 에러가 발생한다. static변수를 사용하거나 자동 변수의 주소를 반환하지 말자.
- 재귀함수는 명령어를 반복하는 면에서 반복문과 약간 비슷하지만, 명령어를 반복 처리만 하는 것이 아니라 함수 호출 스택을 이용하여 명령어들을 하나의 단위로 다루면서 스택 자료구조의 이점까지 챙길 수 있다.
- 명령어의 반복을 선형적으로 처리할 때는 두 방법에 별 차이가 없지만 비선형적(재귀)인 명령어의 반복을 처리할 때는 반복문보다 재귀 함수를 사용하는 것이 문제를 단순화하고 코드의 이해를 쉽게한다.
- 종료조건이 맞지 않으면 재귀 함수도 이론상 무한 반복에 빠진다.
### Ch9. void형 포인터와 함수
- void * 형은 자료형과 무관하게 주소를 저장하고자 할 때 사용할 수 있는 포인터이다.
- void * 형 변수를 이용하여 값에 접근하고자 할 때 형변환하여 사용한다.
- 함수 포인터는 함수의 주소를 저장하는 포인터로, 함수의 주소를 저장하면 그 주소를 이용하여 함수를 호출할 수 있다.
- 함수의 원형이 같은 함수들의 주소는 하나의 함수 포인터에 저장할 수 있다.
### Ch10. 동적 메모리, 가변 인자, const 상수
- 동적 메모리는 프로그램이 실행될 때 동적으로 메모리를 할당하고 해제할 수 있는 메모리로, malloc() 함수를 사용하여 할당하고 free() 함수를 사용하여 해제한다.
- 동적 메모리는 프로그램 영역 중 힙 영역에 생성된다.
- 가변 인자 함수는 인자의 개수나 인자의 자료형이 다른 함수를 만들고자 할 때 사용한다.
- const 상수는 변수 영역의 메모리를 상수화 시킬 때 사용한다.
- const 상수는 메모리 값을 변경시키지 못하도록 하기 위해 사용된다.
- calloc() 함수는 할당할 메모리의 개수와 할당할 메모리의 크기를 인자로 받아 메모리를 할당하며 할당한 메모리를 모두 0으로 초기화한다.
- realloc() 함수는 기존 메모리를 재할당하고자 할 때 사용한다. 기존 메모리의 주소와 할당할 메모리의 크기를 인자로 받아 메모리를 재할당한다.
- realloc() 함수는 기존 메모리 함수를 free() 함수로 직접 제거할 필요는 없다. 단, NULL 반환 시에는 free() 함수로 직접 메모리 제거한다.

# Ch11. 변수와 연산자

# Ch12. 포인터와 배열 
- 주소에 정수를 덧셈 뺄셈하면 결과는 주소가 되지만 주소에서 주소를 뺄셈하면 데이터의 개수인 정수가 된다.

# Ch13. 포인터와 문자열
- str1 == str2 : 문자열 비교가 아닌 문자열의 주소 비교가 되어 잘못된 결과를 출력한다. strcmp함수를 이용하자.

# Ch14. 포인터와 구조체

# Ch15. 스택, 큐, 연결리스트
- 시간복잡도는 '어떤 일을 얼마나 오랜 시간 동안 수행해야 하는가?"에 대한 함수로 나타내는 것을 의미한다.
- 상수 시간 복잡도(constant time complexity): 작업양이 증가할 때 변하지 않는 일정한 수행 성능을 보인다는 것
- 로그 시간 복잡도(logarithmic time complexity): 작업양이 증가할 때 수행시간도 일정하게 늘어나지만, 로그 함수의 비율로 늘어나는 것
- 선형 시간 복잡도(linear time complexity): 작업양이 증가할 때 수행시간도 비례해서 늘어나는 것
- 지수 시간 복잡도(exponential time complexity): 작업양이 증가할 때 지수함수의 비율로 늘어나는 것

# Ch16. 이중 연결 리스트를 활용한 프로그래밍 예제 구현

