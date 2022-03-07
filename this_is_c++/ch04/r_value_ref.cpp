#include "../ch01/stdafx.h"

int _tmain(int argc, _TCHAR *argv[])
{
	int &&data = 3 + 4;
	cout << data << '\n';
	data++;
	cout << data << '\n';
}
