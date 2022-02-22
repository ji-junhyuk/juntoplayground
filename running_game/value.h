#pragma once

#include <iostream>
#include <windows.h>

using namespace std;
// 매크로는 #define을 이용해서 기능을 만들어주는 것이다. 이 매크로를 사용하게 되면 사용한 부분에 컴파일 단계에서 뒤의 코드를 복사해주는 개념이다. 매크로의 단점 : 브레이크 포인터를 걸고 값을 체크할 수 없다.
#define safe_delete(p) if(p) { delete p; p = NULL; }

#define STAGE_MAX_COUNT 3

#define BLOCK_X 50
#define BLOCK_Y 10

static int get_input()
{
	int i_input;
	cin >> i_input;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return i_input;
}
