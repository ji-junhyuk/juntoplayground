/*
   1~45번까지의 숫자.
   로또 추첨은 1~45번까지 숫자 중 6개 추첨. 보너스 번호로 1개 추가로 추첨.
   유효하지 않은 숫자, 중복되지 않은 숫자 처리. (입력, 로또번호)

   1등 : 번호 6개 일치.
   2등 : 번호 5개 일치하며 보너스 숫자가 일치.
   3등 : 번호 5개 일치.
   4등 : 번호 4개 일치.
   5등 : 번호 3개 일치.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);

	int	flag;
	int select_number[6];
	int	lotto_number[7];
	int bonus;
	int	winning_number;

	for (int idx = 0; idx < 6; idx++)
		select_number[idx] = 0;
	for (int idx = 0; idx < 7; idx++)
		lotto_number[idx] = 0;
	srand(time(NULL));
	flag = 0;

	cout << "Lotto 6/45\n";
	cout << "1 ~ 45 중에서 고르세요\n";
	for (int idx = 0; idx < 6; idx++)
	{
		if (idx < 6)
			cout << idx + 1 << "번째 번호를 입력하세요.\n:";
		do {
			flag = 0;
			cin >> select_number[idx];
			for (int jdx = 0; jdx < idx; jdx++)
			{
				if (select_number[idx] == select_number[jdx])
				{
					flag = 1;
					cout << "번호가 중복됩니다. 다시 입력하세요\n:";
				}
			}
			if (select_number[idx] > 45 || select_number[idx] < 1)
				cout << "유효한 숫자가 아닙니다. 다시 입력하세요\n:";
		} while (select_number[idx] < 1 || select_number[idx] > 45 || flag);
	}
	cout << '\n' << rand() % 999 + 1 << "회 로또 번호를 추첨하겠습니다!!\n";
	for (int idx = 0; idx < 7; idx++)
	{
		do {
			flag = 0;
			lotto_number[idx] = rand() % 45 + 1;
			for (int jdx = 0; jdx < idx; jdx++)
			{
				if (lotto_number[idx] == lotto_number[jdx])
				{
					flag = 1;
					lotto_number[jdx] = rand() % 45 + 1;
				}
			}
		} while (flag);
		if (idx < 6)
			cout << "뚜루뚜루뚜루!!! " << idx + 1 << "번째 당첨 번호는 바로 [" << lotto_number[idx] << "]입니다!!\n";
		else
			cout << "뚜루뚜루뚜루!!! " << "보너스 번호는 바로 [" << lotto_number[idx] << "]입니다!!\n";
	}
	cout << '\n';
	flag = 0;
	winning_number = 0;
	bonus = 0;
	for (int idx = 0; idx < 6; idx++)
	{
		for (int jdx = 0; jdx < 7; jdx++)
		{
			if (select_number[idx] == lotto_number[jdx])
			{
				if (select_number[idx] == lotto_number[6])
					bonus = 1;
				winning_number++;
				flag = 1;
				if (idx < 5)
					cout << idx + 1 << "번째 번호가 맞았습니다.\n";
				else
					cout << "보너스 번호가 맞았습니다.\n";
			}
		}
	}
	if (winning_number > 5)
		cout << "[1]등입니다. 축하드립니다!\n";
	else if (winning_number > 4 && bonus)
		cout << "[2]등입니다. 축하드립니다!\n";
	else if (winning_number > 4)
		cout << "[3]등입니다. 축하드립니다!\n";
	else if (winning_number > 3)
		cout << "[4]등입니다. 축하드립니다!\n";
	else if (winning_number > 2)
		cout << "[5]등입니다. 축하드립니다!\n";
	else 
		cout << "꽝!입니다\n";
	return (0);
}
