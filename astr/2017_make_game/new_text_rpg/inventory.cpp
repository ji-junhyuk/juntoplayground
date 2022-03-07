#include "inventory.h"
#include "item.h"
#include "player.h"
#include "object_manager.h"

DEFINITION_SINGLE(CInventory)

CInventory::CInventory()	:
	m_i_inven_max(10)
{
}

CInventory::~CInventory()
{
	safe_delete_vec_list(m_vec_item);
}

bool CInventory::init()
{
	return false;
}

void CInventory::add_item(CItem *p_item)
{
	if (m_i_inven_max == m_vec_item.size())
		return ;
	m_vec_item.push_back(p_item);
}

void CInventory::run()
{

	CPlayer *p_player = (CPlayer *)GET_SINGLE(CObjectManager)->find_object("Player");
	while (true)
	{
		system("cls");
		cout << "=============== Inventory ===============" << '\n' << '\n';
		p_player->render();
		cout << '\n';
		for (size_t idx = 0; idx < m_vec_item.size(); ++idx)
		{
			cout << idx + 1 << ". ";
			m_vec_item[idx]->render();
			cout << '\n';
		}
		cout << m_vec_item.size() + 1 << ". 뒤로가기" << '\n';
		cout << "장착할 아이템을 선택하세요 : ";
		int i_item = input<int>();
		if (i_item < 1 || i_item > m_vec_item.size() + 1)
			continue;
		else if (i_item == m_vec_item.size() + 1)
			return ;
		CItem* p_equip = p_player->equip(m_vec_item[i_item - 1]);
		if (p_equip)
		{
			m_vec_item[i_item - 1] = p_equip;
		}
		else
		{
			vector<CItem*>::iterator iter = m_vec_item.begin() + (i_item - 1);
			m_vec_item.erase(iter);
		}
	}
}

void CInventory::add_item(CItem *p_item)
{
}
