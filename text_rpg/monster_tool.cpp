#include <iostream>
# define NAME_SIZE 32
using namespace std;

enum MAP_TYPE
{
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_END
};

enum MAIN_MENU
{
	MM_NONE,
	MM_ADD,
	MM_LOAD,
	MM_SAVE,
	MM_OUTPUT,
	MM_EXIT
};

struct _tag_monster
{
	char	str_name[NAME_SIZE];
	int     i_attack_min;
	int     i_attack_max;
	int     i_armor_min;
	int     i_armor_max;
	int     i_hp;
	int     i_hp_max;
	int     i_mp;
	int     i_mp_max;
	int     i_level;
	int     i_exp;
	int     i_gold_min;
	int     i_gold_max;
};

int get_input()
{
	int i_input;

	cin >> i_input;
	if (cin.fail())
	{
			cin.clear();
			cin.ignore(1024, '\n');
			return INT_MAX;
	}

	return i_input;
}

void add_monster(_tag_monster *p_monster_arr)
{
	int	i_map = 0;

	while (true)
	{
		system("cls");
		cout << "1. 쉬움" << '\n';
		cout << "2. 보통" << '\n';
		cout << "3. 어려움" << '\n';
		cout << "4. 취소" << '\n';
		cout << "추가할 난이도를 선택하세요 : ";
		i_map = get_input();

		if (i_map == 4)
			return ;
		else if (i_map < 1 || i_map > 4)
			continue ;
		--i_map;
		break ;
	}
	cin.clear();
	cin.ignore(1024, '\n');
	cout << "이름 : ";
	cin.getline(p_monster_arr[i_map].str_name, NAME_SIZE - 1);
	cout << "최소공격력 : ";
	p_monster_arr[i_map].i_attack_min = get_input();
	cout << "최대공격력 : ";
	p_monster_arr[i_map].i_attack_max = get_input();
	cout << "최소방어력 : ";
	p_monster_arr[i_map].i_armor_min = get_input();
	cout << "최대방어력 : ";
	p_monster_arr[i_map].i_armor_max = get_input();
	cout << "체력 : ";
	p_monster_arr[i_map].i_hp = get_input();
	p_monster_arr[i_map].i_hp_max = p_monster_arr[i_map].i_hp;
	cout << "마나 : ";
	p_monster_arr[i_map].i_mp = get_input();
	p_monster_arr[i_map].i_mp_max = p_monster_arr[i_map].i_mp;
	cout << "레벨 : ";
	p_monster_arr[i_map].i_level = get_input();
	cout << "획득경험치 : ";
	p_monster_arr[i_map].i_exp = get_input();
	cout << "획득 최소 골드 : ";
	p_monster_arr[i_map].i_gold_min = get_input();
	cout << "획득 최대 골드 : ";
	p_monster_arr[i_map].i_gold_max = get_input();
	cout << "몬스터 추가 완료" << '\n';
	system("pause");
}

bool save_monster(_tag_monster *p_monster_arr)
{
	FILE	*p_file = NULL;
	fopen_s(&p_file, "Monster.mst", "wb");
	if (p_file)
	{
		fwrite(p_monster_arr, sizeof(_tag_monster), MT_END, p_file);
		fclose(p_file);
		return (true);
	}
	return false;
}

bool load_monster(_tag_monster *p_monster_arr)
{
	FILE	*p_file = NULL;
	fopen_s(&p_file, "Monster.mst", "rb");
	if (p_file)
	{
		fread(p_monster_arr, sizeof(_tag_monster), MT_END, p_file);
		fclose(p_file);
		return (true);
	}
	return false;
}

void output_monster_info(_tag_monster* p_monster)
{
        cout << "이름 : " << p_monster->str_name << "\t레벨 : " << p_monster->i_level << '\n';
        cout << "공격력 : " << p_monster->i_attack_min << " - " << p_monster->i_attack_max << "\t방어력 : " << p_monster->i_armor_min << " - " << p_monster->i_armor_max << '\n';
        cout << "체력 : " << p_monster->i_hp << " / " << p_monster->i_hp_max << "\t마나 : " << p_monster->i_mp << " / " << p_monster->i_mp_max << '\n';
        cout << "획득경험치 : " << p_monster->i_exp << "\t획득골드 : " << p_monster->i_gold_min << " - " << p_monster->i_gold_max << '\n' << endl;
};
void output_monster(_tag_monster *p_monster_arr)
{
	system("cls");
	cout << "====================== Monster ======================" << '\n';
	for (int idx = 0; idx < MT_END; ++idx)
	{
		output_monster_info(&p_monster_arr[idx]);
	}
	system("pause");
}

int main(void)
{
	_tag_monster t_monster[MT_END] = {};

	while (true)
	{
		system("cls");
		cout << "1. 몬스터 추가" << '\n';
		cout << "2. 읽어오기" << '\n';
		cout << "3. 저장" << '\n';
		cout << "4. 몬스터 출력" << '\n';
		cout << "5. 종료" << '\n';
		cout << "메뉴를 선택하세요 : ";
		int i_menu = get_input();
		if (i_menu == MM_EXIT)
			break ;
		switch (i_menu)
		{
			case MM_ADD:
				add_monster(t_monster);
				break;
			case MM_LOAD:
				load_monster(t_monster);
				break;
			case MM_SAVE:
				save_monster(t_monster);
				break;
			case MM_OUTPUT:
				output_monster(t_monster);
				break;
		}
	}
	save_monster(t_monster);
}
