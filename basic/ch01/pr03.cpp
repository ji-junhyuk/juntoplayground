#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char *arr = new char(12);
	delete[] arr;
	return (0);
}
