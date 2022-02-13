/*
   1 ~ 23 까지의 숫자가 있고, 이 숫자를 골고루 섞어서 5 x 5 로 출력한다.
   w(상) a(좌) s(하) d(우) 키를 이용하여 각 위치에 있는 숫자를 바꿀 수 있다.
   키보드를 이용하여 모든 숫자를 정렬하는 프로그램을 만든다.
*/

#include <iostream>
#include <limits.h>

using namespace std;

int main(void)
{
	int arr[25];

	srand(time(NULL));

	for (int idx = 0; idx < 24; idx ++)
		arr[idx] = idx + 1;
	arr[24] = INT_MAX;

	for (int idx = 0; idx < 25; idx++)
		cout << arr[idx] << ' ';
	cout << '\n';

	for (int idx = 0; idx < 100; idx++)
	{
		int temp;
		int a;
		int b;

		a = rand() % 24;
		b = rand() % 24;

		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (arr[idx * 5 + jdx] == INT_MAX)
				cout << "*\t";
			else
				cout << arr[idx * 5 + jdx] << '\t';
		}
		cout << '\n';
	}
}
