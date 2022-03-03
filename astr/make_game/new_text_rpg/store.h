#pragma once

#include "value.h"

class CStore
{
	protected:
		CStore();
	public:
		virtual CStore();
	private:
		friend class CStoreManager;
	protected:
		vector<class CItem *> m_vec_item;
	protected:
		CItem *create_item(char *p_name, ITEM_TYPE e_type, int i_price, int i_sell, char *p_desc);
		void output_item_list();
		void output_tag(char *p_store_name);
	public:
		virtual bool init() = 0;
		virtual void run() = 0;
};
