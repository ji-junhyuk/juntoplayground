#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <time.h>

using namespace std;

#include "defines.h"
#include "flags.h"

template <typename T>
T input()
{
	T	data;
	cin >> data;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return 0;
	}
	return data;
}

template <typename T>
void safe_delete_map(T& p)
{
	T::iterator iter;
	T::iterator iter_end = p.end();
	for (iter = p.begin(); iter != iter_end; ++iter)
	{
		SAFE_DELETE(iter->second);
	}
	p.clear();
}

template <typename T>
void safe_delete_vec_list(T& p)
{
	T::iterator iter;
	T::iterator iter_end = p.end();
	for (iter = p.begin(); iter != iter_end; ++iter)
	{
		SAFE_DELETE(*iter);
	}
	p.clear();
}

typedef struct _tag_character_info
{
	int	i_attack_max;
	int	i_attack_min;
	int i_armor_max;
	int i_armor_min;
	int i_hp;
	int i_hp_max;
	int i_mp;
	int i_mp_max;
	int i_level;
	int i_exp;
} CHARACTERINFO, *PCHARACTERINFO;

typedef struct _tag_level_up_info
{
	int i_attack_min;
	int i_attack_max;
	int i_armor_min;
	int i_armor_max;
	int i_hp;
	int i_mp;
} LEVELUPINFO, *PLEVELUPINFO;

#define MAX_LEVEL 10
static int g_i_level_up_table[MAX_LEVEL] = {4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 11000, 12000};
typedef struct _tag_item_info
{
	ITEM_TYPE e_type;
	string	str_type_name;
	int		i_price;
	int		i_sell;
	string	str_desc;
} ITEMINFO, *PITEMINFO;
