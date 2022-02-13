#include <iostream>
#include <limits.h>
#include <conio.h>

using namespace std;

int check(char *arr)
{
	int flag;

	flag = 0;
	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (jdx < 4)
			{
				if (arr[idx * 5 + jdx] == 'O')
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
	char 	arr[25];
	char	star_arr[25];
	char 	star_index;
	char	input;
	int		flag;

	flag = 24;
	srand(time(NULL));
	star_index = 24;
	for (int idx = 0; idx < 25; idx ++)
		arr[idx] = 'O';
	for (int idx = 0; idx < 25; idx ++)
		star_arr[idx] = 'O';
	arr[24] = 'X';


	//cout << "check, arr:" << check(arr);
	cout << '\n';
	while (1)
	{
		for (int idx = 0; idx < 5; idx++)
		{
			for (int jdx = 0; jdx < 5; jdx++)
			{
				if (idx * 5 + jdx != flag)
					cout << arr[idx * 5 + jdx] << '\t';
				else
					cout << "X\t";
			}
			cout << '\n';
		}

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료\n";
		input = _getch();
		arr[star_index] = '*';
		if (input == 'q' || input == 'Q')
			break ;
		switch (input)
		{
			case 'W':
			case 'w':
				if (star_index > 4)
				{
					arr[star_index - 5] = '*';
					star_index -= 5;
					flag = star_index;
				}
				break;
			case 'S':
			case 's':
				if (star_index < 20)
				{
					arr[star_index + 5] = '*';
					star_index += 5;
					flag = star_index;
				}
				break;
			case 'A':
			case 'a':
				if (star_index % 5 > 0)
				{
					arr[star_index - 1 ] = '*';
					star_index -= 1;
					flag = star_index;
				}
				break;
			case 'D':
			case 'd':
				if (star_index % 5 < 4)
				{
					arr[star_index + 1] = '*';
					star_index += 1;
					flag = star_index;
				}
				break;
		}
		if (!check(arr))
		{
		for (int idx = 0; idx < 5; idx++)
		{
			for (int jdx = 0; jdx < 5; jdx++)
			{
					cout << arr[idx * 5 + jdx] << '\t';
			}
			cout << '\n';
		}
			cout << "퍼즐을 맞추느라 수고하셨떠염\n";
			break ;
		}
	}
	cout << "end\n";
}	
