#pragma once

#include <iostream>
using namespace std;
#include "defines.h"

template <typename T>
T input()
{
	T	data;
	cin >> data;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return 0;
	}
	return data;
}
