/*
   1 ~ 23 까지의 숫자가 있고, 이 숫자를 골고루 섞어서 5 x 5 로 출력한다.
   w(상) a(좌) s(하) d(우) 키를 이용하여 각 위치에 있는 숫자를 바꿀 수 있다.
   키보드를 이용하여 모든 숫자를 정렬하는 프로그램을 만든다.
*/

#include <iostream>
#include <limits.h>
#include <conio.h>

using namespace std;

int check(int *arr)
{
	int flag;

	flag = 0;
	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (jdx < 4)
			{
				if (arr[idx * 5 + jdx] > arr[idx * 5 + jdx + 1])
				{
					flag = 1;
					return flag;
				}
			}
		}
	}
	return (flag);
}

int main(void)
{
	int 	arr[25];
	int 	star_index;
	char	input;

	srand(time(NULL));
	star_index = 24;

	for (int idx = 0; idx < 24; idx ++)
		arr[idx] = idx + 1;
	arr[24] = INT_MAX;


	cout << "check, arr:" << check(arr);
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

	for (int idx = 0; idx < 25; idx++)
		cout << arr[idx] << ' ';
	cout << "check, arr:" << check(arr);
	cout << '\n';
	while (1)
	{
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

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료\n";
		input = _getch();
		if (input == 'q' || input == 'Q')
			break ;
		switch (input)
		{
			case 'W':
			case 'w':
				if (star_index > 4)
				{
					arr[star_index] = arr[star_index - 5];
					arr[star_index - 5] = INT_MAX;
					star_index -= 5;
				}
				break;
			case 'S':
			case 's':
				if (star_index < 20)
				{
					arr[star_index] = arr[star_index + 5];
					arr[star_index + 5] = INT_MAX;
					star_index += 5;
				}
				break;
			case 'A':
			case 'a':
				if (star_index % 5 > 0)
				{
					arr[star_index] = arr[star_index - 1];
					arr[star_index - 1] = INT_MAX;
					star_index -= 1;
				}
				break;
			case 'D':
			case 'd':
				if (star_index % 5 < 4)
				{
					arr[star_index] = arr[star_index + 1];
					arr[star_index + 1] = INT_MAX;
					star_index += 1;
				}
				break;
		}
		if (!check(arr))
		{
			cout << "퍼즐을 맞추느라 수고하셨떠염\n";
			break ;
		}
	}
	cout << "end\n";
}
