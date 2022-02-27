#pragma once

#include <iostream>
#include <vector>
#include <list>
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

template <typename T>
void safe_delete_vec_list(T& p)
{
	T::iterator iter;
	T::iterator iter_end = p.end();
	for (iter = p.begin(); iter != iter_end; ++iter)
	{
		SAFE_DELETE(*iter);
	}
	p.clear();
}
