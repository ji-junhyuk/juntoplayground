#pragma once

#include <value.h>

enum STORE_TYPE
{
	STR_NONE,
	STR_WEAPON,
	STR_ARMOR,
	STR_BACK
};

class CStoreManager
{
	private:
		vector<CStore *>	m_vec_store;
	public:
		bool init();
		void run();
	private:
		CStore *create_store(STORE_TYPE e_type);
		int output_menu();
	DECLARE_SINGLE(CStoreManager)
};
