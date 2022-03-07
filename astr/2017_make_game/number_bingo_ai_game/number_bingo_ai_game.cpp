/*
   AI와 빙고게임.
   난이도를 선택한다. easy, normal.
   플레이어가 선택 후 AI가 선택한다.

   easy모드는 AI가 선택하지 않은 숫자 중 랜덤하게 선택한다.
   normal모드는 AI가 모든 라인을 조사해서 완성할 가능성이 제일 높은 라인을 선택한다.
*/

#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

enum level 
{
	easy_mode,
	normal_mode
};

int	check_board(int ai_board[25])
{
	int find_max[4];
	int check_line[5];
	int flag[2];
	int start[2];
	
	for (int idx = 0; idx < 2; idx++)
		start[idx] = 0;
	for (int idx = 0; idx < 2; idx++)
		flag[idx] = 0;
	for (int idx = 0; idx < 5; idx++)
		check_line[idx] = 0;
	for (int idx = 0; idx < 4; idx++)
		find_max[idx] = 0;
	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (ai_board[idx * 5 + jdx] == INT_MAX)
				check_line[idx] += 1;
		}
	}
	int row_max = 0;
	for (int idx = 0; idx < 5; idx++)
	{
		if (check_line[idx] > row_max && check_line[idx] != 5)
		{
			row_max = check_line[idx];
			start[0] = idx;
		}
	}

	for (int idx = 0; idx < 5; idx++)
		check_line[idx] = 0;

	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (ai_board[idx + 5 * jdx] == INT_MAX)
				check_line[idx] += 1;
		}
	}
	int col_max = 0;
	for (int idx = 0; idx < 5; idx++)
	{
		if (check_line[idx] > col_max && check_line[idx] != 5)
		{
			col_max = check_line[idx];
			start[1] = idx;
		}
	}
	for (int idx = 0; idx < 25; idx++)
	{
		if (idx % 6 == 0 && ai_board[idx] == INT_MAX)
			flag[0]++;
		if (idx != 0 && idx != 24 && (idx % 4 == 0) && ai_board[idx] == INT_MAX)
			flag[1]++;
	}
	int diag_max = 0;
	if (diag_max < flag[0] && flag[0] != 5)
		diag_max = flag[0];
	if (diag_max < flag[1] && flag[1] != 5)
		diag_max = flag[1];
	int optimal_line;
	optimal_line = 0;
	find_max[0] = row_max;	
	find_max[1] = col_max;	
	find_max[2] = flag[0];	
	find_max[3] = flag[1];	

	optimal_line = 0;
	for (int idx = 0; idx < 4; idx++)
	{
		if (optimal_line < find_max[idx])
			optimal_line = find_max[idx];
	}
	for (int idx = 0; idx < 4; idx++)
		cout << "find_max[" << idx << "]" <<find_max[idx] << '\n';
	cout << "optimal_line:[" << optimal_line << "]\n";
	if (optimal_line == find_max[0])
	{
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (ai_board[start[0] * 5 + jdx] != INT_MAX)
			{
				cout << "QWE1\n";
				cout << "start:" << start[0] << '\n';
				return (ai_board[start[0] * 5 + jdx]);
			}
		}
	}
	else if (optimal_line == find_max[1])
	{
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (ai_board[start[1] + jdx * 5] != INT_MAX)
			{
				cout << "QWE2\n";
				cout << "start:" << start[1] << '\n';
				return (ai_board[start[1] + jdx * 5]);
			}
		}
	}
	else if (optimal_line == find_max[2])
	{
		for (int idx = 0; idx < 25; idx++)
		{
			if (idx % 6 == 0 && ai_board[idx] != INT_MAX)
			{
				cout << "QWE3\n";
				return (ai_board[idx]);
			}
		}
	}
	else
	{
		for (int idx = 0; idx < 25; idx++)
		{
			if (idx != 0 && idx != 24 && (idx % 4 == 0) && ai_board[idx] != INT_MAX)
			{
				cout << "QWE4\n";
				return (ai_board[idx]);
			}
		}
	}
}

int	check_bingo(int player_board[25], int ai_board[25])
{
	int player_bingo_number;
	int ai_bingo_number;
	int player_flag[4];
	int ai_flag[4];

	player_bingo_number = 0;
	ai_bingo_number = 0;
	for (int idx = 0; idx < 5; idx++)
	{
		player_flag[0] = 1; // 세로줄
		player_flag[1] = 1; // 가로줄
		ai_flag[0] = 1;
		ai_flag[1] = 1;
		for (int jdx = 0; jdx < 5; jdx++)
		{
			if (player_board[idx + 5 * jdx] != INT_MAX)
				player_flag[0] = 0;
			if (player_board[idx * 5 + jdx] != INT_MAX)
				player_flag[1] = 0;
			if (ai_board[idx + 5 * jdx] != INT_MAX)
				ai_flag[0] = 0;
			if (ai_board[idx * 5 + jdx] != INT_MAX)
				ai_flag[1] = 0;
		}
		if (player_flag[0])
			player_bingo_number++;
		if (player_flag[1])
			player_bingo_number++;
		if (ai_flag[0])
		{
			cout << "1231\n";
			ai_bingo_number++;
		}
		if (ai_flag[1])
		{
			cout << "1232\n";
			ai_bingo_number++;
		}
	}
	player_flag[2] = 1; // \줄
	player_flag[3] = 1; // /줄
	ai_flag[2] = 1;
	ai_flag[3] = 1;
	for (int idx = 0; idx < 25; idx++)
	{
		if (idx % 6 == 0 && player_board[idx] != INT_MAX)
			player_flag[2] = 0;
		if (idx != 0 && idx != 24 && (idx % 4 == 0) && player_board[idx] != INT_MAX)
			player_flag[3] = 0;
		if (idx % 6 == 0 && ai_board[idx] != INT_MAX)
			ai_flag[2] = 0;
		if (idx != 0 && idx != 24 && (idx % 4 == 0) && ai_board[idx] != INT_MAX)
			ai_flag[3] = 0;
	}
	if (player_flag[2])
		player_bingo_number++;
	if (player_flag[3])
		player_bingo_number++;
	if (ai_flag[2])
	{
		cout << "1233\n";
		ai_bingo_number++;
	}
	if (ai_flag[3])
	{
		cout << "1234\n";
		ai_bingo_number++;
	}
	cout << "player_bingo_number:" << player_bingo_number << '\n';
	cout << "ai_bingo_number:" << ai_bingo_number << '\n';
	if (player_bingo_number >= 5 || ai_bingo_number >= 5)
		return (1);
	return (0);
}
int main(void)
{
	int player_board[25];
	int ai_board[25];
	int selected_number[25];
	int game_level;
	int order;

	for (int idx = 0; idx < 25; idx++)
		selected_number[idx] = idx + 1;
	order = -1;
	cout << "빙고 듀얼 게임에 오신 것을 환영합니다!!\n";
	do {
	cout << "easy_mode:0, normal_mode:1, 게임 종료:2\n";
	cin >> game_level;
	} while (game_level < 0 || game_level > 2);
	if (game_level == 2)
		return (0);
	cout << game_level;
	for (int idx = 0; idx < 25; idx++)
		player_board[idx] = idx + 1;
	for (int idx = 0; idx < 25; idx++)
		ai_board[idx] = idx + 1;
	cout << "========================Player=========================\n";
	for (int idx = 0; idx < 100; idx++)
	{
		int temp;
		int shuffle_idx;
		int shuffle_jdx;

		shuffle_idx = rand() % 25;
		shuffle_jdx = rand() % 25;
		temp = player_board[shuffle_idx];
		player_board[shuffle_idx] = player_board[shuffle_jdx];
		player_board[shuffle_jdx] = temp;
	}
	for (int idx = 0; idx < 100; idx++)
	{
		int temp;
		int shuffle_idx;
		int shuffle_jdx;

		shuffle_idx = rand() % 25;
		shuffle_jdx = rand() % 25;
		temp = ai_board[shuffle_idx];
		ai_board[shuffle_idx] = ai_board[shuffle_jdx];
		ai_board[shuffle_jdx] = temp;
	}
	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
			cout << player_board[idx * 5 + jdx] << '\t';
		cout << '\n';
	}
	cout << '\n';
	cout << "========================AI=========================\n";
	for (int idx = 0; idx < 5; idx++)
	{
		for (int jdx = 0; jdx < 5; jdx++)
			cout << ai_board[idx * 5 + jdx] << '\t';
		cout << '\n';
	}
	if (game_level == 0)
	{
		while (1)
		{
			++order;
			int select_number;
			if (check_bingo(player_board, ai_board))
				break ;
			if (order % 2 == 0)
			{
				cout << "Player가 선택할 차례입니다.\n";
				int user_select;
				cin >> user_select;
				cout << "Player는 [" << user_select << "]를 선택했습니다.\n";
				selected_number[user_select - 1] = 0;
				select_number = user_select;
			}
			else
			{
				cout << "AI가 선택할 차례입니다.\n";
				int computer_select;
				computer_select = rand() % 25 + 1;
				while (1)
				{
					if (selected_number[computer_select - 1])
						break ;
					computer_select = rand() % 25 + 1;
				}
				selected_number[computer_select - 1] = 0;
				cout << "AI는 [" << computer_select << "]를 선택했습니다.\n";
				select_number = computer_select;
				Sleep(5000);
			}
			for (int idx = 0; idx < 25; idx++)
				if (select_number == player_board[idx])
					player_board[idx] = INT_MAX;
			for (int idx = 0; idx < 25; idx++)
				if (select_number == ai_board[idx])
					ai_board[idx] = INT_MAX;
			cout << "========================Player=========================\n";
			for (int idx = 0; idx < 5; idx++)
			{
				for (int jdx = 0; jdx < 5; jdx++)
				{
					if (player_board[idx * 5 + jdx] != INT_MAX)
						cout << player_board[idx * 5 + jdx] << '\t';
					else
						cout << "*\t";
				}
				cout << '\n';
			}
			cout << "========================AI=========================\n";
			for (int idx = 0; idx < 5; ++idx)
			{
				for (int jdx = 0; jdx < 5; ++jdx)
				{
					if (ai_board[idx * 5 + jdx] != INT_MAX)
						cout << ai_board[idx * 5 + jdx] << '\t';
					else
						cout << "*\t";
				}
				cout << '\n';
			}
		}
	}
	else
	{
		while (1)
		{
			int select_number;
			
			++order;
			if (check_bingo(player_board, ai_board))
				break ;
			if (order % 2 == 0)
			{
				cout << "Player가 선택할 차례입니다.\n";
				int user_select;
				cin >> user_select;
				cout << "Player는 [" << user_select << "]를 선택했습니다.\n";
				selected_number[user_select - 1] = 0;
				select_number = user_select;
			}
			else
			{
				cout << "AI가 선택할 차례입니다.\n";
				int computer_select;
				computer_select = check_board(ai_board);
				cout << "AI는 [" << computer_select << "]를 선택했습니다.\n";
				select_number = computer_select;
			}
			for (int idx = 0; idx < 25; idx++)
				if (select_number == player_board[idx])
					player_board[idx] = INT_MAX;
			for (int idx = 0; idx < 25; idx++)
				if (select_number == ai_board[idx])
					ai_board[idx] = INT_MAX;
			cout << "========================Player=========================\n";
			for (int idx = 0; idx < 5; idx++)
			{
				for (int jdx = 0; jdx < 5; jdx++)
				{
					if (player_board[idx * 5 + jdx] != INT_MAX)
						cout << player_board[idx * 5 + jdx] << '\t';
					else
						cout << "*\t";
				}
				cout << '\n';
			}
			cout << "========================AI=========================\n";
			for (int idx = 0; idx < 5; ++idx)
			{
				for (int jdx = 0; jdx < 5; ++jdx)
				{
					if (ai_board[idx * 5 + jdx] != INT_MAX)
						cout << ai_board[idx * 5 + jdx] << '\t';
					else
						cout << "*\t";
				}
				cout << '\n';
			}	
		}
	}
	cout << "end\n";
}
