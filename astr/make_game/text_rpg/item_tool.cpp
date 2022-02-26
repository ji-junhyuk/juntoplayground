#include <iostream>
# define NAME_SIZE			32
# define STORE_WEAPON_MAX	3
# define STORE_ARMOR_MAX	3
# define ITEM_DESC_LENGTH	512

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_ADD,
	MM_LOAD,
	MM_SAVE,
	MM_OUTPUT,
	MM_EXIT
};

enum STORE_MENU
{
        SM_NONE,
        SM_WEAPON,
        SM_ARMOR,
        SM_BACK
};

enum ITEM_TYPE
{
        IT_NONE,
        IT_WEAPON,
        IT_ARMOR,
        IT_BACK
};

struct _tag_item
{
        char            str_name[NAME_SIZE];
        char            str_type_name[NAME_SIZE];
        ITEM_TYPE       e_type;
        int                     i_min;
        int                     i_max;
        int                     i_price;
        int                     i_sell;
        char            str_desc[ITEM_DESC_LENGTH];
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

void add_item(_tag_item *p_weapon_store, _tag_item *p_armor_store)
{
	int	i_store = 0;
	int i_item_level = 0;
	while (true)
	{
		system("cls");
		cout << "1. 무기상점" << '\n';
		cout << "2. 방어구상점" << '\n';
		cout << "3. 취소" << '\n';
		cout << "추가할 상점을 선택하세요 : ";
		i_store = get_input();

		if (i_store == 3)
			return ;
		else if (i_store < 1 || i_store > 3)
			continue ;
		break ;
	}
	while (true)
	{
		system("cls");
		cout << "1. 초급" << '\n';
		cout << "2. 중급" << '\n';
		cout << "3. 고급" << '\n';
		cout << "4. 취소" << '\n';
		cout << "추가할 아이템 단계를 선택하세요 : ";
		i_item_level = get_input();

		if (i_item_level == 4)
			return ;
		else if (i_item_level < 1 || i_item_level > 4)
			continue ;
		--i_item_level;
		break ;
	}
	cin.clear();
	cin.ignore(1024, '\n');
	_tag_item *p_item = NULL;
	if (i_store == SM_WEAPON)
	{
		cout << "SM_WEAPON\n";
		p_item = &p_weapon_store[i_item_level];
		p_item->e_type = IT_WEAPON;
		strcpy_s(p_item->str_type_name, "attck");
	}
	else
	{
		cout << "SM_ARMOR\n";
		p_item = &p_armor_store[i_item_level];
		p_item->e_type = IT_ARMOR;
		strcpy_s(p_item->str_type_name, "shield");
	}
	cout << "이름 : ";
	cin.getline(p_item->str_name, NAME_SIZE - 1);
	cout << "아이템 설명 : ";
	cin.getline(p_item->str_desc, ITEM_DESC_LENGTH - 1);
	cout << "최소능력치 : ";
	p_item->i_min = get_input();
	cout << "최대능력치 : ";
	p_item->i_max = get_input();
	cout << "구매가격 : ";
	p_item->i_price= get_input();
	cout << "판매가격 : ";
	p_item->i_sell = get_input();
	cout << "아이템 추가 완료" << '\n';
	system("pause");
}

bool save_store(_tag_item *p_weapon, _tag_item *p_armor)
{
	FILE	*p_file = NULL;
	fopen_s(&p_file, "store.mst", "wb");
	if (p_file)
	{
		fwrite(p_weapon, sizeof(_tag_item), STORE_WEAPON_MAX, p_file);
		fwrite(p_armor, sizeof(_tag_item), STORE_ARMOR_MAX, p_file);
		fclose(p_file);
		return (true);
	}
	return false;
}

bool load_store(_tag_item *p_weapon, _tag_item *p_armor)
{
	FILE	*p_file = NULL;
	fopen_s(&p_file, "store.mst", "rb");
	if (p_file)
	{
		fread(p_weapon, sizeof(_tag_item), STORE_WEAPON_MAX, p_file);
		fread(p_armor, sizeof(_tag_item), STORE_ARMOR_MAX, p_file);
		fclose(p_file);
		return (true);
	}
	return false;
}

void output_store_item_list(_tag_item *p_weapon, _tag_item *p_armor)
{
	system("cls");
	cout << "================ Store ================" << '\n';
	for (int idx = 0; idx < STORE_WEAPON_MAX; ++idx)
	{
		cout << idx + 1 << ". 이름 : " << p_weapon[idx].str_name <<
				"\t종류 : " << p_weapon[idx].str_type_name << '\n';
		cout << "공격력 : " << p_weapon[idx].i_min << " ~ " << p_weapon[idx].i_max << '\n';
		cout << "판매가격 : " << p_weapon[idx].i_price <<
				"\t구매가격 : " << p_weapon[idx].i_sell << '\n';
		cout << "설명 : " << p_weapon[idx].str_desc << '\n' << endl;
	}
	for (int idx = 0; idx < STORE_ARMOR_MAX; ++idx)
	{
		cout << idx + 1 << ". 이름 : " << p_armor[idx].str_name <<
				"\t종류 : " << p_armor[idx].str_type_name << '\n';
		cout << "방어력 : " << p_armor[idx].i_min << " ~ " << p_armor[idx].i_max << '\n';
		cout << "판매가격 : " << p_armor[idx].i_price <<
				"\t구매가격 : " << p_armor[idx].i_sell << '\n';
		cout << "설명 : " << p_armor[idx].str_desc << '\n' << endl;
	}
	system("pause");
};

int main(void)
{
	_tag_item t_weapon[STORE_WEAPON_MAX] = {};
	_tag_item t_armor[STORE_ARMOR_MAX] = {};

	while (true)
	{
		system("cls");
		cout << "1. 아이템 추가" << '\n';
		cout << "2. 읽어오기" << '\n';
		cout << "3. 저장" << '\n';
		cout << "4. 아이템 목록 출력" << '\n';
		cout << "5. 종료" << '\n';
		cout << "메뉴를 선택하세요 : ";
		int i_menu = get_input();
		if (i_menu == MM_EXIT)
			break ;
		switch (i_menu)
		{
			case MM_ADD:
				add_item(t_weapon, t_armor);
				break;
			case MM_LOAD:
				load_store(t_weapon, t_armor);
				break;
			case MM_SAVE:
				save_store(t_weapon, t_armor);
				break;
			case MM_OUTPUT:
				output_store_item_list(t_weapon, t_armor);
				break;
		}
	}
	save_store(t_weapon, t_armor);
	return (0);
}
