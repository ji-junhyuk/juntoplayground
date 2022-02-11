/*
   야구게임 만들기
   1 ~ 9 사이에 랜덤한 숫자 3개를 얻어온다. 단, 순자는 중복되어서는 안된다.
   3개의 숫자는 * * * 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
   사용자는 이 3개의 숫자를 맞출 때까지 계속해서 3개의 숫자를 입력한다.

   만약 맞춰야할 숫자가 7 3 8 일 경우, 
   사용자는 3개의 숫자를 계속 입력한다.
   입력 : 1 2 4
   출력 : Out

   입력 : 7 5 9 (숫자와 위치가 같다)
   출력 : 1strike

   입력 : 7 8 6 (8은 숫자가 있지만, 위치가 다르므로 ball)
   출력 : 1strike, 1ball

   입력 : 0 1 2 (입력 받은 숫자 중 하나라도 0이 있으면)
   출력 : 게임 종료

   입력 : 7 3 8
   출력 : 게임 종료
*/

#include <iostream>

using namespace std;
int	main(void)
{
	ios::sync_with_stdio(false);

	int	ans[3];
	int guess[3];
	int cnt;
	int strike;
	int ball;
	int flag;

	cnt = 0;
	srand(time(NULL));
	for (int idx = 0; idx < 3; idx++)
	{
		do {
			flag = 0;
			ans[idx] = rand() % 8 + 1;
			for (int jdx = 0; jdx < idx; jdx++)
			{
				if (ans[idx] == ans[jdx])
				{
					flag = 1;
					ans[idx] = rand() % 8 + 1;
				}
			}
		} while (flag);
	}
//	cout << ans[0] << ans[1] << ans[2] << '\n';
	cout << "This is baseball game!!!\n";
	while (strike != 3)
	{
		strike = 0;
		ball = 0;
		for (int idx = 0; idx < 3; idx++)
			guess[idx] = 0;
		cout << cnt + 1 << "회전, 3개의 숫자를 입력하시오!\n:";
		for (int idx = 0; idx < 3; idx++)
		{
			do {
				flag = 0;
				cin >> guess[idx];
				if (guess[idx] == 0)
				{
					cout << "게임 종료\n";
					return (0);
				}
				else if (guess[idx] < 1 || guess[idx] > 9)
				{
					flag = 1;
					cout << "유효하지 않은 숫자입니다. 다시 입력해주세요\n:";
				}
				for (int jdx = 0; jdx < idx; jdx++)
				{
					if (guess[idx] == guess[jdx])
					{
						flag = 1;
						cout << "중복된 숫자입니다. 다시 입력해주세요\n:";
					}
				}
			} while (flag);
		}
		for (int idx = 0; idx < 3; idx++)
		{
			for (int jdx = 0; jdx < 3; jdx++)
			{
				if (ans[idx] == guess[jdx] && idx == jdx)
				{
					strike++;
					jdx++;
				}
				if (ans[idx] == guess[jdx])
					ball++;
			}
		}	
		if (strike)
			cout << strike << "strike\n";
		if (ball)
			cout << ball << "ball\n";
		if (!(strike || ball))
			cout << "Out\n";
		cnt++;
	}
	cout << "게임 종료\n";
	return (0);
}
