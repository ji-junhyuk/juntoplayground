/*
100

전역변수로 int i_data = 200;
namespace 안에 
i_data = 100;
void test_func(void)
{
	cout << i_data << '\n';
}

i_data 식별하는 순서는 전역 변수보다 현재 블록 범위를 포함하고 있는 상위 블록(namespace)에 우선한다.
*/
