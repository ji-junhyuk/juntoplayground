#include "store_manger.h"
#include "store_weapon.h"
#include "store_armor.h"

DECLARE_SINGLE(CStoreManager)

CStoreManager::CStoreManager()
{
}

CStoreManager::~CStoreManager()
{
	safe_delete_vec_list(m_vec_store);
}

bool CStoreManager::init()
{
	CStore *p_store = create_store(ST_WEAPON);
	p_store = create_store(ST_ARMOR);
	return true;
}

void CStoreManager::run()
{
	while (true)
	{
		int  i_menu = output_menu();
		if (i_menu == STR_NONE)
			continue;
		else if (i_menu == STR_BACK)
			break;
		m_vec_store[i_menu - 1]->run();
	}
}

CStore *CStoreManager::create_store(STORE_TYPE e_type)
{
	CStore *p_store = NULL;

	switch (e_type)
	{
		case ST_WEAPON:
			p_store = new CStoreWeapon;
			break;
		case ST_ARMOR:
			p_store = new CStoreArmor;
			break;
	}
	if (!p_store->init())
	{
		SAFE_DELETE(p_store);
		return NULL;
	}
	m_vec_store.push_back(p_store);
	return p_store;
}

int CStoreManager::output_menu()
{
	system("cls");
	cout << "1. 무기상점" << '\n';
	cout << "2. 방어구상점" << '\n';
	cout << "3. 뒤로가기" << '\n';
	cout << "상점을 선택하세요 : ";
	int i_store = input<int>();
	if (i_store <= STR_NONE || i_store > STR_BACK)
		return STR_NONE;
	return i_store;
}
