### 8.1 friend
```c++
friend class 클래스이름;
friend 함수원형선언;
```
- private 멤버 변수에 직접 접근이 허용된다.
### 8.2 집합 관계
#### Composition
- 구성요소, 자동차 인스턴스가 소멸하면 구성 요소들도 모두 '함께 소멸'
```c++
class CMyUi
private:
CMyList m_list;

//main
CMyUi ui.
ui.run()
```
#### Aggregation
```c++
class CMyUi
CMyUi(CMyList &r_list) : m_list(r_list) { } // 참조 멤버는 반드시 초기화 목록을 이용해 초기화해야 한다.
private:
	CMyList &m_list; // ui클래스 내부에 자료구조 객체에 대한 참조만 존재
//main
CMyList list;
CMyUi ui(list);
ui.run();
```
- 모두 모여 하나의 시스템을 이루지만 각각 개별적으로 분리되어 독립적으로 활용 가능
