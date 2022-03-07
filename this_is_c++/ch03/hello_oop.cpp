#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

typedef struct USERDATA
{
	int i_age;
	char c_name[32];
} USERDATA;

int _tmain(int argc, _TCHAR *argv[])
{
	USERDATA user = {29, "junto"};
	cout << user.i_age << ' ' << user.c_name << '\n';
	return (0);
}
/*
 * 사용자는 제작자가 만든 자료구조의 멤버 및 구성을 알고 있어야 한다
 * 자료구조에 담긴 정보를 출력하고 싶다면 제작자가 스스로 직접 멤버에 접근해야 하며 적절한 출력 방법도 선택해야(printf)한다.
 * 만일 제작자가 자료구조를 변경한다면 사용자는 제작자의 코드와 관련된 자신의 코드를 몽땅 수정해야 한다.
 */
