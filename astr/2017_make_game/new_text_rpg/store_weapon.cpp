#include "store_weapon.h"
#include "item_weapon.h"
#include "player.h"
#include "object_manager.h"
#include "inventory.h"

CStoreWeapon::CStoreWeapon()
{
}

CStoreWeapon::~CStoreWeapon()
{
}

bool CStoreWeapon::init()
{
	CItemWeapon *p_item = (CItemWeapon *)create_item("목검", IT_WEAPON, 1000, 500, "나무로 만든 검");
	p_item->set_weapon_info(5, 10, 10.f);
	CItemWeapon *p_item = (CItemWeapon *)create_item("철검", IT_WEAPON, 2000, 500, "철로 만든 검");
	p_item->set_weapon_info(25, 10, 10.f);
	CItemWeapon *p_item = (CItemWeapon *)create_item("무한의 대검", IT_WEAPON, 1000, 500, "내가 좋아하는 검");
	p_item->set_weapon_info(250, 10, 10.f);
	return true;
}

void CStoreWeapon::run()
{
	CPlayer *p_player = (CPlayer *)GET_SINGLE(CObjectManager)->find_object("Player");
	while (true)
	{
		system("cls");
		cout << "Weapon Store" << '\n';
		output_item_list();
		cout << m_vec_item.size() + 1 << ". 뒤로가기" << '\n';
		cout << "보유금액 : " << p_player->get_gold() << " Gold" << '\n';
		int i_input = input<int>();
		if (i_input < 1 || i_input > m_vec_item.size() + 1)
			continue;
		else if (i_input == m_vec_item.size() + 1)
			return ;
		if (GET_SINGLE(CInventory)->full())
		{
			cout << "인벤토리에 빈 공간이 없습니다." << '\n';
			continue;
		}
		else if (p_player->get_gold() < m_vec_item[i_input - 1]->get_item_info.i_price)
		{
			cout << "소지금이 부족합니다." << '\n';
			continue;
		}
		CItem p_item = m_vec_item[i_input - 1]->clone();
		GET_SINGLE(CInventory)->add_item(p_item);
		p_player->add_gold(-p_item->get_item_info().i_price);
	}
}
