#include "store.h"
#include "item_weapon.h"
#include "item_armor.h"

CStore::CStore()
{
}

CStore::~CStore()
{
	safe_delete_vec_list(m_vec_item);
}

CItem *CStore::create_item(char *p_name, ITEM_TYPE e_type, int i_price, int i_sell, char *p_desc)
{
	CItem *p_item = NULL;

	switch (e_type)
	{
		case IT_WEAPON:
			p_item = new CItemWeapon;
			break;
		case IT_ARMOR:
			p_item = new CItemArmor;
			break;
	}
	if (!p_item->init())
	{
		SAFE_DELETE(p_item);
		return NULL;
	}
	p_item->set_name(p_name);
	p_item->set_item_info(e_type, i_price, i_sell, p_desc);
	m_vec_item.push_back(p_item);
	return p_item;
}

void CStore::output_item_list()
{
	for (size_t idx = 0; idx < m_vec_item.size(); ++idx)
	{
		cout << idx + 1 << ". ";
		m_vec_item[idx]->render();
		cout << '\n';
	}
}
