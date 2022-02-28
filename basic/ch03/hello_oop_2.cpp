#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

typedef struct USERDATA
{
	int s_i_age;
	char s_c_name[32];
} USERDATA;

void print_data(USERDATA *p_user)
{
	cout << p_user->s_i_age << ' ' << p_user->s_c_name << '\n';
}
int _tmain(int argc, _TCHAR *argv[])
{
	USERDATA user = {29, "junto"};
	print_data(&user);
	return (0);
}
/*
 * 만일 제작자가 구조체를 변경하더라도 사용자가 20번 행 코드를 변경할 이유는 없다. 이와 같은 역활을 수행하는 함수(print_data)를 인터페이스 함수라고 한다.
 */

/*
 * C언어에서는 구조체 안에 함수 선언이 불가하다.
 * typedef struct USERDATA
 * {
 * 		int s_i_age;
 * 		char s_c_name[32];
 * 		void (*print)(struct USERDATA *);
 * }
 *
 * int main()
 * {
 * 		USERDATA user = {20, "junto", print_data};
 * 		user.Print(&user);
 * 		//user 멤버인 print함수를 호출하면서 user의 주소를 매개변수로 전달하는 코드는 어딘가 어색하다. print함수가 user의 멤버인데 user의 주소를 모른다니. c++에선 user.print()가 가능하다.
 *
 * }
 */
