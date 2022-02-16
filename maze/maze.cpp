#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
struct _tagPoint
{
	int x;
	int y;
};

typedef _tagPoint  POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer
{
	_tagPoint 	t_pos;
	bool 		b_wall_push;
	bool 		b_push_on_off;
	bool 		b_transparency;
	int  		i_bomb_power;
} PLAYER, *PPLAYER;

void set_maze(char maze[21][21], PPLAYER p_player, PPOINT p_start_pos,
	PPOINT p_end_pos)
{
	p_start_pos->x = 0;
	p_start_pos->y = 0;
	p_end_pos->x = 19;
	p_end_pos->y = 19;

	p_player->t_pos = *p_start_pos;

	strcpy_s(maze[0],  "21100010000100010000\0");
	strcpy_s(maze[1],  "00111011111100001000\0");
	strcpy_s(maze[2],  "00100010000110011100\0");
	strcpy_s(maze[3],  "01101010000111000100\0");
	strcpy_s(maze[4],  "01000011110001111100\0");
	strcpy_s(maze[5],  "01001110001111000000\0");
	strcpy_s(maze[6],  "01101101001000000000\0");
	strcpy_s(maze[7],  "00101001001111111000\0");
	strcpy_s(maze[8],  "00001110000000001000\0");
	strcpy_s(maze[9],  "01001011111111111000\0");
	strcpy_s(maze[10], "01010101010000000000\0");
	strcpy_s(maze[11], "01111100111111100000\0");
	strcpy_s(maze[12], "00000111100000111110\0");
	strcpy_s(maze[13], "01000001101110000010\0");
	strcpy_s(maze[14], "01100110001111111110\0");
	strcpy_s(maze[15], "01110110011000000000\0");
	strcpy_s(maze[16], "00000010010000000000\0");
	strcpy_s(maze[17], "00101000011111000000\0");
	strcpy_s(maze[18], "01010000100001100000\0");
	strcpy_s(maze[19], "11001001000000111113\0");
	strcpy_s(maze[20], "\0");
}

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 물줄기 아이템
6 : 벽밀기 아이템
7 : 투명 아이템
*/

void print_maze(char maze[21][21], PPLAYER p_player)
{
	for (int idx = 0; idx < 21; ++idx)
	{
		for (int jdx = 0; jdx < 21; ++jdx)
		{
			if (maze[idx][jdx] == '4')
				cout << "♨";
			else if (p_player->t_pos.x == jdx && p_player->t_pos.y == idx)
				cout << "☆";
			else if (maze[idx][jdx] == '0')
				cout << "■";
			else if (maze[idx][jdx] == '1')
				cout << " ";
			else if (maze[idx][jdx] == '2')
				cout << "★";
			else if (maze[idx][jdx] == '3')
				cout << "#";
			else if (maze[idx][jdx] == '5')
				cout << "P";
			else if (maze[idx][jdx] == '6')
				cout << "※";
			else if (maze[idx][jdx] == '7')
				cout << "▷";
		}
		cout << '\n';
	}
	cout << "물줄기(P) : " << p_player->i_bomb_power << '\n';
	cout << "투명 능력(▷) : ";
	if (p_player->b_transparency)
		cout << "사용\n";
	else
		cout << "불가\n";

	cout << "벽밀기 능력(※): ";
	if (p_player->b_wall_push)
	{
		cout << "있음 / ";
		if (p_player->b_push_on_off)
			cout << "ON" << '\n' << '\n';
		else
			cout << "OFF" << '\n' << '\n';
	}
	else
		cout << "없음 / OFF" << '\n' << '\n';
}

bool add_item(char c_item_type, PPLAYER p_player)
{
	if (c_item_type == '5')
	{
		if (p_player->i_bomb_power < 10)
			++p_player->i_bomb_power;
		return true;
	}

	else if (c_item_type == '6')
	{
		p_player->b_wall_push = true;
		p_player->b_push_on_off = true;
		return true;
	}

	else if (c_item_type == '7')
	{
		p_player->b_transparency = true;
		return true;
	}
	return false;
}

void move_up(char maze[21][21], PPLAYER p_player)
{
	if (p_player->t_pos.y - 1 >= 0)
	{
		if (maze[p_player->t_pos.y - 1][p_player->t_pos.x] != '0' &&
			maze[p_player->t_pos.y - 1][p_player->t_pos.x] != '4')
		{
			--p_player->t_pos.y;
		}
		else if (p_player->b_wall_push && maze[p_player->t_pos.y - 1][p_player->t_pos.x] == '0')
		{
			if (p_player->b_push_on_off)
			{
				if (p_player->t_pos.y - 2 >= 0)
				{
					if (maze[p_player->t_pos.y - 2][p_player->t_pos.x] == '0')
					{
						if (p_player->b_transparency)
							--p_player->t_pos.y;
					}
					else if (maze[p_player->t_pos.y - 2][p_player->t_pos.x] == '1')
					{
						maze[p_player->t_pos.y - 2][p_player->t_pos.x] = '0';
						maze[p_player->t_pos.y - 1][p_player->t_pos.x] = '1';
						--p_player->t_pos.y;
					}
				}
				else if(p_player->b_transparency)
					--p_player->t_pos.y;
			}
			else if (p_player->b_transparency)
				--p_player->t_pos.y;
		}
		else if (p_player->b_transparency)
			--p_player->t_pos.y;
		if (add_item(maze[p_player->t_pos.y][p_player->t_pos.x], p_player))
			maze[p_player->t_pos.y][p_player->t_pos.x] = '1';
	}
}

void move_down(char maze[21][21], PPLAYER p_player)
{
	if (p_player->t_pos.y + 1 < 20)
	{
		if (maze[p_player->t_pos.y + 1][p_player->t_pos.x] != '0' && maze[p_player->t_pos.y + 1][p_player->t_pos.x] != '4')
			++p_player->t_pos.y;
		else if (p_player->b_wall_push && maze[p_player->t_pos.y + 1][p_player->t_pos.x] == '0')
		{
			if (p_player->b_push_on_off)
			{
				if (p_player->t_pos.y + 2 < 20)
				{
					if (maze[p_player->t_pos.y + 2][p_player->t_pos.x] == '0')
					{
						if (p_player->b_transparency)
							++p_player->t_pos.y;
					}
					else if (maze[p_player->t_pos.y + 2][p_player->t_pos.x] == '1')
					{
						maze[p_player->t_pos.y + 2][p_player->t_pos.x] = '0';
						maze[p_player->t_pos.y + 1][p_player->t_pos.x] = '1';
						++p_player->t_pos.y;
					}
				}
				else if (p_player->b_transparency)
					++p_player->t_pos.y;
			}
			else if (p_player->b_transparency)
				++p_player->t_pos.y;
		}
		else if (p_player->b_transparency)
			++p_player->t_pos.y;
		if (add_item(maze[p_player->t_pos.y][p_player->t_pos.x], p_player))
			maze[p_player->t_pos.y][p_player->t_pos.x] = '1';
	}
}

void move_right(char maze[21][21], PPLAYER p_player)
{
	if (p_player->t_pos.x + 1 < 20)
	{
		if (maze[p_player->t_pos.y][p_player->t_pos.x + 1] != '0' && maze[p_player->t_pos.y][p_player->t_pos.x + 1] != '4')
			++p_player->t_pos.x;
		else if (p_player->b_wall_push && maze[p_player->t_pos.y][p_player->t_pos.x + 1] == '0')
		{
			if (p_player->b_push_on_off)
			{
				if (p_player->t_pos.x + 2 < 20)
				{
					if (maze[p_player->t_pos.y][p_player->t_pos.x + 2] == '0')
					{
						if (p_player->b_transparency)
							++p_player->t_pos.x;
					}
					else if (maze[p_player->t_pos.y][p_player->t_pos.x + 2] == '1')
					{
						maze[p_player->t_pos.y][p_player->t_pos.x + 2] = '0';
						maze[p_player->t_pos.y][p_player->t_pos.x + 1] = '1';
						++p_player->t_pos.x;
					}
				}
				else if (p_player->b_transparency)
					++p_player->t_pos.x;
			}
			else if (p_player->b_transparency)
				++p_player->t_pos.x;
		}
		else if (p_player->b_transparency)
			++p_player->t_pos.x;
		if (add_item(maze[p_player->t_pos.y][p_player->t_pos.x], p_player))
			maze[p_player->t_pos.y][p_player->t_pos.x] = '1';
	}
}

void move_left(char maze[21][21], PPLAYER p_player)
{
	if (p_player->t_pos.x - 1 >= 0)
	{
		if (maze[p_player->t_pos.y][p_player->t_pos.x - 1] != '0' && maze[p_player->t_pos.y][p_player->t_pos.x - 1] != '4')
			--p_player->t_pos.x;
		else if (p_player->b_wall_push && maze[p_player->t_pos.y][p_player->t_pos.x - 1] == '0')
		{
			if (p_player->b_push_on_off)
			{
				if (p_player->t_pos.x - 2 >= 0)
				{
					if (maze[p_player->t_pos.y][p_player->t_pos.x - 2] == '0')
					{
						if (p_player->b_transparency)
							--p_player->t_pos.x;
					}
					else if (maze[p_player->t_pos.y][p_player->t_pos.x - 2] == '1')
					{
						maze[p_player->t_pos.y][p_player->t_pos.x - 2] = '0';
						maze[p_player->t_pos.y][p_player->t_pos.x - 1] = '1';
						--p_player->t_pos.x;
					}
				}
				else if (p_player->b_transparency)
					--p_player->t_pos.x;
			}
			else if (p_player->b_transparency)
				--p_player->t_pos.x;
		}
		else if (p_player->b_transparency)
			--p_player->t_pos.x;
		if (add_item(maze[p_player->t_pos.y][p_player->t_pos.x], p_player))
			maze[p_player->t_pos.y][p_player->t_pos.x] = '1';
	}
}

void move_player(char maze[21][21], PPLAYER p_player, char c_input)
{
	switch (c_input)
	{
		case 72:
			move_up(maze, p_player);
			break;
		case 80:
			move_down(maze, p_player);
			break;
		case 75:
			move_left(maze, p_player);
			break;
		case 77:
			move_right(maze, p_player);
			break;
	}
}

void create_bomb(char maze[21][21], const PPLAYER p_player, PPOINT p_bomb_arr, int* p_bomb_count)
{
	if (*p_bomb_count == 10)
		return;
	else if (maze[p_player->t_pos.y][p_player->t_pos.x] == '0')
		return;
	for (int idx = 0; idx < *p_bomb_count; ++idx)
	{
		if (p_player->t_pos.x == p_bomb_arr[idx].x && 
			p_player->t_pos.y == p_bomb_arr[idx].y)
			return;
	}
	p_bomb_arr[*p_bomb_count] = (*p_player).t_pos;
	++(*p_bomb_count);
	maze[p_player->t_pos.y][p_player->t_pos.x] = '4';
}

void fire_bomb(char maze[21][21], PPLAYER p_player, PPOINT p_bomb_arr, int* p_bomb_count)
{
	for (int idx = 0; idx < *p_bomb_count; ++idx)
	{
		maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x] = '1';
		for (int jdx = 1; jdx <= p_player->i_bomb_power; ++jdx)
		{
			if (p_bomb_arr[idx].y - jdx >= 0)
			{
				if (maze[p_bomb_arr[idx].y - jdx][p_bomb_arr[idx].x] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							maze[p_bomb_arr[idx].y - jdx][p_bomb_arr[idx].x] = '5';
						else if (iPercent < 70)
							maze[p_bomb_arr[idx].y - jdx][p_bomb_arr[idx].x] = '6';
						else
							maze[p_bomb_arr[idx].y - jdx][p_bomb_arr[idx].x] = '7';
					}
					else
						maze[p_bomb_arr[idx].y - jdx][p_bomb_arr[idx].x] = '1';
				}
				if (p_player->t_pos.x == p_bomb_arr[idx].x && p_player->t_pos.y == p_bomb_arr[idx].y - jdx)
				{
					p_player->t_pos.x = 0;
					p_player->t_pos.y = 0;
				}
			}
			if (p_bomb_arr[idx].y + jdx < 20)
			{
				if (maze[p_bomb_arr[idx].y + jdx][p_bomb_arr[idx].x] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							maze[p_bomb_arr[idx].y + jdx][p_bomb_arr[idx].x] = '5';
						else if (iPercent < 70)
							maze[p_bomb_arr[idx].y + jdx][p_bomb_arr[idx].x] = '6';

						else
							maze[p_bomb_arr[idx].y + jdx][p_bomb_arr[idx].x] = '7';
					}
					else
						maze[p_bomb_arr[idx].y + jdx][p_bomb_arr[idx].x] = '1';
				}
				if (p_player->t_pos.x == p_bomb_arr[idx].x && p_player->t_pos.y == p_bomb_arr[idx].y + jdx)
				{
					p_player->t_pos.x = 0;
					p_player->t_pos.y = 0;
				}
			}
			if (p_bomb_arr[idx].x - jdx >= 0)
			{
				if (maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x - jdx] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x - jdx] = '5';
						else if (iPercent < 70)
							maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x - jdx] = '6';
						else
							maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x - jdx] = '7';
					}
					else
						maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x - jdx] = '1';
				}
				if (p_player->t_pos.x == p_bomb_arr[idx].x - jdx && p_player->t_pos.y == p_bomb_arr[idx].y)
				{
					p_player->t_pos.x = 0;
					p_player->t_pos.y = 0;
				}
			}
			if (p_bomb_arr[idx].x + jdx < 20)
			{
				if (maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x + jdx] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 40)
							maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x + jdx] = '5';
						else if (iPercent < 70)
							maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x + jdx] = '6';
						else
							maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x + jdx] = '7';
					}
					else
						maze[p_bomb_arr[idx].y][p_bomb_arr[idx].x + jdx] = '1';
				}
				if (p_player->t_pos.x == p_bomb_arr[idx].x + jdx && p_player->t_pos.y == p_bomb_arr[idx].y)
				{
					p_player->t_pos.x = 0;
					p_player->t_pos.y = 0;
				}
			}
		}
	}
	*p_bomb_count = 0;
}

int main()
{
	srand((unsigned int)time(0));

	char str_maze[21][21] = {};

	PLAYER t_player = {};
	POINT t_start_pos;
	POINT t_end_pos;

	t_player.i_bomb_power = 1;

	int i_bomb_count= 0;
	POINT t_bomb_pos[10] = {};

	set_maze(str_maze, &t_player, &t_start_pos, &t_end_pos);

	while (true)
	{
		system("cls");
		print_maze(str_maze, &t_player);
		if (t_player.t_pos.x == t_end_pos.x && t_player.t_pos.y == t_end_pos.y)
		{
			cout << "도착했습니다." << '\n';
			system("pause");
			break;
		}
		cout << "[키 조작 방법]\n";
		cout << "종료              : q, Q\n";
		cout << "폭탄 설치         : space\n";
		cout << "폭탄 터뜨리기     : a, A\n";
		cout << "벽 밀기 ON / OFF  : i, I\n";
		cout << "방향키로 움직입니다.\n";
		char c_input = _getch();
		if (c_input == 'q' || c_input == 'Q')
			break;
		else if (c_input == ' ')
			create_bomb(str_maze, &t_player, t_bomb_pos, &i_bomb_count);
		else if (c_input == 'a' || c_input == 'A')
			fire_bomb(str_maze, &t_player, t_bomb_pos, &i_bomb_count);
		else if (c_input == 'i' || c_input == 'I')
		{
			if (t_player.b_wall_push)
				t_player.b_push_on_off = !t_player.b_push_on_off;
		}
		else
			move_player(str_maze, &t_player, c_input);
	}
	return 0;
}
