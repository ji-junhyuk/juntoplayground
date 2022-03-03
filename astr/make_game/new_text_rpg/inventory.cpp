#include "inventory.h"
#include "item.h"

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
	for (size_t idx = 0; idx < m_vec_item.size(); ++idx)
	{
		cout << idx + 1 << ". ";
		m_vec_item[idx]->render();
		cout << '\n';
	}
	system("pause");
}

void CInventory::add_item(CItem *p_item)
{
}
