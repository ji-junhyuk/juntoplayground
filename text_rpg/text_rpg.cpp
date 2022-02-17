#include "text_rpg.h"
#include <iostream>
#include <time.h>

enum GAME_MODE
{
	GM_NONE,
	GM_NEW,
	GM_LOAD,
	GM_END
};

bool save_player(_tag_player *p_player)
{
	FILE *p_file = NULL;
	
	fopen_s(&p_file, "Player.ply", "wb");

	if (p_file)
	{
		fwrite(p_player->str_name, 1, NAME_SIZE, p_file);
		fwrite(&p_player->e_job, sizeof(JOB), 1, p_file);
		fwrite(p_player->str_job_name, 1, NAME_SIZE, p_file);
		fwrite(&p_player->i_attack_min, 4, 1, p_file);
		fwrite(&p_player->i_attack_max, 4, 1, p_file);
		fwrite(&p_player->i_armor_min, 4, 1, p_file);
		fwrite(&p_player->i_armor_max, 4, 1, p_file);
		fwrite(&p_player->i_hp_max, 4, 1, p_file);
		fwrite(&p_player->i_hp, 4, 1, p_file);
		fwrite(&p_player->i_mp_max, 4, 1, p_file);
		fwrite(&p_player->i_mp, 4, 1, p_file);
		fwrite(&p_player->i_exp, 4, 1, p_file);
		fwrite(&p_player->i_level, 4, 1, p_file);
		fwrite(&p_player->b_equip[EQ_WEAPON], 4, 1, p_file);
		if (p_player->b_equip[EQ_WEAPON])
			fwrite(&p_player->t_equip[EQ_WEAPON], sizeof(_tag_item), 1, p_file);
		fwrite(&p_player->b_equip[EQ_ARMOR], 4, 1, p_file);
		if (p_player->b_equip[EQ_ARMOR])
			fwrite(&p_player->b_equip[EQ_ARMOR], sizeof(_tag_item), 1, p_file);
		fwrite(&p_player->t_inventory.i_gold, 4, 1, p_file);
		fwrite(&p_player->t_inventory.i_item_count, 4, 1, p_file);
		fwrite(p_player->t_inventory.t_item, sizeof(_tag_item), p_player->t_inventory.i_item_count, p_file);
		fclose(p_file);
		return (true);
	}
	return (false);
}

bool load_player(_tag_player *p_player)
{
	FILE *p_file = NULL;

	fopen_s(&p_file, "Player.ply", "rb");

	if (p_file)
	{
		fread(p_player->str_name, 1, NAME_SIZE, p_file);
		fread(&p_player->e_job, sizeof(JOB), 1, p_file);
		fread(p_player->str_job_name, 1, NAME_SIZE, p_file);
		fread(&p_player->i_attack_min, 4, 1, p_file);
		fread(&p_player->i_attack_max, 4, 1, p_file);
		fread(&p_player->i_armor_min, 4, 1, p_file);
		fread(&p_player->i_armor_max, 4, 1, p_file);
		fread(&p_player->i_hp_max, 4, 1, p_file);
		fread(&p_player->i_hp, 4, 1, p_file);
		fread(&p_player->i_mp_max, 4, 1, p_file);
		fread(&p_player->i_mp, 4, 1, p_file);
		fread(&p_player->i_exp, 4, 1, p_file);
		fread(&p_player->i_level, 4, 1, p_file);
		fread(&p_player->b_equip[EQ_WEAPON], 4, 1, p_file);
		if (p_player->b_equip[EQ_WEAPON])
			fread(&p_player->t_equip[EQ_WEAPON], sizeof(_tag_item), 1, p_file);
		fread(&p_player->b_equip[EQ_ARMOR], 4, 1, p_file);
		if (p_player->b_equip[EQ_ARMOR])
			fread(&p_player->b_equip[EQ_ARMOR], sizeof(_tag_item), 1, p_file);
		fread(&p_player->t_inventory.i_gold, 4, 1, p_file);
		fread(&p_player->t_inventory.i_item_count, 4, 1, p_file);
		fread(p_player->t_inventory.t_item, sizeof(_tag_item), p_player->t_inventory.i_item_count, p_file);
		fclose(p_file);
		return true;
	}
	return false;
}

int main()
{
	srand((unsigned int)time(0));

	_tag_player t_player = {};
	int i_game_mode = 0;
	while (i_game_mode < 1 || i_game_mode >= GM_END)
	{
		system("cls");
		cout << "1. 새로하기" << '\n';
		cout << "2. 이어하기" << '\n';
		cout << "3. 종료" << '\n';
		cout << "게임모드를 선택하세요. : ";
		i_game_mode = get_input();
	}
	if (i_game_mode == GM_END)
		return 0;
	switch (i_game_mode)
	{
		case GM_NEW:
			set_player(&t_player);
			break ;
		case GM_LOAD:
			if (!load_player(&t_player))
				cout << "플레이어 파일 오류!!" << '\n';
			break ;
	}
	_tag_monster t_monster_arr[MT_BACK - 1] = {};
	g_t_level_up_table[JOB_KNIGHT - 1] = create_level_up_status(4, 10, 8, 16, 50, 100, 10, 20);
	g_t_level_up_table[JOB_ARCHER - 1] = create_level_up_status(10, 15, 5, 10, 30, 60, 30, 50);
	g_t_level_up_table[JOB_WIZARD - 1] = create_level_up_status(15, 20, 3, 7, 20, 40, 50, 100);
	_tag_item	t_store_weapon[STORE_WEAPON_MAX] = {};
	_tag_item	t_store_armor[STORE_ARMOR_MAX] = {};
	t_store_weapon[0] = create_item("목검", IT_WEAPON, 5, 10, 1000, 500, "나무로 만든 칼");
	t_store_weapon[1] = create_item("장궁", IT_WEAPON, 20, 10, 7000, 3500, "짱짱한 활");
	t_store_weapon[2] = create_item("지팡이", IT_WEAPON, 90, 150, 30000, 15000, "나무로 만든 지팡이");
	t_store_armor[0] = create_item("천갑옷", IT_ARMOR, 2, 5, 1000, 500, "천으로 만든 허접한 갑옷");
	t_store_armor[1] = create_item("가죽갑옷", IT_ARMOR, 10, 20, 7000, 3500, "동물 가죽으로 만든 질긴 갑옷");
	t_store_armor[2] = create_item("풀플레이트아머", IT_ARMOR, 70, 90, 30000, 15000, "강철로 만든 판금갑옷");
	set_monster(t_monster_arr);
	bool b_loop = true;
	while (b_loop)
	{
		switch (output_main_menu())
		{
			case MM_MAP:
				loop_map(&t_player, t_monster_arr);
				break;
			case MM_STORE:
				run_store(&t_player.t_inventory, t_store_weapon, t_store_armor);
				break;
			case MM_INVENTORY:
				run_inventory(&t_player);
				break;
			case MM_EXIT:
				b_loop = false;
				break;
		}
	}
	save_player(&t_player);
	return 0;
}

int output_main_menu()
{
	system("cls");
	cout << "**************************** 로비 ****************************" << '\n';
	cout << "1. 맵" << '\n';
	cout << "2. 상점" << '\n';
	cout << "3. 가방" << '\n';
	cout << "4. 종료" << '\n';
	cout << "메뉴를 선택하세요 : ";
	int i_menu = get_input();
	if (i_menu == INT_MAX || i_menu <= MM_NONE || i_menu > MM_EXIT)
		return MM_NONE;
	return i_menu;
}

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

void loop_map(_tag_player* p_player, _tag_monster* p_monster_arr)
{
	bool b_loop = true;

	while (b_loop)
	{
		int i_menu = output_map_menu();
		if (MT_BACK == i_menu)
			return;
		run_battle(p_player, p_monster_arr, i_menu);
	}
}

void output_battle_tag(int i_menu)
{
	switch (i_menu)
	{
		case MT_EASY:
			cout << "**************************** 쉬움 ****************************" << '\n';
			break;
		case MT_NORMAL:
			cout << "**************************** 보통 ****************************" << '\n';
			break;
		case MT_HARD:
			cout << "**************************** 어려움 ****************************" << '\n';
			break;
	}
}

void output_player_info(_tag_player* p_player)
{
	cout << "================== Player ==================" << '\n';
	cout << "이름 : " << p_player->str_name << "\t직업 : " << p_player->str_job_name << '\n';
	cout << "레벨 : " << p_player->i_level << "\t경험치 : " << p_player->i_exp << " / " << g_i_level_up_exp[p_player->i_level - 1] << '\n';
	if (p_player->b_equip[EQ_WEAPON] == true)
		cout << "공격력 : " << p_player->i_attack_min << " + " << p_player->t_equip[EQ_WEAPON].i_min << " ~ " << p_player->i_attack_max << " + " << p_player->t_equip[EQ_WEAPON].i_max;
	else
		cout << "공격력 : " << p_player->i_attack_min << " ~ " << p_player->i_attack_max;
	if (p_player->b_equip[EQ_ARMOR] == true)
		cout << "\t방어력 : " << p_player->i_armor_min << " + " << p_player->t_equip[EQ_ARMOR].i_min << " ~ " << p_player->i_armor_max << " + " << p_player->t_equip[EQ_ARMOR].i_max << '\n';
	else
		cout << "\t방어력 : " << p_player->i_armor_min << " ~ " << p_player->i_armor_max << '\n';
	cout << "체력 : " << p_player->i_hp << " / " << p_player->i_hp_max << "\t마나 : " << p_player->i_mp << " / " << p_player->i_mp_max << '\n';
	if (p_player->b_equip[EQ_WEAPON])
		cout << "장착무기 : " << p_player->t_equip[EQ_WEAPON].str_name;
	else
		cout << "장착무기 : 없음";
	if (p_player->b_equip[EQ_ARMOR])
		cout << "\t장착방어구 : " << p_player->t_equip[EQ_ARMOR].str_name << '\n';
	else
		cout << "\t장착방어구 : 없음" << '\n';
	cout << "보유골드 : " << p_player->t_inventory.i_gold << " Gold" << '\n' << endl;
}

void output_monster_info(_tag_monster* p_monster)
{
	cout << "====================== Monster ======================" << '\n';
	cout << "이름 : " << p_monster->str_name << "\t레벨 : " << p_monster->i_level << '\n';
	cout << "공격력 : " << p_monster->i_attack_min << " - " << p_monster->i_attack_max << "\t방어력 : " << p_monster->i_armor_min << " - " << p_monster->i_armor_max << '\n';
	cout << "체력 : " << p_monster->i_hp << " / " << p_monster->i_hp_max << "\t마나 : " << p_monster->i_mp << " / " << p_monster->i_mp_max << '\n';
	cout << "획득경험치 : " << p_monster->i_exp << "\t획득골드 : " << p_monster->i_gold_min << " - " << p_monster->i_gold_max << '\n' << endl;
}

int output_battle_menu()
{
	cout << "1. 공격" << '\n';
	cout << "2. 도망가기" << '\n';
	cout << "메뉴를 선택하세요 : ";
	int i_menu = get_input();

	if (i_menu == INT_MAX || i_menu <= BATTLE_NONE || i_menu > BATTLE_BACK)
		return BATTLE_NONE;
	return i_menu;
}

void battle(_tag_player* p_player, _tag_monster* p_monster)
{
	int i_attack_min = p_player->i_attack_min;
	int i_attack_max = p_player->i_attack_max;

	if (p_player->b_equip[EQ_WEAPON])
	{
		i_attack_min += p_player->t_equip[EQ_WEAPON].i_min;
		i_attack_max += p_player->t_equip[EQ_WEAPON].i_max;
	}
	int iAttack = rand() % (i_attack_max - i_attack_min + 1) + i_attack_min;
	int iArmor = rand() % (p_monster->i_armor_max - p_monster->i_armor_min + 1) + p_monster->i_armor_min;
	int iDamage = iAttack - iArmor;
	iDamage = iDamage < 1 ? 1 : iDamage;
	p_monster->i_hp -= iDamage;
	cout << p_player->str_name << " 가 " << p_monster->str_name << "에게 " << iDamage << " 피해를 입혔습니다." << '\n';
	if (p_monster->i_hp <= 0)
	{
		cout << p_monster->str_name << " 몬스터가 사망하였습니다." << '\n';
		p_player->i_exp += p_monster->i_exp;
		int i_gold = (rand() % (p_monster->i_gold_max - p_monster->i_gold_min) + p_monster->i_gold_min);
		p_player->t_inventory.i_gold += i_gold;
		cout << p_monster->i_exp << " 경험치를 획득하였습니다." << '\n';
		cout << i_gold << " Gold를 획득하였습니다." << '\n';
		p_monster->i_hp = p_monster->i_hp_max;
		p_monster->i_mp = p_monster->i_mp_max;
		if (p_player->i_exp >= g_i_level_up_exp[p_player->i_level - 1])
		{
			p_player->i_exp -= g_i_level_up_exp[p_player->i_level - 1];
			++p_player->i_level;
			cout << "레벨업 하였습니다." << '\n';
			int iJobIndex = p_player->e_job - 1;
			int i_hp_up = rand() % (g_t_level_up_table[iJobIndex].i_hp_max - g_t_level_up_table[iJobIndex].i_hp_min + 1) +
				g_t_level_up_table[iJobIndex].i_hp_min;
			int i_mp_up = rand() % (g_t_level_up_table[iJobIndex].i_mp_max - g_t_level_up_table[iJobIndex].i_mp_min + 1) +
				g_t_level_up_table[iJobIndex].i_mp_min;

			p_player->i_attack_min += g_t_level_up_table[iJobIndex].i_attack_min;
			p_player->i_attack_max += g_t_level_up_table[iJobIndex].i_attack_max;
			p_player->i_armor_min += g_t_level_up_table[iJobIndex].i_armor_min;
			p_player->i_armor_max += g_t_level_up_table[iJobIndex].i_armor_max;
			p_player->i_hp_max += i_hp_up;
			p_player->i_mp_max += i_mp_up;
			p_player->i_hp = p_player->i_hp_max;
			p_player->i_mp = p_player->i_mp_max;
		}
		return;
	}
	iAttack = rand() % (p_monster->i_attack_max - p_monster->i_attack_min + 1) + p_monster->i_attack_min;
	int i_armor_min = p_player->i_armor_min;
	int i_armor_max = p_player->i_armor_max;

	if (p_player->b_equip[EQ_ARMOR])
	{
		i_armor_min += p_player->t_equip[EQ_ARMOR].i_min;
		i_armor_max += p_player->t_equip[EQ_ARMOR].i_max;
	}
	iArmor = rand() % (i_armor_max - i_armor_min + 1) + i_armor_min;
	iDamage = iAttack - iArmor;
	iDamage = iDamage < 1 ? 1 : iDamage;
	p_player->i_hp -= iDamage;
	cout << p_monster->str_name << " 가 " << p_player->str_name << "에게 " << iDamage << " 피해를 입혔습니다." << '\n';
	if (p_player->i_hp <= 0)
	{
		cout << p_player->str_name << " 플레이어가 사망하였습니다." << '\n';
		int i_exp = p_player->i_exp * 0.1f;
		int i_gold = p_player->t_inventory.i_gold * 0.1f;

		p_player->i_exp -= i_exp;
		p_player->t_inventory.i_gold -= i_gold;
		cout << i_exp << " 경험치를 잃었습니다." << '\n';
		cout << i_gold << " Gold를 잃었습니다." << '\n';
		p_player->i_hp = p_player->i_hp_max;
		p_player->i_mp = p_player->i_mp_max;
	}
}

void run_battle(_tag_player* p_player, _tag_monster* p_monster_arr, int i_menu)
{
	_tag_monster t_monster = p_monster_arr[i_menu - 1];

	while (true)
	{
		system("cls");
		output_battle_tag(i_menu);
		output_player_info(p_player);
		output_monster_info(&t_monster);
		switch (output_battle_menu())
		{
			case BATTLE_ATTACK:
				battle(p_player, &t_monster);
				system("pause");
				break;
			case BATTLE_BACK:
				return;
		}
	}
}

int output_map_menu()
{
	system("cls");
	cout << "**************************** 맵 ****************************" << '\n';
	cout << "1. 쉬움" << '\n';
	cout << "2. 보통" << '\n';
	cout << "3. 어려움" << '\n';
	cout << "4. 뒤로가기" << '\n';
	cout << "맵을 선택하세요 : ";
	int i_menu = get_input();

	if (i_menu == INT_MAX || i_menu <= MT_NONE || i_menu > MT_BACK)
		return MT_NONE;
	return i_menu;
}

int select_job()
{
	int iJob = JOB_NONE;

	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. 기사" << '\n';
		cout << "2. 궁수" << '\n';
		cout << "3. 마법사" << '\n';
		cout << "직업을 선택하세요 : ";
		iJob = get_input();

		if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}
	return iJob;
}

void set_player(_tag_player* p_player)
{
	cout << "이름 : ";
	cin.getline(p_player->str_name, NAME_SIZE - 1); 
	p_player->e_job = (JOB)select_job();
	p_player->i_level = 1;
	p_player->i_exp = 0;
	p_player->t_inventory.i_gold = 10000;
	switch (p_player->e_job)
	{
		case JOB_KNIGHT:
			strcpy_s(p_player->str_job_name, "기사");
			p_player->i_attack_min = 5;
			p_player->i_attack_max = 10;
			p_player->i_armor_min = 15;
			p_player->i_armor_max = 20;
			p_player->i_hp_max = 500;
			p_player->i_hp = 500;
			p_player->i_mp_max = 100;
			p_player->i_mp = 100;
			break;
		case JOB_ARCHER:
			strcpy_s(p_player->str_job_name, "궁수");
			p_player->i_attack_min = 10;
			p_player->i_attack_max = 15;
			p_player->i_armor_min = 10;
			p_player->i_armor_max = 15;
			p_player->i_hp_max = 400;
			p_player->i_hp = 400;
			p_player->i_mp_max = 200;
			p_player->i_mp = 200;
			break;
		case JOB_WIZARD:
			strcpy_s(p_player->str_job_name, "마법사");
			p_player->i_attack_min = 15;
			p_player->i_attack_max = 20;
			p_player->i_armor_min = 5;
			p_player->i_armor_max = 10;
			p_player->i_hp_max = 300;
			p_player->i_hp = 300;
			p_player->i_mp_max = 300;
			p_player->i_mp = 300;
			break;
	}
}

_tag_monster create_monster(const char* p_name, int i_attack_min, int i_attack_max, int i_armor_min, int i_armor_max, int i_hp, int i_mp, int i_level, int i_exp, int i_gold_min, int i_gold_max)
{
	_tag_monster t_monster = {};
	strcpy_s(t_monster.str_name, p_name);
	t_monster.i_attack_min = i_attack_min;
	t_monster.i_attack_max = i_attack_max;
	t_monster.i_armor_min = i_armor_min;
	t_monster.i_armor_max = i_armor_max;
	t_monster.i_hp = i_hp;
	t_monster.i_hp_max = i_hp;
	t_monster.i_mp = i_mp;
	t_monster.i_mp_max = i_mp;
	t_monster.i_level = i_level;
	t_monster.i_exp = i_exp;
	t_monster.i_gold_min = i_gold_min;
	t_monster.i_gold_max = i_gold_max;
	return t_monster;
}

_tag_level_up_status create_level_up_status(int i_attack_min, int i_attack_max, int i_armor_min, int i_armor_max, int i_hp_min, int i_hp_max, int i_mp_min, int i_mp_max)
{
	_tag_level_up_status tStatus = {};

	tStatus.i_attack_min = i_attack_min;
	tStatus.i_attack_max = i_attack_max;
	tStatus.i_armor_min = i_armor_min;
	tStatus.i_armor_max = i_armor_max;
	tStatus.i_hp_min = i_hp_min;
	tStatus.i_hp_max = i_hp_max;
	tStatus.i_mp_min = i_mp_min;
	tStatus.i_mp_max = i_mp_max;
	return tStatus;
}

_tag_item create_item(const char* p_name, ITEM_TYPE e_type, int i_min, int i_max, int i_price, int i_sell, const char* p_desc)
{
	_tag_item t_item = {};

	strcpy_s(t_item.str_name, p_name);
	strcpy_s(t_item.str_desc, p_desc);
	t_item.e_type = e_type;
	switch (e_type)
	{
		case IT_WEAPON:
			strcpy_s(t_item.str_type_name, "무기");
			break;
		case IT_ARMOR:
			strcpy_s(t_item.str_type_name, "방어구");
			break;
	}
	t_item.i_min = i_min;
	t_item.i_max = i_max;
	t_item.i_price = i_price;
	t_item.i_sell = i_sell;
	return t_item;
}

void set_monster(_tag_monster* p_monster_arr)
{
	p_monster_arr[0] = create_monster("고블린", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	p_monster_arr[1] = create_monster("트롤", 80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);
	p_monster_arr[2] = create_monster("드래곤", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);
}

int OutputStoreMenu()
{
	system("cls");
	cout << "**************************** 상점 ****************************" << '\n';
	cout << "1. 무기상점" << '\n';
	cout << "2. 방어구상점" << '\n';
	cout << "3. 뒤로가기" << '\n';
	cout << "상점을 선택하세요 : ";
	int i_menu = get_input();
	if (i_menu == INT_MAX || i_menu <= SM_NONE || i_menu > SM_BACK)
		return SM_NONE;
	return i_menu;
}

int output_store_item_list(_tag_inventory* p_inventory, _tag_item* p_store, int i_item_count)
{
	for (int idx = 0; idx < i_item_count; ++idx)
	{
		cout << idx + 1 << ". 이름 : " << p_store[idx].str_name <<
			"\t종류 : " << p_store[idx].str_type_name << '\n';
		cout << "공격력 : " << p_store[idx].i_min << " ~ " << p_store[idx].i_max << '\n';
		cout << "판매가격 : " << p_store[idx].i_price <<
			"\t구매가격 : " << p_store[idx].i_sell << '\n';
		cout << "설명 : " << p_store[idx].str_desc << '\n' << endl;
	}
	cout << i_item_count + 1 << ". 뒤로가기" << '\n' << endl;
	cout << "보유금액 : " << p_inventory->i_gold << " Gold" << '\n';
	cout << "남은공간 : " << INVENTORY_MAX - p_inventory->i_item_count << '\n';
	cout << "구입하고 싶은 물품을 고르세요 : ";
	int i_menu = get_input();
	if (i_menu < 1 || i_menu > i_item_count + 1)
		return INT_MAX;
	return i_menu;
}

void buy_item(_tag_inventory* p_inventory, _tag_item* p_store, int i_item_count, int iStoreType)
{
	while (true)
	{
		system("cls");
		switch (iStoreType)
		{
			case IT_WEAPON:
				cout << "**************************** 무기상점 ****************************" << '\n';
				break;
			case IT_ARMOR:
				cout << "**************************** 방어구상점 ****************************" << '\n';
				break;
		}
		int i_input = output_store_item_list(p_inventory, p_store, i_item_count);
		if (i_input == INT_MAX)
		{
			cout << "잘못 입력하였습니다." << '\n';
			system("pause");
			continue;
		}
		else if (i_input == i_item_count + 1)
			break;
		int iIndex = i_input - 1;
		if (p_inventory->i_item_count == INVENTORY_MAX)
		{
			cout << "가방이 꽉 찼습니다." << '\n';
			system("pause");
			continue;
		}
		else if (p_inventory->i_gold < p_store[iIndex].i_price)
		{
			cout << "보유금액이 부족합니다." << '\n';
			system("pause");
			continue;
		}
		p_inventory->t_item[p_inventory->i_item_count] = p_store[iIndex];
		++p_inventory->i_item_count;
		p_inventory->i_gold -= p_store[iIndex].i_price;
		cout << p_store[iIndex].str_name << " 아이템을 구매하였습니다." << '\n';
		system("pause");
	}
}

void run_store(_tag_inventory* p_inventory, _tag_item* p_weapon, _tag_item* p_armor)
{
	while (true)
	{
		switch (OutputStoreMenu())
		{
			case SM_WEAPON:
				buy_item(p_inventory, p_weapon, STORE_WEAPON_MAX, IT_WEAPON);
				break;
			case SM_ARMOR:
				buy_item(p_inventory, p_armor, STORE_ARMOR_MAX, IT_ARMOR);
				break;
			case SM_BACK:
				return;
		}
	}
}

int output_inventory(_tag_player* p_player)
{
	system("cls");
	cout << "**************************** 가방 ****************************" << '\n';
	output_player_info(p_player);
	for (int idx = 0; idx < p_player->t_inventory.i_item_count; ++idx)
	{
		cout << idx + 1 << ". 이름 : " << p_player->t_inventory.t_item[idx].str_name <<
			"\t종류 : " << p_player->t_inventory.t_item[idx].str_type_name << '\n';
		cout << "공격력 : " << p_player->t_inventory.t_item[idx].i_min << " ~ " <<
			p_player->t_inventory.t_item[idx].i_max << '\n';
		cout << "판매가격 : " << p_player->t_inventory.t_item[idx].i_price <<
			"\t구매가격 : " << p_player->t_inventory.t_item[idx].i_sell << '\n';
		cout << "설명 : " << p_player->t_inventory.t_item[idx].str_desc << '\n' << endl;
	}
	cout << p_player->t_inventory.i_item_count + 1 << ". 뒤로가기" << '\n';
	cout << "장착할 아이템을 선택하세요 : ";
	int i_menu = get_input();
	if (i_menu < 1 || i_menu > p_player->t_inventory.i_item_count + 1)
		return INT_MAX;
	return i_menu;
}

EQUIP compute_equip_type(ITEM_TYPE e_type)
{
	EQUIP eq;

	switch (e_type)
	{
		case IT_WEAPON:
			eq = EQ_WEAPON;
			break;
		case IT_ARMOR:
			eq = EQ_ARMOR;
			break;
	}
	return eq;
}

void run_inventory(_tag_player* p_player)
{
	while (true)
	{
		int i_input = output_inventory(p_player);
		if (i_input == INT_MAX)
			continue;
		else if (i_input == p_player->t_inventory.i_item_count + 1)
			break;
		int index = i_input - 1;
		EQUIP eq = compute_equip_type(p_player->t_inventory.t_item[index].e_type);
		if (p_player->b_equip[eq] == true)
		{
			_tag_item	tSwap = p_player->t_equip[eq];
			p_player->t_equip[eq] = p_player->t_inventory.t_item[index];
			p_player->t_inventory.t_item[index] = tSwap;
		}
		else
		{
			p_player->t_equip[eq] = p_player->t_inventory.t_item[index];
			for (int idx = index; idx < p_player->t_inventory.i_item_count - 1; ++idx)
				p_player->t_inventory.t_item[idx] = p_player->t_inventory.t_item[idx + 1];
			--p_player->t_inventory.i_item_count;
			p_player->b_equip[eq] = true;
		}
		cout << p_player->t_equip[eq].str_name << " 아이템을 장착하였습니다." << '\n';
		system("pause");
	}
}
