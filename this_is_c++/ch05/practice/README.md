1. 대입 연산자 오버로딩 시 주의해야 할 점(두가지)은 무엇인지, 그리고 이유를 답하세요.
- 첫째로 자기 자신을 대입하는 경우(a = a)를 주의해야 한다. 대입 전 기존 데이터를 삭제하므로 자기 자신에게 대입하기 전에 원본 데이터가 삭제될 수 있기 때문이다.
- 둘재로 대입 연산의 결과가 클래스의 참조자가 필요한 경우(a = b = c)를 주의해야 한다. 일반적인 경우에는 반환 형식을 void로 해도 문제가 없지만 a = b = c의 경우 b = c의 결과 값이 다시 a와 연산이 되도록 참조자로 해야한다.
2. 각종 대입 연산자들의 적절한 반환 형식은 무엇입니까?
- 자신이 속한 클래스를 참조하는 참조자 형식이 적절하다. (대입 연산자에는 단순, 복합, 이동이 있다) 
3. 후위식 단항 증가 연산자를 작성하려고 합니다. 적절한 함수 원형을 예로 들어보세요.
```c++
int operator++(int)
{
	int i_data = m_i_data;
	m_i_data++;
	return i_data;
}
```
