#include "../ch01/stdafx.h"

int _tmain(int argc, _TCHAR *argv[])
{
	int *p_i_a, *p_i_b;

	p_i_a = new int;
	*p_i_a = 10;
	p_i_b = new int;
	// p_i_b = p_i_a; // 얕은 복사
	// p_i_a 는 동적 생성한 int 인스턴스, p_i_b는 접근 불가능한 int 인스턴스
	*p_i_b = *p_i_a; // 포인터가 가리키고 있는 메모리의 내용이 복사된다!

	cout << *p_i_a << '\n';
	cout << *p_i_b << '\n';

	delete p_i_a;
	delete p_i_b; // 해제된 메모리를 한번 더 해제하려고 하기에 에러.
}
