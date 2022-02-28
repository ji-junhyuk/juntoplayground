#include "stdafx.h"
#include <iostream>
#define MAX 10
using namespace std;

void swap(int &i_a, int &i_b)
{
	int i_temp = i_a;
	i_a = i_b;
	i_b = i_temp;
}

void v_quick_sort(int i_arr[], int i_start, int i_end)
{
	int i_pivot;
	int i_left;
	int i_right;

	i_pivot = i_start;
	i_left = i_start + 1;
	i_right = i_end;
	if (i_start >= i_end)
		return ;
	while (i_left <= i_right)
	{
		while (i_left <= i_end && i_arr[i_left] <= i_arr[i_pivot])
			i_left++;
		while (i_right > i_start && i_arr[i_right] >= i_arr[i_pivot])
			i_right--;
		if (i_left > i_right)
			swap(i_arr[i_pivot], i_arr[i_right]);
		else
			swap(i_arr[i_left], i_arr[i_right]);
	}
	v_quick_sort(i_arr, i_start, i_right - 1);
	v_quick_sort(i_arr, i_right + 1, i_end);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i_arr[MAX] = {5, 4, 3, 2, 1, 6, 7, 9, 8, 10};
	v_quick_sort(i_arr, 0, MAX -1); 
	for (auto num : i_arr)
		cout << num << ' ';
	cout << '\n';
	return (0);
}
