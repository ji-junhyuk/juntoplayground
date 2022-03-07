/*
   1 ~ 25 까지의 숫자가 있고, 이 숫자를 골고루 섞어서 5 x 5 로 출력한다.
   플레이어는 숫자를 입력받는다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
   0을 입력하면 게임을 종료한다.

   숫자를 입력받았으면 숫자목록중 입력받은 숫자를 찾아서 *로 만들어준다.
   숫자를 *로 만든 후에 빙고 줄 수를 체크한다. 5 x 5 이기 때문에 가로 5줄, 세로 5줄
   대각선 2줄이 나올 수 있다. 빙고줄이 몇줄인지를 체크해서 화면에 보여준다.
   5줄 이상일 경우 게임을 종료한다.
*/

#include <iostream>
using namespace std;

int	check_five_bingo(int *arr)
{
	int bingo_number;
	int	flag;

	bingo_number = 0;

	flag = 1;
	for (int idx = 0; idx < 5; idx++)
	{
		flag = 1;
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (arr[idx + 5 * jdx] != '*')
				flag = 0;
		}
		if (flag)
			bingo_number++;
	}
	flag = 1;
	for (int idx = 0; idx < 5; idx++)
	{
		flag = 1;
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (arr[idx * 5 + jdx] != '*')
				flag = 0;
		}
		if (flag)
			bingo_number++;
	}
	flag = 1;
	for (int idx = 0; idx < 25; idx++)
	{
		if (idx % 6 == 0 && arr[idx] != '*')
			flag = 0;
	}
	if (flag)
		bingo_number++;
	flag = 1;
	for (int idx = 0; idx < 25; idx++)
	{
		if (idx != 0 && idx != 24 && (idx % 4 == 0) && arr[idx] != '*')
			flag = 0;
	}
	if (flag)
		bingo_number++;
	cout << "현재까지 찾은 빙고:" << bingo_number << '\n';
	return (bingo_number);
}

int main(void)
{
	ios::sync_with_stdio(false);
	int arr[25];
	int selected_number;

	srand(time(NULL));
	for (int idx = 0; idx < 25; idx++)
		arr[idx] = idx + 1;
	for (int idx = 0; idx < 100; idx++)
	{
		int temp;
		int shuffle_idx;
		int shuffle_jdx;

		shuffle_idx = rand() % 24 + 1;
		shuffle_jdx = rand() % 24 + 1;
		temp = arr[shuffle_idx];
		arr[shuffle_idx] = arr[shuffle_jdx];
		arr[shuffle_jdx] = temp;
	}
	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
			cout << arr[idx * 5 + jdx] << "\t";
		cout << '\n';
	}
	cout << '\n';
	while (1)
	{
		cin >> selected_number;
		for (int idx = 0; idx < 25; idx++)
		{
			if (arr[idx] == selected_number)
			   arr[idx] = '*';
		}	
		for (int idx = 0; idx < 5; idx++)
		{
			for (int jdx = 0; jdx < 5; jdx++)
			{
				if (arr[idx * 5 + jdx] != '*')
					cout << arr[idx * 5 + jdx] << "\t";
				else
					cout << "*\t";
			}
			cout << '\n';
		}
		cout << '\n';
		if (check_five_bingo(arr) >= 5)
			break;
	}
}
