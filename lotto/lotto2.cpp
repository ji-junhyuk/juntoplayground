/*
   입력 받은 금액만큼 로또(1000원)를 산다.
   로또에 당첨된 등수별 갯수(1 ~ 5등)를 각각 구하고, 당첨금을 구한다.

   1~45번까지의 숫자.
   로또 추첨은 1~45번까지 숫자 중 6개 추첨. 보너스 번호로 1개 추가로 추첨.
   유효하지 않은 숫자, 중복되지 않은 숫자 처리. (입력, 로또번호)

   1등 : 번호 6개 일치.
   2등 : 번호 5개 일치하며 보너스 숫자가 일치.
   3등 : 번호 5개 일치.
   4등 : 번호 4개 일치.
   5등 : 번호 3개 일치.

   총 당첨금 : 로또 총 판매금액.
   당첨금 : 총 판매금액의 50%.
   1등 : 총 당첨금 중 4등과 5등을 제외한 금액의 75%.
   2등 : 총 당첨금 중 4등과 5등을 제외한 금액의 12.5%.
   3등 : 총 당첨금 중 4등과 5등을 제외한 금액.
   4등 : 50,000원.
   5등 : 5,000원.
*/

#include <iostream>
#include <unistd.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);

	long long	total_amount;
	long long	purchase_lotto_amount;
	long long	winning_lotto_amount;
	long long	winning_lotto_number[7];
	int			flag;
	int			bonus;
	int			winning_number;
	int			rank_winning_number[6];
	int			lotto_number[6];

	cin >> total_amount;
	purchase_lotto_amount = total_amount / 2000;
	cout << "purchase_lotto_amount: " << purchase_lotto_amount << '\n';
	winning_lotto_amount = (purchase_lotto_amount * 2000) / 2;
	cout << "winning_lotto_amount: " << winning_lotto_amount << '\n';

	for (int idx = 0; idx < 6; idx++)
		rank_winning_number[idx] = 0;

	cout << "Lotto 6/45\n";
	srand(time(NULL));
	cout << rand() % 999 + 1 << "회 로또 번호를 추첨하겠습니다!!!\n";
	for (int idx = 0; idx < 7; idx++)
	{
		do {
			flag = 0;
			winning_lotto_number[idx] = rand() % 45 + 1;
			for (int jdx = 0; jdx < idx; jdx++)
			{
				if (winning_lotto_number[idx] == winning_lotto_number[jdx])
				{
					flag = 1;
					winning_lotto_number[idx] = rand() % 45 + 1;
				}
			}
		} while (flag);
		if (idx < 6)
			cout << "뚜루뚜루뚜루!!! " << idx + 1 << "번째 당첨 번호는 바로 [" << winning_lotto_number[idx] << "]입니다!!\n";
		else
			cout << "뚜루뚜루뚜루!!! " << "보너스 번호는 바로오   [" << winning_lotto_number[idx] << "]입니다!!\n";
	}

	for (int idx = 0; idx < purchase_lotto_amount; idx++)
	{
		sleep(1);
		winning_number = 0;
		for (int idx = 0; idx < 6; idx++)
			lotto_number[idx] = 0;
		for (int idx = 0; idx < 6; idx++)
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
		}

		bonus = 0;
		for (int idx = 0; idx < 6; idx++)
		{
			for (int jdx = 0; jdx < 7; jdx++)
			{
				if (lotto_number[idx] == winning_lotto_number[jdx])
				{
					if (lotto_number[idx] == winning_lotto_number[idx])
						bonus = 1;
					winning_number++;
				}
			}
		}

		if (winning_number > 5)
			rank_winning_number[0]++;
		else if (winning_number > 4 && bonus)
			rank_winning_number[1]++;
		else if (winning_number > 4)
			rank_winning_number[2]++;
		else if (winning_number > 3)
			rank_winning_number[3]++;
		else if (winning_number > 1)
			rank_winning_number[4]++;
		else
			rank_winning_number[5]++;
	}
	for (int idx = 0; idx < 6; idx++)
	{
		if (idx < 5)
			cout << "[" <<idx + 1 << "]등은 " << rank_winning_number[idx] << "명입니다.\n";
		else
			cout << "꼴등은" << rank_winning_number[idx] << "명입니다.\n";
	}
}
